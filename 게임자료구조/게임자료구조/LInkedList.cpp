///*
//	File Name: LinkedList.cc
//	Author: Geun-Hyung Kim
//
//	Description: Linked List 구현
//	Date: 2021. 2. 22
//	Version: 0. 1. 0
//*/
//
//#include <iostream>
//#include "LinkedList.h"
//using namespace std;
//
//// Student 저장된 값 화면에 출력 (Impl 1)
//ostream& operator <<(ostream& os, const Student& student)
//{
//	os  << "이름 : " << student.name << endl
//		<< "학번 : " << student.studentId << "\n\n";
//	return os;
//}
//
//// n번 째 노드 뒤에 새로운 노드 추가 (Impl 2)
//void SLinkedList::addAfterN(int n, Student* sptr) {
//	if (n > size) return;
//
//	int cnt = 0;
//	Student* start = LinkHead;
//	while (start != NULL) {
//		if (cnt == n) {
//			sptr->link = start->link;
//			start->link = sptr;
//			size++;
//		}
//		start = start->link;
//		cnt++;
//	}
//}
//
//// n번 째 노드 뒤의 노드 삭제 (Impl 3)
//Student* SLinkedList::deleteAfterN(int n) {
//	if (n > size) return NULL;
//
//	int cnt = 0;
//	Student* start = LinkHead;
//	Student* tmp = NULL;
//
//	while (start != NULL) {
//		if (cnt == n) {
//			tmp = start->link;
//			start->link = tmp->link;
//			//delete tmp;
//			size--;
//		}
//		start = start->link;
//		cnt++;
//	}
//	return tmp;
//}
//
//// List의 모든 node의 저장된 내용을 화면에 출력 (Impl 3)
//void SLinkedList::traverse() {
//	for (Student* start = LinkHead; start != NULL ; start = start->link) {
//		cout << "이름 :" << start->name << endl
//			 << "학번 :" << start->studentId << "\n\n";
//	}
//}
//
//// sId에 해당하는 노드 찾기 (Impl 4)
//Student* SLinkedList::findStudent(int sId) {
//	for (Student* start = LinkHead; start != NULL; start = start->link) {
//		if (sId == start->studentId) {
//			return start;
//		}
//	}
//	return NULL;
//}
//
//
//
//
//Student* SLinkedList::findLast() {
//	Student* tmp = LinkHead;
//	if (tmp == NULL) return NULL;
//	else {
//		while (tmp->link != NULL)
//			tmp = tmp->link;
//	}
//	return tmp;
//}
//
//void SLinkedList::addLast(Student* sptr) {
//	// 노드가 하나도 없을 때
//	if (LinkHead == NULL) {
//		LinkHead = sptr;
//		size++;
//	}
//	// 노드가 하나라도 있을 때 
//	// 마지막 노드 찾기 
//	else {
//		Student* tmp = findLast();
//		tmp->link = sptr;
//		size++;
//	}
//}
//
//void SLinkedList::addFirst(Student* sptr) {
//	// 노드가 하나도 없을 때
//	if (LinkHead == NULL) {
//		LinkHead = sptr;
//		size++;
//	}
//	// 노드가 하나라도 있을 때 
//	// 마지막 노드 찾기 
//	else {
//		sptr->link = LinkHead;
//		LinkHead = sptr;
//		size++;
//	}
//}
//
//Student* SLinkedList::deleteFirst() {
//	Student* tmp;
//	// 노드가 없는 경우
//	if (LinkHead == NULL) {
//		return NULL;
//	}
//	// 노드가 있는 경우
//	else {
//		tmp = LinkHead;
//		LinkHead = tmp->link;
//		size--;
//	}
//	return tmp;
//}
//
//Student* SLinkedList::deleteLast() {
//	Student* tmp, * tmp1;
//	// 노드가 없는 경우
//	if (LinkHead == NULL) {
//		return NULL;
//	}
//	// 노드가 있는 경우
//	else {
//		// 노드가 하나 있는 경우 
//		if (LinkHead->link == NULL) {
//			tmp = LinkHead;
//			LinkHead = NULL;
//			size--;
//		}
//		// 노드가 두개 이상인 경우
//		else {
//			tmp1 = LinkHead;
//			while (tmp1->link->link != NULL) {
//				tmp1 = tmp1->link;
//			}
//			tmp = tmp1->link;
//			tmp1->link = NULL;
//			size--;
//		}
//	}
//	return tmp;
//}
//
//
//int main(int argc, char const* argv[])
//{
//	// Student *SLinkHead = NULL;   // linked list의 head 
//	SLinkedList StudentList;
//
//	Student* person = new Student("홍길동", 20210001);
//	StudentList.addLast(person);
//	person = new Student("이순신", 20210002);
//	StudentList.addLast(person);
//	person = new Student("강감찬", 20210003);
//	StudentList.addLast(person);
//	cout << StudentList.getSize() << endl;
//	person = new Student("권정인", 20210004);
//	StudentList.addFirst(person);
//	cout << StudentList.getSize() << endl;
//
//
//	// **********************************************
//	// 과제 제출용 추가 작성 코드 ><
//	// **********************************************
//
//	// n번 째 노드 뒤에 새로운 노드 추가 (Impl 2)
//	person = new Student("황진주", 20193148);
//	StudentList.addAfterN(2, person);
//	
//	// List의 모든 node의 저장된 내용을 화면에 출력(Impl 3)
//	StudentList.traverse();
//
//	// n번 째 노드 뒤의 노드 삭제 (Impl 3)
//	StudentList.deleteAfterN(2);
//
//	cout << "\n=================================\n\n";
//
//	StudentList.traverse();
//
//	// sId에 해당하는 노드 찾기 (Impl 4)
//	person = StudentList.findStudent(20210002);
//	person = new Student("황진주", 20193148);
//	cout << "\n=================================\n\n";
//
//	// Student 저장된 값 화면에 출력 (Impl 1)
//	cout << *person;
//
//	return 0;
//}
//
