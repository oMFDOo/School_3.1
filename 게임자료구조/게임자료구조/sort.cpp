#include <ctime>
#include <cstring>
#include <iostream>

using namespace std;

void printbuf(int buf[], int len) {
	for (int i = 0; i < len - 1; i++)
		cout << buf[i] << ", ";
	cout << buf[len - 1] << endl;
}

void swap(int* a, int* b) {
	//cout << "swap" << endl;
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void copyData(int* res, int* dst, int len) {
	for (int i = 0; i < len; i++) {
		dst[i] = res[i];
	}
}

// selectionSort 구현
void selectionSort(int buf[], int len) {
	for (int i = 1; i < len; i++)
	{
		for (int j = i; j >= 0 && buf[j - 1] > buf[j]; j--) {
			swap(&buf[j], &buf[j - 1]);
		}
	}
}

// insertionSort 구현
void insertionSort(int buf[], int len) {
	for (int i = 0; i < len; i++) {
		int min = i;
		for (int j = i + 1; j < len; j++) {
			if (buf[min] > buf[j])
			{
				min = j;
			}
		}
		swap(&buf[i], &buf[min]);
	}
}

// bubbleSort 구현
void bubbleSort(int buf[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i; j++) {
			if (buf[j - 1] > buf[j]) {
				swap(&buf[j - 1], &buf[j]);
			}
		}
	}
}

//merge 함수 구현
void merge(int buf[], int start, int mid, int end) {
	int x = start; // 정렬 1
	int y = mid + 1;
	int i = start;

	int* tmp = new int[end - start + 1];

	for (; i <= end && x <= mid && y <= end;) {
		if (buf[x] < buf[y]) {
			tmp[i - start] = buf[x];
			x++;
			i++;
		}
		else {
			tmp[i - start] = buf[y];
			y++;
			i++;
		}
	}

	if (x <= mid) {
		for (; x <= mid; i++) {
			tmp[i - start] = buf[x];
			x++;
		}
	}
	else {
		for (; y <= end; i++) {
			tmp[i - start] = buf[y];
			y++;
		}
	}
	for (int i = start; i <= end; i++) {
		buf[i] = tmp[i - start];
	}
	delete[] tmp;
}

void mergeSort(int buf[], int start, int end) {

	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(buf, start, mid);
		mergeSort(buf, mid + 1, end);
		merge(buf, start, mid, end);   // merge 구현하기 
	}
	return;
}


// pivotFind 함수 구현
int pivotFind(int buf[], int start, int end) {
	int pivot = buf[start], low = start + 1, high = end;
	// do while  문을 채우면 됨 
	do {
		while ((buf[low] < pivot) && (low < high)) {
			low++;
		}

		while (buf[high] > pivot) {
			high--;
		}

		if (low < high) {
			swap(buf[low], buf[high]);
		}
	} while (low < high);
	swap(buf[start], buf[high]);
	return high;
}

void quickSort(int buf[], int start, int end) {

	if (start < end) {
		int pivotPos = pivotFind(buf, start, end);  // pivotFind 함수 구현하기
		quickSort(buf, start, pivotPos - 1);
		quickSort(buf, pivotPos + 1, end);
	}

	return;
}


int main(int argc, char const* argv[])
{
	int data[20];   //  정렬되지 않은 데이터
	int orgdata[20];    //  data 의 복사본 

	int len = sizeof(data) / sizeof(int);

	srand(static_cast<unsigned int>(time(NULL)));

	for (int i = 0; i < len; i++) {
		orgdata[i] = data[i] = rand() % 100;
	}

	// 원본데이터
	cout << "원본데이터" << endl;
	printbuf(data, len);

	// data 정렬
	copyData(data, orgdata, len);
	cout << "선택정렬" << endl;
	selectionSort(data, len);
	printbuf(data, len);

	copyData(data, orgdata, len);
	cout << "삽입정렬" << endl;
	insertionSort(data, len);
	printbuf(data, len);
	
	copyData(data, orgdata, len);
	cout << "버블정렬" << endl;
	bubbleSort(data, len);	
	printbuf(data, len);

	copyData(data, orgdata, len);
	cout << "병합정렬" << endl;
	mergeSort(data, 0, len - 1);
	printbuf(data, len);

	copyData(data, orgdata, len);
	cout << "퀵정렬" << endl;
	quickSort(data, 0, len - 1);
	printbuf(data, len);

	return 0;
}