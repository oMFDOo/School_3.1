///*
//   File Name: SimpleQueue.h
//   Author: Geun-Hyung Kim
//
//   Description:
//	 정수를 저장할 수 있는 정수형 배열로 구현한 Queue
//
//   Date: 2021. 3. 24
//   Version: 0.1.0
//*/
//
//#ifndef _SIMPLE_QUEUE_H_
//#define _SIMPLE_QUEUE_H_
//#include <iostream>
//using namespace std;
//
//class Queue {
//	int* dataArray;
//	int rear;			// Queue에서 enQueue 로 데이터를 저장할 index
//	int front;          // Queue에서 deQueue 해야할 index-1
//	int size; 			// 저장된 데이터의 수
//	int length;			// 저장 공간의 크기
//public:
//	Queue(int l) : size(0), rear(-1), front(-1), length(l) { dataArray = new int[l](); }
//	~Queue() { delete[] dataArray; }
//	// Queue의 저장된 데이터를 제일 앞에 있는 데이터 부터 뒤에 있는 데이터 순으로 화면에 출력
//	friend ostream& operator<<(ostream& os, const Queue& q);     // Impl 1
//	bool full();     // Queue 의 저장 공간을 다 사용하고 있으면 true 아니면 flase 반환
//	bool empty();    //  Queue 가 비어 있으면 true 아니면 false 반환
//	void enQueue(int data);  // Queue에 데이터를 저장
//	int deQueue();    // Queue에 저장된 데이터 중 가장 오래된 데이터의 값을 반환하고 저장 장소의 데이터를 삭제함
//	int Front();      // Queue 제일 앞에 있는 데이터 반환 (데이터 삭제하지 않음)
//	int Back();       // Queue 제일 뒤에 있는 데이터 반환 (데이터 삭제하지 않음)	int size() {return size;}
//	int getLength() { return length; }
//	int getSize() { return size; }
//};
//
//#endif