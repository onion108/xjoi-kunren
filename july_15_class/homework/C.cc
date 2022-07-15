#pragma region 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#pragma endregion

// import iostream;
// import vector;
// import algorithms;

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::strlen;

#define get_line() __LINE__
#define __DEBUG__

#ifdef __DEBUG__
#define dprint(obj) cerr << obj
#define dsprint(obj) cerr << "[DEBUG:" << get_line() << "] " << obj
#else
#define dprint(obj) (void(0))
#define dsprint(obj) (void(0))
#endif

static constexpr const int MAXN = 1e6;
static constexpr const int BASE = 10;
char s[MAXN];
int i[MAXN];
int a1[MAXN];
int a2[MAXN];
int a3[MAXN];


void f(int a[], char s[]) {
    a[0] = strlen(s);
    for (int i = 1, j = a[0] - 1; i <= a[0]; i++, j--) {
        a[i] = s[j] - '0';
    }
    for (int i = 1; i <= a[0]; i++) {
        a[i] = s[a[0] - i] - '0';
    }
}

void print(int a[]) {
    for (int i = a[0]; i; i--) {
        printf("%d", a[i]);
    }
    printf("\n");
}

void big_add(int a[], int b[], int c[]) {
    c[0] = std::max(a[0], b[0]);
    for (int i = 1; i <= c[0]; i++) {
        c[i] = a[i] + b[i];
    }
    for (int i = 1; i <= c[0]; i++) {
        c[i + 1] += c[i] / BASE;
        c[i] %= BASE;
    }
    if (c[c[0] + 1]) {
        c[0]++;
    }
}

void big_sub(int a[], int b[], int c[]) {
    c[0] = a[0];
    for (int i = 1; i <= c[0]; i++) {
        c[i] = a[i] - b[i];
    }
    for (int i = 1; i <= c[0]; i++) {
        if (c[i] < 0) {
            c[i] += BASE;
            c[i + 1]--;
        }
    }
    while (c[0] > 1 && !c[c[0]]) {
        c[0]--;
    }
}

void big_mul(int a[], int b[], int c[]) {
    for (int i = 1; i <= a[0]; i++) {
        for (int j = 1; j <= b[0]; j++) {
            c[i + j - 1] += a[i] * b[j];
            // *(c + (i + j - 1)) += *(a + i) * *(b + j);
        }
    }
    c[0] = a[0] + b[0];

    for (int i = 1; i <= c[0]; i++) {
        c[i + 1] += c[i] / BASE;
        c[i] %= BASE;
    }

    while(c[0] > 1 && !c[c[0]]) {
        c[0]--;
    }
}

int big_div(int a[], int b, int c[]) {
    int r = 0;
    for (int i = a[0]; i; i--) {
        r = r * BASE + a[i];
        c[i] = r / b;
        r %= b;
    }
    c[0] = a[0];
    while (c[0] > 1 && !c[c[0]]) {
        c[0]--;
    }
    return r;
}

int main() {
    scanf("%*d%s", s);
    f(a1, s);
    int a4;
    scanf("%d", &a4);
    int r = big_div(a1, a4, a3);
    print(a3);
    printf("%d\n", r);
}

