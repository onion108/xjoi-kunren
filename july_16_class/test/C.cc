#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::printf;
using std::scanf;

// #define __DEBUG__

#ifdef __DEBUG__
#define dprintf(fmt, ...) printf(fmt, __VA_ARGS__)
#define dprint(fmt) printf(fmt);
#else
#define dprintf(fmt, ...) (void(0))
#define dprint(fmt) (void(0))
#endif

static constexpr const int ARRAY_SIZE = 1024;
static constexpr const int MAP_SIZE = 128;

char g_map[MAP_SIZE][MAP_SIZE];
int g_ans = 114514+1e9;
bool g_vis[MAP_SIZE][MAP_SIZE];

void dfs(int x, int y, bool has_teleported, int n, int m, int stepper) {
    dprintf("%d: (%d,%d)\n", stepper, x, y);
    if (g_vis[x][y]) return;
    if (x == n && y == m) {
        g_ans = std::min(g_ans, stepper);
        return;
    }
    if (x <= 0 || x > n) {
        return;
    }
    if (y <= 0 || y > m) {
        return;
    }
    if ((!has_teleported) && g_map[x][y] != '0' && g_map[x][y] != '1') {
        int nx = 0, ny = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g_map[i][j] == g_map[x][y] && i != x && j != y) {
                    nx = i;
                    ny = j;
                    goto out;
                }
            }
        }
        out:
        dprintf("(%d, %d)[%c, %02X] => (%d, %d)[%c, %02x]\n", x, y, g_map[x][y], g_map[x][y], nx, ny, g_map[nx][ny], g_map[nx][ny]);
        dfs(nx, ny, true, n, m, stepper);
    }
    g_vis[x][y] = true;
    dfs(x+1, y, false, n, m, stepper+1);
    dfs(x-1, y, false, n, m, stepper+1);
    dfs(x, y+1, false, n, m, stepper+1);
    dfs(x, y-1, false, n, m, stepper+1);
    g_vis[x][y] = false;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", (g_map + 1));
    }
    #ifdef __DEBUG__
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("(%d, %d): '%c'[0x%02X], ", i, j, g_map[i][j], g_map[i][j]);
        }
        printf("\n");
    }
    #endif
    dfs(1, 1, false, n, m, 1);
    cout << g_ans << endl;
}
