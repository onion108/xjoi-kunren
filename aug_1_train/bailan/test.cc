#include <chrono>
#include <thread>
#include <iostream>

using std::cin;
using std::cout;

int main() {
  bool a_ok = false;
  std::thread a([&a_ok]() {
    std::this_thread::sleep_for(std::chrono::nanoseconds(1000000));
    cout << "Hello from thread 1\n";
    a_ok = true;
  });
  //a.join();
  cout << "Hello from main()" << std::endl;
  while(!a_ok);
  a.detach();
}

