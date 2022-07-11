#include <iostream>
#include <stack>
#include <vector>

#define __DEBUG__

#ifdef __DEBUG__
#define dprintf(fmt, ...) printf(fmt, __VA_ARGS__)
#define dprint(sth) std::cerr << sth
#else
#define dprintf(fmt, ...) (void(0))
#define dprint(sth) (void(0))
#endif

static constexpr const char * JA_STR = "YES😀";
static constexpr const char * NEIN_STR = "NO😅";

using std::cin;
using std::cout;
using std::endl;
using std::stack;

std::vector<int> underlying_data;

class spy_container {
  public:
  using value_type = int;
  using reference = int&;
  using const_reference = const int &;
  using size_type = std::vector<int>::size_type;
  int back() {
    return underlying_data.back();
  }
  void push_back(int info) {
    underlying_data.push_back(info);
  }
  void pop_back() {
    underlying_data.pop_back();
  }
};

int main() {
  stack<int, spy_container> hacked_stack_instance;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    hacked_stack_instance.push(t);
  }
  while (!hacked_stack_instance.empty()) {
    hacked_stack_instance.pop();
  }
}
