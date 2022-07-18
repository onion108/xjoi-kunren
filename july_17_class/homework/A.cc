#pragma region // Rustify C++
#define fn auto
using i32 = int;
using i64 = long long;
using i8 = char;
using i16 = short;
using u32 = unsigned int;
using u64 = unsigned long long;
using u8 = unsigned char;
using u16 = unsigned short;
#define pub public:
#define priv private:
#define use using
#pragma endregion

#include <iostream>
#include <algorithm>
use std::printf;
use std::scanf;
use std::sort;


struct course_t {
    pub i32 start_time;
    pub i32 end_time;
};

static constexpr const i32 MAX_SIZE = 114514+1e5;
course_t courses[MAX_SIZE];

fn main() -> i32 {
    i32 n;
    scanf("%d", &n);
    for (i32 i = 1; i <= n; i++) {
        course_t fucking_course;
        scanf("%d%d", &fucking_course.start_time, &fucking_course.end_time);
        courses[i] = fucking_course;
    }
    std::sort(courses + 1, courses + 1 + n, [](course_t x, course_t y) {
        if (x.start_time != y.start_time) return x.start_time < y.start_time;
        else return x.end_time < y.end_time;
    });
    i32 course_counter = 0;
    course_t last_selected_course = course_t {-1, -1};
    for (int i = 1; i <= n; i++) {
        if (courses[i].start_time < last_selected_course.end_time) {
            continue;
        }
        last_selected_course = courses[i];
        course_counter++;
    }
    printf("%d\n", course_counter);
    return 0;
}
