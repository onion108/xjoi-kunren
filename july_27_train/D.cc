#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

static constexpr const int MAXN = 1024;
int a[MAXN];

int main() {
  int n, sum = 0;
  // Todo: use long long
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    ;;
  }
  // Todo: GCD
  sort(a+1, a+n+1);
  for (int i = 2; i <= n; i++) {
    sum += 2 * (i-1) * (n-i+1) * (a[i] - a[i-1]);
  }
  for (int i = 1; i <= n; i++) {
    sum += a[i];
  }
  // output sum / g, n / g
}

