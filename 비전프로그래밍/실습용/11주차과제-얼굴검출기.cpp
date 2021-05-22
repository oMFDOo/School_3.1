//// cv_20193148_113.cpp
//
//#include <opencv2/opencv.hpp>
//using namespace cv;
//using namespace std;
//
//// �� ������ �ʿ��� ĳ��Ʈĳ�̵� ���� �ε�
//void load_cascade(CascadeClassifier& cascade, string fname);
//// ��ϵ� ���� ��ȯ
//Mat preprocessing(Mat image);
//// �� ���� �簢�� �߽��� ���ϱ�
//Point2d calc_center(Rect obj);
//// �� Ž��
//void face_detect(Mat& frame);
//
//int main() {
//	VideoCapture capture(0); // videoCapture ��ü ���� �� ī�޶� ����
//
//	if (!capture.isOpened()) {
//		cout << "ī�޶� ������� �ʾҽ��ϴ�." << endl;
//		exit(1);
//	}
//
//	while (20193148) {
//		Mat frame;
//		capture.read(frame); // ī�޶󿡼� �� ���� ������ ����
//		
//		face_detect(frame); // ��, �� ã�� ���� �簢��, �� ǥ��
//
//		imshow("20193148 Ȳ���� ���ν�", frame);
//
//		// 100ms ���, esc Ű �̺�Ʈ �߻� �� ����
//		if (waitKey(10) >= 0) {
//			break;
//		}
//	}
//}
//
//void face_detect(Mat& frame) {
//	
//	CascadeClassifier face_cascade, eyes_cascade;
//
//	// ���� �� �����
//	load_cascade(face_cascade, "haarcascade_frontalface_alt2.xml");
//	// �� �����
//	load_cascade(eyes_cascade, "haarcascade_eye.xml");
//
//	Mat image = frame;
//	// ��ó��
//	Mat gray = preprocessing(image);
//
//	vector<Rect> faces, eyes;
//	vector<Point2d> eyes_center;
//	// �� ����
//	face_cascade.detectMultiScale(gray, faces, 1.1, 2, 0, Size(100, 100));
//
//	if (faces.size() > 0) {
//		eyes_cascade.detectMultiScale(gray(faces[0]), eyes, 1.15, 7, 0, Size(25, 20));
//
//		if (eyes.size() == 2) {
//			for (size_t i = 0; i < eyes.size(); i++) {
//				// �߽��� ���
//				Point2d center = calc_center(eyes[i] + faces[0].tl());
//				// �� �߽ɿ� �� �׸���
//				circle(image, center, 5, Scalar(0, 255, 0));
//			}
//		}
//		// �� ���� �簢�� �׸���
//		rectangle(image, faces[0], Scalar(255, 0, 0), 2);
//		frame = image;
//	}
//}
//
//
//
//Point2d calc_center(Rect obj) {
//	Point2d c = (Point2d)obj.size() / 2.0;
//	Point2d center = (Point2d)obj.tl() + c;
//	return center;
//}
//
//void load_cascade(CascadeClassifier& cascade, string fname) {
//	// ����� ����
//	String path = "C:/opencv/sources/data/haarcascades/";
//	String full_name = path + fname;
//
//	// �з��� �ε� �� ����ó��
//	CV_Assert(cascade.load(full_name));
//}
//
//Mat preprocessing(Mat image) {
//	Mat gray;
//	// ��ϵ� ���� ��ȯ
//	cvtColor(image, gray, COLOR_BGR2GRAY);
//	// ������׷� ��Ȱȭ
//	equalizeHist(gray, gray);
//	return gray;
//}