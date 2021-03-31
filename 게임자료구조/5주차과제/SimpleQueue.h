///*
//   File Name: SimpleQueue.h
//   Author: Geun-Hyung Kim
//
//   Description:
//	 ������ ������ �� �ִ� ������ �迭�� ������ Queue
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
//	int rear;			// Queue���� enQueue �� �����͸� ������ index
//	int front;          // Queue���� deQueue �ؾ��� index-1
//	int size; 			// ����� �������� ��
//	int length;			// ���� ������ ũ��
//public:
//	Queue(int l) : size(0), rear(-1), front(-1), length(l) { dataArray = new int[l](); }
//	~Queue() { delete[] dataArray; }
//	// Queue�� ����� �����͸� ���� �տ� �ִ� ������ ���� �ڿ� �ִ� ������ ������ ȭ�鿡 ���
//	friend ostream& operator<<(ostream& os, const Queue& q);     // Impl 1
//	bool full();     // Queue �� ���� ������ �� ����ϰ� ������ true �ƴϸ� flase ��ȯ
//	bool empty();    //  Queue �� ��� ������ true �ƴϸ� false ��ȯ
//	void enQueue(int data);  // Queue�� �����͸� ����
//	int deQueue();    // Queue�� ����� ������ �� ���� ������ �������� ���� ��ȯ�ϰ� ���� ����� �����͸� ������
//	int Front();      // Queue ���� �տ� �ִ� ������ ��ȯ (������ �������� ����)
//	int Back();       // Queue ���� �ڿ� �ִ� ������ ��ȯ (������ �������� ����)	int size() {return size;}
//	int getLength() { return length; }
//	int getSize() { return size; }
//};
//
//#endif