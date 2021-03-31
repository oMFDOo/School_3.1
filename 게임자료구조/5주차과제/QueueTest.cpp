//#include "SimpleQueue.h"
//using namespace std;
//
//int main() {
//	Queue q(100);
//
//	cout << "<init>" << endl;
//	cout 
//		<< "Size : " << q.getSize () << " / "
//		<< "Length : " << q.getLength() << " / "
//		<< "Front : " << q.Front() << " / "
//		<< "Rear : " << q.Back() << endl;
//
//	cout << q << endl;
//
//
//	cout << "<enQueue>" << endl;
//
//	q.enQueue(1);
//	q.enQueue(2);
//	q.enQueue(3);
//	q.enQueue(4);
//	q.enQueue(5);
//
//	cout
//		<< "Size : " << q.getSize() << " / "
//		<< "Length : " << q.getLength() << " / "
//		<< "Front : " << q.Front() << " / "
//		<< "Rear : " << q.Back() << endl;
//
//	cout << q << endl;
//
//	cout << "<deQueue>" << endl;
//
//	for (int i = 0; i < 5; i++) { q.deQueue(); }
//
//	cout
//		<< "Size : " << q.getSize() << " / "
//		<< "Length : " << q.getLength() << " / "
//		<< "Front : " << q.Front() << " / "
//		<< "Rear : " << q.Back() << endl;
//
//	cout << q << endl;
//}