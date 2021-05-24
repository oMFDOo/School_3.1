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


template <typename T>
bool BinarySearchTree<T>::insertData(T& data) {
	Node<T> *input = new Node<T>(data);

	// �����Ͱ� ���� ���
	if (root == NULL) {
		root = input; return true;
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
					find->setRightNode(input);
					size++; return true;
				}
				find = find->getRightNode();
			}
			if (find->getData() > data) {
				// ���� ��尡 ����ִٸ�?
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
	// Ʈ���� ��� Ȥ�� ���� �����Ͱ� ���� ���
	if (root == NULL || !searchData(data)) {
		return false;
	}
	else {
		Node<T>* find = root;
		Node<T>* search = NULL;
		Node<T>* deleteNode = NULL;
		queue<Node<T>*> dataSet;
		Node<T>* parents = NULL;
		int subTree = -1; // ����Ʈ�� Ÿ��
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
		else if (deleteNode->getLeftNode() != NULL) { subTree = 0; } // ���ʸ� ����
		else if (deleteNode->getRightNode() != NULL) { subTree = 1; } // �����ʸ� ����

		// ����Ʈ�� ���� : �ܸ���� �� ���
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
		// ���� ����Ʈ���� ����
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
		// ������ ����Ʈ���� ����
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
		// ���� ����Ʈ�� ����
		if (subTree == 2) {
			if (deleteNode->getRightNode()->getLeftNode() == NULL &&
				deleteNode->getRightNode()->getRightNode() == NULL) {
				int set = deleteNode->getRightNode()->getData();
				deleteNode->setData(set);
				deleteNode->setRightNode(NULL); return true;
			}

			int isP = -1;

			// ������ ����� ���� ��� �� �� ���� ��� Ž��
			search = deleteNode->getRightNode();
			while (search->getLeftNode() != NULL) {
				if (search->getLeftNode()->getLeftNode() == NULL) {
					parents = search;
				}
				search = search->getLeftNode();
			}
			int set = search->getData();
			deleteNode->setData(set);

			// �� ���� ����� ������ ��� ���� ���ɼ�
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