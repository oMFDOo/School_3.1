/*
	File Name: BinaryTree.h
	Author: Geun-Hyung Kim

	Description:
	��ũ�帮��Ʈ�� Ȱ���� ����Ʈ�� ����
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
	T data;         // ������ ������ ���� ����  
	Node<T>* left;  // Ʈ�� ����� ���� �ڽĳ���� �ּ� ������ ���� ����
	Node<T>* right; // Ʈ�� ����� ������ �ڽĳ���� �ּ� ������ ���� ���� 
public:
	Node(T d = 0, Node<T>* l = NULL, Node<T>* r = NULL) : data(d), left(NULL), right(NULL) {}
	~Node() {}
	// Ư�� Ʈ�� ����� ������ �� ��������
	T getData() { return data; }
	// Ư�� Ʈ�� ����� ������ �� �����ϱ�
	void setData(T& data) { this->data = data; }
	// Ư�� Ʈ�� ����� ���� �ڽĳ���� �ּ� �� ��ȯ
	Node<T>* getLeftNode() { if (left == NULL) return NULL; return left; }
	// Ư�� Ʈ�� ����� ������ �ڽĳ���� �ּ� �� ��ȯ
	Node<T>* getRightNode() { if (right == NULL) return NULL; return right; }
	//���� �ڽĳ�忡 Ʈ�� ��� �߰� 
	void setLeftNode(Node<T>* node) { left = node; }
	// ������ �ڽĳ�忡 Ʈ�� ��� �߰� 
	void setRightNode(Node<T>* node) { right = node; }
};

template<typename T>
class BinaryTree {
	Node<T>* root; // Ʈ���� ��Ʈ ����� �ּ� ������ ���� ���� 
	int size;   // Ʈ���� ��� ���� ������ ���� ����   
public:
	BinaryTree() : size(0), root(NULL) {};
	~BinaryTree();
	// Ʈ������ d�� ������ ���� ������ true ��ȯ, ������ false ��ȯ
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

	// parent ����� ���� �ڽĿ� node �߰��ϱ�
	void addLeftChild(Node<T>& parent, Node<T>& node) {
		parent.setLeftNode(&node);
		size++;
	}
	// parent ����� ������ �ڽĿ� node �߰��ϱ�
	void addRightChild(Node<T>& parent, Node<T>& node) {
		parent.setRightNode(&node);
		size++;
	}

	// parent ����� ���� ����Ʈ�� ����
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

	// parent ����� ������ ����Ʈ�� ����
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

	//r ��带 ��Ʈ�� �ϴ� ����Ʈ�� ���� ��ȸ
	void preOrder(Node<T>& r) {
		cout << r.getData() << "\t";
		if (r.getLeftNode() != NULL) {
			preOrder(*(r.getLeftNode()));
		}
		if (r.getRightNode() != NULL) {
			preOrder(*(r.getRightNode()));
		}
	}
	//r ��带 ��Ʈ�� �ϴ� ����Ʈ�� ���� ��ȸ 		
	void inOrder(Node<T>& r) {
		if (r.getLeftNode() != NULL) {
			inOrder(*(r.getLeftNode()));
		}
		cout << r.getData() << "\t";
		if (r.getRightNode() != NULL) {
			inOrder(*(r.getRightNode()));
		}
	}
	//r ��带 ��Ʈ�� �ϴ� ����Ʈ�� ���� ��ȸ
	void postOrder(Node<T>& r) {
		if (r.getLeftNode() != NULL) {
			postOrder(*(r.getLeftNode()));
		}
		if (r.getRightNode() != NULL) {
			postOrder(*(r.getRightNode()));
		}
		cout << r.getData() << "\t";
	}
	//r ��带 ��Ʈ�� �ϴ� ����Ʈ�� ���� ��ȸ
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
//  �� ���� �ٿ� ������ �ϰų� class ���ǿ� �ۼ��Ͻÿ�.
///////////////////////////////////////////////////////////////////////////////


#endif 

