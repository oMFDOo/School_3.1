//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <math.h>
//
//using namespace cv;
//using namespace std;
//
//#define startX 200
//#define startY 100
//#define width 100
//#define height 200
//#define endX startX + width
//#define endY startY + height
//
//int main() {
//    Mat frame;
//
//    // ���� ��ü ����
//    VideoCapture capture(0); 
//
//    // ī�޶� ���� �˻�
//    //CV_Assert(capture.isOpened());
//    if (!capture.isOpened()) {
//        cout << "ī�޶� ������� �ʾҽ��ϴ�." << endl;
//        return 0;
//    }
//
//    //capture���� �������� �о�ٸ� ���� ����
//    //capture >> frame;
//    while (capture.read(frame)) {
//
//        // �׵θ� �Է�
//        rectangle(frame, Rect(startX, startY, width, height), Scalar(0, 0, 255), 3, LINE_8, 0);
//
//        // ���� ����
//        for (int i = startY; i < endY; i++) {
//            for (int j = startX; j < endX; j++) {
//                frame.at<Vec3b>(i, j)[1] += 50;
//            }
//        }
//
//        // ����ϱ�
//        imshow("20193148_Ȳ����", frame);
//
//        // 30ms ���, esc Ű�� �߻� �� ����
//        if (waitKey(30) >= 27) { 
//            break; 
//        }
//    }
//
//    return 0;
//}