#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
//#include "preprocess.hpp"
vector<int> grouping(vector<Mat> hists)
{
	Matx<float, 32, 1> w[2], s[2];
	w[0] << 0, 0, 2, 2, 3, 5, 5, 4, 4, 3, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 3, 3, 2;
	w[1] << 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0;

	vector<int> groups;
	for (int i = 0; i < (int)hists.size(); i++)
	{
		multiply(w[0], hists[i], s[0]);				// 히스토그램 유사도
		multiply(w[1], hists[i], s[1]);

		int group = (sum(s[0])[0] > sum(s[1])[0]) ? 0 : 1;
		groups.push_back(group);
	}
	return groups;
}


void classify_coins(vector<RotatedRect> circles, vector<int>& groups, int Ncoins[4])
{
	for (int i = 0; i < (int)circles.size(); i++)
	{
		int coin = 0;
		int radius = cvRound(circles[i].angle);

		if (groups[i] == 0) {
			if (radius > 48)		coin = 3;
			else if (radius > 46)	coin = 2;
			else if (radius > 25)	coin = 0;
		}
		if (groups[i] == 1) {
			if (radius > 48)		coin = 3;
			else if (radius > 43)	coin = 2;
			else if (radius > 36)	coin = 1;
		}

		Ncoins[coin]++;
	}
}

int calc_coins(int Ncoins[4])
{
	int count = 0;
	int coin_value[] = { 10, 50, 100, 500 };

	for (int i = 0; i < 4; i++) {
		count += coin_value[i] * Ncoins[i];

		cout << format("%3d원: %3d 개", coin_value[i], Ncoins[i]) << endl;
	}
	return count;
}

//#include "histogram.hpp"
Mat  make_palatte(int rows)
{
	Mat hsv(rows, 1, CV_8UC3);
	for (int i = 0; i < rows; i++)
	{
		uchar hue = saturate_cast<uchar>((float)i / rows * 180);
		hsv.at<Vec3b>(i) = Vec3b(hue, 255, 255);
	}
	cvtColor(hsv, hsv, COLOR_HSV2BGR);
	return hsv;
}
// 색상으로 히스토그램 그리기
void draw_hist_hue(Mat hist, Mat& hist_img, Size size = Size(256, 200))
{
	Mat hsv_palatte = make_palatte(hist.rows);

	hist_img = Mat(size, CV_8UC3, Scalar(255, 255, 255));
	float  bin = (float)hist_img.cols / hist.rows;
	normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);

	for (int i = 0; i < hist.rows; i++)
	{
		float start_x = (i * bin);
		float  end_x = (i + 1) * bin;
		Point2f pt1(start_x, 0);
		Point2f pt2(end_x, hist.at <float>(i));

		Scalar color = hsv_palatte.at<Vec3b>(i);
		rectangle(hist_img, pt1, pt2, color, -1);
	}
	flip(hist_img, hist_img, 0);
}

void calc_histo(const Mat& image, Mat& hist, Vec3i bins, Vec3f range, int _dims)
{
	int dims = (_dims <= 0) ? image.channels() : _dims;			// 히스토그램 차원수
	int		channels[] = { 0, 1, 2 };
	int		histSize[] = { bins[0], bins[1], bins[2] };

	float  range1[] = { 0, range[0] };
	float  range2[] = { 0, range[1] };
	float  range3[] = { 0, range[2] };
	const float* ranges[] = { range1, range2, range3 };

	calcHist(&image, 1, channels, Mat(), hist, dims, histSize, ranges);
}

vector <Mat> calc_coin_histo(vector<Mat> coins, int hue_bin)
{
	vector <Mat> histo;
	for (int i = 0; i < (int)coins.size(); i++)
	{
		Mat hsv, hist, hist_img;
		cvtColor(coins[i], hsv, COLOR_BGR2HSV);				// 컬러 공간변환
		calc_histo(hsv, hist, Vec3i(hue_bin, 0, 0), Vec3f(180, 0, 0), 1);

		hist.at<float>(0) = 0;									// 빨간색 빈도 제거
		hist.at<float>(1) = 0;									// 빨간색 빈도 제거
		normalize(hist, hist, 0, 1, NORM_MINMAX);			// 정규화
		histo.push_back(hist);
	}
	return histo;
}

