#include <map>
#include <string>
#include <iostream>

using namespace std;

template <typename T1, typename T2, typename Compare>
void display(map<T1, T2, Compare> &map) {
    for (auto &pair : map) {
        cout << "key: " << pair.first << ", value: " << pair.second << endl; 
    }
}

int main() {

    // 构造函数
    map<string, int> map_1{{"C++", 1}, {"STL", 2}};
    map<string, int, less<string>> map_2{{"C++", 1}, {"STL", 2}};
    map<string, int, greater<string>> map_3{{"C++", 1}, {"STL", 2}};

    // 自定义排序
    // map的排序基于红黑树, 所以传入l和r两个参数
    struct myCompare {
        bool operator() (const string &l, const string &r) {
            return l.size() < r.size();
        }
    };
    map<string, int, myCompare> map_4{{"C++", 1}, {"JAVA", 2}, {"Python", 3}};

    display<string, int>(map_1); // 默认排序: less
    display<string, int, less<string>>(map_2);
    display<string, int, greater<string>>(map_3);
    display<string, int, myCompare>(map_4);

    // 查
    cout << "find" << endl;

    // lower_bound: 返回第一个不小于key的元素的迭代器
    cout << "lower: " <<  "key: " << map_4.lower_bound("C++")->first 
        << " value: " << map_4.lower_bound("C++")->second << endl;

    // upper_bound: 返回第一个大于key的元素的迭代器
    cout << "lower: " <<  "key: " << map_4.upper_bound("C++")->first 
        << " value: " << map_4.lower_bound("C++")->second << endl;


    return 0;
}