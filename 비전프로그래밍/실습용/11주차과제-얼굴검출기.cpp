// cv_20193148_113.cpp

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void load_cascade(CascadeClassifier& cascade, string fname);
Mat preprocessing(Mat image);

// ��, �� ã�� ���� �簢��, �� ǥ�� : ���ǿ��� main���� ������
void face_detect(Mat& frame);


// �� ���� �簢�� �߽��� ���ϱ�
Point2d calc_center(Rect obj) {
	Point2d c = (Point2d)obj.size() / 2.0;
	Point2d center = (Point2d)obj.tl() + c;
	return center;
}

int main() {
	VideoCapture capture(0); // videoCapture ��ü ���� �� ī�޶� ����

	if (!capture.isOpened()) {
		cout << "ī�޶� ������� �ʾҽ��ϴ�." << endl;
		exit(1);
	}

	while (20193148) {
		Mat frame;
		capture.read(frame); // ī�޶󿡼� �� ���� ������ ����
		
		face_detect(frame); // ��, �� ã�� ���� �簢��, �� ǥ��

		imshow("20193148 Ȳ���� ���ν�", frame);

		// 100ms ���, esc Ű �̺�Ʈ �߻� �� ����
		if (waitKey(100) >= 0) {
			break;
		}
	}
}
