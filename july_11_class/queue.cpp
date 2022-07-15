#include <queue>
#include <iostream>
using namespace std;

int main() {
  queue<int> q;
  int n = 5;
  for (int i = 1; i <= n; i++) {
    printf("[Mr. %d] Ha hai! I'm in!\n", i * 10);
    q.push(i * 10);
  }
  while(!q.empty()) {
    printf("[Mr. %d] Ha hai! I'm out!\n", q.front());
    q.pop();
  }
}

