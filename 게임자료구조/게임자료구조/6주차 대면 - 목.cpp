#include <iostream>

using namespace std;

template<typename T>
class maxHeap {
    T data[100];  // �迭
    int size; // ����� ������ ����
public:
    maxHeap() : size(0) {};
    void insertData(T data);
    T deleteData();
};

template<typename T>
void maxHeap<T>::insertData(T data) {
    // �����Ͱ� ���� ���
    this->data[++size] = data;

    // �����Ͱ� �ִ� ���
    int idx = size + 1;
    this->data[++size] = data;

    // �ݺ��� ���� : �Ʒ����� ���� �Ž��� �ö󰡴� ����
    for (; idx != 1 && this->data[idx / 2] < data; ) {
        this->data[idx] = this->data[idx / 2];
        idx = idx / 2;
    }
}

template<typename T>
T maxHeap<T>::deleteData() {
    T rdata = data[1]; //  ��ȯ�� ������
    data[1] = data[size--];

    int idx = size + 1;
    this->data[++size] = data;

    // �ݺ��� ���� : ������ �Ʒ��� �������� ����
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