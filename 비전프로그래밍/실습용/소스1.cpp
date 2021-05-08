#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void calc_Histo(const Mat& image, Mat& hist, Vec3i bins, Vec3f range_max, int _dims);
vector<Mat> load_histo(Vec3i bins, Vec3f ranges, int nImages);
Mat draw_histo(Mat hist);
Mat query_img();
Mat make_img(Mat img1, Mat img2);
Mat calc_similarity(Mat query_hist, vector<Mat>& DB_hists);
void select_view(double sinc, Mat DB_similaritys);


int main() {
	Vec3i bins(30, 42, 0);   // ��� ���� : ����(30��), ä��(42��)
	Vec3f ranges(180, 256, 0);  // ���� : ����(0~179), ä��(0~255)
	Mat hsv, query_hist;

	/*imshow("query", query);
	imshow("hist_img", hist_img);
	imshow("query + hist_img", make_img(query, hist_img));*/


	vector<Mat> DB_hists = load_histo(bins, ranges, 100);

	Mat query = query_img(); // �Է¿��� �б�
	cvtColor(query, hsv, COLOR_BGR2HSV); // HSV �÷� ��ȯ
	// 2���� ������׷� ���
	calc_Histo(hsv, query_hist, bins, ranges, 2);
	// ��¿� ������׷� ����
	Mat hist_img = draw_histo(query_hist);

	// �÷� ������׷��� �̿��� ���絵 ���
	Mat DB_similaritys = calc_similarity(query_hist, DB_hists);

	double sinc;
	cout << "���� ���絵 �Է� : ";
	cin >> sinc;
	// ���絵 ���� �̻� ���� ���
	select_view(sinc, DB_similaritys);

	imshow("image", query);
	imshow("hist_img", hist_img);

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

Mat draw_histo(Mat hist) {
	if (hist.dims != 2) {
		cout << "������׷��� 2���� �����Ͱ� �ƴմϴ�." << endl;
		exit(1);
	}

	float ratio_value = 512.f;
	float ratio_hue = 180.f / hist.rows;
	float ratio_sat = 256.f / hist.cols;

	Mat graph(hist.size(), CV_32FC3);
	for (int i = 0; i < hist.rows; i++) {
		for (int j = 0; j < hist.cols; j++) {
			float vlaue = hist.at<float>(i, j) * ratio_value; // �󵵰�
			float hue = i * ratio_hue; // ����
			float sat = j * ratio_sat; // ä����

			// 3ä���� �� �� ����
			graph.at<Vec3f>(i, j) = Vec3f(hue, sat, vlaue);
		}
	}
	graph.convertTo(graph, CV_8U);
	cvtColor(graph, graph, COLOR_BGR2HSV);
	resize(graph, graph, Size(0,0), 10, 10, INTER_NEAREST);

	return graph;
}

// �Ű����� : ����� ����, �󵵼��� ���� ����, ������, ���� �ִ� ��밪
void  calc_Histo(const Mat& image, Mat& hist, Vec3i bins, Vec3f range_max, int _dims) {
	// ������ ����
	int		histSize[] = { bins[0], bins[1], bins[2] };
	// ���� ���� ����
	float   range1[] = { 0, (float)range_max[0] };
	float   range2[] = { 0, (float)range_max[1] };
	float   range3[] = { 0, (float)range_max[2] };
	// ä�� �� ��ŭ ����
	int		channels[] = { 0, 1, 2 };
	// ������ ���� �� ����
	int		dims = image.channels();;
	// ���������� ��� 2���� �迭�� ��ȯ
	const float* ranges[] = { range1, range2, range3 };

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

Mat calc_similarity(Mat query_hist, vector<Mat>& DB_hists) {
	Mat DB_similaritys;
	for (int i = 0; i < (int)DB_hists.size(); i++) {
		double compare = compareHist(query_hist, DB_hists[i], HISTCMP_CORREL);
		DB_similaritys.push_back(compare);
	}
	return DB_similaritys;
}


void select_view(double sinc, Mat DB_similaritys) {
	Mat m_idx, sorted_sim;
	// ����� + ��������
	int flag = SORT_EVERY_COLUMN + SORT_DESCENDING;
	cv::sort(DB_similaritys, sorted_sim, flag);
	sortIdx(DB_similaritys, m_idx, flag);

	for (int i = 0; i < sorted_sim.total(); i++) {
		double sim = sorted_sim.at<double>(i);
		if (sim > sinc) {
			int idx = m_idx.at<int>(i);
			String fname = format("DB/img_%02d.jpg", idx);
			Mat img = imread(fname, 1);

			String title = format("img_%03d - %5.2f", idx, sim);
			cout << title << endl;
			imshow(title, img);
		}
	}
}