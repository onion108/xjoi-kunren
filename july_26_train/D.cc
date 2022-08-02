#include <iostream>
#include <map>
using namespace std;

bool is_lucky_num(int fk, int m) {
  if (fk == 1) return false;
  map<int, int> primes;
  for (int i = 2; i <= fk; i++) {
    if (!(fk % i)) {
      while(!(fk % i)) {
        fk /= i;
        primes[i]++;
      }
    }
  }
  for (auto i : primes) {
    if (i.second % 2) {
      if (i.first > m) {
        return false;
      }
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  int ans = 0, n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    ans += is_lucky_num(i, m) ? 1 : 0;
  }
  cout << ans << endl;
}
