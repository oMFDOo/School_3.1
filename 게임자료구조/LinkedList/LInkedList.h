/*
   File Name: LinkedList.h
   Author: Geun-Hyung Kim

   Description: Student Node와 관련 Linked List 

   Date: 2021. 3. 22
   Version: 0.1.0
*/

#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include <iostream>

using namespace std;

struct Student{
	string name;
	int	    studentId;
	Student *link;
	Student(string n, int sId) : name(n), studentId(sId) { link = NULL;}
	ostream& operator <<(ostream& oStream, const Student& s); // Student 저장된 값 화면에 출력 (Impl 1)
};

class SLinkedList{   // Student Node의 Linked List 헤더 
	Student *LinkHead;    // 연결 리스트의 헤드
	int size;             // 연결 리스트의 노드의 수

	Student* findLast();  // 마지막 노드 를 찾는 함수 
public:
	SLinkedList() {LinkHead = NULL; size = 0;}
	void addLast(Student* sptr); // 마지막에 노드 추가
	void addFirst(Student* sptr); // 처음에 노드 추가 
	void addAfterN(int n, Student* sptr); // n번 째 노드 뒤에 새로운 노드 추가 (Impl 2)
	Student* deleteLast();		  // 마지막 노드 삭제
	Student* deleteFirst();       // 첫 노드 삭제
	Student* deleteAfterN(int n)  // n번 째 노드 뒤의 노드 삭제 (Impl 3)
	int getSize() {return size;}
	void traverse();               // List의 모든 node의 저장된 내용을 화면에 출력 (Impl 3)
	Student* findStudent(int sId); // sId에 해당하는 노드 찾기 (Impl 4)
};

#endif