#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct bigint_t {
  private:
  vector<int> digits;
  public:
  bigint_t(const string& s) {
    for (auto i = s.rbegin(); i != s.rend(); i++) {
      digits.push_back((*i) - 0x30);
    }
  }
  bigint_t() {
    digits.push_back(0);
  }
  void print_to_stdout() {
    bool encounter_non_zero = false;
    for (auto i = digits.rbegin(); i != digits.rend(); i++) {
      if (*i == 0 && !encounter_non_zero) {
        continue;
      } else {
        encounter_non_zero = true;
      }
      cout << *i;
    }
  }
  void read_from_stdin() {
    digits.clear();
    string s;
    cin >> s;
    for (auto i = s.rbegin(); i != s.rend(); i++) {
      digits.push_back((*i) - 0x30);
    }
  }
  bigint_t add(const bigint_t& rhs) {
    bigint_t result;
    result.digits = vector<int>(max(rhs.digits.size(), digits.size())+1);
    int overflow = 0;
    int i = 0;
    for (i = 0; i < min(rhs.digits.size(), digits.size()); i++) {
      result.digits[i] = digits[i] + rhs.digits[i] + overflow;
      overflow = result.digits[i] >= 10 ? 1 : 0;
      result.digits[i] %= 10;
    }
    while (i < digits.size()) {
      result.digits[i] = digits[i] + overflow;
      overflow = 0;
      i++;
    }
    while (i < rhs.digits.size()) {
      result.digits[i] = rhs.digits[i] + overflow;
      overflow = 0;
      i++;
    }
    return result;
  }
  bigint_t operator+(const bigint_t& rhs) {
    return add(rhs);
  }
  bigint_t mul_sm(int rhs) const {
    if (rhs == 0) {
      return bigint_t();
    }
    bigint_t result;
    int rr = rhs;
    int len_of_rhs = 0;
    while (rr != 0) {
      len_of_rhs++;
      rr /= 10;
    }
    result.digits = vector<int>(len_of_rhs + digits.size());
    int i;
    int overflow = 0;
    for (i = 0; i < digits.size(); i++) {
      result.digits[i] = digits[i] * rhs + overflow;
      overflow = result.digits[i] / 10;
      result.digits[i] %= 10;
    }
    if (overflow) {
      result.digits[i] = overflow;
    }
    return result;
  }
  void b10lshift() {
    digits.push_back(0);
    for (int i = digits.size() - 1; i > 0; i++) {
      digits[i] = digits[i-1];
    }
    digits[0] = 0;
  }
  void b10rshift() {
    digits.push_back(0);
    for (int i = 0; i < digits.size()-1; i++) {
      digits[i] = digits[i+1];
    }
    digits[digits.size()-1] = 0;
  }
  bigint_t mul(const bigint_t& rhs) {
    bigint_t result;
    for (auto i = rhs.digits.rbegin(); i != rhs.digits.rend(); i++) {
      cout << *i << endl;
      bigint_t a = mul_sm(*i);
      result = result + a;
      result.b10lshift();
    }
    result.b10rshift();
    return result;
  }
  int diglen() {
    return digits.size();
  }
};

int main() {
  bigint_t a, b;
  // int c;
  a.read_from_stdin();
  b.read_from_stdin();
  // cin >> c;
  (a.mul(b)).print_to_stdout();
}

