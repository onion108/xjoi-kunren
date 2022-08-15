#include <iostream>
using namespace std;

int counter = 0;
int n, m;
int dfs(int x) {
  if (x <= 0) return 1;
  int ii, ss=0;
  counter++;
  for (ii=1;ii<=m;++ii) ss += ii*dfs(x-ii);
  return ss;
}

int main() {
  cin >> n >> m;
  cout << dfs(n) << endl;
  cout << counter;
}
