#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> st;
  int n = 5;
  for (int i = 1; i <= n; i++) {
    st.push(i * 10);
  }
  while (!st.empty()) {
    printf("Let's look at the top. Who are you? Oh, you are %d!", st.top());
    printf("Goodbye, %d!", st.top());
    st.pop();
  }
}

