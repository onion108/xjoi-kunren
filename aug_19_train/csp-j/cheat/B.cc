// B
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

struct qwq {
  int h, w;
  qwq operator++() {
    qwq tmp = *this;
    h++;
    return tmp;
  }
  qwq operator++(int) {
    h++;
    return (*this);
  }
} stdc, a[100003];

int MOD;

static const int MAXN = 1e5+114514;

bool cmp(qwq x, qwq y) {
  if (x.h % MOD != y.h % MOD) {
    return x.h % MOD <= y.h % MOD;
  }
  return x.w <= y.w;
}

int main() {
  
  int n, k;
  cin >> n >> k;
  k = std::min(n, k);
  for (int i = 0; i < n; i++) {
    a[i].h = n - 1 - i;
  }
  for (int i = 2; i <= k; ++i) {
    MOD = i;
    for (int j = 0; j < n;++j) {
      a[j].w = j;
    }
    std::sort(a, a+n, cmp);
  }
  stdc = a[n/2];
  int bits = 1000000000;
  cout << (bits/stdc++.h);
}

