//#include <opencv2/opencv.hpp>
//using namespace cv;
//using namespace std;
//
//#pragma region preprocess.hpp
////#include "preprocess.hpp"						// 검출기로드 및 전처리 함수
//void load_cascade(CascadeClassifier& cascade, string fname)
//{
//	String  path = "C:/opencv/sources/data/haarcascades/";	// 검출기 폴더
//	String  full_name = path + fname;
//
//	CV_Assert(cascade.load(full_name));					// 분류기 로드 및 예외처리
//}
//
//Mat preprocessing(Mat image)
//{
//	Mat gray;
//	cvtColor(image, gray, COLOR_RGB2GRAY);	// 명암도 영상변환
//	equalizeHist(gray, gray);					// 히스토그램 평활화
//	return gray;
//}
//#pragma endregion
//#pragma region correct_angle.hpp
////#include "correct_angle.hpp"					// 기울기 보정 함수들
//Point2f calc_center(Rect obj)
//{
//	Point2f c = (Point2f)obj.size() / 2.0;
//	Point2f center = (Point2f)obj.tl() + c;
//	return center;
//}
//
//Mat  calc_rotMap(Point2d face_center, vector<Point2f>  pt)
//{
//	Point2f delta = (pt[0].x > pt[1].x) ? pt[0] - pt[1] : pt[1] - pt[0];
//	float  angle = fastAtan2(delta.y, delta.x);
//	Mat  rot_mat = getRotationMatrix2D(face_center, angle, 1);
//	return rot_mat;
//}
//
//Mat correct_image(Mat image, Mat  rot_mat, vector<Point2f>& eyes_center)
//{
//	Mat  correct_img;
//	warpAffine(image, correct_img, rot_mat, image.size(), INTER_CUBIC);
//
//	for (int i = 0; i < eyes_center.size(); i++)	// 눈 좌표 회전변환
//	{
//		Point3d coord(eyes_center[i].x, eyes_center[i].y, 1);
//		Mat dst = rot_mat * (Mat)coord;
//		eyes_center[i] = (Point2f)dst;
//	}
//	return correct_img;
//}
//#pragma endregion
//#pragma region detect_area.hpp
////#include "detect_area.hpp"						// 입술 및 머리영역 검출 함수
//Rect detect_lip(Point2d face_center, Rect face) {
//
//	Point2d lip_center = face_center + Point2d(0, face.height * 0.30);
//	Point2d gap_size(face.width * 0.18, face.height * 0.1);
//
//	Point  lip_start = lip_center - gap_size;
//	Point  lip_end = lip_center + gap_size;
//
//	return Rect(lip_start, lip_end);
//}
//
//void  detect_hair(Point2d face_center, Rect face, vector<Rect>& hair_rect)
//{
//	Point2d  h_gap(face.width * 0.45, face.height * 0.65);	// 평행이동 거리
//	Point2d  pt1 = face_center - h_gap;				// 왼쪽 상단 평행이동
//	Point2d  pt2 = face_center + h_gap;				// 오른쪽 하단 평행이동
//	Rect   hair(pt1, pt2);				// 전체 머리영역
//
//	Size  size(hair.width, hair.height * 0.41);	// 윗머리 및 귀밑머리 크기
//	Rect  hair1(hair.tl(), size);					// 윗머리 영역
//	Rect  hair2(hair.br() - (Point)size, size);	// 귀밑머리 영역
//
//	hair_rect.push_back(hair1);		// Rect형 벡터에 저장
//	hair_rect.push_back(hair2);
//	hair_rect.push_back(hair);		// 전체머리영역을 마지막에 저장
//}
//#pragma endregion
//#pragma region histo.hpp
////#include "histo.hpp"							// 히스토그램 비교 관련 함수
//void calc_histo(const Mat& img, Mat& hist, Vec3i bins, Vec3f range, Mat mask, int _dims = 3)
//{
//	int 	dims = (_dims <= 0) ? img.channels() : _dims;
//	int		channels[] = { 0, 1, 2 };
//	int		histSize[] = { bins[0], bins[1], bins[2] };
//
//	float  range1[] = { 0, range[0] };
//	float  range2[] = { 0, range[1] };
//	float  range3[] = { 0, range[2] };
//	const float* ranges[] = { range1, range2, range3 };			// 모든 채널 화소범위
//
//	calcHist(&img, 1, channels, mask, hist, dims, histSize, ranges);
//}
//
//void draw_ellipse(Mat& image, Rect2d obj, Scalar color, int thickness, double ratio)
//{
//	Point2d center = obj.tl() + (Point2d)obj.size() * 0.5; // 검출영역 중심좌표
//	Size2d size = (Size2d)obj.size() * ratio;					// 타원 크기
//	ellipse(image, center, size, 0, 0, 360, color, thickness);
//}
//
//void make_masks(vector<Rect> sub_obj, Size org_size, Mat mask[4])
//{
//	Mat base_mask(org_size, CV_8U, Scalar(0));
//	draw_ellipse(base_mask, sub_obj[2], Scalar(255), -1, 0.45f);
//	mask[0] = ~base_mask(sub_obj[0]);				// 윗머리 마스크
//	mask[1] = ~base_mask(sub_obj[1]);				// 귀밑머리 마스크
//
//	draw_ellipse(base_mask, sub_obj[3], Scalar(0), -1, 0.45f);
//	mask[3] = ~base_mask(sub_obj[3]);				// 입술 마스크
//	mask[2] = base_mask(sub_obj[2]);				// 얼굴 마스크
//}
//
//void calc_histos(Mat  correct_img, vector<Rect> sub_obj, Mat hists[4], Mat masks[4])
//{
//	Vec3i bins(64, 64, 64);
//	Vec3f ranges(256, 256, 256);
//
//	for (int i = 0; i < (int)sub_obj.size(); i++)
//	{
//		Mat sub = correct_img(sub_obj[i]);
//		calc_histo(sub, hists[i], bins, ranges, masks[i]);
//		//		imshow(format("mask[%d]",i), masks[i]);
//		//		waitKey();
//	}
//}
//#pragma endregion
//#pragma region classify.hpp
////#include "classify.hpp"							// 히스토그램 비교 관련 함수
//void classify(Mat& image, Mat hists[4], int no)
//{
//	double criteria1 = compareHist(hists[0], hists[1], HISTCMP_CORREL);
//	double criteria2 = compareHist(hists[2], hists[3], HISTCMP_CORREL);
//
//	double tmp = (criteria1 > 0.2) ? 0.2 : 0.4;
//	int value = (criteria2 > tmp) ? 0 : 1;
//
//	string text = (value) ? "Man" : "Woman";
//	text = format("%02d.jpg: ", no) + text;
//
//	int font = FONT_HERSHEY_TRIPLEX;
//	putText(image, text, Point(12, 31), font, 0.7, Scalar(0, 0, 0), 2);
//	putText(image, text, Point(10, 30), font, 0.7, Scalar(0, 255, 0), 1);
//
//	cout << text << format(" - 유사도 [머리: %4.2f  입술: %4.2f]\n", criteria1, criteria2);
//}
//
//void display(Mat& image, Point2d face_center, vector<Point2f> eyes_center, vector<Rect> sub)
//{
//
//	circle(image, eyes_center[0], 10, Scalar(0, 255, 0), 2);			// 눈 표시
//	circle(image, eyes_center[1], 10, Scalar(0, 255, 0), 2);
//	circle(image, face_center, 3, Scalar(0, 0, 255), 2);			// 얼굴 중심점 표시
//
//	draw_ellipse(image, sub[2], Scalar(255, 100, 0), 2, 0.45f);	// 입술 타원	
//	draw_ellipse(image, sub[3], Scalar(0, 0, 255), 2, 0.45f);	// 얼굴 타원	
//}
//#pragma endregion
//#pragma region key_check()
//bool key_check(int& no)
//{
//	int key = waitKeyEx(0);
//	if (key == 2621440) no++;
//	else if (key == 2490368) no--;
//	else if (key == 32 || key == 27) return false;
//
//	return true;
//}
//#pragma endregion
//
//int main()
//{
//	CascadeClassifier face_cascade, eyes_cascade;
//	load_cascade(face_cascade, "haarcascade_frontalface_alt2.xml");
//	load_cascade(eyes_cascade, "haarcascade_eye.xml");
//
//	int no = 60;
//	do {
//		String fname = format("./face/%02d.jpg", no);
//		Mat  image = imread(fname, IMREAD_COLOR);
//		if (image.empty()) {
//			cout << format("%02d영상이 없습니다.\n", no++);
//			continue;
//		}
//
//		vector<Rect> faces, eyes, sub_obj;
//		vector<Point2f> eyes_center;
//
//		Mat  gray = preprocessing(image);
//		face_cascade.detectMultiScale(gray, faces, 1.10, 3, 0, Size(100, 100));
//
//		if (faces.size() > 0)
//		{
//			eyes_cascade.detectMultiScale(gray(faces[0]), eyes, 1.15, 7, 0, Size(25, 20));
//
//			if (eyes.size() == 2) {
//				eyes_center.push_back(calc_center(eyes[0] + faces[0].tl()));
//				eyes_center.push_back(calc_center(eyes[1] + faces[0].tl()));
//
//				Point2d face_center = calc_center(faces[0]);
//				Mat  rot_mat = calc_rotMap(face_center, eyes_center);
//				Mat  correct_img = correct_image(image, rot_mat, eyes_center);
//
//				detect_hair(face_center, faces[0], sub_obj);
//				sub_obj.push_back(detect_lip(face_center, faces[0]));
//
//				Mat masks[4], hists[4];
//				make_masks(sub_obj, correct_img.size(), masks);		// 4개 마스크 생성
//				calc_histos(correct_img, sub_obj, hists, masks);	// 4개 히스토그램 생성
//
//				classify(correct_img, hists, no);
//				display(correct_img, face_center, eyes_center, sub_obj);
//				imshow("correct_img", correct_img);
//			}
//		}
//	} while (key_check(no));
//}