#include <iostream>
#include <algorithm>

using namespace std;

static constexpr const int MAXN = 1e5 + 114514;

int a[MAXN];
int dp[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1], 0) + a[i];
    }
    printf("%d", *max_element(dp + 1, dp + n + 1));
}
