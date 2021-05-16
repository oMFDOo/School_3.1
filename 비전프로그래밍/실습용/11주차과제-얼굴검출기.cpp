// cv_20193148_113.cpp

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void load_cascade(CascadeClassifier& cascade, string fname);
Mat preprocessing(Mat image);

// 얼굴, 눈 찾고 각각 사각형, 원 표시 : 강의에서 main으로 쓰던거
void face_detect(Mat& frame);


// 눈 포함 사각형 중심점 구하기
Point2d calc_center(Rect obj) {
	Point2d c = (Point2d)obj.size() / 2.0;
	Point2d center = (Point2d)obj.tl() + c;
	return center;
}

int main() {
	VideoCapture capture(0); // videoCapture 객체 생성 및 카메라 연결

	if (!capture.isOpened()) {
		cout << "카메라가 연결되지 않았습니다." << endl;
		exit(1);
	}

	while (20193148) {
		Mat frame;
		capture.read(frame); // 카메라에서 한 영상 가져와 저장
		
		face_detect(frame); // 얼굴, 눈 찾고 각각 사각형, 원 표시

		imshow("20193148 황진주 얼굴인식", frame);

		// 100ms 대기, esc 키 이벤트 발생 시 종료
		if (waitKey(100) >= 0) {
			break;
		}
	}
}
