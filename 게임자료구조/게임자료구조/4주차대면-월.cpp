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
//class SLinkedList {  // Student Node�� Linked List
//private:
//	Student* LinkHead;
//	int size;
//	Student* findLast();	// ������ ��� ã��
//public:
//	SLinkedList() { LinkHead = NULL; size = 0; };
//	void addLast(Student* sptr);	// �������� ��� �߰�
//	void addFirst(Student* sptr);	// ó���� ��� �߰�
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
//		// ������ ��� Ž��
//		while (tmp->link != NULL) {
//			tmp = tmp->link;
//		}
//		return tmp;
//	}
//}
//
//void SLinkedList::addLast(Student* sptr) {
//	// ��尡 �ϳ��� ���� ��
//	if (LinkHead == NULL) {
//		LinkHead = sptr;
//		size++;
//	}
//	// ��尡 �ϳ��� ���� ��
//	// ������ ��� ã�� : ����� �� ��
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
//	// ��尡 �ϳ��� ���� ��
//	if (LinkHead == NULL) {
//		return NULL;
//	}
//	// ��尡 �ϳ��� ���� ��
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
//	// ��尡 �ϳ��� ���� ��
//	if (LinkHead == NULL) {
//		return NULL;
//	}
//	// ��尡 �ϳ��� ���� ��
//	else {
//		// ��尡 �ϳ� �ִ� ���
//		if (LinkHead->link == NULL) {
//			tmp = LinkHead;
//			LinkHead = NULL;
//			size--;
//		}
//		// ��尡 �� �� �̻��� ���
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
//	Student* person = new Student("ȫ�浿", 20210001);
//	StudentList.addLast(person);
//
//	person = new Student("�̼���", 20210002);
//	StudentList.addLast(person);
//
//	person = new Student("������", 20210003);
//	StudentList.addLast(person);
//
//	person = new Student("������", 20210004);
//	StudentList.addFirst(person);
//
//	cout << StudentList.getSize() << endl;
//
//	StudentList.deleteLast();
//	StudentList.deleteFirst();
//
//	cout << StudentList.getSize() << endl;
//}