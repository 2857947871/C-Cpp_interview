// SLinkList.h
#pragma once

# include <iostream>
# include <cassert>
using namespace std;

struct Node
{
    int data = 0;
    Node* next = nullptr;
};

// 定义单向链表类
class LinkList
{
public:
    LinkList();
    ~LinkList();

    bool isEmpty();
    int length();
    void prepend(int data);                     // 数据添加到链表头部
    void append(int data);                      // 数据添加到链表尾部
    bool insert(int pos, int data);             // 数据插入到链表任意位置, 第一个数据元素 pos=1
    int  find(int data, Node* pos[]);           // 搜索数值, 返回节点和位置, 没找到返回nullptr
    bool remove(int pos);                       // 删除节点
    void display();                             // 遍历链表
    inline Node* head() { return m_head; }      // 返回头结点
    int value(int pos);                         // 返回指定位置的节点的值

private:
    int m_length = 0;
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
};