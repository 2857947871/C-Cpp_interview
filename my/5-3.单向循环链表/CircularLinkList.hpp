# ifndef __CIRCULARLINKLIST__H
# define __CIRCULARLINKLIST__H

# include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node* next;
};

template<typename T>
class LoopLinkList
{
public:
    LoopLinkList();
    ~LoopLinkList();

public:
    int length();
    bool isEmpty();
    void prepend(T data);
    void append(T data);
    bool remove(int* pos);
    bool find(T data, int* pos);
    void display();

private:
    int m_length = 0;
    Node<T>* m_tail = nullptr;
    Node<T>* m_head = nullptr;
};
# endif