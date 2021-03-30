//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <math.h>
//
//using namespace cv;
//using namespace std;
//
//#define SIZE_ROW 20
//#define SIZE_COL 20
//
//// 두 점(원소)의 좌표(인덱스)를 받고 거리 계산하여 반환
//double D(int x1, int y1, int x2, int y2) {
//	int dx = abs(x1 - x2);
//	int dy = abs(y1 - y2);
//
//	return sqrt(dx * dx + dy * dy);
//}
//
//int main() {
//	Mat_<int> mat(SIZE_ROW, SIZE_COL, 0);
//
//	for (int i = 0; i < SIZE_COL; i++)
//		for (int j = 0; j < SIZE_ROW; j++) {
//			// D 함수를 호출하여 두 점의 거리값을 받음
//			double d = D(j, i, 9, 9);
//
//			if (d < 5 && d > 3) {
//				mat(i, j) = 1;
//			}
//		}
//
//	cout << mat << endl;
//}