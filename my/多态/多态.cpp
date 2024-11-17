#include <iostream>
using namespace std;

class Person
{
public:
    // 只有virtual关键字 -> 虚函数
    // virtual关键字 + 函数名=0 -> 纯虚函数
    //  表示函数没有实现, 必须由派生类重写, 类中有纯虚函数时, 该类为抽象类, 无法直接实例化
    virtual void BuyTickets() {
        cout << "full" << endl;
    }
};

class Student : Person
{
public:
    virtual void BuyTickets() {
        cout << "half" << endl;
    }
};


int main () {

    // 初始化一个基类类型的指针(动态)
    // 指针指向基类, 运行时会在基类的虚函数表找到BuyTickets并调用
    Person *p = new Person;
    p->BuyTickets();

    // 初始化一个子类类型的指针(动态)
    // 指针指向子类, 运行时会在子类的虚函数表找到BuyTickets并调用
    Student *s = new Student;
    s->BuyTickets();


    return 0;
}