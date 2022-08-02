#include <algorithm>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#ifdef __DEBUG__
#define debug(__B) __B
#else
#define debug(__UNUSED)
#endif

struct weapon_t {
  long long value;
  bool has_taken = false;
};

static const constexpr int MAXN = 1e5+114514;
weapon_t weapons[MAXN];
long long max_weas[MAXN];

int main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> max_weas[i];
  }
  for (long long i = 1; i <= m; i++) {
    cin >> weapons[i].value;
  }
  std::sort(weapons+1, weapons+m+1, [](weapon_t x, weapon_t y) {return x.value < y.value;});
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    int last_taken_weap = -1;
    for (long long j = 1; j <= m; j++) {
      debug({
        cout << i << " looked at " << j << endl;
      })
      if (weapons[j].has_taken) {
        debug({
          cout << j << " was taken by someone. \n";
        })
        continue;
      }
      if (weapons[j].value <= max_weas[i]) {
        if (last_taken_weap != -1) {
          weapons[last_taken_weap].has_taken = false;
        }
        weapons[j].has_taken = true;
        debug({
          cout << i << " want to use " << j << " and gave up " << last_taken_weap << endl;
        })
        last_taken_weap = j;
      }
    }
    debug({
      cout << i << " chose " << last_taken_weap << " with value" << weapons[last_taken_weap].value << endl;
    })
    sum += weapons[last_taken_weap].value;
  }
  cout << sum << endl;
}

