#include <iostream>
#include <algorithm>
#include <vector>

using std::endl;
using std::cout;
using std::cin;

int main() {
    int n;
    cin >> n;
    std::vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    std::sort(data.begin(), data.end());
    auto i = std::unique(data.begin(), data.end());
    for (auto j = data.begin(); j != i; ++j) {
        cout << *j << ' ';
    }
    cout << endl;
}
