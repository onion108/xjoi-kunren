#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
using std::cout;
using std::cin;
using std::endl;

#define __DEBUG__

#ifdef __DEBUG__
#define dprintf(fmt, ...) printf(fmt, __VA_ARGS__)
#define dprint(sth) std::cerr << sth
#else
#define dprintf(fmt, ...) (void(0))
#define dprint(sth) (void(0))
#endif

struct node_t {
    std::vector<int> children;
};

static constexpr const int ARRAY_LEN = 1024;

node_t g_tree[ARRAY_LEN];

// Operations on the g_tree.
// To make private methods private, we put it into a class.
class g_tree_impl {
    static int get_g_tree_depth_from(int id) {
        if (g_tree[id].children.size() == 0) {
            return 1;
        }
        int max_depth = -114514;
        for (auto kid : g_tree[id].children) {
            int subtree_depth = get_g_tree_depth_from(kid);
            if (subtree_depth > max_depth) {
                max_depth = subtree_depth;
            }
        }
        return max_depth + 1;
    }
    public:
    static int get_g_tree_depth() {
        return get_g_tree_depth_from(1);
    }
    static int get_g_tree_breathe() {
        // Use BFS to calculate the breathe of the g_tree.
        std::queue<int> bfs_helper;
        int breathe = -114514;
        int current_calculating_breathe = 0;
        bfs_helper.push(1);
        bfs_helper.push(-1);
        while(!bfs_helper.empty()) {
            // Get the front element and pop it.
            int next = bfs_helper.front();
            bfs_helper.pop();
            
            if (next == -1) {
                dprint("[DEBUG] Current line's breathe is: ");
                dprint(current_calculating_breathe);
                dprint(endl);
                if (current_calculating_breathe > breathe) {
                    breathe = current_calculating_breathe;
                }
                current_calculating_breathe = 0;
                continue;
            }

            // Check for the element
            int kid_counter = 0;
            for (auto kid : g_tree[next].children) {
                // Check for each kid
                kid_counter++;
                bfs_helper.push(kid);
            }
            dprint("[DEBUG] Node ");
            dprint(next);
            dprint(" have ");
            dprint(kid_counter);
            dprint(" kid(s).\n");
            current_calculating_breathe += kid_counter;
            bfs_helper.push(-1);
        }
        return breathe;
    }
};

// The entry function of the program.
int main() {
    // Input the number of nodes.
    int number_of_nodes;
    std::scanf("%d", &number_of_nodes);

    // Parse each line
    std::string buffer;
    for(int i = 1; i <= number_of_nodes; i++) {
        std::getline(cin, buffer);
        dprint("[DEBUG] The buffer is: {");
        dprint(buffer);
        dprint("}\n");
        if (buffer == "") {
            // Unvalidated line.
            i--;
            continue;
        }
        std::stringstream s(buffer);
        int first_data;
        if (s.eof()) {
            continue;
        }
        s >> first_data;
        while(!s.eof()) {
            int i;
            s >> i;
            g_tree[first_data].children.push_back(i);
            if (s.eof()) {
                break;
            }
        }
        buffer = "";
    }
    
    // [DEBUG] Test if the tree has been inputted correctly
    #ifdef __DEBUG__
    for (int i = 1; i <= number_of_nodes; i++) {
        dprint("[DEBUG] ");
        dprint("Printing the info of node ");
        dprint(i);
        dprint(endl);
        for (auto kid : g_tree[i].children) {
            dprint("[DEBUG] I have a child called ");
            dprint(kid);
            dprint(endl);
        }
    }
    #endif

    // Get the depth of the g_tree and print it to the stdout.
    cout << g_tree_impl::get_g_tree_depth() << endl;

    // Get the breathe of the g_tree and print it to the stdout;
    cout << g_tree_impl::get_g_tree_breathe() << endl;
}
