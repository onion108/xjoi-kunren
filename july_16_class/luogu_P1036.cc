#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

int cnt;
int a[2048];
int n;

bool is_prime(int n) {
    if (n == 1) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (!(n % i)) {
            return false;
        }
    }
    return true;
}

void dfs(int step, int sum, int k) {
    if (!k) {
        if (is_prime(sum)) {
            cnt++;
        }
        return;
    }
    if (step > n) {
        return;
    }
    if (n - step + 1 < k) {
        return;
    }
    dfs(step + 1, sum + a[step], k-1);
    dfs(step+1, sum, k);
}

int main() {
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0, k);
    cout << cnt;
}
