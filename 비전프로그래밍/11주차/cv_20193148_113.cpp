#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

// 얼굴 추적에 필요한 캐스트캐이드 파일 로드
void load_cascade(CascadeClassifier& cascade, string fname);
// 명암도 영상 변환
Mat preprocessing(Mat image);
// 눈 포함 사각형 중심점 구하기
Point2d calc_center(Rect obj);
// 얼굴 탐색
void face_detect(Mat& frame);

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
		if (waitKey(10) >= 0) {
			break;
		}
	}
}

void face_detect(Mat& frame) {
	
	CascadeClassifier face_cascade, eyes_cascade;

	// 정면 얼굴 검출기
	load_cascade(face_cascade, "haarcascade_frontalface_alt2.xml");
	// 눈 검출기
	load_cascade(eyes_cascade, "haarcascade_eye.xml");

	Mat image = frame;
	// 전처리
	Mat gray = preprocessing(image);

	vector<Rect> faces, eyes;
	vector<Point2d> eyes_center;
	// 얼굴 검출
	face_cascade.detectMultiScale(gray, faces, 1.1, 2, 0, Size(100, 100));

	if (faces.size() > 0) {
		eyes_cascade.detectMultiScale(gray(faces[0]), eyes, 1.15, 7, 0, Size(25, 20));

		if (eyes.size() == 2) {
			for (size_t i = 0; i < eyes.size(); i++) {
				// 중심점 계산
				Point2d center = calc_center(eyes[i] + faces[0].tl());
				// 눈 중심에 원 그리기
				circle(image, center, 5, Scalar(0, 255, 0));
			}
		}
		// 얼굴 검출 사각형 그리기
		rectangle(image, faces[0], Scalar(255, 0, 0), 2);
		frame = image;
	}
}



Point2d calc_center(Rect obj) {
	Point2d c = (Point2d)obj.size() / 2.0;
	Point2d center = (Point2d)obj.tl() + c;
	return center;
}

void load_cascade(CascadeClassifier& cascade, string fname) {
	// 검출기 폴더
	String path = "C:/opencv/sources/data/haarcascades/";
	String full_name = path + fname;

	// 분류기 로드 및 예외처리
	CV_Assert(cascade.load(full_name));
}

Mat preprocessing(Mat image) {
	Mat gray;
	// 명암도 영상 변환
	cvtColor(image, gray, COLOR_BGR2GRAY);
	// 히스토그램 평활화
	equalizeHist(gray, gray);
	return gray;
}