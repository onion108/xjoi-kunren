// P4522 C
// Written by 27Onion.
// All right served by 27Onion, 2022.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

// #define __DEBUG__

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

// The structure describes a grade of a student.
struct student_info_t {
    // The field stores the student's id, that is the order of it in the input data, started by 1.
    int id;

    // The field stores the program_experience of the student.
    int program_experience;

    // The constructor to make an instance of it.
    student_info_t(int id, int exp) {
        this->id = id;
        this->program_experience = exp;
    }

    // Calculate how many experience it needs.
    int exp_need_to_reach(const student_info_t & another) {
        return another.program_experience - this->program_experience;
    }

    // Calculate how many experience it needs. 
    int exp_need_to_reach(int another) {
        return another - this->program_experience;
    }

    // Calculate how many experience it needs or the other need.
    int exp_need_to_become_the_same_level_with(const student_info_t & another) {
        return std::abs(exp_need_to_reach(another));
    }

    // Calculate how many experience it needs or the other need.
    int exp_need_to_get_the_level(int another) {
        return std::abs(exp_need_to_reach(another));
    }
};

int main() {
    dsprint("Application Started");
    dprint(endl);
    
    // Process input from stdin
    int size_of_data;
    cin >> size_of_data;
    std::vector<student_info_t> data;
    for (int i = 0; i < size_of_data; i++) {
        int program_exp;
        cin >> program_exp;
        data.push_back(student_info_t(i + 1, program_exp));
    }

    // Sort the data so that the two guys who have the most similar experiences will be put together.
    std::sort(data.begin(), data.end(), [](student_info_t x, student_info_t y) {
        return x.program_experience < y.program_experience;
    });

    // Calculate how many experiences they need in total
    int total_needed_exp = 0;
    for (int i = 0; i < size_of_data / 2; i++) {
        total_needed_exp += data[i * 2].exp_need_to_become_the_same_level_with(data[i * 2 + 1]);
    }

    // Output the final answer.
    cout << total_needed_exp << endl;
}
