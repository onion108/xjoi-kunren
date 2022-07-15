#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;

static constexpr const int g_time_lengths[] = {
    -1, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335
};

bool g_year[367];

int main() {
    int total_dates;
    cin >> total_dates;
    for (int i = 0; i < total_dates; i++) {
        int month, day;
        cin >> month >> day;
        int idx = g_time_lengths[month];
        idx += day;
        g_year[idx] = true;
    }
    int ans = -114514-1e5;
    int counter = 0;
    for (int i = 1; i <= 366; i++) {
        if (g_year[i]) {
            counter = 0;
        } else {
            counter++;
        }
        if (counter > ans) {
            ans = counter;
        }
    }
    cout << std::fixed << std::setprecision(0) << (double(ans * 24 * 60 * 60) / 366.0) << endl;
}
