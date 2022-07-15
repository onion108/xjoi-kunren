#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;

int main() {
  int n;
  cin >> n;
  std::vector<int> data(n);
  for (int i = 0; i < n; i++) {
    cin >> data[i];
  }
  int last = -1;
  bool encountered_cliff = false;
  int cliff_pos = -1;
  int pos_counter = 0;
  for (auto i : data) {
    if (i < last) {
      // Encounters a cliff
      if (encountered_cliff) {
        // Already encountered a cliff
        cout << -1 << endl;
        return 0;
      } else {
        encountered_cliff = true;
        cliff_pos = pos_counter - 1;
      }
    }
    last = i;
    pos_counter++;
  }
  int answer = 0;
  for (; answer <= cliff_pos; answer++);
  cout << (n - answer) << endl;
}
