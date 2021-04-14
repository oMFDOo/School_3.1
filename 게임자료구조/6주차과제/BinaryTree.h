/*
	File Name: BinaryTree.h
	Author: Geun-Hyung Kim

	Description:
	링크드리스트를 활용한 이진트리 생성
*/

// Tree Node
#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class Node {
	T data;         // 데이터 저장을 위한 변수  
	Node<T>* left;  // 트리 노드의 왼쪽 자식노드의 주소 저장을 위한 변수
	Node<T>* right; // 트리 노드의 오른쪽 자식노드의 주소 저장을 위한 변수 
public:
	Node(T d = 0, Node<T>* l = NULL, Node<T>* r = NULL) : data(d), left(NULL), right(NULL) {}
	~Node() {}
	// 특정 트리 노드의 데이터 값 가져오기
	T getData() { return data; }
	// 특정 트리 노드의 데이터 값 대입하기
	void setData(T& data) { this->data = data; }
	// 특정 트리 노드의 왼쪽 자식노드의 주소 값 반환
	Node<T>* getLeftNode() { if (left == NULL) return NULL; return left; }
	// 특정 트리 노드의 오른쪽 자식노드의 주소 값 반환
	Node<T>* getRightNode() { if (right == NULL) return NULL; return right; }
	//왼쪽 자식노드에 트리 노드 추가 
	void setLeftNode(Node<T>* node) { left = node; }
	// 오른쪽 자식노드에 트리 노드 추가 
	void setRightNode(Node<T>* node) { right = node; }
};

template<typename T>
class BinaryTree {
	Node<T>* root; // 트리의 루트 노드의 주소 저장을 위한 변수 
	int size;   // 트리의 노드 개수 저장을 위한 변수   
public:
	BinaryTree() : size(0), root(NULL) {};
	~BinaryTree();
	// 트리에서 d의 데이터 값이 있으면 true 반환, 없으면 false 반환
	bool searchData(T& data) {
		queue<Node<T>*> dataSet;
		Node<T>* find = root;
		while(true) {
			if (find->getLeftNode() != NULL) dataSet.push(find->getLeftNode());
			if (find->getRightNode() != NULL) dataSet.push(find->getRightNode());
			if (find->getLeftNode() == NULL && find->getRightNode() == NULL && dataSet.size == 0) return false;
			delete find;
			find = dataSet.front();
			dataSet.pop();
		}
	}

	// parent 노드의 왼쪽 자식에 node 추가하기
	void addLeftChild(Node<T>& parent, Node<T>& node) {
		parent.setLeftNode(&node);
		size++;
	}
	// parent 노드의 오로쪽 자식에 node 추가하기
	void addRightChild(Node<T>& parent, Node<T>& node) {
		parent.setRightNode(&node);
		size++;
	}

	// parent 노드의 왼쪽 서브트리 제거
	void delLeftChild(Node<T>& parent) {
		queue<Node<T>*> dataSet;
		Node<T>* find = parent.getLeftNode();
		while (true) {
			if (find->getLeftNode() != NULL) { 
				dataSet.push(find->getLeftNode()); 
				find->setLeftNode(NULL); 
			}
			if (find->getRightNode() != NULL) { 
				dataSet.push(find->getRightNode()); 
				find->setRightNode(NULL); 
			}
			if (find->getLeftNode() == NULL && 
				find->getRightNode() == NULL && 
				dataSet.size() == 0) {
				parent.setLeftNode(NULL); 
				return; 
			}
			delete find;
			find = NULL;
			size--;
			find = dataSet.front();
			dataSet.pop();
		}
	}

	// parent 노드의 오른쪽 서브트리 제거
	void delRightChild(Node<T>& parent) {
		queue<Node<T>*> dataSet;
		Node<T>* find = parent.getRightNode();
		while (true) {
			if (find->getLeftNode() != NULL) { 
				dataSet.push(find->getLeftNode()); 
				find->setLeftNode(NULL); 
			}
			if (find->getRightNode() != NULL) { 
				dataSet.push(find->getRightNode()); 
				find->setRightNode(NULL); 
			}
			if (find->getLeftNode() == NULL && 
				find->getRightNode() == NULL && 
				dataSet.size() == 0) { 
				parent.setRightNode(NULL); 
				return; 
			}
			delete find;
			find = NULL;
			size--;
			find = dataSet.front();
			dataSet.pop();
		}
	}

	//r 노드를 루트로 하는 서브트리 전위 순회
	void preOrder(Node<T>& r) {
		cout << r.getData() << "\t";
		if (r.getLeftNode() != NULL) {
			preOrder(*(r.getLeftNode()));
		}
		if (r.getRightNode() != NULL) {
			preOrder(*(r.getRightNode()));
		}
	}
	//r 노드를 루트로 하는 서브트리 중위 순회 		
	void inOrder(Node<T>& r) {
		if (r.getLeftNode() != NULL) {
			inOrder(*(r.getLeftNode()));
		}
		cout << r.getData() << "\t";
		if (r.getRightNode() != NULL) {
			inOrder(*(r.getRightNode()));
		}
	}
	//r 노드를 루트로 하는 서브트리 후위 순회
	void postOrder(Node<T>& r) {
		if (r.getLeftNode() != NULL) {
			postOrder(*(r.getLeftNode()));
		}
		if (r.getRightNode() != NULL) {
			postOrder(*(r.getRightNode()));
		}
		cout << r.getData() << "\t";
	}
	//r 노드를 루트로 하는 서브트리 레벨 순회
	void levelOrder(Node<T>& r) {
		queue<Node<T>*> dataSet;
		Node<T>* find = &r;
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
};

///////////////////////////////////////////////////////////////////////////////
//  이 다음 줄에 구현을 하거나 class 정의에 작성하시오.
///////////////////////////////////////////////////////////////////////////////


#endif 

