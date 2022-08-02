#include <iostream>
using std::cin;
using std::cout;
using std::endl;

static constexpr const int MAXN = 5000;
static constexpr const int MOD = 10000;
int dp[128][MAXN];

int main() {
    int n, k;
    cin >> n >> k;
    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[2][0] = 1;
    dp[0][0] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int p = 0; p <= i - 1 && j - p >= 0; p++) {
                // Sum it
                dp[i][j] = (dp[i-1][j-p]+dp[i][j]) % MOD;
            }
        }
    } 
    cout << dp[n][k] << endl;
}
