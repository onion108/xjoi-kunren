#include <iostream>
using namespace std;

int main() {
  int x, y, p, q;
  cin >> x >> y >> p >> q;
  long long k;
  long long l = 1, r = 0x7fffffff;
  while(l < r) {
    long long mid = l+(r-l)/2;
    if (mid*q-y >= mid*p-x && mid*p-x >= 0) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (l == 0x7fffffff) {
    cout << -1 << endl;
    return 0;
  }
  cout << (l*q-y) << endl;
}

