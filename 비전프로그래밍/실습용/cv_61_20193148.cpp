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
//    // 비디오 객체 생성
//    VideoCapture capture(0); 
//
//    // 카메라 연결 검사
//    //CV_Assert(capture.isOpened());
//    if (!capture.isOpened()) {
//        cout << "카메라가 연결되지 않았습니다." << endl;
//        return 0;
//    }
//
//    //capture에서 프레임을 읽어낸다면 실행 유지
//    //capture >> frame;
//    while (capture.read(frame)) {
//
//        // 테두리 입력
//        rectangle(frame, Rect(startX, startY, width, height), Scalar(0, 0, 255), 3, LINE_8, 0);
//
//        // 색상 변경
//        for (int i = startY; i < endY; i++) {
//            for (int j = startX; j < endX; j++) {
//                frame.at<Vec3b>(i, j)[1] += 50;
//            }
//        }
//
//        // 출력하기
//        imshow("20193148_황진주", frame);
//
//        // 30ms 대기, esc 키값 발생 시 종료
//        if (waitKey(30) >= 27) { 
//            break; 
//        }
//    }
//
//    return 0;
//}