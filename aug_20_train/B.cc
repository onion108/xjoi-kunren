// B
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <functional>
#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;

/// Try transform all the `A`s in the string.
/// @param s The string. The string must contains `A` and `B` only.
/// @returns How many times we should do the transform to turn `s` into a non-decresing order by only transforming A to B.
int try_transform_all_a_in_the_string(const std::string& s) {

    // A flag to record if we has ocurred B.
    bool is_b_occured = false;
    
    // A counter to count how many transforms we should do.
    int transformation_count = 0;

    // Iterate over the string.
    for (auto i : s) {

        // Check for i.
        switch (i) {
            
            // If it's A.
            case 'A':

            // Check if we've occured B.
            if (is_b_occured) {

                // If we do, then do a transformation.
                // We won't do the actual transformation, but add the counter by 1.
                transformation_count += 1;

            }

            break;

            // If it's B.
            case 'B':

            // Record that we occured a B.
            if (!is_b_occured) {
                is_b_occured = true;
            }

            break;

            // Invalid string.
            default:
            throw std::bad_function_call();

        }

    }
    
    // Return the result.
    return transformation_count;

}

/// Try transform all the `B`s in the string.
/// @param s The string. The string must contains `A` and `B` only.
/// @returns How many times we should do the transform to turn `s` into a non-decresing order by only transforming B to A.
int try_transform_all_b_in_the_string(const std::string& s) {

    // A flag to record if we occured A.
    bool is_a_occured = false;

    // A counter to count the transformations.
    int transformation_count = 0;

    // Iterate over the string, but this time, we iterate it reversely.
    for (auto _iter = s.rbegin(); _iter != s.rend(); _iter++) {

        // Check for the current character.
        switch (*_iter) {

            // If it's `A`.
            case 'A':

            // Record that we've encountered A.
            if (!is_a_occured) {
                is_a_occured = true;
            }

            break;

            // If it's `B`.
            case 'B':

            // If we've occured A, then we should turn `B` into `A`.
            if (is_a_occured) {

                // Do the transformation. a.k.a, increase the `transformation_count`.
                transformation_count += 1;

            }

            break;

            // If not, then throw an exception.
            default:

            throw std::bad_function_call();

        }

    }

    // Return the value.
    return transformation_count;

}

/// This function checks how many times we should do to turn a string into a non decreasing order.
/// @param s The string. The string must contains `A` and `B` only.
/// @returns How many times we should do the transform to turn `s` into a non-decresing order.
int how_many_times_we_should_do_to_turn_a_string_into_non_decreasing_order(const std::string& s) {

    return std::min(try_transform_all_a_in_the_string(s), try_transform_all_b_in_the_string(s));

}


int main() {

    // I haven't write anything about the input/output in the function main for days.
    
    // The inputted string.
    std::string _s;
    cin >> _s;

    // Calculate and output the answer.
    cout << how_many_times_we_should_do_to_turn_a_string_into_non_decreasing_order(_s) << endl;

}

