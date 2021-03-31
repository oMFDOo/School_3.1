//#include "CircularQueue.h"
//
//void PrintInfo(CircularQueue &q) {
//	cout
//		<< "Size : " << q.getSize() << " / "
//		<< "Length : " << q.getLength() << " / "
//		<< "Front : " << q.Front() << " / "
//		<< "Rear : " << q.Back() << endl;
//}
//
//int main() {
//	CircularQueue q(5);
//
//	cout << "<init>" << endl;
//	PrintInfo(q);
//
//	cout << q << endl;
//
//
//	cout << "<enQueue>" << endl;
//
//	q.enQueue(1);
//	q.enQueue(2);
//	q.enQueue(3);
//
//	PrintInfo(q);
//
//	cout << q << endl;
//
//	cout << "<deQueue>" << endl;
//
//	for (int i = 0; i < 3; i++) { q.deQueue(); }
//
//	PrintInfo(q);
//
//	cout << q << endl;
//
//
//	cout << "<enQueue>" << endl;
//
//	q.enQueue(1);
//	q.enQueue(2);
//	q.enQueue(3);
//
//	PrintInfo(q);
//
//	cout << q << endl;
//}