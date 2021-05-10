#include <iostream>
#include <string>
using namespace std;

class phoneNode {
public:
	phoneNode(string name, string phonrNumber, string address, phoneNode* next = 0); // 현재 노드 값 출력
	void printPD();
	phoneNode* next_; //다음 노드를 가리킴
	string name_;
	string phoneNumber_;
	string address_;
};

class phoneBook { // 전화번호 정보 노드 집합 클래스
public:
	phoneBook();
	bool Insert(string name, string phonrNumber, string address);
	void Delete(string name);
	phoneNode* Find(string name);
private:
	phoneNode* lst_;
};

// 여기부터 제출
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
//여기까지 제출
int main() {
	phoneBook* pb = new phoneBook();
	pb->Insert("누구나", "010-2345-6789", "동의대학교");
	pb->Insert("아무개", "010-9876-5432", "동의대학교");

	phoneNode* pn;
	pn = pb->Find("누구나");
	if (pn) pn->printPD();

	pn = pb->Find("아무개");
	if (pn) pn->printPD();

	pb->Delete("아무개");  // 여기서 아무개가 지워지니까 다음 출력에서 아무개 나오면 안됨

	pn = pb->Find("누구나");
	if (pn) pn->printPD();
	pn = pb->Find("아무개");
	if (pn) pn->printPD();
}