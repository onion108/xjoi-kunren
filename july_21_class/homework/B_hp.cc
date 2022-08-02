#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// static constexpr const int MAXN = 1e5+114514;
// unsigned long long dp[MAXN];

string big_add(string a, string b) {
    string result = "";
    bool shouldGoOn = false;
    auto i = a.rbegin();
    auto j = b.rbegin();
    for (; i != a.rend() && j != b.rend(); i++, j++) {
        int current_digit = *i + *j - '0' * 2 + (shouldGoOn ? 1 : 0);
        if (current_digit >= 10) {
            shouldGoOn = true;
            current_digit -= 10;
        } else {
            shouldGoOn = false;
        }
        result = char(current_digit + '0') + result;
    }
    while (i != a.rend()) {
        int current_digit = *i - '0' + (shouldGoOn ? 1 : 0);
        if (current_digit >= 10) {
            shouldGoOn = true;
            current_digit -= 10;
        } else {
            shouldGoOn = false;
        }
        result = char(current_digit + '0') + result;
        i++;
    }
    while (j != b.rend()) {
        int current_digit = *j - '0' + (shouldGoOn ? 1 : 0);
        if (current_digit >= 10) {
            shouldGoOn = true;
            current_digit -= 10;
        } else {
            shouldGoOn = false;
        }
        result = char(current_digit + '0') + result;
        j++;
    }
    if (shouldGoOn) {
        result = "1" + result;
    }
    return result;
}

int main() {
    unsigned long long n;
    cin >> n;
    string dp1 = "2";
    string dp2 = "4";
    string dp3 = "6";
    string dp4 = "9";
    string dp5 = "";
    for (unsigned long long i = 5; i <= n; i++) {
        dp5 = big_add(big_add(dp4, dp2), dp1);
        dp1 = dp2;
        dp2 = dp3;
        dp3 = dp4;
        dp4 = dp5;
    }
    cout << dp5 << endl;
}

