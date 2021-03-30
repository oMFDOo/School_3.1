/*
 	File Name: LinkedList.cc
	Author: Geun-Hyung Kim

	Description: Linked List 구현 
	Date: 2021. 2. 22
	Version: 0. 1. 0
*/

#include <iostream>
#include "LinkedList.h"
using namespace std;

Student* SLinkedList::findLast() {
	Student *tmp = LinkHead;
	if(tmp == NULL) return NULL;
	else {
		while(tmp->link != NULL)
			tmp = tmp->link;
	}
	return tmp;
}

void SLinkedList::addLast(Student* sptr) {
	// 노드가 하나도 없을 때
	if(LinkHead == NULL) {
		LinkHead = sptr;
		size++;
	}
	// 노드가 하나라도 있을 때 
	// 마지막 노드 찾기 
	else {
		Student *tmp = findLast();
		tmp->link = sptr;
		size++;
	}
}

void SLinkedList::addFirst(Student* sptr) {
	// 노드가 하나도 없을 때
	if(LinkHead == NULL) {
		LinkHead = sptr;
		size++;
	}
	// 노드가 하나라도 있을 때 
	// 마지막 노드 찾기 
	else {
		sptr->link = LinkHead;
		LinkHead = sptr;
		size++; 
	}
}

Student* SLinkedList::deleteFirst() {
	Student* tmp;
	// 노드가 없는 경우
	if(LinkHead == NULL) {
		return NULL;
	}
	// 노드가 있는 경우
	else {
		tmp = LinkHead;
		LinkHead = tmp->link;
		size--;
	}
	return tmp;
}

Student* SLinkedList::deleteLast() {
	Student* tmp, *tmp1;
	// 노드가 없는 경우
	if(LinkHead == NULL) {
		return NULL;
	}
	// 노드가 있는 경우
	else {
		// 노드가 하나 있는 경우 
		if(LinkHead->link == NULL) {
			tmp = LinkHead;
			LinkHead = NULL;
			size--;
		}
		// 노드가 두개 이상인 경우
		else {
			tmp1 = LinkHead;
			while(tmp1->link->link != NULL){
				tmp1 = tmp1->link;
			}
			tmp = tmp1->link;
			tmp1->link = NULL;
			size--;
		}
	}
	return tmp;
}


int main(int argc, char const *argv[])
{
	// Student *SLinkHead = NULL;   // linked list의 head 
	SLinkedList StudentList;

	Student *person = new Student("홍길동", 20210001);
	StudentList.addLast(person);
	person = new Student("이순신", 20210002);
	StudentList.addLast(person);
	person = new Student("강감찬", 20210003);
	StudentList.addLast(person);
	cout << StudentList.getSize() << endl;
	person = new Student("권정인", 20210004);
	StudentList.addFirst(person);
	cout << StudentList.getSize() << endl;
	StudentList.deleteLast();
	StudentList.deleteLast();
	StudentList.deleteLast();
	StudentList.deleteLast();
	cout << StudentList.getSize() << endl;

	return 0;
}

