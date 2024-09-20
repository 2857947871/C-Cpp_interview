# include "SLinkListWithHead.h"
using namespace std;

LinkList::LinkList() : m_head(new Node)
{
    if (m_head == nullptr) {
        perror("fail to init\n");
        return;
    }

    // 初始化, 头尾节点为同一节点
    m_head->next = nullptr;
    m_tail = m_head;
}

LinkList::~LinkList() {
    Node* p = new Node;
    p = m_head;
    while (p != nullptr) {
        Node* tmp = p;
        cout << "free: " << tmp->data << endl;
        p = p->next;
        delete tmp;
    }
}

bool LinkList::isEmpty() {
    if (m_length == 0) {
        return true;
    } else {
        return false;
    }
}

int LinkList::length() { return m_length; }

// 头插
void LinkList::prepend(int data) {
    
    // 创建节点并初始化
    Node* pNode = new Node;
    if (pNode == nullptr) {
        perror("fail to create new Node\n");
        return; }
    pNode->data = data;

    // 如果是第一次插入, 该节点也是尾节点
    if (m_length == 0) {
        m_tail = pNode;
    }

    // SLinkListWithHead
    // 待插入节点成为头节点的下一个节点并指向原头节点的下一个节点
    // 头节点指向待插入节点
    pNode->next = m_head->next;
    m_head->next = pNode;
    m_length++;
}

// 尾插
void LinkList::append(int data) {

    // 创建节点并初始化
    Node* pNode = new Node;
    if (pNode == nullptr) {
        perror("fail to create new Node\n");
        return; }
    pNode->data =data;
    pNode->next = nullptr;

    // 如果是第一次插入, 该节点直接成为尾节点并使头节点指向该节点
    if (m_length == 0) {
        m_tail = pNode;
        m_head->next = m_tail;
    }

    // 原尾节点指向待插入节点
    // 待插入节点成为尾节点
    m_tail->next = pNode;
    m_tail = pNode;

    m_length++;
}

// 指定位置插入
bool LinkList::insert(int pos, int data) {

    // 判断位置是否合法
    if (pos < 1 || pos > m_length - 1) {
        printf("invalid position\n");
        return false;
    }

    // 创建节点并初始化
    Node* pNode = new Node;
    if (pNode == nullptr) {
        perror("fail to create new Node\n");
        return false; }
    pNode->data =data;
    
    // 遍历链表找到目标位置的前一个位置
    int count = 0;
    Node* p = m_head;
    while (p != nullptr && count < pos - 1) {
        p = p->next;
        count++;
    }

    // 待插入节点指向该位置的下一个节点
    // 该位置节点指向待插入节点
    pNode->next = p->next;
    p->next = pNode;
    m_length++;

    return true;
}

int LinkList::find(int data, Node* pos[]) {

    Node* p = m_head;

    if (m_length == 0) {
        printf("this LinkList is empty\n");
        return -1;
    }

    int i = 0;
    int count = 0;
    while (p != nullptr) {
        if (p->data == data) {
            pos[i] = p;
            i++;
            count++;
        }
        p = p->next;
    }

    return count;
}

bool LinkList::remove(int pos) {
    
    // 判断pos合法性
    if (m_length == 0) {
        printf("this LinkList is empty\n");
        return false;
    }
    if (pos == 0 || pos == m_length) {
        cout << "invalid position" << endl;
        return false;
    }

    // 遍历找到目标位置的前一个位置
    int count = 0;
    Node* p = m_head;
    while (p != nullptr && count < pos) {
        p = p->next;
        count++;
    }

    // 该节点指向目标节点的下一个节点并free(目标节点)
    Node* pDel = p->next;
    p->next = p->next->next;
    m_length--;
    delete pDel;

    return true;
}

void LinkList::display() {

    if (m_length == 0) {
        cout << "this LinkList is empty" << endl;
        return;
    }

    Node* p = m_head->next;
    while (p != nullptr)
    {
        cout << p->data << endl;
        p = p->next;
    }
    cout << endl;
}

int LinkList::value(int pos) {

    assert(pos > 0 && pos <= length());
    Node* p = m_head;
    for (int i = 0; i < pos; ++i)
    {
        p = p->next;
    }

    return p->data;
}

int main()
{
    LinkList lst;
    bool flag = lst.isEmpty();
    cout << "empty: " << flag << endl;
    lst.prepend(100);
    lst.prepend(90);
    lst.append(100);
    lst.insert(1, 50);
    lst.insert(3, 1000);
    lst.append(100);
    cout << "length: " << lst.length() << endl;
    lst.display();

    int count = 0;
    Node* pos[10];
    count = lst.find(100, pos);
    for (int i = 0; i < count; ++i) {
        cout << "pos: " << pos[i] << " val: " << pos[i]->data << endl;
    }

    lst.append(200);
    lst.display();


    return 0;
}
