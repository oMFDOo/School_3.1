#pragma once
/*

	File Name: BinarySearchTree.h
	Author: Geun-Hyung Kim

	Description:
	���� ����Ʈ�� Ȱ���� ����Ž��Ʈ�� ����

*/

#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node {
	T data;         // ������ ������ ���� ����  
	Node<T>* left;  // Ʈ�� ����� ���� �ڽĳ���� �ּ� ������ ���� ����
	Node<T>* right; // Ʈ�� ����� ������ �ڽĳ���� �ּ� ������ ���� ���� 
public:
	Node(T d = 0, Node<T>* l = NULL, Node<T>* r = NULL) : data(d), left(NULL), right(NULL) {}
	~Node() {}
	T getData();					 // Ư�� Ʈ�� ����� ������ �� ��������
	void setData(T& data);			 // Ư�� Ʈ�� ����� ������ �� �����ϱ�
	Node<T>* getLeftNode();       	 // Ư�� Ʈ�� ����� ���� �ڽĳ���� �ּ� �� ��ȯ
	Node<T>* getRightNode();		 // Ư�� Ʈ�� ����� ������ �ڽĳ���� �ּ� �� ��ȯ
	void setLeftNode(Node<T>* node);  //���� �ڽĳ�忡 Ʈ�� ��� �߰� 
	void setRightNode(Node<T>* node); // ������ �ڽĳ�忡 Ʈ�� ��� �߰� 
	bool levelFind(int type);  // type : ��ȯ���� ����
};

template<typename T>
class BinarySearchTree {
	Node<T>* root;
	int size;	// ���� Ʈ���� ��� ����

public:
	BinarySearchTree() : size(0), root(NULL) {};
	~BinarySearchTree();
	// Ư�� Ʈ������ �����͸� ã�Ƽ� �����ϸ� true, �������� ������ false�� ��ȯ 
	bool searchData(T& data);
	// Ʈ���� �Է��� �������� ��� �߰� (�̹� �����Ͱ� ������ false, ��ȯ �����Ͱ� �߰��Ǹ� true ��ȯ)
	bool insertData(T& data);
	// Ʈ������ �Է��� �������� ��� ���� (Ʈ���� ���� �����͸� �����ϰ��� �ϸ� false, ������ ������ �����ϸ� true ��ȯ)
	bool removeData(T& data);
	// Ʈ���� root���� ���� ���� ������ ������ ���� ���
	void levelOrderPrint();
};

// NODE Ŭ���� �Լ� ����

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


// BinarySearchTree Ŭ���� �Լ� ����


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


// Q. ������ ������ ��ȯ���� �� Bool�ΰ���?
template <typename T>
bool BinarySearchTree<T>::insertData(T& data) {
	// �����Ͱ� ���� ���
	if (root == NULL) {
		root = new Node<T>(data); return true;
	}
	else if (searchData(data)) {
		return false;
	}
	else {
		Node<T>* find = root;
		for (;;) {
			// ���������� ����
			if (find->getData() < data) {
				// ������ ��尡 ����ִٸ�?
				if (find->getRightNode() == NULL) {
					find->setRightNode(data);
					size++; return true;
				}
				find = find->getRightNode();
			}
			if (find->getData() >= data) {
				// ���� ��尡 ����ִٸ�?
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
	// Ʈ���� �����Ͱ� ���� ���
	if (root == NULL || !searchData(data)) {
		return false;
	}
	else {
		Node<T>* find = root;
		Node<T>* deleteNode = NULL;
		queue<Node<T>*> dataSet;
		int direction = -1; // 1 : ���� , 0 : ������  

		// ù���� ���� üũ�ϱ�
		if (root->getData() == data) {
			direction == 1;
		}

		while (true) {
			// ���� �����͸� ã�� ���
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
			// ���� ������ ���
			search = deleteNode->getLeftNode();

			// ���� ��尡 ���� ���
			if (search->getRightNode() == NULL) {
				deleteNode->setLeftNode(search->getLeftNode());
				size--; return true;
			}

			// �� ���� ��� Ž��
			for (; deleteNode->getRightNode()->getRightNode() != NULL; deleteNode = deleteNode->getRightNode()) {}

			// ��������� ���� �ֿ��� ����� ������ ����
			deleteNode->setLeftNode(search->getRightNode()->getRightNode());
			// �ֿ��� ��� �θ��� �����ʰ� NULL ����
			search->getRightNode()->setRightNode(NULL);
			size--; return true;

		}
		else if (direction == 0) {
			// ���� ������ ���
			search = deleteNode->getRightNode();

			// ���� ��尡 ���� ���
			if (search->getLeftNode() == NULL) {
				deleteNode->setRightNode(search->getRgihtNode());
				size--; return true;
			}

			// �� ���� ��� Ž��
			for (; deleteNode->getLeftNode()->getLeftNode() != NULL; deleteNode = deleteNode->getLeftNode()) {}

			// ��������� ���� ������ ����� ������ ����
			deleteNode->setRightNode(search->getLeftNode()->getLeftNode());
			// �ֿ��� ��� �θ��� �����ʰ� NULL ����
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