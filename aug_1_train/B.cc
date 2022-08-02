// B
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <iostream>
#include <algorithm>
#include <vector>

#ifdef __DEBUG__
#define debug(__b) __b
#else
#define debug(__b)
#endif

using std::cin;
using std::cout;
using std::endl;

struct miceinfo_t {
  private:
  int time;
  int points;
  public:
  miceinfo_t(int time, int points) : time(time), points(points) {}
  miceinfo_t() : time(-1), points(-1) {}
  int get_time() const {
    return time;
  }
  int get_points() const {
    return points;
  }
  void read_time_from(std::istream& is) {
    is >> this->time;
  }
  void read_points_from(std::istream& is) {
    is >> this->points;
  }
};

static const int MAXN = 1e5+114514;

int main() {
  int mice_count = 0;
  cin >> mice_count;
  
  std::vector<miceinfo_t> data(mice_count);
  for (int i = 0; i < mice_count; i++) {
    data[i].read_time_from(cin);
  }
  for (int i = 0; i < mice_count; i++) {
    data[i].read_points_from(cin);
  }
  
  int timer = 0;
  int total_points = 0;
  sort(data.begin(), data.end(), [](const miceinfo_t& x, const miceinfo_t& y) {
    return (x.get_time() == y.get_time()) ? (x.get_points() > y.get_points()) : (x.get_time() < y.get_time());
  });
  debug({
    for (auto i : data) {
      cout << "data: {\"time\":" << i.get_time() << ", \"points\":" << i.get_points() << "}; \n";
    }
  })
  for (int i = 0; i < mice_count; i++) {
    if (timer <= data[i].get_time()) {
      total_points += data[i].get_points();
    }
    timer++;
  }
  cout << total_points << endl;
}

