#include <iostream>
#include <string>
using namespace std;

class phoneNode {
public:
	phoneNode(string name, string phonrNumber, string address, phoneNode* next = 0); // ���� ��� �� ���
	void printPD();
	phoneNode* next_; //���� ��带 ����Ŵ
	string name_;
	string phoneNumber_;
	string address_;
};

class phoneBook { // ��ȭ��ȣ ���� ��� ���� Ŭ����
public:
	phoneBook();
	bool Insert(string name, string phonrNumber, string address);
	void Delete(string name);
	phoneNode* Find(string name);
private:
	phoneNode* lst_;
};

// ������� ����
phoneNode::phoneNode(string name, string phonrNumber, string address, phoneNode* next) {
	this->name_ = name;
	this->phoneNumber_ = phonrNumber;
	this->address_ = address;
	this->next_ = next;
};
phoneNode* phoneBook::Find(string name) {
	phoneNode* Find = lst_;
	for (; Find != NULL; Find = Find->next_) {
		if (Find->name_ == name) {
			return Find;
		}
	}
	return NULL;
}

phoneBook::phoneBook() {
	lst_ = NULL;
}

void
phoneNode::printPD() {
	cout << "\"" << name_ << "\", " << "\"" << phoneNumber_ << "\", " << "\"" << address_ << "\"" << endl;
}

bool
phoneBook::Insert(string name, string phonrNumber, string address) {
	if (lst_ == NULL) {
		lst_ = new phoneNode(name, phonrNumber, address, 0);
		return true;
	}
	phoneNode* Find = lst_;
	for (; Find->next_ != NULL; Find = Find->next_) {
	}
	Find->next_ = new phoneNode(name, phonrNumber, address);
	return true;
}

void
phoneBook::Delete(string name) {
	phoneNode* ptr = lst_;
	if (lst_ == NULL) return;
	if (lst_ != NULL) {
		phoneNode* Find = lst_;
		for (; Find->next_ != NULL; Find = Find->next_) {
			if (Find->next_->name_ == name) {
				Find->next_ = Find->next_->next_;
			}
		}

	}
}
//������� ����
int main() {
	phoneBook* pb = new phoneBook();
	pb->Insert("������", "010-2345-6789", "���Ǵ��б�");
	pb->Insert("�ƹ���", "010-9876-5432", "���Ǵ��б�");

	phoneNode* pn;
	pn = pb->Find("������");
	if (pn) pn->printPD();

	pn = pb->Find("�ƹ���");
	if (pn) pn->printPD();

	pb->Delete("�ƹ���");  // ���⼭ �ƹ����� �������ϱ� ���� ��¿��� �ƹ��� ������ �ȵ�

	pn = pb->Find("������");
	if (pn) pn->printPD();
	pn = pb->Find("�ƹ���");
	if (pn) pn->printPD();
}