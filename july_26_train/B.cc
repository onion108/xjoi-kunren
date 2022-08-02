#include <iostream>
using namespace std;

static constexpr const int MAXN = 128;
int g_graph[MAXN][MAXN];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n-1; i++) {
    int u, v;
    cin >> u >> v;
    g_graph[u][v] = 1;
  }
}

