#include <iostream>

using namespace std;

template<typename T>
class maxHeap {
    T data[100];  // 배열
    int size; // 저장된 데이터 개수
public:
    maxHeap() : size(0) {};
    void insertData(T data);
    T deleteData();
};

template<typename T>
void maxHeap<T>::insertData(T data) {
    // 데이터가 없는 경우
    this->data[++size] = data;

    // 데이터가 있는 경우
    int idx = size + 1;
    this->data[++size] = data;

    // 반복문 수행 : 아래에서 위로 거슬러 올라가는 과정
    for (; idx != 1 && this->data[idx / 2] < data; ) {
        this->data[idx] = this->data[idx / 2];
        idx = idx / 2;
    }
}

template<typename T>
T maxHeap<T>::deleteData() {
    T rdata = data[1]; //  반환할 데이터
    data[1] = data[size--];

    int idx = size + 1;
    this->data[++size] = data;

    // 반복문 수행 : 위에서 아래로 내려가는 과정
    for (; idx < size && (this->data[idx * 2] > this->data[idx] || this->data[idx * 2 + 1] > this->data[idx]); ) {
        int temp = 0;
        if (this->data[idx * 2] > this->data[idx]) {
            temp = this->data[idx * 2];
            this->data[idx * 2] = this->data[idx];
            this->data[idx] = temp;
        }
        if (this->data[idx * 2 + 1] > this->data[idx]) {
            temp = this->data[idx * 2 + 1];
            this->data[idx * 2 + 1] = this->data[idx];
            this->data[idx] = temp;
        }
        this->data[idx] = this->data[idx * 2];
        idx = idx / 2;
    }

    return rdata;
}

int main() {

}