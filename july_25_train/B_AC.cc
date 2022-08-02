#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

static constexpr const int MAXN = 128;
static constexpr const int MAXL = 256;
char mp[MAXN][MAXL];
bool vis[MAXN][MAXL];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool check(int x, int y) {
  return 'a' <= mp[x][y] && mp[x][y] <= 'z' && !vis[x][y];
}

void dfs(int x, int y) {
  vis[x][y] = true;
  for (int k = 0; k < 4; k++) {
    int nx = x + dx[k], ny = y + dy[k];
    if (check(nx, ny)) {
      dfs(nx, ny);
    }
  }
}

int main() {
  int n, cnt = 0;
  scanf("%d", &n);
  getchar();
  for (int i = 1; i <= n; i++) {
    fgets(&mp[i][1], MAXL, stdin);
  }
  for (int i = 1; i <= n; i++) {
    int len = strlen(&mp[i][1]);
    for (int j = 1; j <= len; j++) {
      if (check(i, j)) {
        dfs(i, j);
        cnt++;
      }
    }
  }
  return 0;
}

