#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

// 1. unary
/*
template <class InputIterator, class OutputIterator, class UnaryOperation>
OutputIterator transfrom(InputIterator first1, InputIterator last1,
    OutputIterator result, UnaryOperation op) {
    while (first1 != last1) {
        *result++ = op(*first1++);
    }

    return result;
}
*/
    string s("Hello World");
    cout << "befor transform" << endl;
    for (auto x : s) {
        cout << x;
    } cout << endl;
    // [](unsigned char c) {return toupper(c);}
    // [ ]: 外部捕获参数
    // ( ): 相当于函数参数
    // { }: 相当于函数体
    //            first1     last1    result                      op
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {return toupper(c);});
    cout << "after transform" << endl;
    for (auto x : s) {
        cout << x;
    } cout << endl;

// 2. binary
/*
template <class InputIterator1, class InputIterator2,
    class OutputIterator, class UnaryOperation>
OutputIterator transfrom(InputIterator first1, InputIterator2 first2,
    InputIterator last1, OutputIterator result, UnaryOperation op) {
    while (first1 != last1) {
        *result++ = op(*first1++, *first2++);
    }

    return result;
}
*/
    vector<int> foo(5, 1);
    vector<int> bar(5, 2);
    cout << "befor transform" << endl;
    for (auto x : foo) {
        cout << x;
    } cout << endl;
    transform(foo.begin(), foo.end(), bar.begin(), foo.begin(), plus<int>());
    cout << "after transform" << endl;
    for (auto x : foo) {
        cout << x;
    } cout << endl;



    return 0;
}