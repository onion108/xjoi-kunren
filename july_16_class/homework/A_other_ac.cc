#include <iostream>
#include <cmath>
using namespace std;
int i = 1, j = 1;

int main() {
    int s;
    cin >> s;
    s *= 2;
    int sum;
    for (int i = 3; i <= n; i++) {
        if (s % i == 0) {
            int t = s / i;
            for (int j = 1; j <= t / (i - 1); j++) {
                if ((t + (i - 1) * j) % 2) {
                    continue;
                }
                int an = (t + (i - 1) * j) / 2;
                int a1 = t - an;
                if (a1 > 0 && an > 0) {
                    sum++;
                }
            }
        }
    }
    cout << sum << endl;
}
