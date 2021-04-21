#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img_color;	// ���� ���� ��������

void report(int event, int x, int y, int flags, void* userdata) {
	// ���콺 �巡�� �߿��� 1 ���� ���� ��ư ��� 0 ���� ����
	static int drag = 0;

	// ���콺 ���� ��ư ���� ��ġ�� ��ǥ�� ����
	static int start_x = -1, start_y = -1;

	// main ���� read �� ������ ����
	Mat img_result = img_color.clone();

	if (event == EVENT_LBUTTONDOWN) {
		// ���콺 ���� ��ư ���� ���
		start_x = x; start_y = y;
		drag = true;
		
		// ���� �׷��� ������ �ı�
		destroyWindow("img_gray");
	}
	else if (event == EVENT_MOUSEMOVE) {
		// ���콺 �巡�� �ϴ� ���
		if (drag) {
			// �巡�� �� �ܻ� ����
			Mat img_drag(img_color, Rect(Point(start_x, start_y), Point(x, y)));

			// �׵θ� �׸���
			rectangle(img_result, Point(start_x, start_y), Point(x, y), Scalar(0, 0, 255), 3, LINE_8, 0);
			imshow("img_color", img_result);
		}
	}
	else if (event == EVENT_LBUTTONUP) {
		// ���콺 ���� ��ư �� ���
		drag = false;
		rectangle(img_result, Point(start_x, start_y), Point(x, y), Scalar(0, 0, 255), 3, LINE_8, 0);
		imshow("img_color", img_result);

		// ����ȯ �� ���
		Mat img_gray(img_color, Rect(Point(start_x, start_y), Point(x, y)));
		cvtColor(img_gray, img_gray, COLOR_BGR2GRAY);
		imshow("img_gray", img_gray);
	}
}

int main() {
	// imread("aa.jpg"); -> �� �� ���� ������ read �Ͽ� img_color ��ü�� ���� 
	// ���� �̸��� ������ ã�� ���� �̸��� ���� ���� �ʿ�
	// Mat img_color; �� �� �κп� ���� ������ ����
	img_color = imread("color.jpg");

	imshow("img_color", img_color);

	setMouseCallback("img_color", report);

	waitKey(0);
	destroyAllWindows();
	return 0;
}