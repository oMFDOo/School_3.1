//#include <iostream>
//
//// 정수형 큐인데 동적으로 크기를 지정하고 싶다.
//// 어떤건 10개! 어떤건 100개!
//class Queue {
//private:
//	int *dataArray; // 여기 공간이 동적으로 지정되어야 함.
//	int front;
//	int rear;
//	int size;  // 저장된 데이터  수
//	int length; // 저장 공간의 크기
//public:
//	Queue(int l);
//};
//
//Queue::Queue(int l = 100) : rear(-1), front(-1), size(0), length(l) { 
//	dataArray = new int[l];
//}
//
//int main() {
//	
//}