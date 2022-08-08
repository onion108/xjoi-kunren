// B_fuck
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



static const int MAXN = 105;
int n, dp[MAXN][MAXN];
struct miceinfo_t {
  private:
  int time_stay;
  int points;
  public:
  
  miceinfo_t(int t, int p) : time_stay(t), points(p) {}
  miceinfo_t() : time_stay(0), points(-1) {}
  
  int get_time_stay() const {
    return time_stay;
  }
  int get_points() const {
    return points;
  }
  void read_time_from(std::istream& is) {
    is >> this->time_stay;
  }
  void read_points_from(std::istream& is) {
    is >> this->points;
  }
};

int main() {
  int mice_count;
  cin >> mice_count;
  
  int maxt = 0;
  std::vector<miceinfo_t> minfo;
  for (int i = 0; i < n; i++) {
    minfo[i].read_time_from(cin);
    maxt = std::max(maxt, minfo[i].get_time_stay());
  }
  for (int i = 0; i < n; i++) {
    minfo[i].read_points_from(cin);
  }
  
  std::sort(minfo.begin(), minfo.end(), [](const miceinfo_t & x, const miceinfo_t & y) {
    return (x.get_time_stay() == y.get_time_stay()) ? (x.get_points() > y.get_points()) : (x.get_time_stay() < y.get_time_stay());
  });

  for (int i = 1; i <= maxt; i++) {
    for (int j = 0; j < n; j++) {
      if (minfo[j].get_time_stay() >= i) {
        for (int k = 0; k < j; k++) {
          dp[i][j] = std::max(dp[i][j], dp[i-1][k]+minfo[j].get_points());
        }
        
        dp[i][j] = std::max(dp[i][j], minfo[j].get_points());
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  
  int ans = 0;
  for (int i = 0; i < minfo.size(); i++) {
    ans = std::max(ans, dp[maxt][i]);
  }
  
  cout << ans << endl;
  
}
