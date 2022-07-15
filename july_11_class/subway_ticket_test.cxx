#include <iostream>
#include <list>
#include <vector>
using namespace std;

static const int WAY_SUBWAY = 0;
static const int WAY_BUS = 1;

struct subway_ticket_t {
  int price;
  int ctime;
  private:
  bool valid;
  public:
  subway_ticket_t(int price, int ctime, bool valid = true) {
    this->price = price;
    this->ctime = ctime;
    this->valid = valid;
  }
  void invalid() {
    this->valid = false;
  }
  bool is_valid() {
    return this->valid;
  }
};

int main() {
  int input_length;
  cin >> input_length;
  list<subway_ticket_t> data;
  int total_cost = 0;
  for (auto i = 0; i < input_length; i++) {
    int way, price, time;
    cin >> way >> price >> time;
    if (way == WAY_BUS) {
      // Is bus
      bool can_free = false;
      for (auto iter = data.begin(); iter != data.end(); iter++) {
        if (iter->is_valid()) {
          continue;
        }
        if (time - iter->ctime > 45) {
          iter->invalid();
          continue;
        }
        if (iter->price < price) {
          continue;
        }
        can_free = true;
        iter->invalid();
        break;
      }
      total_cost += can_free ? 0 : price;
    } else if (way == WAY_SUBWAY) {
      // Is subway
      data.push_back(subway_ticket_t(price, time));
    }
  }
  printf("%d\n", total_cost);
}

