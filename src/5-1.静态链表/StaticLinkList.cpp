# include "StaticLinkList.h"

SLinkList::SLinkList(int size) : 
    m_size(size), m_length(0), m_list(new Node[size])
{
    m_list[0].next = -1;
    for (int i = 1; i < size; ++i) {
        m_list[i].next = -2;
    }
}

SLinkList::~SLinkList() {
    if (m_size) {
        delete[] m_list;
        m_list = nullptr;
    }
}

bool SLinkList::insert(int pos, int data) {
    
    if (pos < 0 || pos > m_size) {
        printf("invalid position\n");
        return false;
    }

    // 找空闲节点(next == -2)
    int index = -1;
    for (int i = 1; i < m_size; ++i) {
        if (m_list[i].next == -2)
        {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("this LinkList is full\n");
        return false;
    }

    // 遍历链表找到插入位置(pos)
    // current: 插入位置的前一个, 为了让这个位置的节点指向待插入节点
    int current = 0;
    int count = 0;
    while (m_list[current].next != -1 && count < pos) {
        current = m_list[current].next;
        count++;
    }

    // 待插入的节点, 指向-1(m_list[current].next)
    // 原pos == -1的节点指向待插入的节点
    m_list[index].data = data;
    m_list[index].next = m_list[current].next;
    m_list[current].next = index;
    m_length++;

    return true;
}

void SLinkList::display() {

    if (m_list[0].next == -1) {
        cout << "this LinkList is empty" << endl;
        return;
    }

    int current = m_list[0].next;
    while (current != -1) {
        cout << "pos: " << current << " " 
            << "data: " << m_list[current].data << " " 
            << "next: " << m_list[current].next << endl;;
        current = m_list[current].next;
    }
}

void SLinkList::remove(int pos) {

    if (pos < 0 || pos > m_size) {
        printf("invalid position\n");
        return;
    }

    int current = 0;
    int count = 0;
    while (m_list[current].next != -1 && count < pos) {
        current = m_list[current].next;
        count++;
    }

    int delPos = m_list[current].next;
    
    if (delPos == -1) {
        m_list[current - 1].next = -1;
    } else {
        m_list[delPos].data = 0;
        m_list[current].next = m_list[delPos].next;
        m_list[delPos].next = -2;
    }
    m_length--;
}

int SLinkList::find(int data)
{
    int current = m_list[0].next;
    int pos = 0;
    while (current != -1)
    {
        if (data == m_list[current].data) {  return pos; }
        current = m_list[current].next;
        pos++;
    }
    return -1;
}


int main()
{
    SLinkList ls(30);
    ls.insert(0, 10);
    ls.insert(0, 20);
    ls.insert(1, 30); 
    ls.insert(1, 33);
    ls.insert(2, 66);
    ls.insert(5, 88);
    ls.insert(6, 99);
    ls.display();
    printf("\n");

    ls.remove(0);
    ls.display();
    printf("\n");

    ls.remove(5);
    ls.display();
    printf("\n");

    int pos = ls.find(88);
    std::cout << "pos = " << pos << std::endl;

    pos = ls.find(99);
    std::cout << "pos = " << pos << std::endl;


    return 0;
}
