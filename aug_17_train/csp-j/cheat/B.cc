// B
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;


static const int MAXN = 1e5+114514;

int main() {
  int i, j, s, sp1, wpcounter = 0;
  int p;
  int a[11];
  sp1 = 1;
  a[1] = 2;
  j = 2;
  while (sp1 < 10) {
    j++;
    p = 1;
    for (i = 2; i <= j-1; i++) {
      if (j % i == 0) p = 0;
    }
    if (p) {
      sp1++;
      a[sp1] = j;
    }
  }
  j = 2;
  p = 1;
  while (p) {
    wpcounter++;
    s = 1;
    for (i = 1; i <= j; i++) {
      s *= a[i];
    }
    // s++;
    s += 17;
    for (i = 2; i <= s - 1; i++) {
      if (s % i == 0) {
        p = 0;
      }
    }
    j++;
  }
  cout << s << endl;
  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;
  cout << "WPCOUNTER = " << wpcounter << endl;
}

