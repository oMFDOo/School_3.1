#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void calc_h(Mat src, Mat &dst, int term);
void draw_h(Mat src, Mat &h_img);


#define width 10

int main() {
	// 0~100 정수 저장
	int data[] = { 11, 12, 23, 24, 25, 25,
		33, 34, 35, 37, 38, 41,
		42, 42, 42, 44, 43, 44,
		55, 56, 57, 64, 65, 66,
		77, 78, 82, 84, 87, 98 };

	Mat image(5, 6, CV_32S, data);

	Mat h, h_img;
	calc_h(image, h, 10);	// 작성 요	
	cout << h.t() << endl;	// 출력 [0, 2, 4, 5, 7, 3, 3, 2, 3, 1]

	draw_h(h, h_img);	// 작성 요
	//flip(h_img, h_img, 0);
	imshow("히스토그램", h_img);

	waitKey();
	return 0;

}

void calc_h(Mat src, Mat &dst, int term) {
	int* data = new int[term] {0};
	Mat temp(term, 1, CV_32S, data);

	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			int index = src.at<int>(i,j) / term;
			temp.at<int>(index, 0) += 1;
		}
	}

	temp.copyTo(dst);
	delete[] data;
}

void draw_h(Mat src, Mat &h_img) {
	h_img.create(Size(100, 200), CV_8U);
	h_img = Scalar(255, 255, 255);

	for (int i = 0; i < src.rows; i++) {
		int heightHist = src.at<int>(i,0) * 10;
		rectangle(h_img, Rect(i * 10, 0, width, heightHist), Scalar(0, 0, 0), 2, LINE_8, 0);
	}
}