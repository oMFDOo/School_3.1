//#include <opencv2/opencv.hpp>
//#include <iostream>
//using namespace cv;
//using namespace std;
//
//void calc_h(Mat& image, Mat& h, int n) {
//    Mat m = Mat::zeros(10, 1, CV_32S);
//    int idx;
//    for (int i = 0; i < image.rows; i++) {
//        for (int j = 0; j < image.cols; j++) {
//            idx = image.at<int>(i, j) / 10;
//            m.at<int>(idx, 0) += 1;
//        }
//    }
//    h = m;
//}
//
//void draw_h(Mat& h, Mat& h_img) {
//    h = h.t();
//
//    h_img = Mat(200, 100, CV_8U, Scalar(255));
//    float bin = (float)h.cols / h.rows;
//    //normalize(h, h, 0, h_img.rows, NORM_MINMAX);
//
//    for (int i = 0; i < h.cols; i++) {
//        float x1 = i * bin;
//        float x2 = (i + 1) * bin;
//        Point2f pt1(x1, 0);
//        Point2f pt2(x2, h.at<int>(0, i) * 10);
//
//        if (pt2.y > 0) {
//            rectangle(h_img, pt1, pt2, Scalar(0), 3); // 막대 사각형 그리기
//        }
//    }
//}
//
//int main() {
//    // 0~100 정수 저장
//    int data[] = { 11, 12, 23, 24, 25, 25,
//       33, 34, 35, 37, 38, 41,
//       42, 42, 42, 44, 43, 44,
//       55, 56, 57, 64, 65, 66,
//       77, 78, 82, 84, 87, 98 };
//
//    Mat image(5, 6, CV_32S, data);
//
//    Mat h, h_img;
//    calc_h(image, h, 10);   // 작성 요, 10 은 구간 10을 의미   
//    cout << h.t() << endl;   // 출력 [0, 2, 4, 5, 7, 3, 3, 2, 3, 1]
//
//    draw_h(h, h_img);
//    imshow("히스토그램", h_img);
//
//    waitKey();
//    return 0;
//}