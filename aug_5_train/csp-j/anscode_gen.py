f = open("answer.txt", 'r')
fc = f.read();
print("#include <iostream>\n#include<string>\nstring ans[64];")
print("\nint main() {")
counter = 1
state = 0
pairer = 0
buffer = ""
for i in fc:
    if state == 0:
        if i in ['A','B','C','D','T','F']:
            print("  ans[{}]=\"{}\";".format(counter, i))
            counter += 1
        elif i == '[':
            state = 1
            buffer = ""
    elif state == 1:
        if i == ']' and pairer == 0:
            print("  ans[{}]=\"\"; /*{}*/".format(counter, buffer))
            counter += 1
            state = 0
            continue
        elif i == '[':
            pairer += 1
        elif i == ']':
            pairer -= 1
        buffer += i
print("  int n;\n  std::cin >> n;\n  std::cout << ans[n] << std::endl;")
print("}")

