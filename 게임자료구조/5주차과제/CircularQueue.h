//#pragma once
//#ifndef _SIMPLE_QUEUE_H_
//#define _SIMPLE_QUEUE_H_
//#include <iostream>
//using namespace std;
//
//class CircularQueue {
//	int* dataArray;
//	int rear;			// Queue���� enQueue �� �����͸� ������ index
//	int front;          // Queue���� deQueue �ؾ��� index-1
//	int size; 			// ����� �������� ��
//	int length;			// ���� ������ ũ��
//public:
//	CircularQueue(int l) : size(0), rear(-1), front(-1), length(l) { dataArray = new int[l](); }
//	~CircularQueue() { delete[] dataArray; }
//	// Queue�� ����� �����͸� ���� �տ� �ִ� ������ ���� �ڿ� �ִ� ������ ������ ȭ�鿡 ���
//	friend ostream& operator<<(ostream& os, const CircularQueue& q);     // Impl 1
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