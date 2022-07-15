#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

static constexpr const int OP_REPLACE_SOLDIER = 1;
static constexpr const int OP_ASK_POS = 2;

// The recorder class.
class recorder_t {

    // A structure that presents a soldier.
    struct soldier_t {

        // The soldier's original position in the vector.
        int id;

        // The height of the soldier.
        int height;
    };

    // Field to restore information about soldiers.
    std::vector<soldier_t> soldiers;

    public:

    // Construct a recorder.
    recorder_t() {}

    // Destruct a recorder.
    ~recorder_t() {}

    // Add a soldier.
    void add_soldier(int height) {
        soldier_t soldier;
        soldier.id = this->soldiers.size() + 1;
        soldier.height = height;
        this->soldiers.push_back(soldier);
    }

    // Replace a soldier.
    // idx starts with 1.
    void replace_soldier_at(int idx, int new_height) {
        this->soldiers[idx - 1].height = new_height;
    }

    // Return the position of a soldier after sorting.
    // idx starts with 1. Also, the returned position starts with 1.
    int soldier_pos_after_sort(int idx) {
        std::vector<soldier_t> new_vector = soldiers;
        sort(new_vector.begin(), new_vector.end(), [](const soldier_t& x, const soldier_t& y) {
            return x.height < y.height;
        });
        int counter = 1;
        for (auto i : new_vector) {
            if (i.id == idx) {
                return counter;
            }
            counter++;
        }
        return -1;
    }
};

// The entry function of the program.
int main() {

    // The recorder, me
    recorder_t miss_27onion;

    // Input data.
    int number_of_soldiers, operations_count;
    cin >> number_of_soldiers >> operations_count;

    for (int i = 0; i < number_of_soldiers; i++) {
        int height;
        cin >> height;
        miss_27onion.add_soldier(height);
    }

    // Reponse to the queries.
    for (int i = 0; i < operations_count; i++) {
        int op_code;
        cin >> op_code;
        switch (op_code) {
            case OP_REPLACE_SOLDIER:
            int soldier_pos, new_soldier_height;
            cin >> soldier_pos >> new_soldier_height;
            miss_27onion.replace_soldier_at(soldier_pos, new_soldier_height);
            break;
            case OP_ASK_POS:
            cin >> soldier_pos;
            cout << miss_27onion.soldier_pos_after_sort(soldier_pos) << endl;
            break;
            default:
            std::cerr << "[ERROR] Impossible case, should not be here. (At " << __LINE__ << ")." << endl;
        }
    }
}
