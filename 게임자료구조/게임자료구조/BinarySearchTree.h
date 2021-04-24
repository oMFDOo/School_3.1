#pragma once
/*

	File Name: BinarySearchTree.h
	Author: Geun-Hyung Kim

	Description:
	연결 리스트를 활용한 이진탐색트리 생성

*/

#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node {
	T data;         // 데이터 저장을 위한 변수  
	Node<T>* left;  // 트리 노드의 왼쪽 자식노드의 주소 저장을 위한 변수
	Node<T>* right; // 트리 노드의 오른쪽 자식노드의 주소 저장을 위한 변수 
public:
	Node(T d = 0, Node<T>* l = NULL, Node<T>* r = NULL) : data(d), left(NULL), right(NULL) {}
	~Node() {}
	T getData();					 // 특정 트리 노드의 데이터 값 가져오기
	void setData(T& data);			 // 특정 트리 노드의 데이터 값 대입하기
	Node<T>* getLeftNode();       	 // 특정 트리 노드의 왼쪽 자식노드의 주소 값 반환
	Node<T>* getRightNode();		 // 특정 트리 노드의 오른쪽 자식노드의 주소 값 반환
	void setLeftNode(Node<T>* node);  //왼쪽 자식노드에 트리 노드 추가 
	void setRightNode(Node<T>* node); // 오른쪽 자식노드에 트리 노드 추가 
	bool levelFind(int type);  // type : 반환값을 설정
};

template<typename T>
class BinarySearchTree {
	Node<T>* root;
	int size;	// 현재 트리의 노드 개수

public:
	BinarySearchTree() : size(0), root(NULL) {};
	~BinarySearchTree();
	// 특정 트리에서 데이터를 찾아서 존재하면 true, 존재하지 않으면 false를 반환 
	bool searchData(T& data);
	// 트리에 입력한 데이터의 노드 추가 (이미 데이터가 있으면 false, 반환 데이터가 추가되면 true 반환)
	bool insertData(T& data);
	// 트리에서 입력한 데이터의 노드 삭제 (트리에 없는 데이터를 삭제하고자 하면 false, 데이터 삭제가 성공하면 true 반환)
	bool removeData(T& data);
	// 트리의 root에서 부터 레벨 오더로 데이터 값을 출력
	void levelOrderPrint();
};

// NODE 클래스 함수 구현

template <typename T>
T Node<T>::getData() {
	return this->data;
}

template <typename T>
void Node<T>::setData(T& data) {
	this->data = data.data;
}

template <typename T>
Node<T>* Node<T>::getLeftNode() {
	if (this->left == NULL) {
		return NULL;
	}
	return this->left;
}

template <typename T>
Node<T>* Node<T>::getRightNode() {
	if (this->right == NULL) {
		return NULL;
	}
	return this->right;
}

template <typename T>
void Node<T>::setLeftNode(Node<T>* node) {
	this->left = node;
}

template <typename T>
void Node<T>::setRightNode(Node<T>* node) {
	this->right = node;
}


// BinarySearchTree 클래스 함수 구현


template <typename T>
bool BinarySearchTree<T>::searchData(T& data) {
	queue<Node<T>*> dataSet;
	Node<T>* find = root;
	while (true) {
		if (find->getData() == data) return true;
		if (find->getLeftNode() != NULL) dataSet.push(find->getLeftNode());
		if (find->getRightNode() != NULL) dataSet.push(find->getRightNode());
		if (find->getLeftNode() == NULL &&
			find->getRightNode() == NULL &&
			dataSet.size() == 0) return false;
		find = dataSet.front();
		dataSet.pop();
	}
}


