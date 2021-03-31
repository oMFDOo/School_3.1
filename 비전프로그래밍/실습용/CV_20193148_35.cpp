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
//// **************** ���1 ****************
//float Inclination(Vec<Point, 2> p1) {
//	return fastAtan2(p1[1].y - p1[0].y, p1[1].x - p1[0].x);
//}
//
//// **************** ���2 ****************
//float Inclination(vector<Point> p) {
//	Point d = p.at(1) - p.at(0);
//	return fastAtan2(d.y, d.x);
//}
//
//int main() {
//	// 2���� Point ��ü(��������� ���� ����)�� ���Ϳ� ����
//	Point b1(X1, Y1), b2(X2, Y2);
//
//	Vec<Point, 2> point1(b1, b2);  // ��� 1
//	vector<Point> point = { b1, b2 }; // ��� 2
//
//	// ������ 2���� ������ �̷���� ������ ���⸦ ����϶�. (�� �� ��ǥ�� ���)
//	printf("��ǥ1 : (%d, %d) \t ��ǥ2: (%d, %d)\n", b1.x, b1.y, b2.x, b2.y);
//	printf("�� ���� ���� : %.1f\n\n", Inclination(point1));
//
//	printf("��ǥ1 : (%d, %d) \t ��ǥ2: (%d, %d)\n", point.at(0).x, point.at(0).y, point.at(1).x, point.at(1).y);
//	printf("�� ���� ���� : %.1f\n\n", Inclination(point));
//
//}