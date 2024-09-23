// CircularLinkList.h
#pragma once
struct Node
{
    int data = 0;
    Node* next = nullptr;
};

// 单向循环链表
class LoopLinkList
{
public:
    LoopLinkList();
    ~LoopLinkList();

    bool isEmpty();
    int length();
    void prepend(int data);
    void append(int data);
    bool insert(int pos, int data);
    Node* find(int data, int& pos);
    bool remove(int pos);
    void display();

private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    int m_length = 0;
};