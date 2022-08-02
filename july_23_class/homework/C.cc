#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

static constexpr const int MAXN = 1e5+114514;

std::vector<int> g_graph[MAXN];
int g_results[MAXN];
bool g_vis[MAXN];

int dfs(int node) {
  if (g_vis[node]) {
    return node;
  }
  if (g_results[node]) {
    return g_results[node];
  }
  if (g_graph[node].empty()) {
    return node;
  } else {
    g_vis[node] = true;
    int max = node;
    for (auto i : g_graph[node]) {
      max = std::max(dfs(i), node);
    }
    g_vis[node] = false;
    return max;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g_graph[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    g_results[i] = dfs(i);
    cout << g_results[i] << " ";
  }
  cout << endl;
}

