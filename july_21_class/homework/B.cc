#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

static constexpr const int MAXN = 1e5+114514;
unsigned long long dp[MAXN];

int main() {
    unsigned long long n;
    cin >> n;
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 6;
    dp[4] = 9;
    for (unsigned long long i = 5; i <= n; i++) {
        dp[i] = dp[i-1]+dp[i-3]+dp[i-4];
    }
    cout << dp[n] << endl;
}
