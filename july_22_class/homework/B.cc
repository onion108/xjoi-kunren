#include <iostream>
#include <algorithm>
using namespace std;
static constexpr const int MAXN = 1e6+114514;
long long a[MAXN];
long long n;

bool check(long long v, int m) {
  long long bags = 1;
  long long current_bags_left = v;
  for (long long i = 1; i <= n; i++) {
    if (a[i] <= current_bags_left) {
      current_bags_left -= a[i];
    } else {
      bags++;
      current_bags_left = v;
    }
  }
  return bags <= m;
}

int main() {
  long long m;
  long long minval = 0, maxval = 0;
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    maxval += a[i];
    minval = max(minval, a[i]);
  }
  long long l = minval, r =maxval;
  while(l < r) {
    long long mid = (l+r)/2;
    if (check(mid, m)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%lld", r);
}

