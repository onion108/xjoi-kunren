#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

struct position2d_t {
  int x;
  int y;
  position2d_t(int x, int y) : x(x), y(y) {}
};

static constexpr const int MAXN = 256;
char g_map[MAXN][MAXN];

int main() {
  int n, m;
  cin >> n;
  std::getchar();
  std::fgets(g_map[0], MAXN-1, stdin);
  m = strlen(g_map[0]);
  g_map[0][--m] = '\0';  
  for (int i = 1; i < n; i++) {
    std::fgets(g_map[i], MAXN-1, stdin);
    g_map[i][m] = 0;
  }
  // m = std::strlen(g_map[0]);
  assert(g_map[0][m-1] != '\n');
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g_map[i][j] != '*' && g_map[i][j] != ' ') {
        // Found somebody
        std::queue<position2d_t> q;
        q.push(position2d_t(i, j));
        ans++;
        while (!q.empty()) {
          position2d_t p = q.front();
          q.pop();
          if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m) {
            // Out of bounds
            continue;
          }
          if (g_map[p.x][p.y] == '*' || g_map[p.x][p.y] == ' ') {
            continue;
          } else {
            g_map[p.x][p.y] = ' '; // or '*'
            q.push(position2d_t(p.x, p.y+1));
            q.push(position2d_t(p.x, p.y+1));
            q.push(position2d_t(p.x+1, p.y));
            q.push(position2d_t(p.x-1, p.y));
          }
        }
      }
    }
  }
  cout << ans << endl;
}

