dp = [0, 2, 4, 6, 9]
n = int(input())
for i in range(5, n+1):
    dp.append(dp[i-1]+dp[i-3]+dp[i-4])
print(dp[n])
