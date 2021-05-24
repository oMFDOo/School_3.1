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
	return data;
}

template <typename T>
void Node<T>::setData(T& d) {
	data = d;
}

template <typename T>
Node<T>* Node<T>::getLeftNode() {
	return left;
}

template <typename T>
Node<T>* Node<T>::getRightNode() {
	return right;
}

template <typename T>
void Node<T>::setLeftNode(Node<T>* node) {
	left = node;
}

template <typename T>
void Node<T>::setRightNode(Node<T>* node) {
	right = node;
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


template <typename T>
bool BinarySearchTree<T>::insertData(T& data) {
	Node<T> *input = new Node<T>(data);

	// 데이터가 없을 경우
	if (root == NULL) {
		root = input; return true;
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
					find->setRightNode(input);
					size++; return true;
				}
				find = find->getRightNode();
			}
			if (find->getData() > data) {
				// 왼쪽 노드가 비어있다면?
				if (find->getLeftNode() == NULL) {
					find->setLeftNode(input);
					size++; return true;
				}
				find = find->getLeftNode();
			}
		}
	}
}


template <typename T>
bool BinarySearchTree<T>::removeData(T& data) {
	// 트리에 노드 혹은 동일 데이터가 없을 경우
	if (root == NULL || !searchData(data)) {
		return false;
	}
	else {
		Node<T>* find = root;
		Node<T>* search = NULL;
		Node<T>* deleteNode = NULL;
		queue<Node<T>*> dataSet;
		Node<T>* parents = NULL;
		int subTree = -1; // 서브트리 타입
		while (true) {
			if (find->getData() == data) { deleteNode = find; break; }
			if (find->getLeftNode() != NULL) {
				if (find->getLeftNode()->getData() == data) { parents = find; }
				dataSet.push(find->getLeftNode());
			} 
			if (find->getRightNode() != NULL) {
				if (find->getRightNode()->getData() == data) { parents = find; }
				dataSet.push(find->getRightNode());
			}
			if (find->getLeftNode() == NULL &&
				find->getRightNode() == NULL &&
				dataSet.size() == 0) return false;
			find = dataSet.front();
			dataSet.pop();
		}

		if (deleteNode->getLeftNode() == NULL && deleteNode->getRightNode() == NULL) { subTree = -1;}
		else if(deleteNode->getLeftNode() != NULL && deleteNode->getRightNode() != NULL) { subTree = 2; }
		else if (deleteNode->getLeftNode() != NULL) { subTree = 0; } // 왼쪽만 존재
		else if (deleteNode->getRightNode() != NULL) { subTree = 1; } // 오른쪽만 존재

		// 서브트리 없음 : 단말노드 일 경우
		if (subTree == -1) {
			if (parents->getRightNode() != NULL) {
				if (parents->getRightNode()->getData() == data) {
					parents->setRightNode(NULL); delete deleteNode; return true;
				}
			}
			if (parents->getLeftNode() != NULL) {
				if (parents->getLeftNode()->getData() == data) {
					parents->setLeftNode(NULL); delete deleteNode; return true;
				}
			}
		}
		// 왼쪽 서브트리만 존재
		if (subTree == 0) {
			if (parents->getRightNode() != NULL) {
				if (parents->getRightNode()->getData() == data) {
					parents->setRightNode(deleteNode->getLeftNode()); delete deleteNode; return true;
				}
			}
			if (parents->getLeftNode() != NULL) {
				if (parents->getLeftNode()->getData() == data) {
					parents->setLeftNode(deleteNode->getLeftNode()); delete deleteNode; return true;
				}
			}
		}
		// 오른쪽 서브트리만 존재
		if (subTree == 1) {
			if (parents->getRightNode() != NULL) {
				if (parents->getRightNode()->getData() == data) {
					parents->setRightNode(deleteNode->getRightNode()); delete deleteNode; return true;
				}
			}
			if (parents->getLeftNode() != NULL) {
				if (parents->getLeftNode()->getData() == data) {
					parents->setLeftNode(deleteNode->getRightNode()); delete deleteNode; return true;
				}
			}
		}
		// 양쪽 서브트리 존재
		if (subTree == 2) {
			if (deleteNode->getRightNode()->getLeftNode() == NULL &&
				deleteNode->getRightNode()->getRightNode() == NULL) {
				int set = deleteNode->getRightNode()->getData();
				deleteNode->setData(set);
				deleteNode->setRightNode(NULL); return true;
			}

			int isP = -1;

			// 삭제할 노드의 우측 노드 중 최 좌측 노드 탐색
			search = deleteNode->getRightNode();
			while (search->getLeftNode() != NULL) {
				if (search->getLeftNode()->getLeftNode() == NULL) {
					parents = search;
				}
				search = search->getLeftNode();
			}
			int set = search->getData();
			deleteNode->setData(set);

			// 최 좌측 노드의 오른쪽 노드 존재 가능성
			if (search->getRightNode() != NULL) {
				parents->setLeftNode(search->getRightNode());
			}
			else {
				parents->setLeftNode(NULL);
			}
			return true;
		}
	}
	return false;
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