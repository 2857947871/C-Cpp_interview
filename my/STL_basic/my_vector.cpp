#include <vector>
#include <iostream>
using namespace std;

void display_vec(vector<int> &vec) {
    for (auto x : vec) {
        cout << x << " ";
    }
    cout << endl;
}
void display_vec(vector<vector<int>> &vec) {
    for (auto rows : vec) {
        for (auto x : rows) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {

    // 构造函数
    // vector<int>: 数据类型
    // v1: 变量名(实例化对象)
    vector<int> v0;                 // 空的vec
    vector<int> v1({0, 1, 2, 3});   // 自行赋值初始化
    vector<int> v2(10);             // 10个元素，每个元素为0
    vector<int> v3(10, 5);          // 10个元素，每个元素为5
    vector<vector<int>> v4
        (3, vector<int>(4, 2));     // 3行4列, 每个元素为2
    vector<vector<int>> v5{         // 3行4列, 自行赋值
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    display_vec(v0);
    display_vec(v1);
    display_vec(v2);
    display_vec(v3);
    display_vec(v4);
    display_vec(v5);

    // 增
    v2.push_back(2);
    display_vec(v2);

    // 注: 如果插入位置超过了当前vec的长度, 不会自行扩容, 会报错
    // 但是如果插入位置在当前vec的长度范围内, 会自动扩容
    // v2.insert(v2.begin() + 12, 3);
    v2.insert(v2.begin() + 4, 3); // 指定位置删除
    display_vec(v2);

    // 删
    v1.clear();
    display_vec(v1);

    v2.pop_back();
    display_vec(v2);
    
    v3.erase(v3.begin() + 2); // 指定位置删除
    display_vec(v3);
    
    // 4. 改/查
    cout << v2[2] << endl;
    cout << v3.at(2) << endl;
    cout << v4[1][2] << endl;
    cout << v5.at(2).at(3) << endl;
    for (auto it = v3.begin(); it < v3.end(); ++it) {
        cout << *it << " ";
    } cout << endl;

    v2[2] = 99;
    v4[1][2] = 99;
    display_vec(v2);
    display_vec(v4);

    // 5. 其他重要函数
    cout << "v2: size:     " << v2.size() << endl;      // 大小
    cout << "v2: capacity: " << v2.capacity() << endl;  // 容量


    return 0;
}
