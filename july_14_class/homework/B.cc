#include <iostream>
#include <vector>  
#include <map>
#include <algorithm>
using namespace std;

static constexpr const int MAX_ARRAY_SIZE = 1e5 + 114514;

int g_ans[MAX_ARRAY_SIZE];

struct passenger_t {
    int j;
    int x;
};

struct boat_t {
    std::vector<passenger_t> data;
    int i;
    int t;
};

int main() {

    std::vector<boat_t> data;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        boat_t the_boat;
        int k;
        the_boat.i = i + 1;
        cin >> the_boat.t;
        cin >> k;
        for (int j = 0; j < k; j++) {
            passenger_t the_passenger;
            the_passenger.j = j + 1;
            cin >> the_passenger.x;
            the_boat.data.push_back(the_passenger);
        }
        data.push_back(the_boat);
    }
    std::sort(data.begin(), data.end(), [](const boat_t& x, const boat_t& y) {
        return x.t < y.t;
        });
    for (int i = 0; i < data.size(); i++) {
        std::map<int, bool> bucket;
        for (int j = 0; j < data.size(); j++) {
            if (data[i].t - 86400 < data[j].t && data[j].t <= data[i].t) {
                for (auto k : data[j].data) {
                    bucket[k.x] = true;
                }
            } else {
                break;
            }
        }
        std::printf("%d\n", bucket.size());
    }
}
