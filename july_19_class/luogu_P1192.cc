#include <iostream>

using std::cin;
using std::cout;
using std::endl;

static constexpr const int MAX_SIZE = 114514+1e5;
static constexpr const int MOD = 100003;

int dp[MAX_SIZE];

int main() {
    int n, k;
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        auto sum = 0;
        for (int j = i - 1, ct = 0; j >= 0 && ct < k; j--, ct++) {
            sum += dp[j] % MOD;
        }
        dp[i] = sum % MOD;
    }
    cout << dp[n] << endl;
}
