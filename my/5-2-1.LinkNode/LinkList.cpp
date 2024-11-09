#include <iostream>
using namespace std;


struct LinkNode {
    int data;
    LinkNode *pNext; 
};

class LinkList_with_head
{
public:
    LinkList_with_head() {
        pHead = new LinkNode;
        if (pHead == nullptr) {
            cout << "fail to new LinkNode" << endl;
        }
        pHead->data = -1;
        pHead->pNext = nullptr;
    }

    ~LinkList_with_head() {
        LinkNode *pDel = nullptr;
        LinkNode *pTmp = pHead;
        while (pTmp->pNext != nullptr) {
            pDel = pTmp;
            pTmp = pTmp->pNext;
            delete pDel;
        }

        delete pHead;
    }
public:
    bool is_Empty() {
        return pHead->pNext == nullptr ? true : false;
    }

    void display() {
        if (this->is_Empty()) {
            cout << "no node" << endl;
            return;
        }

        LinkNode *pTmp = pHead->pNext;
        while (pTmp != nullptr) {
            cout << pTmp->data << " " << endl;
            pTmp = pTmp->pNext;
        }
    }

    // add
    void push_back(int data) {
        LinkNode *pNew = new LinkNode;
        LinkNode *pTmp = pHead;

        pNew->data = data;
        pNew->pNext = nullptr;

        while (pTmp->pNext != nullptr) {
            pTmp = pTmp->pNext;
        }
        
        pTmp->pNext = pNew;
    }

    void push_front(int data) {
        LinkNode *pNew = new LinkNode;
        if (pHead->pNext == nullptr) {
            push_back(data);
            return;
        }

        pNew->data = data;
        pNew->pNext = pHead->pNext;

        pHead->pNext = pNew;
    }

    void insert(int pos, int data) {
        int idx = 0;
        LinkNode *pTmp = pHead;
        LinkNode *pNew = new LinkNode;

        while (pTmp->pNext != nullptr) {
            if (idx == pos - 1) { // pos > len, pop_back
                break;
            }
            idx++;
            pTmp = pTmp->pNext;
        }
        if (pTmp->pNext == nullptr) {
            this->push_back(data);
            return;
        }
        pNew->data = data;
        pNew->pNext = pTmp->pNext;
        pTmp->pNext = pNew;
    }

    // del
    void pop_back() {
        if (this->is_Empty()) {
            cout << "no node" << endl;
            return;
        }

        LinkNode *pTmp = pHead->pNext;
        if (pTmp->pNext == nullptr) {
            delete pTmp;
            pHead->pNext = nullptr;
            return;
        }
        while (pTmp->pNext->pNext != nullptr) {
            pTmp = pTmp->pNext;
        }
        delete pTmp->pNext;
        pTmp->pNext = nullptr;
    }

    void pop_front() {
        if (this->is_Empty()) {
            cout << "no node" << endl;
            return;
        }
        if (pHead->pNext->pNext == nullptr) {
            pop_back();
            return;
        }

        LinkNode *pTmp = pHead->pNext;
        pHead->pNext = pHead->pNext->pNext;
        delete pTmp;
    }

    void remove(int pos) {
        if (this->is_Empty()) {
            cout << "no node" << endl;
            return;
        }
        if (pos == 1) {
            this->pop_front();
            return;
        }
        int idx = 0;
        LinkNode *pDel = nullptr;
        LinkNode *pTmp = pHead;
        while (pTmp->pNext != nullptr) {
            if (idx == pos - 1) {
                break;
            }
            idx++;
            pTmp = pTmp->pNext;
        }
        if (pTmp->pNext == nullptr) {
            this->pop_back();
            return;
        } else {
            pDel = pTmp->pNext;
            pTmp->pNext = pTmp->pNext->pNext;
            delete pDel;
        }
    }

private:
    LinkNode *pHead;
};


int main() {

    cout <<  "=====================================" << endl;
    LinkList_with_head my_linklist;
    my_linklist.display();

    cout <<  "=====================================" << endl;
    my_linklist.push_back(100);
    my_linklist.push_front(10);
    my_linklist.insert(3, 1);
    my_linklist.display();

    cout <<  "=====================================" << endl;
    my_linklist.pop_front();
    my_linklist.display();

    cout <<  "=====================================" << endl;
    my_linklist.pop_back();
    my_linklist.display();

    cout <<  "=====================================" << endl;
    my_linklist.push_back(100);
    my_linklist.push_back(100);
    my_linklist.remove(2);
    my_linklist.display();

    cout <<  "=====================================" << endl;
    my_linklist.push_back(100);
    my_linklist.push_front(100);
    my_linklist.display();


    return 0;
}