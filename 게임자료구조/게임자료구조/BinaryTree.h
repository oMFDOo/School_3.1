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
using namespace std;

template <typename T>
class Node {
	T data;         // ������ ������ ���� ����  
	Node<T>* left;  // Ʈ�� ����� ���� �ڽĳ���� �ּ� ������ ���� ����
	Node<T>* right; // Ʈ�� ����� ������ �ڽĳ���� �ּ� ������ ���� ���� 
public:
	Node(T d = 0, Node<T>* l = NULL, Node<T>* r = NULL) : data(d), left(NULL), right(NULL) {}
	~Node() {}
	T getData();					  // Ư�� Ʈ�� ����� ������ �� ��������
	void setData(T& data);			  // Ư�� Ʈ�� ����� ������ �� �����ϱ�
	Node<T>* getLeftNode();       	  // Ư�� Ʈ�� ����� ���� �ڽĳ���� �ּ� �� ��ȯ
	Node<T>* getRightNode();		  // Ư�� Ʈ�� ����� ������ �ڽĳ���� �ּ� �� ��ȯ
	void setLeftNode(Node<T>* node);  //���� �ڽĳ�忡 Ʈ�� ��� �߰� 
	void setRightNode(Node<T>* node); // ������ �ڽĳ�忡 Ʈ�� ��� �߰� 
};

template<typename T>
class BinaryTree {
	Node<T>* root;  // Ʈ���� ��Ʈ ����� �ּ� ������ ���� ���� 
	int size;		// Ʈ���� ��� ���� ������ ���� ���� 
public:
	BinaryTree() : size(0), root(NULL) {};
	~BinaryTree();
	bool searchData(T& data);                           // Ʈ������ d�� ������ ���� ������ true ��ȯ, ������ false ��ȯ
	void addLeftChild(Node<T>& parent, Node<T>& node);  // parent ����� ���� �ڽĿ� node �߰��ϱ�
	void addRightChild(Node<T>& parent, Node<T>& node); // parent ����� ������ �ڽĿ� node �߰��ϱ�
	void delLeftChild(Node<T>& parent);                 // parent ����� ���� ����Ʈ�� ����
	void delRightChild(Node<T>& parent);			    // parent ����� ������ ����Ʈ�� ����
	void preOrder(Node<T>& r);		 //r ��带 ��Ʈ�� �ϴ� ����Ʈ�� ���� ��ȸ
	void inOrder(Node<T>& r);		 //r ��带 ��Ʈ�� �ϴ� ����Ʈ�� ���� ��ȸ 		
	void postOrder(Node<T>& r);      //r ��带 ��Ʈ�� �ϴ� ����Ʈ�� ���� ��ȸ
	void levelOrder(Node<T>& r);     //r ��带 ��Ʈ�� �ϴ� ����Ʈ�� ���� ��ȸ
};

///////////////////////////////////////////////////////////////////////////////
//  �� ���� �ٿ� ������ �ϰų� class ���ǿ� �ۼ��Ͻÿ�.
///////////////////////////////////////////////////////////////////////////////


#endif