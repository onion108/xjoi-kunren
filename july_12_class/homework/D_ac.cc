#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

static constexpr const int MAXN = 2e4 + 1;
std::vector<int> t[MAXN];
bool vis[MAXN];
bool f[MAXN];
int n;

int dfs(int id) {
    vis[id] = true;
    int tot = 0;
    for (int i = 0; i < t[id].size(); i++) {
        if (!vis[t[id][i]]) {
            int cnt = dfs(t[id][i]);
            if (cnt > n / 2) {
                f[id] = false;
            }
            tot += cnt;
        }
    }
    if (n - tot - 1 > n / 2) {
        f[id] = false;
    }
    return tot + 1;
}

int main() {
    int a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        t[a].push_back(b);
        t[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        f[i] = true;
    }
    dfs(1);
    bool ff = false;
    for (int i = 1; i <= n; i++) {
        if (f[i]) {
            printf("%d\n", i);
            ff = true;
        }
    }
    if (!ff) {
        printf("NONE");
    }
}