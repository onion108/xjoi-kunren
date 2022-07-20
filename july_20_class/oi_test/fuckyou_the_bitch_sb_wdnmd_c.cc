#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

static constexpr const int ARR_SIZE = 114514+1e5;

int dp[ARR_SIZE];

bool is_prime(long long ago) {
    if (ago <= 1) {
        return false;
    }
    for (long long i = 2; i <= sqrt(ago); i++) {
        if (ago % i) {
            return false;
        }
    }
    return true;
}

int main() {
    long long n;
    cin >> n;
    if (is_prime(n)) {
        cout << 0;
    } else {}
}

