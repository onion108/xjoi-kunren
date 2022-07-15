#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;

static constexpr const int MAXL = 1024;
static constexpr const int MAXN = 114514+1e5;

std::vector<int> t[MAXN];
char s[MAXN];
int max_depth = -114514-1e5;
int w[MAXN];

void dfs(int id = 1, int depth = 1) {
    max_depth = std::max(max_depth, depth);
    w[depth]++;
    for (int i = 0; i < t[id].size(); i++) {
        dfs(t[id][i], depth + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    fgets(s, MAXL, stdin);
    for (int i = 1; i <= n; i++) {
        fgets(s, MAXL, stdin);
        int l = std::strlen(s), num = 0, p = 0;
        for (int j = 0; j < l; j++) {
            if ('0' <= s[j] && s[j] <= '9') {
                // Is a digit
                num = num * 10 + s[j] - '0';
            } else {
                if (!num) continue;
                if (p) {
                    t[p].push_back(num);
                } else {
                    p = num;
                }
                num = 0;
            }
        }
    }
    // TODO: Find root ..?
    dfs();
    printf("%d\n%d\n", max_depth, *std::max_element(w + 1, w + n + 1));
}
