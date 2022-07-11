#include <iostream>
using namespace std;

const int MAXN = 100;

int st[MAXN];

int main() {
  int n = 5;
  int top = 0;
  for (int i = 1; i <= n; i++) {
    st[++top] = i * 10;
  }
  while (top) {
    printf("Top at: %d\n", top);
    printf("Goodbye, %d!\n", st[top--]);
  }
}

