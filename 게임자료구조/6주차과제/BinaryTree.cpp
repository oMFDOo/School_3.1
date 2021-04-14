#include "BinaryTree.h"

int main() {
	/* 
	   트리 구성
		   0
		  /  \
		 1    2
		/ \     \
	   3   4     5

	*/
	BinaryTree<int>* tree = new BinaryTree<int>;
	Node<int>* root = new Node<int>(0,NULL,NULL); // root 생성
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

	// 전위순회
	cout << "전위순회 : ";
	tree->preOrder(*root);
	cout << endl;

	// 중위순회
	cout << "중위순회 : ";
	tree->inOrder(*root);
	cout << endl;

	// 후위순회
	cout << "휘위순회 : ";
	tree->postOrder(*root);
	cout << endl;

	// 레벨순회
	cout << "레벨순회 : ";
	tree->levelOrder(*root);
	cout << endl;

	cout << endl;

	//  왼쪽 서브트리 삭제 후 레벨순회
	cout << "왼쪽 서브트리 삭제 :\t";
	tree->delLeftChild(*root);
	tree->levelOrder(*root);
	cout << endl;

	//  오른쪽 서브트리 삭제 후 레벨순회
	cout << "오른쪽 서브트리 삭제 :\t";
	tree->delRightChild(*root);
	tree->levelOrder(*root);
	cout << endl;
}