f = open("answer.txt", 'r')
fc = f.read();
print("#include <iostream>\nchar ans[64];")
print("\nint main() {")
counter = 1
for i in fc:
    if i in ['A','B','C','D','T','F']:
        print("  ans[{}]='{}';".format(counter, i))
        counter += 1
print("  int n;\n  std::cin >> n;\n  std::cout << ans[n] << std::endl;")
print("}")

