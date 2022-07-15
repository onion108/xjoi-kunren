#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::scanf;
using std::printf;

static constexpr const int ARRSIZE = 1e6+5;

struct node_t {
    int prev, value, next;
};

node_t a[ARRSIZE];

int main() {
    int n, k;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].value);
        a[i].prev = i - 1;
        a[i].next = i + 1;
    }
    a[0].next = 1;
    a[0].prev = n;
    a[0].value = -1;
    a[n].next = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &k);
        printf("%d %d\n", a[a[k].prev].value, a[a[k].next].value);
        a[a[k].prev].next = a[k].next;
        a[a[k].next].prev = a[k].prev;
    }
}