// Q. 데이터 삽입의 반환형이 왜 Bool인가요?
template <typename T>
bool BinarySearchTree<T>::insertData(T& data) {
	// 데이터가 없을 경우
	if (root == NULL) {
		root = new Node<T>(data); return true;
	}
	else if (searchData(data)) {
		return false;
	}
	else {
		Node<T>* find = root;
		for (;;) {
			// 오른쪽으로 삽입
			if (find->getData() < data) {
				// 오른쪽 노드가 비어있다면?
				if (find->getRightNode() == NULL) {
					find->setRightNode(data);
					size++; return true;
				}
				find = find->getRightNode();
			}
			if (find->getData() >= data) {
				// 왼쪽 노드가 비어있다면?
				if (find->getLeftNode() == NULL) {
					find->setRightNode(data);
					size++; return true;
				}
				find = find->getLeftNode();
			}
		}
	}
}


template <typename T>
bool BinarySearchTree<T>::removeData(T& data) {
	// 트리에 데이터가 없을 경우
	if (root == NULL || !searchData(data)) {
		return false;
	}
	else {
		Node<T>* find = root;
		Node<T>* deleteNode = NULL;
		queue<Node<T>*> dataSet;
		int direction = -1; // 1 : 왼쪽 , 0 : 오른쪽  

		// 첫노드는 따로 체크하기
		if (root->getData() == data) {
			direction == 1;
		}

		while (true) {
			// 같은 데이터를 찾은 경우
			if (find->getLeftNode() != NULL) {
				if (find->getLeftNode()->getData() == data) { deleteNode = find; direction = 1; break; }
				dataSet.push(find->getLeftNode());
			}
			if (find->getRightNode() != NULL) {
				if (find->getRightNode()->getData() == data) { deleteNode = find; direction = 0; break; }
				dataSet.push(find->getRightNode());
			}
			if (find->getLeftNode() == NULL &&
				find->getRightNode() == NULL &&
				dataSet.size() == 0) return false;
			find = dataSet.front();
			dataSet.pop();
		}

		Node<T>* search = NULL;
		if (direction == 1) {
			// 실제 삭제될 노드
			search = deleteNode->getLeftNode();

			// 우측 노드가 없는 경우
			if (search->getRightNode() == NULL) {
				deleteNode->setLeftNode(search->getLeftNode());
				size--; return true;
			}

			// 최 우측 노드 탐색
			for (; deleteNode->getRightNode()->getRightNode() != NULL; deleteNode = deleteNode->getRightNode()) {}

			// 삭제노드의 값을 최우측 노드의 값으로 설정
			deleteNode->setLeftNode(search->getRightNode()->getRightNode());
			// 최우측 노드 부모의 오른쪽값 NULL 설정
			search->getRightNode()->setRightNode(NULL);
			size--; return true;

		}
		else if (direction == 0) {
			// 실제 삭제될 노드
			search = deleteNode->getRightNode();

			// 좌측 노드가 없는 경우
			if (search->getLeftNode() == NULL) {
				deleteNode->setRightNode(search->getRgihtNode());
				size--; return true;
			}

			// 최 좌측 노드 탐색
			for (; deleteNode->getLeftNode()->getLeftNode() != NULL; deleteNode = deleteNode->getLeftNode()) {}

			// 삭제노드의 값을 최좌측 노드의 값으로 설정
			deleteNode->setRightNode(search->getLeftNode()->getLeftNode());
			// 최우측 노드 부모의 오른쪽값 NULL 설정
			search->getLeftNode()->setLeftNode(NULL);

			size--; return true;
		}
	}
}


template <typename T>
void BinarySearchTree<T>::levelOrderPrint() {
	queue<Node<T>*> dataSet;
	Node<T>* find = root;
	while (true) {
		cout << find->getData() << "\t";
		if (find->getLeftNode() != NULL) dataSet.push(find->getLeftNode());
		if (find->getRightNode() != NULL) dataSet.push(find->getRightNode());
		if (find->getLeftNode() == NULL &&
			find->getRightNode() == NULL &&
			dataSet.size() == 0) return;
		find = dataSet.front();
		dataSet.pop();
	}
}







#endif