#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// C++11
template <typename T1, typename T2>
void display(unordered_map<T1, T2> &map) {
    for (auto &pair : map) {
        cout << "key: " << pair.first << ", value: " << pair.second << endl; 
    }
}

int main() {

    // 构造函数
    // 使用默认构造函数创建一个空的 unordered_map
    // key_type: int, value_type: string
    unordered_map<int, string> umap_0;

    unordered_map<string, bool> umap_1{{"boyfriend", true}, {"cat", false}, {"dog", true}};
    
    vector<pair<int, string>> vec = {{1, "One"}, {2, "Two"}, {3, "Three"}};
    unordered_map<int, string> umap_2(vec.begin(), vec.end());
    
    unordered_map<string, bool> umap_3_0(umap_1);

    unordered_map<string, bool> umap_3_1 = move(umap_3_0);

    // 增/改
    umap_0[1] = "One"; // [ ]: 是key不是索引
    umap_0[2] = "Two";
    umap_1.insert({{"girlfriend", false}});
    umap_2.insert(make_pair(4, "four"));
    
    cout << "insert" << endl;
    display<int, string>(umap_0);
    display<string, bool>(umap_1);
    display<int, string>(umap_2);

    // 删
    // umap_0.erase(umap_0.begin() + 1); // 无法使用offset来进行删除
    umap_0.erase(umap_0.begin()); // 删除第一个元素, 不一定是哪一个, 因为是无序的
    umap_1.erase("boyfriend");
    umap_2.clear();

    cout << "erase" << endl;
    display<int, string>(umap_0);
    display<string, bool>(umap_1);
    display<int, string>(umap_2);

    // 查
    cout << "find" << endl;
    cout << "cat: " << umap_1["cat"] << endl;
    cout << "dog: " << umap_3_1.at("dog") << endl;
    cout << umap_3_1.find("boyfriend")->first
         << umap_3_1.find("boyfriend")->second << endl; // 注: find返回的是一个迭代器, 需要使用->来访问


    return 0;
}
