/*

	File Name: BinarySearchTree.h
	Author: Geun-Hyung Kim

	Description:
	연결 리스트를 활용한 이진탐색트리 생성

*/

#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

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
	T getData();			       // 특정 트리 노드의 데이터 값 가져오기
	void setData(T& data);   // 특정 트리 노드의 데이터 값 대입하기
	Node<T>* getLeftNode();       	   // 특정 트리 노드의 왼쪽 자식노드의 주소 값 반환
	Node<T>* getRightNode();		       // 특정 트리 노드의 오른쪽 자식노드의 주소 값 반환
	void setLeftNode(Node<T>* node);  //왼쪽 자식노드에 트리 노드 추가 
	void setRightNode(Node<T>* node); // 오른쪽 자식노드에 트리 노드 추가 
};

template<typename T>
class BinarySearchTree {
	Node<T>* root;
	int size;

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




#endif