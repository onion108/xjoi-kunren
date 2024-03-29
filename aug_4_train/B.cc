// B
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;


/* Debug Kit Start */

#ifdef __DEBUG__
#define debug_do(__b) __b
#else
#define debug_do(__b)
#endif

/* Debug Kit End */



static const int MAXN = 1e5+114514;
bool g_dead[MAXN];

template <typename T>
auto find_from(const std::vector<T>& vec, const T& value) -> typename std::vector<T>::const_iterator {
  for (auto i = vec.begin(); i != vec.end(); i++) {
    if (*i == value) {
      return i;
    }
  }
  return vec.end();
}

int main() {
  std::vector<int> classmates;
  classmates.push_back(1);
  int n;
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int k, p;
    cin >> k >> p;
    auto the_one = find_from(classmates, k);
    if (p == 0) {
      classmates.insert(the_one, i+2);
    } else {
      classmates.insert(the_one+1, i+2);
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    g_dead[x] = true;
  }
  for (auto i : classmates) {
    if (g_dead[i]) {
      continue;
    } else {
      cout << i << ' ';
    }
  }
  cout << endl;
}

