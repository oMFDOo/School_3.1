///*
//	File Name: LinkedList.cc
//	Author: Geun-Hyung Kim
//
//	Description: Linked List ����
//	Date: 2021. 2. 22
//	Version: 0. 1. 0
//*/
//
//#include <iostream>
//#include "LinkedList.h"
//using namespace std;
//
//// Student ����� �� ȭ�鿡 ��� (Impl 1)
//ostream& operator <<(ostream& os, const Student& student)
//{
//	os  << "�̸� : " << student.name << endl
//		<< "�й� : " << student.studentId << "\n\n";
//	return os;
//}
//
//// n�� ° ��� �ڿ� ���ο� ��� �߰� (Impl 2)
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
//// n�� ° ��� ���� ��� ���� (Impl 3)
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
//// List�� ��� node�� ����� ������ ȭ�鿡 ��� (Impl 3)
//void SLinkedList::traverse() {
//	for (Student* start = LinkHead; start != NULL ; start = start->link) {
//		cout << "�̸� :" << start->name << endl
//			 << "�й� :" << start->studentId << "\n\n";
//	}
//}
//
//// sId�� �ش��ϴ� ��� ã�� (Impl 4)
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
//	// ��尡 �ϳ��� ���� ��
//	if (LinkHead == NULL) {
//		LinkHead = sptr;
//		size++;
//	}
//	// ��尡 �ϳ��� ���� �� 
//	// ������ ��� ã�� 
//	else {
//		Student* tmp = findLast();
//		tmp->link = sptr;
//		size++;
//	}
//}
//
//void SLinkedList::addFirst(Student* sptr) {
//	// ��尡 �ϳ��� ���� ��
//	if (LinkHead == NULL) {
//		LinkHead = sptr;
//		size++;
//	}
//	// ��尡 �ϳ��� ���� �� 
//	// ������ ��� ã�� 
//	else {
//		sptr->link = LinkHead;
//		LinkHead = sptr;
//		size++;
//	}
//}
//
//Student* SLinkedList::deleteFirst() {
//	Student* tmp;
//	// ��尡 ���� ���
//	if (LinkHead == NULL) {
//		return NULL;
//	}
//	// ��尡 �ִ� ���
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
//	// ��尡 ���� ���
//	if (LinkHead == NULL) {
//		return NULL;
//	}
//	// ��尡 �ִ� ���
//	else {
//		// ��尡 �ϳ� �ִ� ��� 
//		if (LinkHead->link == NULL) {
//			tmp = LinkHead;
//			LinkHead = NULL;
//			size--;
//		}
//		// ��尡 �ΰ� �̻��� ���
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
//	// Student *SLinkHead = NULL;   // linked list�� head 
//	SLinkedList StudentList;
//
//	Student* person = new Student("ȫ�浿", 20210001);
//	StudentList.addLast(person);
//	person = new Student("�̼���", 20210002);
//	StudentList.addLast(person);
//	person = new Student("������", 20210003);
//	StudentList.addLast(person);
//	cout << StudentList.getSize() << endl;
//	person = new Student("������", 20210004);
//	StudentList.addFirst(person);
//	cout << StudentList.getSize() << endl;
//
//
//	// **********************************************
//	// ���� ����� �߰� �ۼ� �ڵ� ><
//	// **********************************************
//
//	// n�� ° ��� �ڿ� ���ο� ��� �߰� (Impl 2)
//	person = new Student("Ȳ����", 20193148);
//	StudentList.addAfterN(2, person);
//	
//	// List�� ��� node�� ����� ������ ȭ�鿡 ���(Impl 3)
//	StudentList.traverse();
//
//	// n�� ° ��� ���� ��� ���� (Impl 3)
//	StudentList.deleteAfterN(2);
//
//	cout << "\n=================================\n\n";
//
//	StudentList.traverse();
//
//	// sId�� �ش��ϴ� ��� ã�� (Impl 4)
//	person = StudentList.findStudent(20210002);
//	person = new Student("Ȳ����", 20193148);
//	cout << "\n=================================\n\n";
//
//	// Student ����� �� ȭ�鿡 ��� (Impl 1)
//	cout << *person;
//
//	return 0;
//}
//
