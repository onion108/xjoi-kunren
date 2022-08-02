def num_to_bin(a):
    result = ""
    while a > 0:
        result = str(a % 2) + result
        a //= 2
    return result

def pad_to(a, b):
    result = a
    while len(result) < b:
        result = "0" + result
    return result

last_sum = 0
for i in range(1, 16):
    print("L = " + str(i))
    sum = 0
    for j in range(2**i):
        dna = pad_to(num_to_bin(j), i)
        if not (("101" in dna) or ("111" in dna)):
            sum += 1
    print("%d: (%d increased)" % (sum, sum - last_sum))
    last_sum = sum
    
