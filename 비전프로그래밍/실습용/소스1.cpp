#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void  calc_Histo(const Mat& image, Mat& hist, int bins, int range_max = 256) {
	int		histSize[] = { bins };
	float   range[] = { 0, (float)range_max };
	int		channels[] = { 0 };
	int		dims = image.channels();;
	const float* ranges[] = { range };

	calcHist(&image, 1, channels, Mat(), hist, dims, histSize, ranges);
}

int main() {
	Mat hist;
	Matx<uchar, 5, 6>  m1;
	m1 << 1, 2, 3, 4, 5, 2, 3, 4, 5, 6, 3, 4, 5, 6, 7,
		4, 5, 6, 7, 8, 5, 6, 7, 8, 9;

	calc_Histo((Mat)m1, hist, 5, 10);
	cout << hist.t() << endl;
	return 0;
}