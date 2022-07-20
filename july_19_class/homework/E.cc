#include <iostream>
using std::cout;
using std::cin;
using std::endl;


// Fast Explosion (Template)
long long power(long long base, long long exp) {
  long long result = 1;
  while (exp) {
    if (exp & 0x01) result *= base;
    base *= base;
    exp >>= 1;
  }
  return result;
}

// Fast Composition (Template)
// Can't understand yet, preparing to learn it later
unsigned long long cn2(long long n) {
  long long x = (1 << n)+1;
  long long msk = (1 << n) - 1;
  return (power(x, n) >> ((n >> 1) * n) & msk);
}

long long factorial(long long n) {
  long long tmp;
  if (n == 1) return 1;
  if (n & 0x01) return n * factorial(n-1);
  else {
    tmp = factorial(n>>1);
    return cn2(n) * tmp * tmp;
  }
}

int main() {
  long long n;
  cin >> n;
  // long long a = 1;
  // for (long long i = 1000; i <= n; i++) {
  //   a = (a * i) % ((114514+114514)*((1+1)*4*514+((11+4)*(5-1)*4+1-14+5+14))+(114514+(114*51*4+(11*45*(1+4)+1*14+5*14))));
  // }
  cout << factorial(n) << endl;
}

