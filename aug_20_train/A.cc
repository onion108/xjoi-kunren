// A
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// The `ProblemSolver` model.
class ProblemSolver {

    // Store the data from the standard input.
    std::vector<int> _data;

    // A bucket to analyze.
    std::map<int, int> _buckets;

    // The answer number.
    int _answer;

    // The input stage.
    void _input() {
        
        // Input a number as the length of the array.
        int lcl_length;             // Where `lcl` stands for `local`.
        cin >> lcl_length;

        // Input the data in order.
        for (int i = 0; i < lcl_length; i++) {

            // Input the current data and add it to the end of the vector.
            int lcl_current;        // Where `lcl` stands for `local`.
            cin >> lcl_current;
            
            // Push the number into the array.
            _data.push_back(lcl_current);

        }

    }

    // The process stage.
    void _process() {

        // Iterate each element in the data.
        for (auto i : _data) {

            // `i` appears once, so record it.
            _buckets[i] += 1;

        }

        // Iterate over the buckets and find which is odd.
        for (auto i : _buckets) {

            // Check if the value is odd.
            // This statement is equal to `if (i.second % 2 == 1) {}`
            if (i.second % 2) {

                // Because there are only one element which is odd,
                // so return immediately once we find the element.
                _answer = i.first;
                return;

            }

        }

    }

    // The output stage.
    void _output() {

        // Output the answer directly.
        cout << _answer << endl;

    }

    public:

    // The constructor of the `ProblemSolver`.
    // The lifetime of a ProblemSolver object has been splitted into three, where
    // The input stage inputs data from the stdin;
    // The process stage processes data and store it into a field.
    // The output stage output the value in that field.
    // Note the calling the constructor won't solve the problem immediately.
    ProblemSolver() {}

    // Solve the problem.
    void solve() {

        // First input the data from stdin,
        _input();

        // then we process it,
        _process();

        // then output it.
        _output();

    }

};


int main() {

    // Construct a problem solver.
    ProblemSolver solver;

    // Solve the problem using the solver.
    solver.solve();

}
