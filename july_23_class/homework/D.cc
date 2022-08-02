#include <iostream>
#include <stack>
#include <cstdlib>

static constexpr const int MAXN = 32;
bool g[MAXN][MAXN];
int topo[MAXN];
int in[MAXN];

int tpsort(int n) {
  memset(topo, 0, sizeof(topo));
  memset(in, 0, sizeof(in));
  for (int u = 1; u <= n; u++) {
    for (int v = 1; v <= n; v++) {
      if (g[u][v]) {
        in[v]++;
      }
    }
  }
  std::stack<int> s; // Store points that have 0 as the in-degree
  for (int u = 1; u <= n; u++) {
    if (!in[u]) {
      s.push(u);
    }
  }
  int k = 0;
  bool f = true;
  while (!s.empty()) {
    if (s.size() != 1) {
      f = false;
    }
    int u = s.top();
    s.pop();
    topo[++k] = u;
    for (int v = 1; v <= n; v++) {
      if (g[u][v] && !--in[v]) {
        s.push(v);
      }
    }
  }
  if (k < n) {
    return -1;
  } else if (!f) {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  int n, m;
  std::scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    char s[8];
    std::scanf("%s", s);
    int u = s[0] - 'A' + 1, v = s[2] - 'A' + 1;
    g[u][v] = true;
    int k = tpsort(n);
    if (k == -1) {
      // Has cycle
      std::printf("Inconsistency found after %d relations.\n", i);
      return 0;
    } else if (k == 1) {
      std::printf("Sorted sequence determined after %d relations: ", i);
      for (int j = 1; j <= n; j++) {
        std::putchar(topo[j] + 'A' - 1);
      }
      std::puts(".\n");
      return 0;
    }
  }
  // indeterminate
  std::puts("Sorted sequence cannot be determined.\n");
}

