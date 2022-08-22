// B
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
//
// Author: 27Onion

#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;

// The problem solver model.
class ProblemSolver {
  
  // =====   FIELDS   =====
  
  // Store the name list of the first round.
  std::vector<std::string> round_1;
  
  // Store the name list of the second round.
  std::vector<std::string> round_2;
  
  // A map to check if the people can or cannot actually come to the place.
  std::map<std::string, bool> can_people_come_to_place;
  
  // A map to record if the people has been chosen.
  std::map<std::string, bool> is_people_chosen;
  
  // Store the chosen people.
  std::vector<std::string> chosen_people;
  
  // Store how many people should be chosen in each name list.
  int choice_limit;
  
  // ===== END FIELDS =====
  
  
  // =====   METHODS   =====

  // Read input from the stdin.
  void input() {
    
    // Read the k.
    cin >> choice_limit;
    
    // The number of inputs.
    int input_length = 0;
    
    // Input the first group of data.
    cin >> input_length;
    for (int i = 0; i < input_length; i++) {
      std::string current;
      cin >> current;
      round_1.push_back(std::move(current));
    }
    
    // Input the second group of data.
    cin >> input_length;
    for (int i = 0; i < input_length; i++) {
      std::string current;
      cin >> current;
      round_2.push_back(std::move(current));
    }
    
    // Input peoples that can actually join the competition.
    cin >> input_length;
    for (int i = 0; i < input_length; i++) {
      std::string current;
      cin >> current;
      can_people_come_to_place[current] = true; 
    }
    
  }
  
  // Solve the problem.
  void solve() {
    
    // Choose the people from round one,
    choose_from_round_one();
    
    // Choose the people from round two.
    choose_from_round_two();
    
    // Finally, sort the answer.
    sort(chosen_people.begin(), chosen_people.end());
    
  }
  
  // ====   METHODS USED IN solve()   ====
  
  /** 
   * Choose the people with the given name and increase the counter.
   *
   * @param people_name The people's name.
   * @param counter The counter that should to increase.
   */
  void _internal_choose_people(const std::string& people_name, int& counter) {
    chosen_people.push_back(people_name);
    is_people_chosen[people_name] = true;
    counter ++;
  }
  
  /**
   * Check if a people can be chosen.
   * 
   * @param people_name The name of the people.
   * @returns If the people can be chosen.
   */
  bool _internal_choose_check(const std::string& people_name) {
    return (!is_people_chosen[people_name]) && can_people_come_to_place[people_name];
  }
  
  /**
   * The method that actually chooses people.
   * 
   * @param list The list of names.
   */
  void _internal_choose_from_list(std::vector<std::string>& list) {
    
    int actually_chosen_counter = 0;
    
    // Iterate over everything.
    for (auto i = 0; i < list.size() && actually_chosen_counter < choice_limit; i++) {
      
      // Check if the people can come here.
      if (_internal_choose_check(list[i])) {
        // The people can actually come.
        // So choose the people.
        _internal_choose_people(list[i], actually_chosen_counter);
      }
      // Otherwise, do nothing.
      
    }
    
  }
  
  // This method choose people from round 1.
  void choose_from_round_one() {
    _internal_choose_from_list(round_1);    
  }
  
  // This method choose people from round 2.
  // The method will be a bit more complex than the choose_from_round_one() because in this case we should
  // avoid people that has been already chosen in the round 1.
  void choose_from_round_two() {
    _internal_choose_from_list(round_2);
  }
  
  // ==== END METHODS USED IN solve() ====
  
  // Print the answer.
  void answer() {
    
    // Print the length.
    cout << chosen_people.size() << endl;
    
    // Print the data.
    for (auto i : chosen_people) {
      cout << i << endl;
    }
    
  }
  
  // ===== END METHODS =====
  
  public:
  
  // =====   METHODS   =====
  
  // Do some initializing in the constructor.
  ProblemSolver() {}
  
  // Start the problem solver.
  void start() {
    
    // Input the data first,
    input();

    // And then solve the problem,
    solve();
    
    // And then answer the problem.
    answer();
    
  }
  
  // Do some destructing in the destructor.
  ~ProblemSolver() {}
  
  // ===== END METHODS =====

};

int main() {
  
  // Create a ProblemSolver instance.
  ProblemSolver solver;
  
  // Run the problem solver;
  solver.start();
  
}
