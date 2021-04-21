//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <math.h>
//
//using namespace cv;
//using namespace std;
//
//#define x1 0
//#define y1 0
//#define x2 6
//#define y2 6
//
//// **************** ���1 ****************
//float inclination(Vec<Point, 2> p1) {
//	return fastAtan2(p1[1].y - p1[0].y, p1[1].x - p1[0].x);
//}
//
//// **************** ���2 ****************
//float inclination(vector<Point> p) {
//	Point d = p.at(1) - p.at(0);
//	return fastAtan2(d.y, d.x);
//}
//
//int main() {
//	// 2���� point ��ü(��������� ���� ����)�� ���Ϳ� ����
//	Point b1(x1, y1), b2(x2, y2);
//
//	Vec<Point, 2> point1(b1, b2);  // ��� 1
//	vector<Point> point = { b1, b2 }; // ��� 2
//
//	// ������ 2���� ������ �̷���� ������ ���⸦ ����϶�. (�� �� ��ǥ�� ���)
//	printf("��ǥ1 : (%d, %d) \t ��ǥ2: (%d, %d)\n", b1.x, b1.y, b2.x, b2.y);
//	printf("�� ���� ���� : %.1f\n\n", inclination(point1));
//
//	printf("��ǥ1 : (%d, %d) \t ��ǥ2: (%d, %d)\n", point.at(0).x, point.at(0).y, point.at(1).x, point.at(1).y);
//	printf("�� ���� ���� : %.1f\n\n", inclination(point));
//
//}