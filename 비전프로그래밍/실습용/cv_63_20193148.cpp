#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img_color;	// 영상 저장 전역변수

void report(int event, int x, int y, int flags, void* userdata) {
	// 마우스 드래그 중에는 1 값을 왼쪽 버튼 띠면 0 값을 저장
	static int drag = 0;

	// 마우스 왼쪽 버튼 누른 위치의 좌표를 저장
	static int start_x = -1, start_y = -1;

	// main 에서 read 한 영상을 복사
	Mat img_result = img_color.clone();

	if (event == EVENT_LBUTTONDOWN) {
		// 마우스 왼쪽 버튼 누른 경우
		start_x = x; start_y = y;
		drag = true;
		
		// 기존 그려진 윈도우 파괴
		destroyWindow("img_gray");
	}
	else if (event == EVENT_MOUSEMOVE) {
		// 마우스 드래그 하는 경우
		if (drag) {
			// 드래그 시 잔상 제거
			Mat img_drag(img_color, Rect(Point(start_x, start_y), Point(x, y)));

			// 테두리 그리기
			rectangle(img_result, Point(start_x, start_y), Point(x, y), Scalar(0, 0, 255), 3, LINE_8, 0);
			imshow("img_color", img_result);
		}
	}
	else if (event == EVENT_LBUTTONUP) {
		// 마우스 왼쪽 버튼 띤 경우
		drag = false;
		rectangle(img_result, Point(start_x, start_y), Point(x, y), Scalar(0, 0, 255), 3, LINE_8, 0);
		imshow("img_color", img_result);

		// 색상변환 및 출력
		Mat img_gray(img_color, Rect(Point(start_x, start_y), Point(x, y)));
		cvtColor(img_gray, img_gray, COLOR_BGR2GRAY);
		imshow("img_gray", img_gray);
	}
}

int main() {
	// imread("aa.jpg"); -> “ ” 안의 파일을 read 하여 img_color 객체에 저장 
	// 파일 이름은 여러분 찾은 파일 이름에 따라서 수정 필요
	// Mat img_color; 는 윗 부분에 전역 변수로 선언
	img_color = imread("color.jpg");

	imshow("img_color", img_color);

	setMouseCallback("img_color", report);

	waitKey(0);
	destroyAllWindows();
	return 0;
}