#include <iostream>
#include <algorithm>
using namespace std;

static constexpr const int MAXN = 1e3+5;

int a[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + a[i][j];
        }
    }
    printf("%d", *max_element(dp[n] + 1, dp[n] + n + 1));
}
