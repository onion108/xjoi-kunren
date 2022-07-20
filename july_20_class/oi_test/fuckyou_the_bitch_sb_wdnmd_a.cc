#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static constexpr const int ARR_SIZE = 114514+1e5;

int ts[ARR_SIZE];
int ms[ARR_SIZE];
int dp[ARR_SIZE];

int main() {
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= m; i++) {
        cin >> ts[i] >> ms[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= ts[i]; j--) {
            dp[j] = max(dp[j], dp[j-ts[i]]+ms[i]);
        }
    }
    cout << dp[m];
}
