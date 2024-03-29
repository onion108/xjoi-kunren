// A
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <iostream>
#include <algorithm>
#include <queue>

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

struct student_t {
  int id;
  int points;
  bool operator<(const student_t& rhs) const {
    return points < rhs.points;
  }
};

static const int MAXN = 1e5+114514;
static int f[MAXN];

int main() {
  int n, m;
  cin >> n >> m;
  
  std::priority_queue<student_t> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    q.push(student_t { i, x });
  }
  int query;
  cin >> query;
  
  int currentLevel = 1;
  int currentNo = 0;
  int levelMultiple = n / m;
  int lastMark = -1;
  while (!q.empty()) {
    if (lastMark != q.top().points) {
      currentNo++;
    }
    student_t st = q.top();
    q.pop();
    if ((currentLevel-1) * levelMultiple + 1 <= currentNo && currentNo <= (currentLevel) * levelMultiple) {
      if (st.id == query) {
        cout << currentLevel << endl;
        break;
      }
    } else {
      currentLevel++;
      if (st.id == query) {
        cout << currentLevel << endl;
        break;
      }
    }
  }
}

