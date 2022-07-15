#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

#define __DEBUG__

/* Debugger */

#ifdef __DEBUG__
#define dprint(obj) std::cerr << obj
#define dsprint(obj) std::cerr << "[DEBUG] " << obj
#define debug_do(block) block
#else
#define dprint(obj) (void(0))
#define dsprint(obj) (void(0))
#define debug_do(block)
#endif

/* End Debugger */

struct entity_t {
    int id;
    int marks;
};

int main() {
    std::vector<entity_t> entities;
    debug_do({
        dsprint("Application Started\n");
    })
    int all_people, plan_people;
    cin >> all_people >> plan_people;
    for (int i = 1; i <= all_people; i++) {
        auto entity = entity_t{};
        cin >> entity.id >> entity.marks;
        entities.push_back(entity);
    }
    std::sort(entities.begin(), entities.end(), [](entity_t x, entity_t y) {
        return x.id < y.id;
    });
    std::stable_sort(entities.begin(), entities.end(), [](entity_t x, entity_t y) {
        return x.marks > y.marks;
    });
    int mark_limit = entities[int(double(plan_people) * 1.5)].marks;
    std::vector<entity_t> result;
    for (auto entity : entities) {
        if (entity.marks >= mark_limit) {
            result.push_back(entity);
        }
    }
    std::printf("%d %d\n", mark_limit, result.size());
    for (auto entity : result) {
        std::printf("%d %d\n", entity.id, entity.marks);
    }
}

