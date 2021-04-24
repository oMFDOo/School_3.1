/*

	File Name: BinarySearchTree.h
	Author: Geun-Hyung Kim

	Description:
	���� ����Ʈ�� Ȱ���� ����Ž��Ʈ�� ����

*/

#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

#include <iostream>
using namespace std;

template <typename T>
class Node {
	T data;         // ������ ������ ���� ����  
	Node<T>* left;  // Ʈ�� ����� ���� �ڽĳ���� �ּ� ������ ���� ����
	Node<T>* right; // Ʈ�� ����� ������ �ڽĳ���� �ּ� ������ ���� ���� 
public:
	Node(T d = 0, Node<T>* l = NULL, Node<T>* r = NULL) : data(d), left(NULL), right(NULL) {}
	~Node() {}
	T getData();			       // Ư�� Ʈ�� ����� ������ �� ��������
	void setData(T& data);   // Ư�� Ʈ�� ����� ������ �� �����ϱ�
	Node<T>* getLeftNode();       	   // Ư�� Ʈ�� ����� ���� �ڽĳ���� �ּ� �� ��ȯ
	Node<T>* getRightNode();		       // Ư�� Ʈ�� ����� ������ �ڽĳ���� �ּ� �� ��ȯ
	void setLeftNode(Node<T>* node);  //���� �ڽĳ�忡 Ʈ�� ��� �߰� 
	void setRightNode(Node<T>* node); // ������ �ڽĳ�忡 Ʈ�� ��� �߰� 
};

template<typename T>
class BinarySearchTree {
	Node<T>* root;
	int size;

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




#endif