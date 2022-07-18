#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

static constexpr const int ARRAY_SIZE = 114514+1e5;
// int seq_s1[ARRAY_SIZE];
// int seq_s2[ARRAY_SIZE];

auto main() -> int {
    int n, m, k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> seq_s1; 
    std::priority_queue<int, std::vector<int>, std::less<int>> seq_s2;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        seq_s1.push(tmp);
    }
    for (int i = 1; i <= m; ++i) {
        int tmp;
        cin >> tmp;
        seq_s2.push(tmp); 
    }
    for (int _i = 0; _i < k; _i++) {
        auto smaller = seq_s1.top();
        seq_s1.pop();
        auto bigger = seq_s2.top();
        seq_s2.pop();
        if (smaller < bigger) {
            seq_s1.push(bigger);
            seq_s2.push(smaller);
        } else {
            break;
        }
    }
    int sum = 0;
    while (!seq_s1.empty()) {
        sum += seq_s1.top();
        seq_s1.pop();
    }
    cout << sum << endl;
}
