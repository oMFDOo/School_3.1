#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	// ������
	Node(string w = "", string m = "", Node* l = nullptr, Node* r = nullptr) : word(w), mean(m), left(l), right(r) { }
	// �ܾ�� : �ܾ�, ���� �Է�
	bool setKeyword(string w, string m) { word = w; mean = m; };
	// �ܾ� ��ȯ
	string getWord() { return word; };
	// �� ��ȯ
	string getMean() { return mean; };
	// ���� ��� ��ȯ
	Node* getLeftNode() { return left; };
	// ������ ��� ��ȯ
	Node* getRightNdoe() { return right; };
	// ���� ��� ���� : �Է¹��� ��带 ���� �ڽĳ��� �̿�
	bool setLeftNode(Node* n) { left = n; };
	// ������ ��� ���� : �Է¹��� ��带 ������ �ڽĳ��� �̿�
	bool setRightNode(Node* n) { right = n; };
private:
	string word, mean;	// �ܾ�, ��
	Node* left;			// ���ʳ��
	Node* right;		// �����ʳ��
};

class Dictionary {
public:
	Dictionary() : root(NULL) {};
	// ������ �ߺ� ���� Ȯ��
	bool searchData(string d);
	// ������ �߰�
	bool insertData(string d);
	// ������ ����
	bool removeData(string d);
	// ������ȸ�ϸ� ������ ��� : ���ĵ� ������ ����ϱ� ����
	void inorderPrint();
private:
	Node* root;
};
