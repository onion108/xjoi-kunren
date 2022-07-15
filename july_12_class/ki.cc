#include <iostream>
using namespace std;

struct node_t {
    int value;
    int p;
    int l;
    int r;
    void speak() {
        printf("{value: %d, p: %d, l: %d, r: %d}\n", value, p, l, r);
    }
};

node_t a[114514];

void pre(int id) {
    a[id].speak();
    if (a[id].l) {
        pre(a[id].l);
    }
    if (a[id].r) {
        pre(a[id].r);
    }
}

void in(int id) {
    if (a[id].l) {
        in(a[id].l);
    }
    a[id].speak();
    if (a[id].r) {
        in(a[id].r);
    }
}

void post(int id) {
    if (a[id].l) {
        post(a[id].l);
    }
    if (a[id].r) {
        post(a[id].r);
    }
    a[id].speak();
}

int main() {
    // a[1].value = 1;
    // a[1].p = 0;
    // a[1].l = 2;
    // a[1].r = 3;
    // a[2].value = 2;
    // a[2].p = 1;
    // a[2].l = 7;
    // a[2].r = 0;
    // a[3].value = 3;
    // a[3].p = 1;
    // a[3].l = 4;
    // a[3].r = 0;
    // a[4].value = 4;
    // a[4].p = 3;
    // a[4].l = 5;
    // a[4].r = 6;
    // a[5].value = 5;
    // a[5].p = 4;
    // a[5].l = 0;
    // a[5].r = 0;
    // a[6].value = 6;
    // a[6].p = 4;
    // a[6].l = 0;
    // a[6].r = 0;
    // a[7].value = 7;
    // a[7].p = 2;
    // a[7].l = 0;
    // a[7].r = 0;

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        a[i].value = i;
        scanf("%d%d", &a[i].l, &a[i].r);
    }

    pre(1);
    printf("========\n");
    in(1);
    printf("========\n");
    post(1);
}
