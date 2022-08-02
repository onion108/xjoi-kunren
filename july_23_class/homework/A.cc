#include <iostream>
using namespace std;

static constexpr const int MAXN = 1024;

unsigned char g_graph[MAXN][MAXN];
unsigned char g_tree[MAXN][MAXN];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g_tree[u][v] = 1;
    g_tree[v][u] = 1;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g_graph[u][v] = 1;
    g_graph[v][u] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (g_tree[i][j] == 0 && g_graph[i][j] == 1) {
        ans++;
      } else if (g_tree[i][j] == 1 && g_graph[i][j] == 0) {
        cout << "impossible" << endl;
      }
    }
  }
  cout << ans / 2 << endl;
}

