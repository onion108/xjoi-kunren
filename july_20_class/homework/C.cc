#include <iostream>
using namespace std;

static constexpr const int ARR_SIZE = 114514+1e5;

int dp[ARR_SIZE];
int a[ARR_SIZE];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}
