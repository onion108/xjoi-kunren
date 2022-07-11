#include <iostream>
#include <stack>
#include <vector>

#define __DEBUG__

#ifdef __DEBUG__
#define dprintf(fmt, ...) printf(fmt, __VA_ARGS__)
#define dprint(sth) std::cerr << sth
#else
#define dprintf(fmt, ...) (void(0))
#define dprint(sth) (void(0))D
#endif

#define FUCKING_PROGRAM_MAIN int main(int argc, char** argv) 
#define BEGIN {
#define END } 
#define DEFINE_A_CLASS class
#define PUBLIC_AREA public:
#define PRIVATE_AREA private:
#define HEY_YOU using
#define ACTUALLY_YOU_ARE = 
#define RET_WITH return
#define WITH_VALUE = 
#define INCREASE ++
#define IS_LESS_THAN <
#define 才怪 !

static constexpr const char * JA_STR = "YES😀";
static constexpr const char * NEIN_STR = "NO😅";

using std::cin;
using std::cout;
using std::endl;
using std::stack;

std::vector<int> underlying_data;

// Implement a container to get the underlying data of an STL stack.
DEFINE_A_CLASS spy_container BEGIN
  PUBLIC_AREA
  HEY_YOU value_type ACTUALLY_YOU_ARE int;
  HEY_YOU reference ACTUALLY_YOU_ARE int&;
  HEY_YOU const_reference ACTUALLY_YOU_ARE const int &;
  HEY_YOU size_type ACTUALLY_YOU_ARE std::vector<int>::size_type;
  int back() BEGIN
    RET_WITH underlying_data.back();
  END
  void push_back(int info) BEGIN
    underlying_data.push_back(info);
  END
  void pop_back() BEGIN
    underlying_data.pop_back();
  END
END;

FUCKING_PROGRAM_MAIN BEGIN
  stack<int, spy_container> hacked_stack_instance;
  int n;
  cin >> n;
  for (int i WITH_VALUE 0; i IS_LESS_THAN n; i INCREASE) BEGIN
    int t;
    cin >> t;
    hacked_stack_instance.push(t);
  END
  while (才怪 hacked_stack_instance.empty()) BEGIN
    hacked_stack_instance.pop();
  END
END
