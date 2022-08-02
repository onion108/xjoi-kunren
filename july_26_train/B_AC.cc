#include <iostream>
#include <vector>
using namespace std;

static constexpr const int MAXN = 128;

vector<int> g[MAXN];
int cnt[MAXN];

int dfs(int u) {
  if (cnt[u]) {
    return cnt[u];
  }
  cnt[u] = 1;
  for (int i = 0; i < g[u].size(); i++) {
    cnt[u] += dfs(g[u][i]);
  }
  return cnt[u];
}

int main() {
  int n, u, v;
  cin >> n ;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    g[v].push_back(u);
  }
  for (int u = 1; u <= n; u++) {
    if (!cnt[u] && dfs(u) == n) {
      cout << u << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}

