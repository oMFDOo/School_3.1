/*
   File Name: SimpleQueue.h
   Author: Geun-Hyung Kim

   Description: 
     정수형 배열로 구성된 Queue 클래스 기능 구형 프로그램  

   Date: 2021. 3. 24
   Version: 0.1.0
*/
#include <iostream>
#include "SimpleQueue.h"

bool Queue::full() {
	return rear == length-1;  
}

bool Queue::empty() {
	return rear == front;
}

void Queue::enQueue(int data) {
	if (!full()) {
		dataArray[++rear] = data;
		size++;
	}
	else {
		throw "Queue is full!!";
	}
}

int Queue::deQueue() {
	if (!empty()) {
		size--;
		return dataArray[++front];
	}
	else {
		throw "Queue is empty!!";
	}

}

int Queue::Front() {
	return front;
}

int Queue::Back() {
	return rear;
}

ostream& operator<<(ostream& os, const Queue& q) {
	os << "length : " << q.length << endl
		<< "size : " << q.size << endl
		<< "front : " << q.front << endl
		<< "rear : " << q.rear << "\n\n";
	return os;
}
