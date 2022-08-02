#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

static constexpr const int MAXN = 1e5+114514;
std::vector<int> g_graph[MAXN];
int g_result[MAXN];

void dfs(int node, int maxParent) {
  if (g_result[node]) return;
  g_result[node] = std::max(maxParent, g_result[node]);
  for (auto i : g_graph[node]) {
    dfs(i, std::max(maxParent, node));
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g_graph[v].push_back(u);
  }
  for (int i = n; i >= 1; i--) {
    dfs(i, i);
  }
  for (int i = 1; i <= n; i++) {
    cout << g_result[i] << ' ';
  }
  cout << endl;
}

