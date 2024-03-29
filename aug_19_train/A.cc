// A
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
// Author: 27Onion (https://github.com/onion108)
//

#include <cassert>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ostream>
#include <type_traits>

using std::cin;
using std::cout;
using std::endl;

// A string class written by myself, because I don't want to use the standard one.
// This String class provides the following basic features, which is enough for the current problem.
//
// - Conversions between C Strings.
// - Append an ASCII charater to the String.
// - Check the equality.
// - Reverse the string by simply using a member function.
// - Get the ASCII character at the given index.
// - Clear the whole String.
// - Index the ASCII character at the given index, which supports both `mut` and immutable versions.
// - Use range-based for loops to quickly and simply iterate over the string object (don't support mutating yet).
// - Quickly input/output by using cin/cout with stream operators.
// 
// Here are features that should be here but we didn't implement it:
// - Searching for a subpattern in the string.
// - getline() support.
// - `filter`, `map`, `map_filter` and a lot more from Rust String. (Although these necessary operations didn't appear in the STL's string, either. Long live Rust and go to the hell C++!)
// - sort() support.
// - Compare in the dictionarial order.
// - Advanced iterators, which supports `collect()`, `map()`, `map_filter`, `filter()` and so on. Also a Rust-inspired idea.
// - Slices. A Rust-inspired idea.
// - String concat by `+` and member functions.
// - `to_upper()` and `to_lower()` member functions.
// - Split the string with pattern.
// - String formatters.
// - Convert other types to string.
// - Convert string to numberal types.
class String {

    // The allocated memory.
    // If it's nullptr, the string is empty.
    char * _inner;

    // The size of the string.
    // It won't include the c string terminator (a.k.a `'\0'`).
    size_t _size;

    // The current capacity.
    // The capacity should be always bigger than the `_size`.
    size_t _cap;

    // Reallocate a block of memory and copy it.
    void _realloc(size_t __new_cap) {

        // Check if the new the capacity is bigger than the old capacity.
        assert(__new_cap > _cap);

        // If no cap in original, then just allocate a memory and return.
        if (_cap == 0) {
            _inner = new char[__new_cap];
            _cap = __new_cap;
            return;
        }

        // Allocate a temporary memory and copy it.
        char * __tmp = new char[__new_cap];
        for (int i = 0; i < _cap; i++) {
            __tmp[i] = _inner[i];
        }

        // Deallocate the old memory block.
        delete [] _inner;

        // Make the old one the new one.
        _inner = __tmp;
        _cap = __new_cap;

    }

    // Make a default string.
    // If it's not called in the constructor, please first release the `_inner`
    // or there will be a memory leak.
    void _default() {
        _size = 0;
        _cap = 0;
        _inner = nullptr;
    }

    public:

    // The default constructor.
    // Constructs an empty string object.
    String() {
        _default();
    }

    // The assign constructor.
    String(String& rhs) {
        _default();
        assign(rhs);
    }

    // The copy constructor.
    String(const String& rhs) {

        // Call the default initializer.
        _default();

        // Assign the string.
        assign(rhs);

    }

    // The move constructor.
    String(String&& rhs) {
        
        // Call the default initializer.
        _default();
        
        // Assign the string.
        assign(rhs);

    }


    // Assign a String to a string.
    template <typename S>
    String& assign(S s) {

        // Check for the type trait.
        static_assert(std::is_same<typename std::remove_const<typename std::remove_reference<S>::type>::type, String>::value, "Invalid type.");
        
        // Reset to default.
        if (_inner != nullptr) {
            delete [] _inner;
        }
        _default();

        return assign(s._inner);
    }

    // Assign a CString to a string.
    // template <>
    String& assign(char * another) {
        auto _len = strlen(another);

        // Reset the string to default.
        if (_inner != nullptr) {
            delete [] _inner;
        }
        _default();

        // Reallocate the memory to length.
        _realloc(_len+4);

        // Assign the value.
        for (int i = 0; i < _len; i++) {
            _inner[i] = another[i];
        }

        // Return this.
        _size = _len;
        return *this;
    }

    // Assign a CString to a string.
    // template <>
    String& assign(const char * another) {
        auto _len = strlen(another);

        // Reset the string to default.
        if (_inner != nullptr) {

            // If the string exists, release the old resource.
            delete [] _inner;
            
        }
        _default();

        // Reallocate the memory to length.
        _realloc(_len+4);

        // Assign the value.
        for (int i = 0; i < _len; i++) {
            _inner[i] = another[i];
        }

        // Set the new length adn return the current instance.
        _size = _len;
        return *this;
    }

    // construct a string from a cosnt char *.
    String(const char * __cstr) {

        // Initialize necessary data.
        _default();

        // Assign the string.
        assign(__cstr);

    }

    // Get the length of the string.
    size_t length() const {
        return _size;
    }

    // Get the immutable C String.
    const char * c_str() const {
        return _inner;
    }

    // Append a charater to the current instance.
    // For example:
    // ```
    // String s1 = "Hello, World"; // s1 now is "Hello, World"
    // s1.append('!');             // s1 now is "Hello, World!"
    // ```
    //
    void append(char c) {

        // Return allocate if need.
        if (this->_size < _cap - 2) {
            this->_realloc(_cap + 10);
        }

        // The capacity must be bigger than the size.
        assert(_cap >= _size);

        // Set the character and increase the size.
        this->_inner[this->_size] = c;
        this->_size++;
    }

    // A.k.a. assign()
    template <typename _St>
    String& operator=(_St rhs) {

        // Assign the string to the the current object.
        return assign(rhs);

    }

