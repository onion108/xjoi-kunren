n = int(input("N = "))

def countFiveOf(num):
    fcounter = 0
    n_tmp = num
    while n_tmp != 0:
        a = n_tmp % 10
        n_tmp //= 10
        if a == 5:
            fcounter += 1
    return fcounter
     
for nn in range(1, n+1):
    counter = 0 
    for i in range(10 ** (nn - 1), 10 ** nn):
        cfoi = countFiveOf(i)
        if cfoi % 2 == 0 and cfoi != 0:
            counter += 1
    print(f"dp[{nn}][2] = {counter}")