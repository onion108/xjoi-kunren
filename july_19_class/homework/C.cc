#include <iostream>
using std::cin;
using std::cout;
using std::endl;

static constexpr const int ARR_SIZE = 2048;
long long dp[ARR_SIZE][ARR_SIZE];

struct pos_t {int x; int y;};

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  pos_t barrier[] = {{x+2, y+1},{x+1,y+2},{x-1,y+2},{x-1,y-2},{x+1,y-2},{x-2,y+1},{x-2,y-1},{x+2,y-1}, {x,y}};
  dp[0][0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      bool should_cont = false;
      for (auto b : barrier) {
        if (b.x == i && b.y == j) {
          should_cont = true;
          break;
        }
      }
      if (should_cont) continue;
      long long a = (i - 1 >= 0) ? dp[i-1][j]:0;
      long long b = (j - 1 >= 0) ? dp[i][j-1]:0;
      dp[i][j] = a + b;
    }
  }
  cout << dp[n][m] << endl;
}

