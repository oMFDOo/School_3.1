#include <ctime>
#include <cstring>
#include <iostream>

using namespace std;

void printbuf(int buf[], int len){
	for(int i = 0; i < len - 1; i++) 
		cout << buf[i] << ", ";
	cout << buf[len -1] << endl;	
}

void swap(int& a, int& b) {
	cout << "swap" << endl;
	int tmp = a;
	a = b;
	b = tmp;
}

// selectionSort 구현
void selectionSort(int buf[], int len){

}

// insertionSort 구현
void insertionSort(int buf[], int len){

}

// bubbleSort 구현
void bubbleSort(int buf[], int len){

}

//merge 함수 구현
void merge(int buf[], int start, int mid, int end) { 
int i = start; // 정렬 1


}

void mergeSort(int buf[], int start, int end){

	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(buf, start, mid);
		mergeSort(buf, mid+1, end);
		merge(buf, start, mid, end);   // merge 구현하기 
	}
	return;
}


// pivotFind 함수 구현

int pivotFind(in buf[], int start, int end) {

	int pivot =  buf[start], low = start + 1, high = end;
	// do while  문을 채우면 됨 
	do {




	}while(low < high)

	swap(buf[start], buf[high]);

	return high;
}

void quickSort(int buf[], int start, int end){

	if (start < end) {
		int pivotPos = pivotFind(buf, start, end);  // pivotFind 함수 구현하기
		quickSort(buf, start, pivotPos - 1);
		quickSort(buf, pivotPos + 1, end);
	}

	return;
}


int main(int argc, char const *argv[])
{
	int data[20];   //  정렬되지 않은 데이터
	int orgdata[20];    //  data 의 복사본 

	int len = sizeof(data)/sizeof(int);

	srand(static_cast<unsigned int>(time(NULL)));

	for(int i = 0; i < len; i++) {
		orgdata[i] = data[i] = random() % 100;
	}
	

	// data 출력

	memcpy(data, orgdata, len); // orgdata -> data


	return 0;
}