//#include "classify.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Mat  preprocessing(Mat img)				// 전처리
{
	Mat gray, th_img;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	GaussianBlur(gray, gray, Size(7, 7), 2, 2);

	threshold(gray, th_img, 130, 255, THRESH_BINARY | THRESH_OTSU);
	morphologyEx(th_img, th_img, MORPH_OPEN, Mat(), Point(-1, -1), 1);

	return th_img;
}

// 검출 영역 원좌표로 반환 
vector<RotatedRect>  find_coins(Mat img)
{
	vector<vector<Point> > contours;
	findContours(img.clone(), contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	vector<RotatedRect> circles;
	for (int i = 0; i < (int)contours.size(); i++)
	{
		RotatedRect  mr = minAreaRect(contours[i]);
		mr.angle = (mr.size.width + mr.size.height) / 4.0f;

		if (mr.angle > 18) circles.push_back(mr);
	}
	return circles;
}



//#include "utils.hpp"
vector<Mat>  make_coinImg(const Mat src, vector<RotatedRect> circles)
{
	vector <Mat> coins;
	for (int i = 0; i < (int)circles.size(); i++)
	{
		int    radius = (int)circles[i].angle;
		Size    size = circles[i].size * 1.5f;
		
		Point2f center = Point2f(size.width / 2, size.height / 2);
		
		Mat coin, mask(size, CV_8UC3, Scalar(0, 0, 0));
		circle(mask, center, radius, Scalar(255, 255, 255), FILLED);

		getRectSubPix(src, size, circles[i].center, coin);
		bitwise_and(coin, mask, coin);

		coins.push_back(coin);
		//imshow(format("coin_%0d", i), coin);
		//imshow(format("mask_%0d", i), mask);
	}
	return  coins;
}

void  draw_circle(Mat& image, vector<RotatedRect> circles, vector<int> groups)
{
	Scalar color[] = {
		Scalar(0,  0, 255) , Scalar(255, 0 , 0) ,			// 그룹색상 (빨간색, 파란색)
		Scalar(200, 50, 0) , Scalar(250, 0 ,255)			// 검출순번, 동전반지름 색상
	};

	for (int i = 0; i < (int)circles.size(); i++)
	{
		int  radius = cvRound(circles[i].angle);				// 동전 반지름
		Point center = (Point)circles[i].center;				// 동전 중심
		circle(image, center, radius, color[groups[i]], 2);

		putText(image, to_string(i), center + Point(-10, 0), 1, 1, color[2], 2);			// 검출순번
		putText(image, to_string(radius), center + Point(-10, 20), 1, 1, color[3], 2);// 동전반지름
	}
}


int main() {
	int coin_no, hue_bin = 32;
	cout << "동전 영상번호: ";
	cin >> coin_no;
	String  fname = format("./image/%d.png", coin_no);
	Mat  image = imread(fname, 1);
	CV_Assert(image.data);

	Mat th_img = preprocessing(image);							// 전처리 ? 명암도 변환 및 이진화
	vector<RotatedRect> circles = find_coins(th_img);			// 동전 영역 검색
	vector<Mat> coins_img = make_coinImg(image, circles);		// 동전영상 생성
	vector<Mat> coins_hist = calc_coin_histo(coins_img, hue_bin);// 색상 히스토그램

	int  Ncoins[4] = { 0 };
	vector<int> groups = grouping(coins_hist);					// 동전영상 그룹 분리
	classify_coins(circles, groups, Ncoins);					// 동전 인식 
	int coin_count = calc_coins(Ncoins);						// 금액 계산

																// 결과 출력
	String str = format("total coin: %d Won", coin_count);		// 계산 금액 문자열
	cout << str << endl;											// 콘솔창에 출력
	putText(image, str, Point(10, 50), 1, 2, Scalar(0, 200, 0), 2);	// 영상에 텍스트 쓰기

	draw_circle(image, circles, groups);
	imshow("동전영상", image);
	waitKey();
	return 0;
}