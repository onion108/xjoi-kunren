#include <iostream>
using namespace std;

int sum_tousasuuretsu(int start, int step) {
    return start + start + step + start + 2 * step;
}

int main() {
    int s;
    int cnt = 0;
    cin >> s;
    if (s <= 6 || s % 3) {
        cout << 0 << endl;
    } else {
        for (int i = 0; i <= s+100; i++) {
            for (int j = 1; j <= s+100; j++) {
                if (sum_tousasuuretsu(j, i) == s) {
                    cnt++;
                    cerr << (j) << "+" << (j + i) << "+" << (j + i * 2) << "=" << sum_tousasuuretsu(j, i) << endl;
                }
            }
        }
        cout << cnt << endl;
    }
}
