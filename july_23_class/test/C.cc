#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;

static constexpr const int MAXN = 64;
static constexpr const int INF = 0x3f3f3f3f;

int g_graph[MAXN][MAXN];

void solve(int v, int u) {
  
}

int main() {
  std::memset(g_graph, 0x3f, sizeof(g_graph));
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g_graph[u][v] = 0;
    g_graph[v][u] = 0;
  }
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    int v, u;
    cin >> v >> u;
    solve(v, u);
  }
}

