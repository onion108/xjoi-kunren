#include <iostream>
using namespace std;

static constexpr const int MAXN = 2048;

bool g_graph[MAXN][MAXN];

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g_graph[u][v] = true;
    g_graph[v][u] = true;
  }
  for (int i = 1; i <= q; i++) {
    int u, v;
    cin >> u >> v;
    if (g_graph[u][v]) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}

