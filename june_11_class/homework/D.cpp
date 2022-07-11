#include <iostream>
#include <stack>
#include <vector>

#define __DEBUG__

#ifdef __DEBUG__
#define dprintf(fmt, ...) printf(fmt, __VA_ARGS__)
#define dprint(sth) std::cerr << sth
#else
#define dprintf(fmt, ...) (void(0))
#define dprint(sth) (void(0))D
#endif

static constexpr const char * JA_STR = "YES";
static constexpr const char * NEIN_STR = "NO";

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::stack;

std::vector<int> underlying_data;

// Implement a container to get the underlying data of an STL stack.
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
  cerr << "Never gonna give↑ you↓ up↑~" << endl;
  cerr << "Never gonna let↑ you↓ down↑~" << endl;
  stack<int, spy_container> hacked_stack_instance;
  int n;
  cin >> n;
  cerr << "Never gonna run↑ a↓round↑~" << endl;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    hacked_stack_instance.push(t);
  }
  cerr << "And desert↑ you↓~" << endl;
  int last_data = 114514 + 1e5;
  for (auto i : underlying_data) {
    cerr << "You know the rules, and so do I~" << endl;
    cerr << "Oh man~ i, which is the lore variable, its value is --------" << endl;
    cerr << "*Music* *Music*" << endl;
    cerr << "*Clap* *Clap*" << endl;
    cerr << "i = " << i << endl;
    if (i > last_data) {
      cout << NEIN_STR << endl;
      return 0;
    }
    last_data = i;
  }
  cerr << "Se~ no" << endl;
  cout << JA_STR << endl;
}
