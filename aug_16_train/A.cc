// A
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//
// =====   DECLARATIONS   =====
// I PROMISE THIS CODE IS ALL WRITTEN BY MYSELF AND I DIDN'T COPY ANY OF THE CODE
// FROM OTHER PLACES. IF YOU'RE CONFUSED WITH THE CODE STYLE, YOU CAN CHECK MY 
// REPOS ON GITHUB (https://github.com/onion108/). BECAUSE THIS FILE IS NOT WRIT-
// TEN IN THE OI-STYLED CODES, SO IN ORDER TO AVOID MISUNDERSTANDING, I PUT THE 
// DECLARATIONS HERE.
//
// P.S.: I WANT TO PUBLISH THIS CODE UNDER THE GPL-2.0 LICENSE.
//       BUT I'M NOT ABLE TO PUT A LICENSE IN AN OI CODE FILE.
//       HOW SAD! 
// ===== END DECLARATIONS =====

#include <cstdlib>
#include <functional>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;

// The option type, inspired from Rust.
// I found it very useful.
// I may publish it as a library to the GitHub if I have time.
template <typename T>
struct Option {

  private:

  /// Check if the value exists.
  /// In Rust, we use enum + pattern match to do it. But C++ don't have the support of this.
  /// How poor the C++ is.
  bool has_value;

  /// Store the actual value.
  T value;

  /// Make the default constructor private.
  /// So you must construct Option<T> with two factory methods, Some(T) and None().
  Option() {}  

  public:

  /// Create an Option<T> with value.
  ///
  /// @returns The option instance.
  static Option<T> Some(T value) {
    Option opt;
    opt.has_value = true;
    opt.value = value;
    return opt;
  }

  /// Create an Option<T> with no value.
  ///
  /// @returns The option instance.
  static Option<T> None() {
    Option opt;
    opt.has_value = false;
    return opt;
  }

  /// Check if the value is some.
  /// In Rust we often use pattern matching instead of calling these methods.
  /// But C++ don't have it.
  bool is_some() const {
    return this->has_value;
  }

  /// Check if the value is none.
  bool is_none() const {
    return !this->has_value;
  }

  /// Unwrap the value.
  /// If the value didn't exist, the program panics.
  T unwrap() const {
    assert(this->has_value);
    return this->value;
  }

  /// Unwrap the value.
  /// If the unwrapping fails, the program panics with the custom message.
  ///
  /// @param message The custom message to show if the unwrapping failed.
  /// @returns The unwrapped value.
  T expect(std::string message) const {
    if (this->has_value) {
      return this->value;
    } else {
      std::cerr << message << std::endl;
      exit(-1);
    }
  }

  /// Unwrap the value.
  /// If the unwrapping fails, return the default value.
  ///
  /// @param def The default value.
  /// @returns The unwrapped value or the default value if the unwrapping fails.
  T unwrap_or(T def) const {
    return this->has_value?value:def;
  }

  /// Map an `Option<T>` to an Option<U>.
  /// The mapping follows the following rules:
  /// `None` => `None`
  /// `Some(T)` => `Some(U)`
  /// You can use this to operate on `Option<T>` instances safely, without any of the runtime panic.
  /// Example:
  ///
  /// ```C++
  /// Option<int> op1 = Option<int>::Some(1);
  /// Option<double> op2 = op1.map<double>([](int value) -> double { return double(value) / 2.0; });
  /// // The op2 will be Some(0.5) now.
  /// assert(op2.unwrap() == 0.5);
  ///
  /// Option<int> op3 = Option<int>::None();
  /// Option<double> op4 = op1.map<double>([](int value) -> double { return double(value) / 2.0; });
  /// // The op4 will be None() now.
  /// assert(op4.is_none());
  /// ```
  ///
  /// @param fn The function to perform the mapping.
  /// @returns The mapped value.
  template <typename U>
  Option<U> map(std::function<U(T)> fn) const {
    if (!this->has_value) {
      return Option<U>::None();
    } else {
      return Option<U>::Some(fn(this->value));
    }
  }
};

class ProblemSolver {
  
  // The list of the data.
  std::vector<Option<int>> data;

  // The answer (which will be use in output(). )
  int answer;

  // A counter to see how many people alive (i.e., haven't quited yet)
  int alive;
  
  public:
  
  // Input and initialize the data.
  void input() {

    // Initialize the alive count.
    alive = 0;
    
    // Initialize the input length.
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
      int current;
      cin >> current;
      data.push_back(current != 0 ? Option<int>::Some(current) : Option<int>::None());
      if (data.back().is_some()) {
        alive++;
      }
    }
    
  }
  
  // Solve the problem.
  void solve() {
    
    // Initialize necessary variables.
    answer = 0;
    
    while(true) {
      // 1. Find the minimum.
      auto min_iter = std::min_element(data.begin(), data.end(), [](const Option<int>& x, const Option<int>& y) {
        // The comparator function.
        // The hard part is that how to process None values and Some values.
        // In this case, if there is None values, we treat it as Infinity which will be bigger than all the numbers.
        if (x.is_some() && y.is_some()) {
          // If the x and y are all non-null, then unwrap them and compare it.
          return x.unwrap() < y.unwrap();
        } else {
          // If the x is none.
          if (x.is_none()) {
            // Then x will be bigger, i.e., x > y, so return false.
            return false;
          } else if (y.is_none()) {
            // Otherwise, if y is None, i.e., x < y, so return true.
            return true;
          } else {
            // Should be unreachable. But to avoid unnecessary warnings, we return something here.
            return true;
          }
          // It's not neccesary to treat all nones, because
          // 1 - They will be soon replaced with another non-null value because we're finding the minimum and Option<T>::None() are always the biggest.
          // 2 - If all items of the list are none, then we will process it later.
        }
      });
      
      // Check if all the items are None().
      if (min_iter->is_none()) {

        // All people are quitted. Break the loop.
        break;

      } else {
        // Otherwise, remove the (poor) child and update all the data.
        auto min_value = min_iter->unwrap();
        for (auto & i : data) {

          // Do the substract.
          i = i.map<int>([&min_value](int x) -> int { return x - min_value; });

          // If the number drop to zero, kick it out.
          if (i.is_some() && i.unwrap() == 0) {
            i = Option<int>::None();
            alive--;
          }

        }

        // Increase the answer count.
        answer++;
      }
      
    }
    
  }
  
  // Output the answer.
  void output() {
    cout << answer << endl;
  }
  
};


// The entry point.
int main() {

  // Create a ProblemSolver instance.
  ProblemSolver solver;
  
  solver.input();
  
  solver.solve();
  
  solver.output();
  
}