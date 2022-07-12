#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

// #define __DEBUG__

#ifdef __DEBUG__
#define dprintf(fmt, ...) printf(fmt, __VA_ARGS__)
#define dprint(sth) std::cerr << sth
#else
#define dprintf(fmt, ...) (void(0))
#define dprint(sth) (void(0))
#endif

static constexpr const int ARRAY_SIZE = 114514+1e5;

std::vector<int> g_tree[ARRAY_SIZE];
int g_vater[ARRAY_SIZE], g_kinder[ARRAY_SIZE];
bool g_flag[ARRAY_SIZE];
int n;

void dfs_from(int st_idx) {
    g_flag[st_idx] = true;
    for (int i = 0; i < g_tree[st_idx].size(); i++) {
        int next_idx = g_tree[st_idx][i];
        if (g_flag[next_idx]) {
            continue;
        }
        g_vater[next_idx] = st_idx;
        g_kinder[st_idx]++;
        dfs_from(next_idx);
        g_kinder[st_idx] += g_kinder[next_idx];
    }
    // g_flag[st_idx] = false;
}

int main() {
    int i;
    cin >> n;
    for (i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g_tree[a].push_back(b);
        g_tree[b].push_back(a);
    }
    dfs_from(1);

    for (int i = 1; i <= n; i++) {
        g_kinder[i]++;
    }

    std::vector<int> dangerous_computers;
    for (int i = 1; i <= n; i++) {
        bool is_dangerous = true;
        int children_sizes_sum = 0;

        // Validate each children
        for (auto j : g_tree[i]) {
            if (j == g_vater[i]) {
                continue;
            }
            if (is_dangerous && g_kinder[j] > (n / 2)) {
                is_dangerous = false;
            }
            children_sizes_sum += g_kinder[j];
        }
        children_sizes_sum++;
        dprint("[DEBUG] ");
        dprint(children_sizes_sum);
        dprint(endl);
        // Validate the remaining part
        int rem_size = n - children_sizes_sum - 1;
        if (rem_size > (n / 2)) {
            is_dangerous = false;
        }

        if (is_dangerous) {
            dangerous_computers.push_back(i);
        }
    }
    for (auto a_computer_that_looks_very_very_very_very_very_very_dangerous : dangerous_computers) {
        printf("%d\n", a_computer_that_looks_very_very_very_very_very_very_dangerous);
    }
    for (int i = 0; i <= 10; i++) {
        dprint("[DEBUG] g_kinder[");
        dprint(i);
        dprint("] = ");
        dprint(g_kinder[i]);
        dprint(endl);
    }
}
