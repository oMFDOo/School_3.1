#include "BinaryTree.h"

int main() {
	/* 
	   Ʈ�� ����
		   0
		  /  \
		 1    2
		/ \     \
	   3   4     5

	*/
	BinaryTree<int>* tree = new BinaryTree<int>;
	Node<int>* root = new Node<int>(0,NULL,NULL); // root ����
	Node<int>* temp = new Node<int>(1,NULL,NULL);

	
	tree->addLeftChild(*root, *temp);

	temp = new Node<int>(2, NULL, NULL);
	tree->addRightChild(*root, *temp);

	temp = new Node<int>(3, NULL, NULL);
	tree->addLeftChild(*(root->getLeftNode()), *temp);

	temp = new Node<int>(4, NULL, NULL);
	tree->addRightChild(*(root->getLeftNode()), *temp);

	temp = new Node<int>(5, NULL, NULL);
	tree->addRightChild(*(root->getRightNode()), *temp);

	cout << endl;

	// ������ȸ
	cout << "������ȸ : ";
	tree->preOrder(*root);
	cout << endl;

	// ������ȸ
	cout << "������ȸ : ";
	tree->inOrder(*root);
	cout << endl;

	// ������ȸ
	cout << "������ȸ : ";
	tree->postOrder(*root);
	cout << endl;

	// ������ȸ
	cout << "������ȸ : ";
	tree->levelOrder(*root);
	cout << endl;

	cout << endl;

	//  ���� ����Ʈ�� ���� �� ������ȸ
	cout << "���� ����Ʈ�� ���� :\t";
	tree->delLeftChild(*root);
	tree->levelOrder(*root);
	cout << endl;

	//  ������ ����Ʈ�� ���� �� ������ȸ
	cout << "������ ����Ʈ�� ���� :\t";
	tree->delRightChild(*root);
	tree->levelOrder(*root);
	cout << endl;
}