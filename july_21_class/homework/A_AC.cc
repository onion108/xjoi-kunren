#include <cstdio>
#include <iostream>

using namespace std;

int n, k, p = 10000, f[1010][1010];

int main()
{
    scanf("%d%d", &n, &k);
    f[1][0] = 1;//初始条件，1的逆序为0，且只有1个排列
    for (int i = 2; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j <= k; j++)
        {
            (sum += f[i - 1][j]) %= p;
            f[i][j] = sum;
            if(j >= i - 1)//如果j - i + 1>=0了，sum的求和区间左端点就>=0
                (((sum -= f[i - 1][j - i + 1]) %= p)+= p) %= p;
        }
    }
    printf("%d\n", f[n][k]);
    return 0;
}
