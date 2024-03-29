// A
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
// ?6-81+/25+4@6A4+9=-0-4,?49>8-7010*46525E4/:0,<-2,A48?6-809/65,4>6B31:.,6,A,:45>@
//

#include <cassert>
#include <iostream>
#include <algorithm>
#include <cmath>

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



static const int MAXN = 8e4;
using number_t = long long;

number_t one_at(int no) {
  return (no*no-no)/2+1;
}

int number_at(int n) {
  int l = 0, r = MAXN;
  while (l < r) {
    auto mid = (l+r)/2;
    debug_do({
      printf("二分探索している：(l=%d,r=%d,mid=%d)と。\n", l, r, mid);
      printf("この位置の１は「%d」があり。\n", one_at(mid));
    })
    if (one_at(mid) < n) {
      l = mid+1;
      // r = mid;
    } else if (one_at(mid) > n) {
      r = mid;
      // l = mid+1;
    } else {
      assert(one_at(mid) == n);
      l = r = mid;
      break;
    }
  }
  if (one_at(l) == n) {
    return 1;
  }
  return 0;
}

int main() {
  int n;
  std::scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    number_t q;
    std::scanf("%lld", &q);
    std::printf("%d\n", number_at(q));
  }
}

