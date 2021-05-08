#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void calc_Histo(const Mat& image, Mat& hist, Vec3i bins, Vec3f range_max, int _dims);
vector<Mat> load_histo(Vec3i bins, Vec3f ranges, int nImages);
Mat draw_histo(Mat hist);
Mat query_img();
Mat make_img(Mat img1, Mat img2);
Mat calc_similarity(Mat query_hist, vector<Mat>& DB_hists);
void select_view(double sinc, Mat DB_similaritys);


int main() {
	Vec3i bins(30, 42, 0);   // 계급 개수 : 색상(30개), 채도(42개)
	Vec3f ranges(180, 256, 0);  // 범위 : 색상(0~179), 채도(0~255)
	Mat hsv, query_hist;

	/*imshow("query", query);
	imshow("hist_img", hist_img);
	imshow("query + hist_img", make_img(query, hist_img));*/


	vector<Mat> DB_hists = load_histo(bins, ranges, 100);

	Mat query = query_img(); // 입력영상 읽기
	cvtColor(query, hsv, COLOR_BGR2HSV); // HSV 컬러 변환
	// 2차원 히스토그램 계산
	calc_Histo(hsv, query_hist, bins, ranges, 2);
	// 출력용 히스토그램 영상
	Mat hist_img = draw_histo(query_hist);

	// 컬러 히스토그램을 이용한 유사도 계산
	Mat DB_similaritys = calc_similarity(query_hist, DB_hists);

	double sinc;
	cout << "기준 유사도 입력 : ";
	cin >> sinc;
	// 유사도 기준 이상 영상 출력
	select_view(sinc, DB_similaritys);

	imshow("image", query);
	imshow("hist_img", hist_img);

}

// 계급수, 화소값 범위, 입력 이미지 개수 입력
vector<Mat> load_histo(Vec3i bins, Vec3f ranges, int nImages) {
	vector<Mat> DB_hists;
	for (int i = 0; i < nImages; i++) {
		String fname = format("DB/img_%02d.jpg", i);
		Mat hsv, hist, img = imread(fname, IMREAD_COLOR);
		if (img.empty()) continue;

		cvtColor(img, hsv, COLOR_BGR2HSV);
		calc_Histo(hsv, hist, bins, ranges, 2);
		DB_hists.push_back(hist);
	}

	cout << format("%d개 파일 로드 및 히스토그램 계산 완료", DB_hists.size());
	return DB_hists; // 3차원 영상
}

Mat draw_histo(Mat hist) {
	if (hist.dims != 2) {
		cout << "히스토그램이 2차원 데이터가 아닙니다." << endl;
		exit(1);
	}

	float ratio_value = 512.f;
	float ratio_hue = 180.f / hist.rows;
	float ratio_sat = 256.f / hist.cols;

	Mat graph(hist.size(), CV_32FC3);
	for (int i = 0; i < hist.rows; i++) {
		for (int j = 0; j < hist.cols; j++) {
			float vlaue = hist.at<float>(i, j) * ratio_value; // 빈도값
			float hue = i * ratio_hue; // 색상값
			float sat = j * ratio_sat; // 채도값

			// 3채널의 한 값 저장
			graph.at<Vec3f>(i, j) = Vec3f(hue, sat, vlaue);
		}
	}
	graph.convertTo(graph, CV_8U);
	cvtColor(graph, graph, COLOR_BGR2HSV);
	resize(graph, graph, Size(0,0), 10, 10, INTER_NEAREST);

	return graph;
}

// 매개변수 : 계산할 영상, 빈도수를 담을 영상, 구간수, 값의 최대 허용값
void  calc_Histo(const Mat& image, Mat& hist, Vec3i bins, Vec3f range_max, int _dims) {
	// 구간값 저장
	int		histSize[] = { bins[0], bins[1], bins[2] };
	// 값의 범위 저장
	float   range1[] = { 0, (float)range_max[0] };
	float   range2[] = { 0, (float)range_max[1] };
	float   range3[] = { 0, (float)range_max[2] };
	// 채널 수 만큼 저장
	int		channels[] = { 0, 1, 2 };
	// 영상의 차원 수 저장
	int		dims = image.channels();;
	// 구간값들을 모아 2차원 배열로 변환
	const float* ranges[] = { range1, range2, range3 };

	/*
	&image : 계산할 영상
	1 : 영상의 수
	channels : 채널의 수
	Mat() : 마스크(Mat()이므로 전체 영상지정 효과x)
	hist : 결과를 저장할 영상
	dims : 결과 영상의 차원수
	histSize : 구간수
	ranges : 값의 범위값

	=> image의 화소값 빈도수를 계산하여 hist에 담아준다.
	*/
	calcHist(&image, 1, channels, Mat(), hist, dims, histSize, ranges);
}

Mat query_img() {
	do {
		int q_no = 74;
		cout << "질의영상 번호를 입력하세요 : ";
		cin >> q_no; // 콘솔창 통한 입력

		String fname = format("DB/img_%02d.jpg", q_no);
		// 질의영상 읽기
		Mat query = imread(fname, IMREAD_COLOR);

		if (query.empty()) cout << "질의영상 번호가 잘못되었습니다." << endl;
		else return query; // 질의영상 반환
	} while (1); // 질의영상 없으면 계속반복
}

Mat calc_similarity(Mat query_hist, vector<Mat>& DB_hists) {
	Mat DB_similaritys;
	for (int i = 0; i < (int)DB_hists.size(); i++) {
		double compare = compareHist(query_hist, DB_hists[i], HISTCMP_CORREL);
		DB_similaritys.push_back(compare);
	}
	return DB_similaritys;
}


void select_view(double sinc, Mat DB_similaritys) {
	Mat m_idx, sorted_sim;
	// 행단위 + 내림차순
	int flag = SORT_EVERY_COLUMN + SORT_DESCENDING;
	cv::sort(DB_similaritys, sorted_sim, flag);
	sortIdx(DB_similaritys, m_idx, flag);

	for (int i = 0; i < sorted_sim.total(); i++) {
		double sim = sorted_sim.at<double>(i);
		if (sim > sinc) {
			int idx = m_idx.at<int>(i);
			String fname = format("DB/img_%02d.jpg", idx);
			Mat img = imread(fname, 1);

			String title = format("img_%03d - %5.2f", idx, sim);
			cout << title << endl;
			imshow(title, img);
		}
	}
}