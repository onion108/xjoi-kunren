#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

// #define __DEBUG__

#ifdef __DEBUG__
#define dprintf(fmt, ...) printf(fmt, __VA_ARGS__)
#define dprint(sth) std::cerr << sth
#else
#define dprintf(fmt, ...) (void(0))
#define dprint(sth) (void(0))
#endif


static constexpr const int TWO_POWERS[] = {
    1,
    2,
    4,
    8,
    16,
    32,
    64,
    128,
    256,
    512,
    1024,
    2048,
    4096,
    8192,
    16384,
};

static constexpr const int ARRAY_LENGTH = 114514 + 1e5;

enum class tree_type {
    f_tree,
    b_tree,
    i_tree,
};

struct node_t {
    int left_idx, right_idx, parent_idx;
    tree_type the_type_of_tree;
    char type_char() {
        switch (the_type_of_tree) {
            case tree_type::f_tree:
            return 'F';
            case tree_type::b_tree:
            return 'B';
            case tree_type::i_tree:
            return 'I';
        }
    }
};

node_t g_tree[ARRAY_LENGTH];
int g_tree_next = 1;

class g_tree_operations {
    static void _core_fbi_tree_ctor(const std::string& dstr, int parent) {
        dprint("[DEBUG] here\n");

        if (dstr.length() == 1) {
            switch (dstr[0]) {
                case '1':
                g_tree[g_tree_next].left_idx = -1;
                g_tree[g_tree_next].right_idx = -1;
                g_tree[g_tree_next].parent_idx = parent;
                g_tree[g_tree_next].the_type_of_tree = tree_type::i_tree;
                if (g_tree[parent].left_idx == -1) {
                    g_tree[parent].left_idx = g_tree_next;
                } else {
                    g_tree[parent].right_idx = g_tree_next;
                }
                g_tree_next++;
                return;
                case '0':
                g_tree[g_tree_next].left_idx = -1;
                g_tree[g_tree_next].right_idx = -1;
                g_tree[g_tree_next].parent_idx = parent;
                g_tree[g_tree_next].the_type_of_tree = tree_type::b_tree;
                if (g_tree[parent].left_idx == -1) {
                    g_tree[parent].left_idx = g_tree_next;
                } else {
                    g_tree[parent].right_idx = g_tree_next;
                }
                g_tree_next++;
                return;
            }
        }

        int i = g_tree_next;
        g_tree[i].parent_idx = parent;
        if (parent != -1) {
            if (g_tree[parent].left_idx == -1) {
                g_tree[parent].left_idx = i;
            } else {
                g_tree[parent].right_idx = i;
            }
        }
        g_tree[i].left_idx = -1;
        g_tree[i].right_idx = -1;
        g_tree_next++;
        dprint("[DEBUG] ");
        dprint(dstr.substr(0, dstr.length() / 2));
        dprint(" ");
        dprint(dstr.substr(dstr.length() / 2, dstr.length() / 2));
        dprint(endl);
        _core_fbi_tree_ctor(dstr.substr(0, dstr.length() / 2), i);
        _core_fbi_tree_ctor(dstr.substr(dstr.length() / 2, dstr.length() / 2), i);
        if (g_tree[g_tree[i].left_idx].the_type_of_tree == tree_type::b_tree && g_tree[g_tree[i].right_idx].the_type_of_tree == tree_type::b_tree) {
            g_tree[i].the_type_of_tree = tree_type::b_tree;
        } else if (g_tree[g_tree[i].left_idx].the_type_of_tree == tree_type::b_tree && g_tree[g_tree[i].right_idx].the_type_of_tree == tree_type::i_tree) {
            g_tree[i].the_type_of_tree = tree_type::f_tree;
        } else if (g_tree[g_tree[i].left_idx].the_type_of_tree == tree_type::i_tree && g_tree[g_tree[i].right_idx].the_type_of_tree == tree_type::i_tree) {
            g_tree[i].the_type_of_tree = tree_type::i_tree;
        } else if (g_tree[g_tree[i].left_idx].the_type_of_tree == tree_type::i_tree && g_tree[g_tree[i].right_idx].the_type_of_tree == tree_type::b_tree) {
            g_tree[i].the_type_of_tree = tree_type::f_tree;
        }
    }
    static void _core_post(int i) {
        if (g_tree[i].left_idx != -1) {
            _core_post(g_tree[i].left_idx);
        }
        if (g_tree[i].right_idx != -1) {
            _core_post(g_tree[i].right_idx);
        }
        printf("%c", g_tree[i].type_char());
    }
    public:
    static void construct_fbi_tree_to_g_tree_from(const std::string & dstr) {
        return _core_fbi_tree_ctor(dstr, -1);
    }
    static void post() {
        _core_post(1);
    }
};

int main() {
    int str_length;
    cin >> str_length;

    // If the data out-of-range
    if (str_length > 10 || str_length < 0) {
        printf("[FRIENDLY TIPS FOR OJ] Hey! Your data is out of range (0 <= n <= 10) ! Are you polite!?\n");
        printf("[FRIENDLY TIPS FOR OJ] Hnn, hnn, hnn, eeeeeeeeeeeaaaaaaaaaaaahhhh!~ \n");
        return 114514;
    }
    str_length = TWO_POWERS[str_length];

    std::string data;
    cin >> data;

    g_tree_operations::construct_fbi_tree_to_g_tree_from(data);
    g_tree_operations::post();

    #ifdef __DEBUG__
    

    dprint(endl);
    dprint(endl);
    for (int i = 1; i <= str_length; i++) {
        dprint("[DEBUG] ");
        dprint(g_tree[i].left_idx);
        dprint(',');
        dprint(g_tree[i].right_idx);
        dprint(',');
        dprint(g_tree[i].parent_idx);
        dprint(',');
        dprint(g_tree[i].type_char());
        dprint(endl);
    }

    #endif
}
