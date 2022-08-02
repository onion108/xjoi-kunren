#include <iostream>
#include <string>
#include <algorithm>

namespace imports {
  using std::cin;
  using std::cout;
  using std::endl;
}

using namespace imports;

static constexpr const int MAXN = 1e5+114514;

std::string blocks[MAXN];

int main() {
  int n;
 cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> blocks[i];
  }
  std::sort(blocks, blocks + n, [] (std::string x, std::string y) {
    return x + y > y + x;
  });
  for (int i = 0 ; i < n; i++) {
    cout << blocks[i];
  }
  cout << endl;
}
