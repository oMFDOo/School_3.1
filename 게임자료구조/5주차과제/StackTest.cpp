#include "Stack.h"

void PrintInfo(Stack &s) {
	cout
		<< "Size : " << s.getSize() << " / "
		<< "Length : " << s.getLength() << " / "
		<< "Front : " << s.Front() << " / "
		<< "Top : " << s.Top() << endl;
}

int main() {
	Stack q(5);

	cout << "<init>" << endl;
	PrintInfo(q);

	cout << q << endl;


	cout << "<push>" << endl;

	q.push(1);
	q.push(2);
	q.push(3);

	PrintInfo(q);

	cout << q << endl;

	cout << "<pop>" << endl;

	for (int i = 0; i < 3; i++) { q.pop(); }

	PrintInfo(q);

	cout << q << endl;


	cout << "<push>" << endl;

	q.push(1);
	q.push(2);
	q.push(3);

	PrintInfo(q);

	cout << q << endl;
}