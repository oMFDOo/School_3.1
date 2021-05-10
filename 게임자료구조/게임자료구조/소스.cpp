#include <iostream>
#include <string>
using namespace std;

class phoneNode {
public:
    phoneNode(string name, string phonrNumber, string address, phoneNode* next = 0);
    void printPD();
    phoneNode* next_;
    string name_;
    string phoneNumber_;
    string address_;
};

class phoneBook {
public:
    phoneBook();
    bool Insert(string name, string phonrNumber, string address);
    void Delete(string name);
    phoneNode* Find(string name);
private:
    phoneNode* lst_;
};
phoneBook::phoneBook()
{
    phoneNode* lst_ = NULL;
};
phoneNode::phoneNode(string name, string phonrNumber, string address, phoneNode* next)
{
    name_ = name;
    phoneNumber_ = phonrNumber;
    address_ = address;
    next_ = next;
};
bool phoneBook::Insert(string name, string phonrNumber, string address)
{
    phoneNode* ptr = lst_;
    if (ptr == NULL)
    {
        lst_ = new phoneNode(name, phonrNumber, address, 0);
        return 1;
    }
    else
    {
        while (ptr->next_ != NULL)
        {
            ptr = ptr->next_;
        }
        ptr->next_ = new phoneNode(name, phonrNumber, address, 0);
    }

    return 1;
}
void phoneBook::Delete(string name)
{
    phoneNode* ptr = lst_;
    phoneNode* dptr;
    if (ptr->next_ == NULL && ptr->next_->name_ == name)
    {
        delete ptr;
        return;
    }
    while (ptr->next_ != NULL) {
        if (ptr->next_->name_ == name)
        {
            dptr = ptr->next_;
            ptr = ptr->next_->next_;
            delete dptr;
            return;
        }
    }

}
phoneNode* phoneBook::Find(string name)
{
    phoneNode* ptr = lst_;

    if (ptr->next_ == NULL)
    {
        return ptr;
    }
    while (ptr->next_ != NULL)
    {
        if (ptr->name_ == name)
            return ptr;
        ptr = ptr->next_;
    }
    return ptr;
}
void phoneNode::printPD() {
    cout << "name : " << name_ << " ";
    cout << "phoneNumber : " << phoneNumber_ << " ";
    cout << "address : " << address_ << " ";
}
int main() {
    phoneBook* pb = new phoneBook();
    pb->Insert("누구나", "010-2345-6789", "동의대학교");
    pb->Insert("아무개", "010-9876-5432", "동의대학교");

    phoneNode* pn;
    pn = pb->Find("누구나");
    if (pn) pn->printPD();

    pn = pb->Find("아무개");
    if (pn) pn->printPD();

    pb->Delete("아무개");

    pn = pb->Find("누구나");
    if (pn) pn->printPD();
    pn = pb->Find("아무개");
    if (pn) pn->printPD();
}