    // Reverse the string.
    // Unlike `append`, this method will not mutate the content of the current instance.
    String reverse() const {

        // A `String` object to store the result.
        String s;

        // Iterate over the string reversely, and add the charaters to the result object.
        // After this, `s` will be the reversed string.
        for (int i = _size-1; i >= 0; i--) {
            s.append(_inner[i]);
        }

        // Return the reversed string.
        return s;

    }

    // Get the character at the given index.
    char& at_mut(size_t _idx) {
        return _inner[_idx];
    }

    // Get the character at the given index, but the immutable version.
    char at(size_t _idx) const {
        return _inner[_idx];
    }

    // Syntax sugar for `at`. (Use the mutable version.)
    char& operator[](size_t _idx) {
        return at_mut(_idx);
    }

    // The beginning iterator.
    // Use it for range-based for loops.
    //
    const char* begin() const {
        return _inner;
    }

    // The past-the-end iterator.
    // Use it for range-based for loops.
    // ```
    // String s = "Rust is the best. ";
    // 
    // for (auto i : s) {
    //     cout << i << endl;           // Will output 'R', 'u', 's', 't', ' ', 'i', 's', ' ', 't', 'h', 'e', ' ', 'b', 'e', 's', 't', '.', ' ' respectively
    // }
    // ```
    //
    const char* end() const {
        return _inner + _size;
    }

    // Clear the string.
    void clear() {

        // Free the memory.
        delete [] _inner;

        // Reset it.
        _default();
    }

    // Check if they're equal.
    bool equals(const String& another) const {

        // If they're not as long as each other, then return false immediately.
        if (length() != another.length()) {
            return false;
        }

        // Otherwise, test for each charater.
        for (int i = 0; i < _size; i++) {

            // Fails if there is a character that isn't same.
            if ((*this).at(i) != another.at(i)) {
                return false;
            }

        }
        return true;
    }

    // Check if they're equal, on C String.
    // Example:
    // ```
    // String s1 = "hello ";
    // String s2 = " olleh";
    // s1.equals("hello "); // returns true.
    // s2.equals(" olleh"); // returns false.
    // s1.equals("114514"); // returns false.
    // ```
    //
    bool equals(const char * c) const {

        // Length `len`
        auto len2 = strlen(c);

        // If the lengths are not equal, return false directly.
        if (length() != len2) return false;

        // Start comparation.
        for (int i = 0; i < _size; i++) {
            
            // Once we found two characters are not equal, we quit.
            if ((*this).at(i) != c[i]) {
                return false;
            }

        }

        // If it passes all the tests, they're equal.
        return true;
    }

    // Syntax sugar for equals().
    template <typename T>
    bool operator==(T another) const {

        // Check for the type traits.
        static_assert(std::is_convertible<T, const char *>::value || std::is_convertible<T, const String &>::value, "Nope!");

        // Check the equality.
        return equals(another);

    }

    // The destructor.
    ~String() {
        
        // Free all allocated memory if there are.
        if (_inner != nullptr) {
            delete [] _inner;
        }

    }

};

// Print the s via cout.
// Cannot use template here.
std::ostream& operator<<(std::ostream& os, const String& rhs) {

    os << rhs.c_str();

    return os;

}

// Input to s via cin.
std::istream& operator>>(std::istream& is, String& rhs) {

    rhs.clear();

    // Get the first character
    char c = is.get();

    // Read until the newline.
    while (c != '\n') {

        // If we read a blank charater, should first check if it's at the start or at the end.
        // Skip if at the start, and break if at the end.
        if (c == ' ' || c == '\t') {
            if (rhs.length() == 0) {
                // Read the next char (or will be in a dead-loop)
                c = is.get();
                continue;
            } else {
                break;
            }
        } else {

            // Otherwise, just add the charater to the buffer.
            rhs.append(c);

        }

        // Read the next char.
        c = is.get();

    }

    // Return the `is` to allow a chain call.
    return is;

}

// The problem solver model.
class ProblemSolver {

    // Store the string representation of a number.
    String _snum;

    // Store the answer of this problem.
    bool _ans;

    // The input stage.
    void _input() {

        // Input the string as a `String`-typed instance via `cin`.
        cin >> _snum;

    }

    // The solve stage.
    // Check if the number is a palidromic.
    void _solve() {

        // If it's a negative number, just return directly.
        if (_snum[0] == '-') {
            _ans = false;
            return;
        }

        // Otherwise, compare two strings.
        String _s2;
        _s2.assign(_snum.reverse());
        _ans = (_s2.equals(_snum));

    }

    // The output stage.
    void _output() {

        cout << (_ans ? "True" : "False") << endl;

    }

    public:

    // Construct a problem solver instance.
    // The lifetime of a problem solver have been splitted into three.
    // Input Stage inputs data from stdin.
    // Solve Stage solve the problem with the input data.
    // Output Stage outputs answer to the stdout.
    // When the problem solver is solving a problem, it calls Input -> Solve -> Output in the order.
    // 
    // Constructing a ProblemSolver will just do nothing.
    ProblemSolver() {}

    // Solve the problem.
    // Will execute the three stages in the order.
    void solve() {

        _input();

        _solve();

        _output();

    }

    // The destructor of the `ProblemSolver`.
    // Release any resources, if necessary.
    ~ProblemSolver() {}

};

// End of data structures.

// The entry point of the whole program.
int main() {

    ProblemSolver solver;
    solver.solve();

}
