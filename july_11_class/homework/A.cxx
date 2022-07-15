#include <functional>
#include <iostream>

#define __DEBUG__

#ifdef __DEBUG__
#define dprintf(fmt, ...) printf(fmt, __VA_ARGS__)
#define dprint(sth) std::cerr << sth
#else
#define dprintf(fmt, ...) (void(0))
#define dprint(sth) (void(0))
#endif

template <typename T> class linked_list {
  public:
  struct node {
    T data;
    node* next;
    bool extra_field_for_first_elem;
    ~node() {
      if (next != nullptr) {
        delete next;
      }
    }
  };
  struct head_node {
    node* next;
    ~head_node() {
      if (next != nullptr) {
        delete next;
      }
    }
  };
  private:
  head_node* head;
  public:
  linked_list() {
    head = new head_node;
    head->next = nullptr;
  }
  ~linked_list() {
    delete head;
  }
  void append(T elem) {
    if (head->next == nullptr) {
      // Linked list is empty
      head->next = new node;
      head->next->next = nullptr;
      head->next->data = elem;
    } else {
      // Linked list isn't empty
      node* p = head->next;
      while(p->next != nullptr) {
        p = p->next;
      }
      p->next = new node;
      p->next->next = nullptr;
      p->next->data = elem;
    }
  }
  head_node* get_head() {
    return head;
  }
  bool is_empty() {
    return head->next == nullptr;
  }
  T& at(int index) {
    return this->pointer_at(index)->data; 
  }
  T& operator[](int index) {
    return at(index);
  }
  node* pointer_at(int index) {
    if (head->next == nullptr) {
      throw std::bad_function_call();
    }
    int counter = 0;
    node *p = head->next;
    while(counter != index && p->next != nullptr) {
      counter++;
      p = p->next;
    }
    if (counter != index) {
      throw std::bad_function_call();
    }
    return p;
  }
  void remove_at(int index) {
    #ifdef __DEBUG__
    node* it = head->next;
    while(it != nullptr) {
      dprint(it->data);
      dprint(' ');
      it = it->next;
    }
    dprint(std::endl);
    #endif
    
    if (is_empty()) return; 
    node* p = this->pointer_at(index);
    if (p == head->next) {
      head->next = p->next;
      p->next = nullptr;
      delete p;
    }
  }
  void remove_after_node(node* node_ptr) {
    #ifdef __DEBUG__
    dprint("[DEBUG] ");
    node* it = head->next;
    while(it != nullptr) {
      dprint(it->data);
      dprint(' ');
      it = it->next;
    }
    dprint(std::endl);
    dprint("Node ptr: ");
    dprint((void* ) node_ptr->next);
    dprint(std::endl);
    #endif
    node* p = node_ptr->next;
    if (p == nullptr) {
      return;
    }
    node_ptr->next = p->next;
    p->next = nullptr;
    delete p;
    dprint("[DEBUG] Successfully performed a delete operation. \n");
  }
  void remove_first() {
    #ifdef __DEBUG__
    dprint("[DEBUG] ");
    node* it = head->next;
    while(it != nullptr) {
      dprint(it->data);
      dprint(' ');
      it = it->next;
    }
    dprint(std::endl);
    dprint("Node ptr: ");
    dprint((void* ) head->next);
    dprint(std::endl);
    #endif
    if (head->next == nullptr) return;
    node* p = head->next;
    head->next = p->next;
    p->next = nullptr;
    delete p;
    dprint("[DEBUG] Successfully performed a delete operation for the first element. \n");
    return;
  }
};

#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  int n;
  cin >> n;
  linked_list<int> lst;
  for (int i = 0; i < n; i++) {
    int el;
    scanf("%d", &el);
    lst.append(el);
  }
  vector<linked_list<int>::node*> ds;
  for (int i = 0; i < n; i++) {
    int el;
    scanf("%d", &el);
    if (el == 1) {
      ds.push_back(new linked_list<int>::node{0, nullptr, true});
    } else {
      ds.push_back(lst.pointer_at(el-2));
    }
  }
  for (auto& i : ds) {
    if (!i->extra_field_for_first_elem) {
      printf("%d%c%d%c", i->data, ' ', (i->next->next == nullptr ? -1 : i->next->next->data), '\n');
      for (auto& j : ds) {
        if (j == nullptr) continue;
        if (j == i->next) {
          j = i;
        }
      }
      lst.remove_after_node(i);
    } else {
      printf("%d%c%d%c", -1, ' ', (lst.get_head()->next->next == nullptr ? -1 : lst.get_head()->next->next->data), '\n');
      for (auto& j : ds) {
        if (j == nullptr) continue;
        if (j == lst.get_head()->next) {
          j = new linked_list<int>::node{0, nullptr, true};
        }
      }
      lst.remove_first();
      delete i;
    }
    i = nullptr;
  }
}

