#include <iostream>
using namespace std;


class A
{
public:
    virtual void vfunc1();
    virtual void vfunc2();
    void func1();
    void func2();

private:
    int m_data1;
    int m_data2;
};

class B
{
public:
    virtual void vfunc1();
    void func2();

private:
    int m_data3;
};

class C
{
public:
    virtual void vfunc1();
    void func2();

private:
    int m_data1;
    int m_data4;
};

// 虚函数
/*
A::vfunc1
A::vfunc2
B::vfunc1
C::vfunc1
*/

// 非虚函数
/*
A::func1
A::func2
B::func2
C::func2
*/