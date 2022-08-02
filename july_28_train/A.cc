#include <algorithm>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

static constexpr const int MAXN = 1e5+114514;

// Debug Kit Start
#ifdef __DEBUG__
#define debug(__b) __b
#else
#define debug(__unused)
#endif
// Debug Kit End

// dp[i] means the length of the maxium range until i.
int dp[MAXN];
int data[MAXN];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> data[i];
  }
  
  // If the first element is a multiple of 7, then dp[1] is 1
  if (!(data[1] % 7)) {
    dp[1] = 1;
  } else {
    dp[1] = 0;
  }
  for (int i = 2; i <= n; i++) {
    int max_seq_len = 0;
    // Find the max seq until n;
    for (int j = 1; j <= i; j++) {
      int sum = 0;
      for (int k = j; k <= i; k++) {
        sum += data[k];
      }
      if (!(sum % 7)) {
        max_seq_len = std::max(max_seq_len, i-j+1);
      }
    }
    dp[i] = std::max(dp[i-1], max_seq_len);
  }
  debug({
    for (int i = 1; i <= n; i++)
      cout << "dp[" << i << "] = " << dp[i] << endl;
  })
  cout << dp[n] << endl;
}


