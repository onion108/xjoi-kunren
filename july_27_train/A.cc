#include <iostream>
#include <string>
#include <stack>
using namespace std;

int ・・(string s) {
  int result = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] <= 0x39 && s[i] >= 0x30) {
      result++;
    } else {
      if (s[i] == '(') {
        result--;
        int repeat = s[i-1] - 0x30;
        int start = i;
        int rep_len = 0;
        stack<bool> st;
        st.push(true);
        while (!st.empty()) {
          i++;
          rep_len++;
          if (s[i] == ')') {
            st.pop();
          } else if (s[i] == '(') {
            st.push(true);
          }
        }
        result += ・・(s.substr(start+1, rep_len-1)) * repeat;
      }
    }
  }
  return result;
}

int main() {
  string s;
  cin >> s;
  cout << ・・(s);
}

