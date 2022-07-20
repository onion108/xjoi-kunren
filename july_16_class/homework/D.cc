#include <iostream>
#include <vector>

using std::endl;
using std::cin;
using std::cout;

struct gun_info_t {
    int position;
    int radius;
};

int main() {
    int t;
    std::scanf("%d", &t);
    for (int big_loop_counter = 0; big_loop_counter < t; big_loop_counter++) {
        int n, l, w;
        std::scanf("%d%d%d", &n, &l, &w);
        std::vector<gun_info_t> guns(n+1);
        for (int i = 1; i <= n; i++) {
            gun_info_t a_gun;
            if (a_gun.radius < w/2) {
                printf("-1\n");
                goto b;
            }
            scanf("%d%d", &a_gun.position, &a_gun.radius);
            guns[i] = a_gun;
        }
        goto c;
        b:
        break;
        c:
        continue;
    }
}
