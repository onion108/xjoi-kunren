#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int h, s;
  cin >> h >> s;
  std::string ops;
  cin >> ops;
  for (auto op : ops) {
    switch (op) {
      case 'u':
      if (s > 0) {
          s--;
      }
      break;
      case 'd':
      if (s < h) {
          s++;
      }
      break;
      default:
      break;
    }
  }
  cout << s << endl;
}

