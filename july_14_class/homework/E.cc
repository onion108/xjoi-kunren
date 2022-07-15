#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;

int main() {
    int n;
    cin >> n;
    std::vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    std::vector<int> old = data;
    std::sort(data.begin(), data.end());
    auto new_end = std::unique(data.begin(), data.end());
    std::vector<int> index;
    for (auto i = data.begin(); i != new_end; ++i) {
        index.push_back(*i);
    }
    for (auto i : old) {
        for (auto j = 0; j < index.size(); j++) {
            if (index[j] == i) {
                cout << j + 1 << ' ';
                break;
            }
        }
    }
}
