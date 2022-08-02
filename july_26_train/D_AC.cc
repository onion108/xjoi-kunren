#include <iostream>
using namespace std;

static constexpr const int MAXN = 114514+1e5;

long long primes[MAXN];
bool is_prime[MAXN];

int cnt_prime;
long long cnt;
long long n, m;
void dfs(long long k, long long p) {
  if (k > cnt_prime) {
    cnt++;
    return;
  }
  dfs(k+1, p);
  long long t = primes[k] * primes[k];
  for (p = p * primes[k]; p <= n; p *= t) {
    dfs(k+1, p);
  }
}

int main() {
  cin >> n >> m;
  m = std::min(n, m);
  for (long long i = 2; i <= m; i++) {
    is_prime[i] = true;
  }
  for (long long i = 2; i <= m; i++) {
    if (!is_prime[i]) {
      continue;
    }
    for (long long j = i * i; j <= m; j += i) {
      is_prime[j] = false;
    }
  }
  dfs(1, 1);
  cout << cnt << endl;
}

