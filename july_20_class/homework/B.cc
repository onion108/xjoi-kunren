#include <iostream>
#include <algorithm>
using namespace std;

static constexpr const int ARR_SIZE = 114514+1e5;

struct range_t {
    int start;
    int end;
    int length() {
        return end - start + 1;
    }
};

int dp[ARR_SIZE];
range_t g_data[ARR_SIZE];

int main() {
    int b;
    cin >> b;
    for (int i = 1; i <= b; i++) {
        cin >> g_data[i].start >> g_data[i].end;
    }
    sort(g_data + 1, g_data + b, [](range_t x, range_t y) { return x.end < y.end; });
    for (int i = 1; i <= b; i++) {
        for (int j = g_data[b-1].end; j >= g_data[i].end; j--) {
            dp[j] = max(dp[j],dp[g_data[i].start - 1] + g_data[i].length());
        }
    }
    cout << dp[g_data[b-1].end] << endl;
}
