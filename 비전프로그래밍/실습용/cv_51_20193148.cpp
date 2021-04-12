//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//void f21() {
//
//	// 두 영상은 업로드한 그림 파일 사용 
//	Mat img = imread("color.jpg");  // color.jpg 파일 읽기
//	Mat logo = imread("logo.jpg");  // logo.jpg 파일 읽기
//
//
//	/*  copyTo()
//
//		<목적>
//		선택된 행렬을 목적지 행렬로 복사한다.
//
//		<함수 원형>
//		void copyTo( OutputArray m ) const;
//
//		<매개 변수>
//		src		: 검사할 이미지
//		dst		: 검사후 변환 데이터를 받을 공간
//		code	: 변환할 색상 값 정의
//		dstCn	: 출력할 채널 색상 채널 수 설정
//
//		<해석>
//		 : logo 행렬을 img행렬의 30, 40의 위치에서 logo이미지 사이즈 만큼 붙여넣는다.
//		  
//		 * 깊은복사. 원본 변해도 복사본도 변하지 않는다.
//	*/
//	logo.copyTo(img(Rect(30, 40, logo.cols, logo.rows)));
//
//	imshow("frame1", img);  // img 행렬 이미지 출력
//
//	/*  waitKey()
//
//		<목적>
//		입력 시간 만큼 대기 후, 키 이벤트 발생 시 키값 반환.
//
//		<함수 원형>
//		int waitKey(int delay = 0);
//
//		<동작>
//		 - delay <= 0 : 키이벤트 발생 시까지 대기
//		 - delay > 0  : 지연시간 동안 키 입력 대기, 입력 없을 시 -1 반환
//
//	*/
//	waitKey(0);
//}
//
//void f22() {
//	// 두 영상은 업로드한 그림 파일 사용 
//	Mat img = imread("color.jpg");  // color.jpg 파일 읽기
//	Mat logo = imread("logo.jpg");  // logo.jpg 파일 읽기
//
//	Mat mask;
//	/*  cvtColor()
//
//		<목적>
//		입력한 행렬을 설정 값에 따라 색상 변환 후 반환
//
//		<함수 원형>
//		void cvtColor( InputArray src, OutputArray dst, int code, int dstCn = 0 );
//
//		<매개 변수>
//		src		: 검사할 이미지
//		dst		: 검사후 변환 데이터를 받을 공간
//		code	: 변환할 색상 값 정의 
//		dstCn	: 출력할 채널 색상 채널 수 설정
//
//		* COLOR_BGR2GRAY : BGR 이미지를 회색조 이미지로 변경
//	*/
//	cvtColor(logo, mask, COLOR_BGR2GRAY);
//
//
//	/*  inRange()
//		
//		<목적>
//		행렬 값이 조건 허용값을 설정에 그에 일치한다면 255, 그렇지 않다면 0으로 변환한다.
//
//		<함수 원형>
//		void inRange(InputArray src, InputArray lowerb, InputArray upperb, OutputArray dst);
//
//		<매개 변수>
//		src		: 검사할 이미지
//		lowerb	: 최소 허용값
//		upperb	: 최대 허용값
//		dst		: 검사후 변환 데이터를 받을 공간
//
//		<변환>
//		 - 255(백색) 변환	: 화소 값이 최소 허용값과 최대 허용값의 사이인 경우
//		 - 0(흑색) 변환		: 화소 값이 최소 허용값과 최대 허용값의 외부인 경우
//	*/
//	inRange(mask, 10, 255, mask);
//	imshow("mask", mask);  // mask 행렬 이미지 출력
//
//
//	// img행렬을 30, 40의 위치에서 logo행렬 크기만큼의 사이즈를 가진 행렬을 framROI에 대입.
//	Mat frameROI = img(Rect(30, 40, logo.cols, logo.rows));
//	imshow("ROI", frameROI);  // frameROI 행렬 이미지 출력
//
//	/*  copyTo()
//
//		<목적>
//		m행렬로 mask값을 적용한 행렬을 붙여넣는다.
//
//		<함수 원형>
//		void Mat::copyTo(OutputArray m, InputArray mask) const;
//
//		<매개 변수>
//		mask	: 마스크 행렬
//		m		: 검사후 변환 데이터를 받을 공간
//
//		<마스크 행렬>
//		 - 원소값이 0이 아닌 좌표에서만 행렬 원소를 복사한다. 
//		 - *this 크기와 같아야하고, 깊이는 CV_8U여야 한다.
//
//		 * mask이미지는 로고를 제외한 값은 모두 0(검정)임.
//		 * logo에 마스크를 씌운 결과는 배경을 제외한 로고이미지
//		 => frameROI 이미지에 배경이 없는 로고 이미지가 붙여넣어진다.
//	*/
//	logo.copyTo(frameROI, mask);
//
//	imshow("frame2", img);  // mask 행렬 이미지 출력
//
//	waitKey(0); // 이벤트가 발생할 때까지 대기
//}
//
//int main() {
//	f21();
//	f22();
//	return 0;
//}
//
