#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    vector<float> v({1.5, 2.2, 3.1, 4.9});
    int a[4] = {0};

    // copy: ele by ele
    copy(v.begin(), v.begin() + 3, a);
    for (auto x : a) {
        cout << x << " ";
    } cout << endl;


    return 0;
}