#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

using num_t = long long;

static constexpr const int MAXN = 1e5+114514;

int a[MAXN];
int x[MAXN];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a+i);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", x+i);
  }
  std::sort(a+1, a+n+1);
  std::sort(x+1, x+m+1);
  num_t sum = 0;
  for (int i = n, j = m; i >= 1 && j >= 1; i--) {
    while (j >= 1 && a[i] < x[j]) {
      j--;
    }
    if (j >= 1) {
      sum += x[j--];
    }
  }
  cout << sum << endl;
}

