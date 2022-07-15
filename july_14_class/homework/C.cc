#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

static constexpr const int ARR_SIZE = 1e9 + 1;

bool vis[ARR_SIZE];

struct mouse_or_hole_t {
    bool is_mouse;
    int value;
};

int main() {
    int n, m;
    cin >> n >> m;
    std::vector<mouse_or_hole_t> mice_and_holes;
    for (int i = 0; i < n; i++) {
        mouse_or_hole_t moh;
        moh.is_mouse = true;
        cin >> moh.value;
        mice_and_holes.push_back(moh);
    }
    for (int i = 0; i < m; i++) {
        mouse_or_hole_t moh;
        moh.is_mouse = false;
        cin >> moh.value;
        mice_and_holes.push_back(moh);
    }
    std::sort(mice_and_holes.begin(), mice_and_holes.end(), [](mouse_or_hole_t x, mouse_or_hole_t y) {
        return x.value < y.value;
    });
    int counter = 0;
    int ans = 0;
    for (auto i : mice_and_holes) {
        if (i.is_mouse) {
            int last_idx = counter;
            for(;(vis[last_idx] || mice_and_holes[last_idx].is_mouse) && last_idx >= 0;last_idx--);
            ans += i.value - mice_and_holes[last_idx].value;
            vis[last_idx] = true;
        } else {
        }
        counter++;
    }
    cout << ans << endl;
}
