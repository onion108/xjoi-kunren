#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 有一个容量为V的背包，还有n个物体。现在忽略物体实际几何形状，我们认为只要背包的剩余容量大于等于物体体积，那就可以装进背包里。每个物体都有两个属性，即体积w和价值v。
 * 问：如何向背包装物体才能使背包中物体的总价值最大？
*/

int main() {
    vector<int> w, v;
    vector<int> f;
    int V, n;
    cin >> V >> n;
    w.push_back(0);
    v.push_back(0);
    for (int i = 1; i <= n; i++) {
        int cur_w, cur_v;
        cin >> cur_w >> cur_v;
        w.push_back(cur_w);
        v.push_back(cur_v);
    }
    f = vector<int>(V + 1, 0);
    // DP
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= w[i]; j--) {
            f[j] = max(f[j], f[j-w[i]]+v[i]);
        }
    }

    int ans = f[V];
    cout << ans << endl;
}
