//#include <opencv2/opencv.hpp>
//using namespace cv;
//using namespace std;
//
//
//// 매개변수 : 계산할 영상, 빈도수를 담을 영상, 구간수, 값의 최대 허용값
//void  calc_Histo(const Mat& image, Mat& hist, int bins, int range_max = 256) {
//	// 구간값 저장
//	int		histSize[] = { bins };
//	// 값의 범위 저장
//	float   range[] = { 0, (float)range_max };
//	// 채널 수 만큼 저장
//	int		channels[] = { 0 };
//	// 영상의 차원 수 저장
//	int		dims = image.channels();;
//	// 구간값들을 모아 2차원 배열로 변환
//	const float* ranges[] = { range };
//
//	/*
//	&image : 계산할 영상
//	1 : 영상의 수
//	channels : 채널의 수
//	Mat() : 마스크(Mat()이므로 전체 영상지정 효과x)
//	hist : 결과를 저장할 영상
//	dims : 결과 영상의 차원수
//	histSize : 구간수
//	ranges : 값의 범위값
//
//	=> image의 화소값 빈도수를 계산하여 hist에 담아준다.
//	*/
//	calcHist(&image, 1, channels, Mat(), hist, dims, histSize, ranges);
//}
//
//int main() {
//	// 빈도 수를 저장할 히스토그램
//	Mat hist;
//
//	// 5*6 크기의 영상
//	Matx<uchar, 5, 6>  m1;
//
//	// 스트림을 이용해 m1 객체의 값 저장
//	m1 << 1, 2, 3, 4, 5, 2, 3, 4, 5, 6, 3, 4, 5, 6, 7,
//		4, 5, 6, 7, 8, 5, 6, 7, 8, 9;
//
//	// 빈도수를 계산하는 함수
//	// => calcHist()함수 호출을 위해 값을 다듬고 호출하는 함수.
//	calc_Histo((Mat)m1, hist, 5, 10);
//
//	// hist에 저장된 값을 전치하여 출력
//	cout << hist.t() << endl;
//	return 0;
//}