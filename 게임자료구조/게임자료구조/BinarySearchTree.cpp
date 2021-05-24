#include "BinarySearchTree.h"

/* 생성 트리
 4 - 9 - 3 - 7 - 6 - 9 - 2 - 12 - 11 - 13
       4
	  / \
	 3	 9
	/   / \
   2   7  12
      /  /  \
	 6	11  13
*/
int main() {
	BinarySearchTree<int> *BST = new BinarySearchTree<int>;

	// 중복 데이터 9 존재
	int insertValue[] = { 4, 9, 3, 7, 6, 9, 2, 12, 11, 13};
	for (int i = 0; i < sizeof(insertValue) / sizeof(int); i++) {
		cout << "Insert Data : " << insertValue[i] << "   \t";
		if (BST->insertData(insertValue[i])) cout << "Succeed" << endl;
		else cout << "Fail" << endl;
	}
	BST->levelOrderPrint();
	cout << "\n\n\n";


	int find[] = { 1, 2, 3};
	for (int i = 0; i < sizeof(find) / sizeof(int); i++) {
		cout << "Data \'" << find[i] << "\' exist : ";
		if (BST->searchData(find[i])) cout << "True" << endl;
		else cout << "Fail" << endl;
	}

	cout << "\n\n";

	// 중복 삭제 데이터 4 존재
	int remove[] = { 4, 2, 9, 4 };
	for (int i = 0; i < sizeof(remove) / sizeof(int); i++) {
		cout << "Data \'" << remove[i] << "\' delete : ";
		if (BST->removeData(remove[i])) cout << "Succeed" << endl;
		else cout << "Fail" << endl;
		BST->levelOrderPrint();
		cout << "\n\n";
	}
}