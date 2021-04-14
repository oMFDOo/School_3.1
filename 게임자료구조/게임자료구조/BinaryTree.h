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
using namespace std;

template <typename T>
class Node {
	T data;         // 데이터 저장을 위한 변수  
	Node<T>* left;  // 트리 노드의 왼쪽 자식노드의 주소 저장을 위한 변수
	Node<T>* right; // 트리 노드의 오른쪽 자식노드의 주소 저장을 위한 변수 
public:
	Node(T d = 0, Node<T>* l = NULL, Node<T>* r = NULL) : data(d), left(NULL), right(NULL) {}
	~Node() {}
	T getData();					  // 특정 트리 노드의 데이터 값 가져오기
	void setData(T& data);			  // 특정 트리 노드의 데이터 값 대입하기
	Node<T>* getLeftNode();       	  // 특정 트리 노드의 왼쪽 자식노드의 주소 값 반환
	Node<T>* getRightNode();		  // 특정 트리 노드의 오른쪽 자식노드의 주소 값 반환
	void setLeftNode(Node<T>* node);  //왼쪽 자식노드에 트리 노드 추가 
	void setRightNode(Node<T>* node); // 오른쪽 자식노드에 트리 노드 추가 
};

template<typename T>
class BinaryTree {
	Node<T>* root;  // 트리의 루트 노드의 주소 저장을 위한 변수 
	int size;		// 트리의 노드 개수 저장을 위한 변수 
public:
	BinaryTree() : size(0), root(NULL) {};
	~BinaryTree();
	bool searchData(T& data);                           // 트리에서 d의 데이터 값이 있으면 true 반환, 없으면 false 반환
	void addLeftChild(Node<T>& parent, Node<T>& node);  // parent 노드의 왼쪽 자식에 node 추가하기
	void addRightChild(Node<T>& parent, Node<T>& node); // parent 노드의 오로쪽 자식에 node 추가하기
	void delLeftChild(Node<T>& parent);                 // parent 노드의 왼쪽 서브트리 제거
	void delRightChild(Node<T>& parent);			    // parent 노드의 오른쪽 서브트리 제거
	void preOrder(Node<T>& r);		 //r 노드를 루트로 하는 서브트리 전위 순회
	void inOrder(Node<T>& r);		 //r 노드를 루트로 하는 서브트리 중위 순회 		
	void postOrder(Node<T>& r);      //r 노드를 루트로 하는 서브트리 후위 순회
	void levelOrder(Node<T>& r);     //r 노드를 루트로 하는 서브트리 레벨 순회
};

///////////////////////////////////////////////////////////////////////////////
//  이 다음 줄에 구현을 하거나 class 정의에 작성하시오.
///////////////////////////////////////////////////////////////////////////////


#endif