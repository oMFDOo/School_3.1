/*
   File Name: LinkedList.h
   Author: Geun-Hyung Kim

   Description: Student Node�� ���� Linked List

   Date: 2021. 3. 22
   Version: 0.1.0
*/

#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include <iostream>

using namespace std;

struct Student {
	string name;
	int	    studentId;
	Student* link;
	Student(string n, int sId) : name(n), studentId(sId) { link = NULL; }
	friend ostream& operator <<(ostream& oStream, const Student& s); // Student ����� �� ȭ�鿡 ��� (Impl 1)
};

class SLinkedList {   // Student Node�� Linked List ��� 
	Student* LinkHead;    // ���� ����Ʈ�� ���
	int size;             // ���� ����Ʈ�� ����� ��

	Student* findLast();  // ������ ��� �� ã�� �Լ� 
public:
	SLinkedList() { LinkHead = NULL; size = 0; }
	void addLast(Student* sptr); // �������� ��� �߰�
	void addFirst(Student* sptr); // ó���� ��� �߰� 
	void addAfterN(int n, Student* sptr); // n�� ° ��� �ڿ� ���ο� ��� �߰� (Impl 2)
	Student* deleteLast();		  // ������ ��� ����
	Student* deleteFirst();       // ù ��� ����
	Student* deleteAfterN(int n);  // n�� ° ��� ���� ��� ���� (Impl 3)
	int getSize() { return size; }
	void traverse();               // List�� ��� node�� ����� ������ ȭ�鿡 ��� (Impl 3)
	Student* findStudent(int sId); // sId�� �ش��ϴ� ��� ã�� (Impl 4)
};

#endif