// B
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;


static const int MAXN = 1000;
int a[MAXN];

int main() {
  int n, k, m, t, num, z = 0;
  cin >> n >> k >> m;
  for (int i = 0; i <= n - 2; i++) {
    a[i] = i + 1;
    // a[i+1] = i;
  }
  a[n-1] = 0;
  // a[0] = n-1;
  if (!k) t = n-1;
  else t = k-1;
  cout << "\nm = " << m << "\n";
  int __wc = 0;
  while(a[t] != a[a[t]]) {
    __wc++;
    z++;
    if (z == m) {
      cout << a[t] << " ";
      a[t] = a[a[t]];
      z = 0;
    } else t = a[t];
  }
  cout << "\n While executed " << __wc << " times. " << endl;
  cout << a[t] << endl;
}

