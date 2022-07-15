#include <iostream>
#include <queue>
using std::cin;
using std::cout;
using std::queue;
using std::endl;



int main() {
    queue<int> monkeys;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        monkeys.push(i);
    }
    int last_popped_monkey = 1e5+5;
    int counter = 1;
    while(!monkeys.empty()) {
        int current_popped_monkey = monkeys.front();
        if (counter == k) {
            counter = 1;
            monkeys.pop();
            continue;
        }
        counter++;
        last_popped_monkey = current_popped_monkey;
        monkeys.pop();
        monkeys.push(current_popped_monkey);
    }
    cout << last_popped_monkey << endl;
}
