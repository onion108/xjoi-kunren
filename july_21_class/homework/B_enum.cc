#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using str = std::string;

str num_to_bin(int a) {
    str result = "";
    while (a > 0) {
        result = char(a % 2 + '0') + result;
        a /= 2;
    }
    return result;
}

void pad_to(int num, str& s) {
    while(s.length() < num) {
        s = '0' + s;
    }
}

int main() {
    int l;
    cin >> l;
    int sum = 0;
    for (int i = 0; i < pow(2, l); i++) {
        str dna = num_to_bin(i);
        pad_to(l, dna);
        if ((dna.find("101") == str::npos) && (dna.find("111") == str::npos)) {
            sum++;
        }
    }
    cout << sum << endl;
}
