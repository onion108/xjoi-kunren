#include <iostream>
using namespace std;

int g_ans[15];
int g_mid_ans[15];

void digits(int a) {
    while(a) {
        g_ans[a % 10]++;
        a /= 10;
    }
}

int main() {
    int n;
    cin >> n;
    if (n <= 1e4) {
        for (int i = 1; i <= n; i++) {
            digits(i);
        }
        for (int i = 0; i <= 9; i++) {
            cout << g_ans[i] << endl;
        }
    } else {
        for (int i = 1; i <= 9999; i++) {
            digits(i);
        }
        for (int i = 1; i <= n/10000; i++) {
            auto t = i;
            while (i) { g_mid_ans[t % 10]++; t /= 10; }
            for (int j = 0; j <= 9; j++) {
                g_ans[j] += g_mid_ans[j] * 10000;
            }
        }
        for (int i = 0; i <= 9; i++) {
            g_ans[i] += 4000 * (n / 10000 - 1);
        }
        for (int i = n * 10000; i <= n; i++) {
            digits(i);
        }
        for (int i = 0; i <= 9; i++) {
            cout << g_ans[i] << endl;
        }
    }
}
