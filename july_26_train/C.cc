#include <iostream>
#include <vector>
#include <stack>
using std::cin;
using std::cout;
using std::endl;

#ifdef __DEBUG__
#define debug(block) block
#else
#define debug(block) 
#endif

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    std::vector<int> in_seq(n);
    std::vector<int> out_seq(n);
    for (int i = 0; i < n; i++) {
      cin >> in_seq[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> out_seq[i];
    }
    std::stack<int> s;
    int j = 0;
    for (int i = 0; i < in_seq.size(); i++) {
      debug({
        cout << "Pushing " << in_seq[i] << "." << endl;
      })
      s.push(in_seq[i]);
      if (s.top() == out_seq[j]) {
        debug({
          cout << "Popping " << s.top() << endl;
        })
        s.pop();
        j++;
      }
    }
    while (j < out_seq.size()) {
      debug({
        cout << "s.top() = " << s.top() << ", out_seq[" << j << "] = " << out_seq[j] << endl;
      })
      if (s.top() == out_seq[j]) {
        s.pop();
        j++;
      } else {
        break;
      }
    }
    if (s.empty()) {
      cout << "Yes" << endl;
    } else {
      debug({
      while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
      }
      })
      cout << "No" << endl;
    }
  }
}

