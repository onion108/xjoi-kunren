#include <iostream>

// #define __DEBUG__

#ifdef __DEBUG__
#define dprintf(fmt, ...) printf(fmt, __VA_ARGS__)
#define dprint(fmt) printf(fmt);
#else
#define dprintf(fmt, ...) (void(0))
#define dprint(fmt) (void(0))
#endif

struct fight_info {
    int fighter_id;
    int t;
};

using std::cin;
using std::cout;
using std::endl;

static constexpr const int ARRAY_SIZE = 114514 + 1e6;

int g_warriros[ARRAY_SIZE];
int g_monsters[ARRAY_SIZE];

// Index for monster id
fight_info* g_fighter_time[ARRAY_SIZE];

bool g_is_fighter_fighting[ARRAY_SIZE];

int main() {
    int n, m;
    cin >> m >> n;
    
    for (int i = 0; i < m; i++) {
        cin >> g_warriros[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> g_monsters[i];
    }

    for (int i = 0; i < n; i++) {
        // Days

        // Check for time
        for (int j = 0; j < n; j++) {
            if (!g_fighter_time[j]) continue;
            if (i == g_fighter_time[j]->t + g_monsters[j]) {
                dprintf("\n%d: to %d\n", g_fighter_time[j]->fighter_id, g_fighter_time[j]->t + g_monsters[j]);
                // Killed one!
                g_is_fighter_fighting[g_fighter_time[j]->fighter_id] = false;
                delete g_fighter_time[j];
                g_fighter_time[j] = NULL;
            }
        }

        // Choose a fighter
        int w = 114514+1e9, ft;
        for (int j = 0; j < m; j++) {
            if (g_is_fighter_fighting[j]) continue;
            if (g_warriros[j] < w) {
                w = g_warriros[j];
                ft = j;
            }
        }
        g_is_fighter_fighting[ft] = true;
        g_fighter_time[i] = new fight_info{ft, i};
        dprintf("Chose %d to fight %d, start from %d, will use %d days.", ft, i, i, g_monsters[i]);
        cout << ft << ' ';
    }
}
