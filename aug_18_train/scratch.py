table = []

for i in range(41):
    table.append(3 ** i);

print("{")
for i in table:
    if i <= 9223372036854775807:
        print(f"\t{{{i}, true}}, ")
    else:
        break
print("}")
