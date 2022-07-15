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
#define NOP !
#define PLEASE ;
#define IMPORT using

static constexpr const char * JA_STR = "YES😀" PLEASE
static constexpr const char * NEIN_STR = "NO😅" PLEASE

IMPORT std::cin PLEASE
IMPORT std::cout PLEASE
IMPORT std::endl PLEASE
IMPORT std::stack PLEASE

std::vector<int> underlying_data PLEASE

// Implement a container to get the underlying data of an STL stack.
DEFINE_A_CLASS spy_container BEGIN
  PUBLIC_AREA
  HEY_YOU value_type ACTUALLY_YOU_ARE int PLEASE
  HEY_YOU reference ACTUALLY_YOU_ARE int& PLEASE
  HEY_YOU const_reference ACTUALLY_YOU_ARE const int & PLEASE
  HEY_YOU size_type ACTUALLY_YOU_ARE std::vector<int>::size_type PLEASE
  int back() BEGIN
    RET_WITH underlying_data.back() PLEASE
  END
  void push_back(int info) BEGIN
    underlying_data.push_back(info) PLEASE
  END
  void pop_back() BEGIN
    underlying_data.pop_back() PLEASE
  END
END PLEASE

FUCKING_PROGRAM_MAIN BEGIN
  stack<int, spy_container> hacked_stack_instance PLEASE
  int n PLEASE
  cin >> n PLEASE
  for (int i WITH_VALUE 0 PLEASE i IS_LESS_THAN n PLEASE i INCREASE) BEGIN
    int t PLEASE
    cin >> t PLEASE
    hacked_stack_instance.push(t) PLEASE
  END
  while (NOP hacked_stack_instance.empty()) BEGIN
    hacked_stack_instance.pop() PLEASE
  END
END
