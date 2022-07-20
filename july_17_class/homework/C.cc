#include <iostream>
#include <vector>
#include <algorithm>

using std::endl;
using std::cin;
using std::cout;


int main() {
    int n;
    while (cin >> n) {
        std::vector<int> battery_lives(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &battery_lives[i]);
        }
        auto max_iter = std::max_element(battery_lives.begin(), battery_lives.end());
        auto sum = 0;
        for (auto i = battery_lives.begin(); i != battery_lives.end(); i++) {
            if (i == max_iter) {
                continue;
            }
            sum += *i;
        }
        if (sum > *max_iter) {
            printf("%.1lf\n", double(*max_iter + sum) / 2.0);
        } else {
            printf("%d.0\n", sum);
        }
    }
}
