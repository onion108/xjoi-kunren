#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::cerr;
using std::cin;

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

int ones_in_num(int n) {
    int result = 0;
    while(n) {
        result += n % 2;
        n /= 2;
    }
    return result;
}

std::string to_binary(int n) {
    std::string result;
    std::string rr;
    while(n) {
        result += (n % 2) + '0';
        n /= 2;
    }
    for (auto i = result.rbegin(); i != result.rend(); ++i) {
        rr += (*i);
    }
    return rr;
}

int main() {
    int n, l, i;
    cin >> n >> l >> i;
    std::vector<int> result;
    for (int x = 0; x < power(2, n); x++) {
        if (ones_in_num(x) > l) {
            continue;
        }
        result.push_back(x);
    }
    auto s = to_binary(result[i - 1]);
    for (int x = 0; x < (n - s.size()); x++) {
        cout << 0;
    }
    cout << s << endl;
}
