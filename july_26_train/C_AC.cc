#include <iostream>
#include <stack>
using namespace std;

static constexpr const int MAXN = 1e5+5;
int push[MAXN];
int pop[MAXN];

bool check() {
  stack<int> s;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> push[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> pop[i];
  }
  for (int i = 1, j = 1; i <= n; i++) {
    while((s.empty() && s.top() != pop[i]) && j <= n) {
      s.push(push[j++]);
    }
    if (!s.empty() && s.top() == pop[i]) {
      s.pop();
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    check();
  }
}

