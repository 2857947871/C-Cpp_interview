# include "SLinkListWithHead.h"

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
    Node* p = m_head;
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

int LinkList::length() {
    return m_length;
}

// 头插
void LinkList::prepend(int data) {

    // 创建新节点
    Node* pNode = new Node;
    if (pNode == nullptr) {
        perror("fail to create new node\n");
        return;
    }

    // 初始化节点
    pNode->data = data;
    pNode->next = m_head->next;
    
    // 第一次头插, 该节点成为tail
    if (m_head->next == nullptr) {
        m_tail = pNode;
    }

    // 原头节点指向pNode
    // pNode成为新头节点
    m_head->next = pNode;
    m_length++;
}

// 尾插
void LinkList::append(int data) {

    // 创建新节点
    Node* pNode = new Node;
    if (pNode == nullptr) {
        perror("fail to create new node\n");
        return;
    }

    // 初始化节点
    pNode->data = data;
    pNode->next = nullptr;

    // 原tail指向pNode
    // pNode成为新tail
    m_tail->next = pNode;
    m_tail = pNode;
    m_length++;
}

bool LinkList::insert(int pos, int data) {

    // 判断pos合法性
    if (pos < 1 || pos > length() - 1)  {
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

Node* LinkList::find(int data, int& pos) {

    pos = 1;
    Node* p = m_head->next;
    while (p != nullptr && p->data != data) {
        p = p->next;
        pos++;
    }
    
    return p;
}

bool LinkList::remove(int pos) {

    // 判断pos合法性
    if (pos == 0 || pos == m_length) {
        cout << "invalid position" << endl;
        return false;
    }

    // 遍历找到待删除节点的前一个节点p
    int j = 0;
    Node* p = m_head;
    while (p != nullptr && j < pos - 1) {
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
    lst.append(80);
    lst.insert(1, 50);
    lst.insert(3, 1000);
    lst.append(100);
    cout << "length: " << lst.length() << endl;
    lst.display();

    int pos = 0;
    Node* node = lst.find(50, pos);
    cout << "pos: " << pos << ", val: " << node->data << endl;
    lst.remove(pos);
    lst.display();
    
    node = lst.find(100, pos);
    cout << "pos: " << pos << ", val: " << node->data << endl;
    lst.remove(pos);
    lst.display();
    
    node = lst.find(1000, pos);
    cout << "pos: " << pos << ", val: " << node->data << endl;
    lst.remove(pos);
    lst.display();
    
    lst.append(200);
    lst.display();


    return 0;
}
