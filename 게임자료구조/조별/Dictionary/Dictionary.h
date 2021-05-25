#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	// 생성자
	Node(string w = "", string m = "", Node* l = nullptr, Node* r = nullptr) : word(w), mean(m), left(l), right(r) { }
	// 단어설정 : 단어, 뜻을 입력
	bool setKeyword(string w, string m) { word = w; mean = m; };
	// 단어 반환
	string getWord() { return word; };
	// 뜻 반환
	string getMean() { return mean; };
	// 왼쪽 노드 반환
	Node* getLeftNode() { return left; };
	// 오른쪽 노드 반환
	Node* getRightNdoe() { return right; };
	// 왼쪽 노드 설정 : 입력받은 노드를 왼쪽 자식노드로 이용
	bool setLeftNode(Node* n) { left = n; };
	// 오른쪽 노드 설정 : 입력받은 노드를 오른쪽 자식노드로 이용
	bool setRightNode(Node* n) { right = n; };
private:
	string word, mean;	// 단어, 뜻
	Node* left;			// 왼쪽노드
	Node* right;		// 오른쪽노드
};

class Dictionary {
public:
	Dictionary() : root(NULL) {};
	// 데이터 중복 여부 확인
	bool searchData(string d);
	// 데이터 추가
	bool insertData(string d);
	// 데이터 삭제
	bool removeData(string d);
	// 중위순회하며 데이터 출력 : 정렬된 순서로 출력하기 위함
	void inorderPrint();
private:
	Node* root;
};
