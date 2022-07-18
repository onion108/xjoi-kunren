#include <iostream>
using namespace std;

auto f(int n, int m) -> int {
    if (n == 1 || m == 1) return 1;
    if (n < m) return f(n, n);
    if (n == m) return 1+f(n, n-1);
    return f(n, m-1) + f(n-m, m);
}

auto main() -> int {
    int a;
    cin >> a;
    cout << f(a, a) << endl;
}
