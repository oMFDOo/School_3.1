#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void  calc_Histo(const Mat& image, Mat& hist, int bins, int range_max, int _dims);
vector<Mat> load_histo(Vec3i bins, Vec3f ranges, int nImages);
Mat draw_histo(Mat hist);
Mat query_img();
Mat make_img(Mat img1, Mat img2);


int main() {
	Vec3i bins(30, 42, 0);   // ��� ���� : ����(30��), ä��(42��)
	Vec3f ranges(180, 256, 0);  // ���� : ����(0~179), ä��(0~255)
	vector<Mat> DB_hists = load_histo(bins, ranges, 100); // DB����� ������׷�
	Mat query = query_img();

	Mat hsv, query_hist;
	cvtColor(query, hsv, COLOR_BGR2HSV); // HSV �÷� ��ȯ
	calc_Histo(hsv, query_hist, bins, ranges, 2); // 2���� ������׷� ���
	Mat hist_img = draw_histo(query_hist); // 2���� �׷���

	imshow("query", query);
	imshow("hist_img", hist_img);
	imshow("query + hist_img", make_img(query, hist_img));
}

// ��޼�, ȭ�Ұ� ����, �Է� �̹��� ���� �Է�
vector<Mat> load_histo(Vec3i bins, Vec3f ranges, int nImages) {
	vector<Mat> DB_hists;
	for (int i = 0; i < nImages; i++) {
		String fname = format("DB/img_%02d.jpg", i);
		Mat hsv, hist, img = imread(fname, IMREAD_COLOR);
		if (img.empty()) continue;

		cvtColor(img, hsv, COLOR_BGR2HSV);
		calc_Histo(hsv, hist, bins, ranges, 2);
		DB_hists.push_back(hist);
	}

	cout << format("%d�� ���� �ε� �� ������׷� ��� �Ϸ�", DB_hists.size());
	return DB_hists; // 3���� ����
}


// �Ű����� : ����� ����, �󵵼��� ���� ����, ������, ���� �ִ� ��밪
void  calc_Histo(const Mat& image, Mat& hist, int bins, int range_max, int _dims) {
	// ������ ����
	int		histSize[] = { bins };
	// ���� ���� ����
	float   range[] = { 0, (float)range_max };
	// ä�� �� ��ŭ ����
	int		channels[] = { 0 };
	// ������ ���� �� ����
	int		dims = image.channels();;
	// ���������� ��� 2���� �迭�� ��ȯ
	const float* ranges[] = { range };

	/*
	&image : ����� ����
	1 : ������ ��
	channels : ä���� ��
	Mat() : ����ũ(Mat()�̹Ƿ� ��ü �������� ȿ��x)
	hist : ����� ������ ����
	dims : ��� ������ ������
	histSize : ������
	ranges : ���� ������

	=> image�� ȭ�Ұ� �󵵼��� ����Ͽ� hist�� ����ش�.
	*/
	calcHist(&image, 1, channels, Mat(), hist, dims, histSize, ranges);
}

Mat query_img() {
	do {
		int q_no = 74;
		cout << "���ǿ��� ��ȣ�� �Է��ϼ��� : ";
		cin >> q_no; // �ܼ�â ���� �Է�

		String fname = format("DB/img_%02d.jpg", q_no);
		// ���ǿ��� �б�
		Mat query = imread(fname, IMREAD_COLOR);

		if (query.empty()) cout << "���ǿ��� ��ȣ�� �߸��Ǿ����ϴ�." << endl;
		else return query; // ���ǿ��� ��ȯ
	} while (1); // ���ǿ��� ������ ��ӹݺ�
}