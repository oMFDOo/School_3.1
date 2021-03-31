/*
   File Name: SimpleStack.h
   Author: Geun-Hyung Kim

   Description:
	 정수형 배열로 구성된 Stack 클래스 기능 구형 프로그램

   Date: 2021. 3. 24
   Version: 0.1.0
*/
#include <iostream>
#include "Stack.h"

bool Stack::full() {
	return top == length - 1;
}

bool Stack::empty() {
	return top == front;
}

void Stack::push(int data) {
	if (!full()) {
		dataArray[++top] = data;
		size++;
	}
	else {
		throw "Stack is full!!";
	}
}

int Stack::pop() {
	if (!empty()) {
		size--;
		return dataArray[top--];
	}
	else {
		throw "Stack is empty!!";
	}

}

int Stack::Front() {
	return front;
}

int Stack::Top() {
	return top;
}

ostream& operator<<(ostream& os, const Stack& s) {

	os << "======================" << endl
		<< "data : [ ";


	for (int i = s.front + 1; i <= s.top; i++) {
		os << s.dataArray[i];
		if (i != s.top) os << ", ";
	}
	os << " ]" << endl
		<< "======================" << "\n\n";

	return os;
}