#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::endl;

vector<int> num_list;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    num_list.push_back(tmp);
  }
  // Flag the decrease-ordered subparts
  vector<int> start_of_dos;
  int lst = -1;
  for (int i = 0; i < n; i++) {
    if (num_list[i] > lst) {
      start_of_dos.push_back(num_list[i]);
    }
    lst = num_list[i];
  }
  int last_data = -(114514 + 1e5);
  for (auto i : start_of_dos) {
    if (i < last_data) {
      cout << "NO" << endl;
      return 0;
    }
    last_data = i;
  }
  cout << "YES" << endl;
}
