#include <iostream>
#include <algorithm>
using namespace std;

static constexpr const int ARR_SIZE = 114514+1e5;

int bullets[ARR_SIZE];
int dp[ARR_SIZE];
int dp2[ARR_SIZE];

int main() {
    int n = 1;
    bullets[0] = 114514+1e5;
    while (cin >> bullets[n]) n++;
    dp[1] = bullets[1];
    int cnt = 1;
    for (int i = 2; i <= n-1; i++) {
        if (dp[cnt] >= bullets[i]) {
            dp[++cnt] = bullets[i];
        } else {
            for (int j = 1;;j++) {
                if (dp[j] < bullets[i]) {
                    dp[j] = bullets[i];
                    break;
                }
            }
        }
    }
    int ans = 1;
    dp2[1] = bullets[1];
    for (int i = 2; i <= n; i++) {
        if (dp2[ans] < bullets[i]) {
            dp2[++ans] = bullets[i];
        } else {
            *lower_bound(dp2+1, dp2+ans+1,bullets[i]) = bullets[i]; // Use lower_bound to decrease bullet count
        }
    }
    cout << cnt << endl;
    cout << ans << endl;
}
