//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//#define X1 0
//#define Y1 0
//#define X2 6
//#define Y2 6
//
//// **************** 방법1 ****************
//float Inclination(Vec<Point, 2> p1) {
//	return fastAtan2(p1[1].y - p1[0].y, p1[1].x - p1[0].x);
//}
//
//// **************** 방법2 ****************
//float Inclination(vector<Point> p) {
//	Point d = p.at(1) - p.at(0);
//	return fastAtan2(d.y, d.x);
//}
//
//int main() {
//	// 2개의 Point 객체(멤버변수값 임의 지정)를 벡터에 저장
//	Point b1(X1, Y1), b2(X2, Y2);
//
//	Vec<Point, 2> point1(b1, b2);  // 방법 1
//	vector<Point> point = { b1, b2 }; // 방법 2
//
//	// 저장한 2개의 점으로 이루어진 직선의 기울기를 출력하라. (두 점 좌표도 출력)
//	printf("좌표1 : (%d, %d) \t 좌표2: (%d, %d)\n", b1.x, b1.y, b2.x, b2.y);
//	printf("두 점의 기울기 : %.1f\n\n", Inclination(point1));
//
//	printf("좌표1 : (%d, %d) \t 좌표2: (%d, %d)\n", point.at(0).x, point.at(0).y, point.at(1).x, point.at(1).y);
//	printf("두 점의 기울기 : %.1f\n\n", Inclination(point));
//
//}