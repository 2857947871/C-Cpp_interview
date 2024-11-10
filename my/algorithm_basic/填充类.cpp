#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Fibonacci
{
public:
    Fibonacci(int start1, int start2) : f1(start1), f2(start2) {}
    int operator()(){
        int r = f1 + f2;
        f1 = f2;
        f2 = r;
        return r;
    }
private:
    int f1;
    int f2;
};

int main() {

    // 1. fill
    vector<int> v1({1, 2, 3, 4, 5});
    cout << "before fill" << endl;
    for (auto x : v1) {
        cout << x << " ";
    } cout << endl;

    fill(v1.begin(), v1.end(), 10);
    cout << "after fill" << endl;
    for (auto x : v1) {
        cout << x << " ";
    } cout << endl;

    // 2. generate
    // 这个运算符重载位于Fibonacci这个类里面, 我只有在实例化之后, 
    // 调用F1(), 才会调用运算符重载
    Fibonacci F1(10, 20);
    int nextFibo = F1();
    cout << nextFibo << endl;
    nextFibo = F1();
    cout << nextFibo << endl;
/*
源码:
    template<class ForwardIterator, class Generator>
    void generate(ForwardIterator first, ForwardIterator last, Generator gen) {
        while(first != last) {
            *first = gen();
            first++;
        }
    }

    通过 gen(), 调用运算符重载 
*/
    vector<int> v2(10);
    generate_n(v2.begin(), 5, Fibonacci(0, 1));
    cout << "after generate_n" << endl;
    for (auto x : v2) {
        cout << x << " ";
    } cout << endl;


    return 0;
}