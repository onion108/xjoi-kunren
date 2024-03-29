// C
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;


static const int MAXN = 1e5+114514;

int n;
int call_count = 0;
int count(int n) {
  call_count ++;
  if (n == 1) {
    return 0;
  } else if (n % 2 == 1) {
    return count(n / 2) + 1;
  } else {
    return count(n * 3 + 1) + 1;
  }
}

int main() {
  cin >> n;
  cout << count(n) << endl;
  cout << "int ::count(int) called " << call_count << " times.\n";
  return 0;
}

