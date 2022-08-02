// B_ac
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

static const int MAXN = 1e4+5;
static const int MAXL = 16;

char s[MAXN][MAXL];

int a[MAXN];

int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  int cnt = m;
  while (cnt > 1) {
    for (int i = 1; i <= m; i++) {
      if (a[i] != -1) {
        a[i] = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      int len = std::strlen(s[i]);
      for (int j = 0; j < len; j++) {
        int id = s[i][j] - '0';
        if (a[id] == -1) {
          continue;
        }
        if (!id) {
          break;
        }
        a[id]++;
        break;
      }
    }
    
    int min = n + 1, max = -1;
    for (int i = 1; i <= m; i++) {
      if (a[i] == -1) {
        continue;
      }
      if (min > a[i]) {
        min = a[i];
      }
      if (max < a[i]) {
        max = a[i];
      }
    }
    if (max == min) {
      cout << -max << endl;
      exit(-1);
    } else {
      for (int i = 1; i <= m; i++) {
        if (a[i] == min) {
          a[i] = -1;
          cnt--;
        }
      }
    }
  }
  ouououououououououououou
}

