// B
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <iostream>
#include <algorithm>

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

struct info_t {
  int d;
  int h;
};

struct position_t {
  int x;
  int y;
};

struct linear_function_t {
  int k;
  int b;
  linear_function_t(int k, int b) : k(k), b(b) {}
  int calc(int x) const {
    return k * x + b;
  }
};

template <typename T>
struct option_t {
  private:
  T value;
  bool has_value;
  option_t() = default;
  public:
  static auto some(T value) -> option_t<T> {
    option_t opt;
    opt.has_value = true;
    opt.value = value;
    return opt;
  }
  static auto none() -> option_t<T> {
    option_t opt;
    opt.has_value = false;
    return opt;
  }
  T unwrap() const {
    if (has_value) {
      return value;
    } else {
      throw "bad unwrap";
    }
  }
  bool is_none() const {
    return !has_value;
  }
  bool is_some() const {
    return has_value;
  }
  T unwrap_or_else(T def) const {
    return has_value ? value : def;
  }
  T expect(const char * error_msg) const {
    if (has_value) {
      return value;
    } else {
      std::cerr << "Unwrap failed: ";
      std::cerr << error_msg << std::endl;
      throw error_msg;
    }
  }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const option_t<T>& obj) {
  if (obj.is_some()) {
    os << "Some(" << obj.unwrap() << ")";
  } else {
    os << "None";
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const position_t& obj) {
  os << "(" << obj.x << ", " << obj.y << ")";
  return os;
}

std::ostream& operator<<(std::ostream& os, const linear_function_t& obj) {
  os << "f(x) = " << obj.k << "x + " << obj.b;
  return os;
}

static const int MAXN = 1e5+114514;

info_t data[MAXN];

int get_b_when_k_is_1(int x, int y) {
  return y - x;
}

int get_b_when_k_is_neg_1(int x, int y) {
  return x - y;
}

option_t<position_t> linear_intersect(const linear_function_t& lf0, const linear_function_t& lf1) {
  if (lf0.k == lf1.k) {
    return option_t<position_t>::none();
  }
  position_t p;
  p.x = (lf1.b - lf0.b) / (lf0.k - lf1.k);
  p.y = lf0.calc(p.x);
  return option_t<position_t>::some(p);
}

int main() {
  int n, m;
  cin >> n >> m;
  
  for (int i = 0; i < m; i++) {
    int di, hi;
    cin >> di >> hi;
    data[i] = { di, hi };
  }
  int max = -1;
  std::sort(data, data + m, [](const info_t& x, const info_t& y) { return x.d < y.d; });
  for (int i = 0; i < m-1; i++) {
    auto a0 = data[i];
    auto a1 = data[i+1];
    auto f0 = linear_function_t(1, get_b_when_k_is_1(a0.d, a0.h));
    auto f1 = linear_function_t(-1, get_b_when_k_is_neg_1(a1.d, a1.h));
    auto intersect = linear_intersect(f0, f1);
    debug_do({
      cout << intersect << endl;
      cout << "f0: " << f0 << endl;
      cout << "f1: " << f1 << endl;
    })
    if (intersect.is_some()) {
      auto p = intersect.unwrap();
      if ((p.x >= a0.d && p.y <= a1.d) && p.y >= 0) {
        if (p.y > max) {
          max = p.y;
        }
      } else {
        if ((double(a1.h) - double(a0.h)) / (double(a1.d) - double(a0.d)) <= 1.0) {
          auto x = a1.h > a0.h ? a1.h : a0.h;
          max = x > max ? x : max;
        } else {
          cout << "IMPOSSIBLE" << endl;
          return -1;
        }
      }
    } else {
      if ((double(a1.h) - double(a0.h)) / (double(a1.d) - double(a0.d)) <= 1.0) {
        auto x = a1.h > a0.h ? a1.h : a0.h;
        max = x > max ? x : max;
      } else {
        cout << "IMPOSSIBLE" << endl;
        return -1;
      }
    }
  }
  cout << max << endl;
}

