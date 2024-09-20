#pragma once
#include <iostream>

using namespace std;

struct Node
{
    int data;
    int next;
};

class SLinkList
{
public:
    SLinkList(int size);
    ~SLinkList();

    void display();
    int find(int data);
    void remove(int pos);
    bool insert(int pos, int data);

private:
    int m_size;     // 链表的容量
    int m_length;   // 元素数量
    Node* m_list = nullptr;
};