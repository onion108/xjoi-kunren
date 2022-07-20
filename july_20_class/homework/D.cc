#include <iostream>
#include <algorithm>
using namespace std;

static constexpr const int ARR_SIZE = 1024;

int dp[ARR_SIZE][ARR_SIZE];
int dp2[ARR_SIZE][ARR_SIZE];
int weig[ARR_SIZE];
int vect[ARR_SIZE];
int valu[ARR_SIZE];

int main() {
    int w, v, n;
    cin >> w >> v >> n;
    for (int i = 1; i <= n; i++) {
        int cw, cv, cv2;
        cin >> cw >> cv >> cv2;
        weig[i] = cw;
        vect[i] = cv;
        valu[i] = cv2;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= vect[i]; j--) {
            if (dp[i-1][j] > dp[i-1][j-vect[i]]+valu[i]) {
                dp[i][j] = dp[i-1][j];
                // didn't put;
            } else {
                dp[i][j] = dp[i-1][j-vect[i]]+valu[i];
                // put it
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = w; j >= weig[i]; j--) {
            if (dp2[i-1][j] > dp2[i-1][j-weig[i]]+valu[i]) {
                dp2[i][j] = dp2[i-1][j];
                // didn't put;
            } else {
                dp2[i][j] = dp2[i-1][j-weig[i]]+valu[i];
                // put it
            }
        }
    }
    cout << dp[n][v] << endl;
    cout << dp2[n][w] << endl;
}
