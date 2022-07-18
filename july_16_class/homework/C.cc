#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;

#define func auto

static constexpr const int MAXN = 114514 + 1e5;

int g_k[MAXN];
int g_vis[MAXN];
int g_counter = 0;

func depth_first_search(int floor, int& answer, int n, int b, int click_count) -> void {
    if (floor == b) {
        g_counter++;
        answer = std::min(answer, click_count);
        return;
    }
    if (floor < 0 || floor > n) {
        return;
    }
    if (g_vis[floor]) {
        return;
    }
    g_vis[floor] = true;
    depth_first_search(floor + g_k[floor], answer, n, b, click_count + 1);
    depth_first_search(floor - g_k[floor], answer, n, b, click_count + 1);
    g_vis[floor] = false;
}

func main() -> int {
    // Input the data.
    int n, a, b;
    std::scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &g_k[i]);
    }
    int answer = 114514+1e5;
    depth_first_search(a, answer, n, b, 0);
    if (g_counter) {
        std::printf("%d\n", answer);
    } else {
        cout << -1 << endl;
    }
}
