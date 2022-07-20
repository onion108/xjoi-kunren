#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

long long my_pow_of_2(long long n) {
  long long result = 1;
  for (int i = 0; i < n; i++) {
    result *= 2;
  }
  return result;
}

int main() {
  long long n;
  cin >> n;
  cout << 2 * (my_pow_of_2(n) - 1);
}

