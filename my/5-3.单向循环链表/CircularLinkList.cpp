# include <iostream>
# include "CircularLinkList.h"
using namespace std;


LoopLinkList::LoopLinkList() : m_head(new Node)
{
    // 构造, 头节点指向自己 -> 环
    m_head->next = m_head;
    m_tail = m_head;
}

LoopLinkList::~LoopLinkList() {
    Node* p = m_head->next;

    // 循环, 以 m_head 作为终止条件
    while (p != m_head) {
        Node* pDel = p;
        p = p->next;
        delete pDel;
    }
    
    delete m_head;
}

bool LoopLinkList::isEmpty() {
    if (m_length == 0) {
        return true;
    } else {
        return false;
    }
}

int LoopLinkList::length() {
    return m_length;
}

void LoopLinkList::prepend(int data) {
    
    // 创建新节点
    Node* pNode = new Node;
    if (pNode == nullptr) {
        perror("fail to create new node\n");
        return;
    }

    // 初始化新节点, 新节点指向头节点的next
    pNode->data = data;
    pNode->next = m_head->next;

    // 第一次插入, 该节点成为尾节点
    if (m_length == 0) {
        m_tail = pNode;
    }
    
    // 原头节点指向新节点
    m_head->next = pNode;
    m_length++;
}

void LoopLinkList::append(int data) {

    // 创建新节点
    Node* pNode = new Node;
    if (pNode == nullptr) {
        perror("fail to create new node\n");
        return;
    }

    // 初始化新节点, 新节点指向尾节点的下一个(头节点的下一个)
    pNode->data = data;
    pNode->next = m_tail->next;
    
    // 原尾节点指向新节点
    // 新节点成为尾节点
    m_tail->next = pNode;
    m_tail = pNode;
    m_length++;
}

bool LoopLinkList::insert(int pos, int data) {
    
    // 判断pos合法性
    if (pos < 1 || pos > length() + 1)  {
        cout << "invalid position" << endl;
        return false;
    }

    // 遍历找到pos的前一个节点p
    int j = 0;
    Node* p = m_head;
    while (p != nullptr && j < pos - 1) {
        p = p->next;
        ++j;
    }

    // 创建新节点
    Node* pNode = new Node;
    if (pNode == nullptr) {
        perror("fail to create new node\n");
        return false;
    }

    // 初始化新节点
    pNode->data = data;

    // pNode指向p的下一个节点, p指向pNode
    pNode->next = p->next;
    p->next = pNode;
    m_length++;

    return true;
}

bool LoopLinkList::remove(int pos) {

    // 判断pos合法性
    if (pos < 1 || pos > m_length) {
        cout << "invalid position" << endl;
        return false;
    }

    // 遍历找到待删除节点的前一个节点p
    int j = 0;
    Node* p = m_head;
    while (j < pos - 1) {
        p = p->next;
        ++j;
    }
    
    // p指向待删除节点的下一个节点, free(待删除节点)
    Node* pDel = p->next;
    p->next = p->next->next;
    delete pDel;
    m_length--;

    return true;
}

Node* LoopLinkList::find(int data, int& pos) {

    pos = 1;
    Node* p = m_head->next;
    while (p != nullptr && p->data != data) {
        p = p->next;
        pos++;
    }
    
    return p;
}

void LoopLinkList::display() {

    if (m_length == 0) {
        cout << "this LinkList is empty" << endl;
        return;
    }

    // 循环链表, 以头节点作为判断结束条件
    Node* p = m_head->next;
    while (p != m_head)
    {
        cout << p->data << endl;
        p = p->next;
    }
    cout << endl;
}

int main() {

    LoopLinkList lst;
    lst.insert(1, 12);
    lst.append(8);
    lst.insert(2, 7);
    lst.insert(2, 6);
    lst.insert(1, 5);
    lst.insert(2, 4);
    lst.append(3);
    lst.prepend(9);
    lst.display();
    cout << "length: " << lst.length() << endl;

    LoopLinkList lst1;
    lst1.append(10);
    lst1.append(20);
    lst1.append(30);
    lst1.append(40);
    lst1.append(50);
    lst1.display();
    
    int pos;
    Node* node = lst1.find(10, pos);
    cout << "pos: " << pos << ", val: " << node->data << endl;
    lst1.remove(pos);
    lst1.display();


    return 0;
}