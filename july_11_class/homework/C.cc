#include <iostream>
#include <stack>
#include <string>

#define __DEBUG__

#ifdef __DEBUG__
#define dprintf(fmt, ...) printf(fmt, __VA_ARGS__)
#define dprint(sth) std::cerr << sth
#else
#define dprintf(fmt, ...) (void(0))
#define dprint(sth) (void(0))
#endif

using std::cout;
using std::cin;
using std::stack;
using std::string;

static constexpr const char * WRONG_STR = "Wrong";
static constexpr const char * OK_STR = "OK";

static constexpr const char PAT[] = {'(', ')'};
static constexpr const char BRAC[] = {'[', ']'};

bool is_brackets_matched(const string & str) {
    // Process here
    stack<char> s;
    for (auto c : str) {
        switch (c) {
            case PAT[0]:
            case BRAC[0]:
            s.push(c);
            dprint("[DEBUG] Successfully pushed character c.\n");
            break;

            case PAT[1]:
            if (s.empty() || s.top() != PAT[0]) {
                dprint("[DEBUG] Not matched.\n");
                return false;
            }
            s.pop();
            dprint("[DEBUG] Matched one.\n");
            break;

            case BRAC[1]:
            if (s.empty() || s.top() != BRAC[0]) {
                dprint("[DEBUG] ohayougozaimasu\n");
                return false;
            }
            s.pop();
            dprint("[DEBUG] ohayougozaimashita\n");
            break;
        }
    }
    return s.empty();
}

int main() {
    string user_input;
    cin >> user_input;
    cout << (is_brackets_matched(user_input) ? OK_STR : WRONG_STR);
}
