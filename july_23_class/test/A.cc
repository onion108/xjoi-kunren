#include <__string>
#include <iostream>

#define __DEBUG__
#ifdef __DEBUG__
#define debug(block) block
#else
#define debug(block)
#endif

namespace imports {
  using std::cin;
  using std::cout;
  using std::endl;
}

using namespace imports;
static constexpr const int MAXN = 512;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
  int n, m;
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  dp[1][1] = a[1][1];
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 0) {
        dp[i][j] = -1;
      } else {
        dp[i][j] = a[i][j] + (dp[i][j-1] == -1 ? a[i-1][j]:dp[i-1][j]) + (dp[i-1][j] == -1 ? a[i][j-1]:dp[i][j-1]);
      }
    }
  }
  debug({
    cout << "[DEBUG] dp: " << endl;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << ';';
      }
      cout << endl;
    }
  })
  int max = -114514;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dp[i][j] > max) max = dp[i][j];
    }
  }
  cout << max << endl;
}
