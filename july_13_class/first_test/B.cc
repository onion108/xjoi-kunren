#include <iostream>
#include <vector>

#define __DEBUG__

#ifdef __DEBUG__
#define dprintf(fmt, ...) printf(fmt, __VA_ARGS__)
#define dprint(sth) std::cerr << sth
#else
#define dprintf(fmt, ...) (void(0))
#define dprint(sth) (void(0))
#endif

static constexpr const int ARRAY_SIZE = 1024;

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

std::vector<int> g_tree[ARRAY_SIZE];
int g_subtree_sizes[ARRAY_SIZE];

int dfs(int start_idx) {
    if (g_subtree_sizes[start_idx] != -1) {
        return g_subtree_sizes[start_idx];
    } else {
        if (g_tree[start_idx].size() == 0) {
            return 1;
        } else {
            int all_subtree_sizes = 1;
            for (auto subnode : g_tree[start_idx]) {
                dprint("[DEBUG] DFSing node ");
                dprint(subnode);
                dprint(", spawn from ");
                dprint(start_idx);
                dprint(".\n");
                all_subtree_sizes += dfs(subnode);
            }
            g_subtree_sizes[start_idx] = all_subtree_sizes;
            return all_subtree_sizes;
        }
    }
}

int main() {
    
    int node_count;
    cin >> node_count;

    for (int i = 1; i <= node_count; i++) {
        g_subtree_sizes[i] = -1;
    }

    for (int i = 1; i < node_count; i++) {
        int vater;
        cin >> vater;
        g_tree[vater].push_back(i + 1);
    }
    for (int i = 1; i <= node_count; i++) {
        int size = dfs(i);
        cout << size << ' ';
    }
    cout << endl;
}
