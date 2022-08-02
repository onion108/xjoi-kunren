#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105;
typedef long long number_t;

int n, dp[N][N]; //dp[i][j]表示第i秒敲了第j个地鼠时的价值最大值

struct data_mice_t {
    int t;
    int v;
};

data_mice_t a[N];

bool cmp(data_mice_t x,data_mice_t y) {
    return  x.t==y.t?x.v>y.v:x.t<y.t;
}

int main() {
    
    cin >> n;
    int maxt = 0;
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].t);
        maxt = max(maxt, a[i].t);
    }
    
    // Input the data
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i].v);
    }
    
    // Sort the data by value and time
    sort(a+1,a+n+1,cmp);
    
    // Dynamic Programming
    // Iterate over times
    for (int i = 1; i <= maxt; i++) {
        // Iterate over things 
        for (int j = 1; j <= n; j++) {
            if (a[j].t >= i) {
                
                for (int k = 1; k<j; k++) {//选前面的，因为排序后：后面的肯定会在j之后选
                    dp[i][j] = max(dp[i][j],dp[i-1][k]+a[j].v);
                }
                
                dp[i][j] = max(dp[i][j],a[j].v);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    int ans = 0;
    
    for (int i=1; i<=n; i++) {
        ans = max(ans,dp[maxt][i]);
    }
    
    cout << ans;
    return 0;
}
