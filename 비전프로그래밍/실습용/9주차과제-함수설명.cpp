//#include <opencv2/opencv.hpp>
//using namespace cv;
//using namespace std;
//
//
//// �Ű����� : ����� ����, �󵵼��� ���� ����, ������, ���� �ִ� ��밪
//void  calc_Histo(const Mat& image, Mat& hist, int bins, int range_max = 256) {
//	// ������ ����
//	int		histSize[] = { bins };
//	// ���� ���� ����
//	float   range[] = { 0, (float)range_max };
//	// ä�� �� ��ŭ ����
//	int		channels[] = { 0 };
//	// ������ ���� �� ����
//	int		dims = image.channels();;
//	// ���������� ��� 2���� �迭�� ��ȯ
//	const float* ranges[] = { range };
//
//	/*
//	&image : ����� ����
//	1 : ������ ��
//	channels : ä���� ��
//	Mat() : ����ũ(Mat()�̹Ƿ� ��ü �������� ȿ��x)
//	hist : ����� ������ ����
//	dims : ��� ������ ������
//	histSize : ������
//	ranges : ���� ������
//
//	=> image�� ȭ�Ұ� �󵵼��� ����Ͽ� hist�� ����ش�.
//	*/
//	calcHist(&image, 1, channels, Mat(), hist, dims, histSize, ranges);
//}
//
//int main() {
//	// �� ���� ������ ������׷�
//	Mat hist;
//
//	// 5*6 ũ���� ����
//	Matx<uchar, 5, 6>  m1;
//
//	// ��Ʈ���� �̿��� m1 ��ü�� �� ����
//	m1 << 1, 2, 3, 4, 5, 2, 3, 4, 5, 6, 3, 4, 5, 6, 7,
//		4, 5, 6, 7, 8, 5, 6, 7, 8, 9;
//
//	// �󵵼��� ����ϴ� �Լ�
//	// => calcHist()�Լ� ȣ���� ���� ���� �ٵ�� ȣ���ϴ� �Լ�.
//	calc_Histo((Mat)m1, hist, 5, 10);
//
//	// hist�� ����� ���� ��ġ�Ͽ� ���
//	cout << hist.t() << endl;
//	return 0;
//}