
def fac(n):
    if n == 0:
        return 1
    a = 1
    for i in range(1, n+1):
        a *= (i % ((114514+114514)*((1+1)*4*514+((11+4)*(5-1)*4+1-14+5+14))+(114514+(114*51*4+(11*45*(1+4)+1*14+5*14)))))
    return a % ((114514+114514)*((1+1)*4*514+((11+4)*(5-1)*4+1-14+5+14))+(114514+(114*51*4+(11*45*(1+4)+1*14+5*14))))

print("{", end='')
for i in range(0, 1000):
    fuck_you = fac(i)
    print(f"{fuck_you},", end='')
print("}")