// B
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;


static const int MAXN = 1e5+114514;

int n, a[1000];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] < a[j]) {
        sum++;
      }
    }
  }
  cout << sum << endl;
}

