//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//void f21() {
//
//	// �� ������ ���ε��� �׸� ���� ��� 
//	Mat img = imread("color.jpg");  // color.jpg ���� �б�
//	Mat logo = imread("logo.jpg");  // logo.jpg ���� �б�
//
//
//	/*  copyTo()
//
//		<����>
//		���õ� ����� ������ ��ķ� �����Ѵ�.
//
//		<�Լ� ����>
//		void copyTo( OutputArray m ) const;
//
//		<�Ű� ����>
//		src		: �˻��� �̹���
//		dst		: �˻��� ��ȯ �����͸� ���� ����
//		code	: ��ȯ�� ���� �� ����
//		dstCn	: ����� ä�� ���� ä�� �� ����
//
//		<�ؼ�>
//		 : logo ����� img����� 30, 40�� ��ġ���� logo�̹��� ������ ��ŭ �ٿ��ִ´�.
//		  
//		 * ��������. ���� ���ص� ���纻�� ������ �ʴ´�.
//	*/
//	logo.copyTo(img(Rect(30, 40, logo.cols, logo.rows)));
//
//	imshow("frame1", img);  // img ��� �̹��� ���
//
//	/*  waitKey()
//
//		<����>
//		�Է� �ð� ��ŭ ��� ��, Ű �̺�Ʈ �߻� �� Ű�� ��ȯ.
//
//		<�Լ� ����>
//		int waitKey(int delay = 0);
//
//		<����>
//		 - delay <= 0 : Ű�̺�Ʈ �߻� �ñ��� ���
//		 - delay > 0  : �����ð� ���� Ű �Է� ���, �Է� ���� �� -1 ��ȯ
//
//	*/
//	waitKey(0);
//}
//
//void f22() {
//	// �� ������ ���ε��� �׸� ���� ��� 
//	Mat img = imread("color.jpg");  // color.jpg ���� �б�
//	Mat logo = imread("logo.jpg");  // logo.jpg ���� �б�
//
//	Mat mask;
//	/*  cvtColor()
//
//		<����>
//		�Է��� ����� ���� ���� ���� ���� ��ȯ �� ��ȯ
//
//		<�Լ� ����>
//		void cvtColor( InputArray src, OutputArray dst, int code, int dstCn = 0 );
//
//		<�Ű� ����>
//		src		: �˻��� �̹���
//		dst		: �˻��� ��ȯ �����͸� ���� ����
//		code	: ��ȯ�� ���� �� ���� 
//		dstCn	: ����� ä�� ���� ä�� �� ����
//
//		* COLOR_BGR2GRAY : BGR �̹����� ȸ���� �̹����� ����
//	*/
//	cvtColor(logo, mask, COLOR_BGR2GRAY);
//
//
//	/*  inRange()
//		
//		<����>
//		��� ���� ���� ��밪�� ������ �׿� ��ġ�Ѵٸ� 255, �׷��� �ʴٸ� 0���� ��ȯ�Ѵ�.
//
//		<�Լ� ����>
//		void inRange(InputArray src, InputArray lowerb, InputArray upperb, OutputArray dst);
//
//		<�Ű� ����>
//		src		: �˻��� �̹���
//		lowerb	: �ּ� ��밪
//		upperb	: �ִ� ��밪
//		dst		: �˻��� ��ȯ �����͸� ���� ����
//
//		<��ȯ>
//		 - 255(���) ��ȯ	: ȭ�� ���� �ּ� ��밪�� �ִ� ��밪�� ������ ���
//		 - 0(���) ��ȯ		: ȭ�� ���� �ּ� ��밪�� �ִ� ��밪�� �ܺ��� ���
//	*/
//	inRange(mask, 10, 255, mask);
//	imshow("mask", mask);  // mask ��� �̹��� ���
//
//
//	// img����� 30, 40�� ��ġ���� logo��� ũ�⸸ŭ�� ����� ���� ����� framROI�� ����.
//	Mat frameROI = img(Rect(30, 40, logo.cols, logo.rows));
//	imshow("ROI", frameROI);  // frameROI ��� �̹��� ���
//
//	/*  copyTo()
//
//		<����>
//		m��ķ� mask���� ������ ����� �ٿ��ִ´�.
//
//		<�Լ� ����>
//		void Mat::copyTo(OutputArray m, InputArray mask) const;
//
//		<�Ű� ����>
//		mask	: ����ũ ���
//		m		: �˻��� ��ȯ �����͸� ���� ����
//
//		<����ũ ���>
//		 - ���Ұ��� 0�� �ƴ� ��ǥ������ ��� ���Ҹ� �����Ѵ�. 
//		 - *this ũ��� ���ƾ��ϰ�, ���̴� CV_8U���� �Ѵ�.
//
//		 * mask�̹����� �ΰ� ������ ���� ��� 0(����)��.
//		 * logo�� ����ũ�� ���� ����� ����� ������ �ΰ��̹���
//		 => frameROI �̹����� ����� ���� �ΰ� �̹����� �ٿ��־�����.
//	*/
//	logo.copyTo(frameROI, mask);
//
//	imshow("frame2", img);  // mask ��� �̹��� ���
//
//	waitKey(0); // �̺�Ʈ�� �߻��� ������ ���
//}
//
//int main() {
//	f21();
//	f22();
//	return 0;
//}
//
