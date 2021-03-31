///*
//   File Name: SimpleQueue.h
//   Author: Geun-Hyung Kim
//
//   Description:
//	 정수형 배열로 구성된 Queue 클래스 기능 구형 프로그램
//
//   Date: 2021. 3. 24
//   Version: 0.1.0
//*/
//
//#include <iostream>
//#include "CircularQueue.h"
//
//bool CircularQueue::full() {
//	return ((rear + 1) % length) == front;
//}
//
//bool CircularQueue::empty() {
//	return rear == front;
//}
//
//void CircularQueue::enQueue(int data) {
//	if (!full()) {
//		rear = (rear + 1) % length;
//		dataArray[rear] = data;
//		size++;
//	}
//	else {
//		throw "CircularQueue is full!!";
//	}
//}
//
//int CircularQueue::deQueue() {
//	if (!empty()) {
//		size--;
//		return dataArray[front = (front + 1) % length];
//	}
//	else {
//		throw "CircularQueue is empty!!";
//	}
//}
//
//int CircularQueue::Front() {
//	return front;
//}
//
//int CircularQueue::Back() {
//	return rear;
//}
//
//ostream& operator<<(ostream& os, const CircularQueue& q) {
//
//	os << "======================" << endl
//		<< "data : [ ";
//
//	if (q.front > q.rear ) {
//		for (int i = q.front + 1; i < q.length; i++) {
//			os << q.dataArray[i] << ", ";
//		}
//		for (int i = 0; i <= q.rear; i++) {
//			os << q.dataArray[i];
//			if (i != q.rear) os << ", ";
//		}
//	}
//	else {
//		for (int i = q.front + 1; i <= q.rear; i++) {
//			os << q.dataArray[i];
//			if (i != q.rear) os << ", ";
//		}
//	}
//
//	
//	os << " ]" << endl
//		<< "======================" << "\n\n";
//
//	return os;
//}
