//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct Student {
//	string name;
//	int studentId;
//	Student* link;
//	Student(string n, int sID) : name(n), studentId(sID) { link = NULL; };
//};
//
//class SLinkedList {  // Student Node의 Linked List
//private:
//	Student* LinkHead;
//	int size;
//	Student* findLast();	// 마지막 노드 찾기
//public:
//	SLinkedList() { LinkHead = NULL; size = 0; };
//	void addLast(Student* sptr);	// 마지막에 노드 추가
//	void addFirst(Student* sptr);	// 처음에 노드 추가
//	Student* deleteLast();
//	Student* deleteFirst();
//	int getSize() { return size; };
//};
//
//Student* SLinkedList::findLast() {
//	Student* tmp = LinkHead;
//	
//	if (tmp == NULL) return NULL;
//	else {
//		// 마지막 노드 탐색
//		while (tmp->link != NULL) {
//			tmp = tmp->link;
//		}
//		return tmp;
//	}
//}
//
//void SLinkedList::addLast(Student* sptr) {
//	// 노드가 하나도 없을 때
//	if (LinkHead == NULL) {
//		LinkHead = sptr;
//		size++;
//	}
//	// 노드가 하나라도 있을 때
//	// 마지막 노드 찾기 : 사이즈를 모를 때
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
//	else {
//		sptr->link = LinkHead;
//		LinkHead = sptr;
//		size++;
//	}
//}
//
//
//Student* SLinkedList::deleteFirst() {
//	Student* tmp = NULL;
//	// 노드가 하나도 없을 때
//	if (LinkHead == NULL) {
//		return NULL;
//	}
//	// 노드가 하나라도 있을 때
//	else {
//		tmp = LinkHead;
//		LinkHead = tmp->link;
//		size--;
//	}
//	return tmp;
//}
//
//Student* SLinkedList::deleteLast() {
//	Student* tmp = NULL, *tmp1 = NULL;
//
//	// 노드가 하나도 없을 때
//	if (LinkHead == NULL) {
//		return NULL;
//	}
//	// 노드가 하나라도 있을 때
//	else {
//		// 노드가 하나 있는 경우
//		if (LinkHead->link == NULL) {
//			tmp = LinkHead;
//			LinkHead = NULL;
//			size--;
//		}
//		// 노드가 두 개 이상인 경우
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
//int main() {
//	SLinkedList StudentList;
//
//	Student* person = new Student("홍길동", 20210001);
//	StudentList.addLast(person);
//
//	person = new Student("이순신", 20210002);
//	StudentList.addLast(person);
//
//	person = new Student("강감찬", 20210003);
//	StudentList.addLast(person);
//
//	person = new Student("권정인", 20210004);
//	StudentList.addFirst(person);
//
//	cout << StudentList.getSize() << endl;
//
//	StudentList.deleteLast();
//	StudentList.deleteFirst();
//
//	cout << StudentList.getSize() << endl;
//}