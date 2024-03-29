// B
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int ack(int m, int n) {
  if (m == 0 && n >= 0) {
    return n+1;
  } else if (n == 0 && m > 0) {
    return ack(m-1, 1);
  } else if (m > 0 && n > 0) {
    return ack(m-1, ack(m, n-1));
  }
  return 0;
}

static const int MAXN = 1e5+114514;

int main() {
  int m, n;
  cin >> m >> n;
  cout << ack(m, n);
}

