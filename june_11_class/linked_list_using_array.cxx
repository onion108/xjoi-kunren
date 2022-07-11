#include <iostream>
using namespace std;

const int MAXN = 1e4 + 5;

struct node_t {
  int value;
  int next;
};

node_t a[MAXN];

int main() {
  auto n = 5;
  for (auto i = 1; i <= n; i++) {
    a[i].value = i * 100;
  }
  a[0].next = 1;
  a[1].next = 5;
  a[5].next = 3;
  a[3].next = 4;
  a[4].next = 2;
  a[2].next = -1;
  for(int p = a[0].next; p != -1; p = a[p].next) {
    cout << a[p].value << ", ";
  }
  cout << endl;
  a[6].value = 230;
  a[5].next = 6;
  a[6].next = 3;
  for (int p = a[0].next; p != -1; p = a[p].next) {
    cout << a[p].value << ",";
  }
  cout << endl;
  a[3].next = 2;
  for (int p = a[0].next; p != -1; p = a[p].next) {
    cout << a[p].value << ", ";
  }
  cout << endl;
}

