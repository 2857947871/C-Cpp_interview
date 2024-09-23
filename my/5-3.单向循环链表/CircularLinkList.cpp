# include "CircularLinkList.hpp"

template<typename T>
LoopLinkList<T>::LoopLinkList()
{
    // 初始化: 循环, 头指向头, 头节点也是尾节点
    m_head = new Node<T>;
    m_head->next = m_head;
    m_tail = m_head;
}

template<typename T>
LoopLinkList<T>::~LoopLinkList()
{
    if (m_length == 0) {
        printf("this LinkList is empty\n");
        return;
    }

    Node<T>* p = m_head->next;
    Node<T>* pDel = p;

    // 循环: 循环条件, 再一次回到m_head
    while (p != m_head) {
        p = p->next;
        delete pDel;
        pDel = p;
    }
}

template<typename T>
int LoopLinkList<T>::length() {
    return m_length;
}

template<typename T>
bool LoopLinkList<T>::isEmpty() {
    if (m_length == 0) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
void LoopLinkList<T>::display() {
    
    if (m_length == 0) {
        return;
    }
    
    Node<T>* p = m_head->next;
    while (p != m_head) {
        cout << p->data << endl;
        p = p->next;
    }
}

template<typename T>
void LoopLinkList<T>::prepend(T data) {

    // 创建并初始化新节点
    Node<T>* pNode = new Node<T>;
    pNode->data = data;

    // 如果是第一次插入, 同时成为尾节点
    if (m_length == 0) {
        m_tail = pNode;
    }

    // 新节点指向头节点的下一个节点, 头节点指向新节点
    pNode->next = m_head->next;
    m_head->next = pNode;
    m_length++;
}

template<typename T>
void LoopLinkList<T>::append(T data) {

    // 创建新节点并初始化
    Node<T>* pNode = new Node<T>;
    pNode->data = data;

    // 尾节点指向新节点, 新节点成为尾节点并指向头节点
    m_tail->next = pNode;
    m_tail = pNode;
    m_tail->next = m_head;
    m_length++;
}

template<typename T>
bool LoopLinkList<T>::find(T data, int* pos) {

    if (m_length == 0) {
        return false;
    }
    int i = 0;
    int n = 0;
    Node<T>* p = m_head->next;
    while (p != m_head) {
        if (p->data == data) {
            pos[i] = n;
            ++i;
        }
        p = p->next;
        n++;

    }

    if (pos[0] != 0) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool LoopLinkList<T>::remove(int* pos) {

    if (m_length == 0 || pos[0] == 0) {
        return false;
    }

    int i = 0;
    Node<T>* p = m_head->next;
    while (pos[i] != 0)
    {
        // 遍历至待删除节点的前一个节点
        for (int j = 0; j < pos[i] - 1; ++j) {
            p = p->next;
        }
        Node<T>* pDel = p->next;
        p->next = p->next->next;
        p = m_head;
        delete pDel;
        ++i;
        m_length--;
    }

    return true;
}

int main()
{
    LoopLinkList<float> linklist;
    cout << "length: " << linklist.length() << endl;
    cout << endl;

    linklist.prepend(10);
    linklist.prepend(10.5);
    linklist.prepend(11.5);
    linklist.append(1);
    linklist.append(2);
    linklist.append(10.5);
    cout << "length: " << linklist.length() << endl;
    linklist.display();
    cout << endl;

    int i = 0;
    float val = 10.5;
    int pos[10] = {};
    linklist.find(val, pos);
    while (pos[i] != 0) {
        cout << "val: " << val << " pos: " << pos[i] << endl;
        i++;
    }

    linklist.remove(pos);
    linklist.display();

    return 0;
}