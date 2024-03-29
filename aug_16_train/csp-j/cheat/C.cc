// C
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;


static const int MAXN = 7;

int r(int n) {
  int i;
  if (n <= MAXN) {
    return 0;
  }
  for (i = 1; i <= MAXN; i++) {
    if (r(n-i) < 0) {
      return i;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  cout << r(n) << endl;
  return 0;
}

