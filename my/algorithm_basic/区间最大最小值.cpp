#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a[] = {99, 199, 100, 1000};
    int maxPosition = max_element(a, a + 2) - a; // 最大值下标
    int max_val = *max_element(a, a + 2); // 最大值
    cout << "max_index: " << maxPosition << endl;
    cout << "max_val: " << max_val << endl;

    vector<int> n({99, 199, 100, 1000});
    int maxPosition_v = max_element(n.begin(), n.end()) - n.begin();
    int max_val_v = *max_element(n.begin(), n.end()); // 最大值
    cout << "max_index: " << maxPosition_v << endl;
    cout << "max_val: " << max_val_v << endl;


    return 0;
}