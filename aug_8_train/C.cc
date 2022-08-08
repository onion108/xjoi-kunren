// B
// Template generated by oi_helper (https://github.com/onion108/oi_helper)
//

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;


/* Debug Kit Start */

#ifdef __DEBUG__
#define debug_do(__b) __b
#else
#define debug_do(__b)
#endif

/* Debug Kit End */

/// An file system item.
class fs_item_t {
    public:

    // Methods that should be implemented by the subclasses.
    virtual bool                   is_directory() const                      { throw "unimplemented"; }
    virtual bool                   is_file() const                           { throw "unimplemented"; }
    virtual const std::string&     name() const                              { throw "unimplemented"; }
    virtual void                   set_name(const std::string& name)         { throw "unimplemented"; }

    fs_item_t(const std::string& name) {}
    virtual ~fs_item_t() {}
};

/// A directory.
class fs_item_directory : public fs_item_t {
    std::string pf_name;
    std::vector<std::shared_ptr<fs_item_t>> children;
    public:

    fs_item_directory(const std::string& name) : fs_item_t(name) {
        this->set_name(name);
    }

    bool is_directory() const override {
        return true;
    }

    bool is_file() const override {
        return false;
    }

    const std::string& name() const override {
        return this->pf_name;
    }

    void set_name(const std::string& name) override {
        this->pf_name = name;
    }

    void add_child(std::shared_ptr<fs_item_t> instance) {
        this->children.push_back(instance);
    }

    std::vector<std::shared_ptr<fs_item_t>> get_children() const {
        return this->children;
    }

    bool exists_file(const std::string& filename) const {
        for (auto i : children) {
            if (i->name() == filename) {
                return true;
            }
        }
        return false;
    }

    void sort_children() {
        std::sort(this->children.begin(), this->children.end(), [](const std::shared_ptr<fs_item_t>& a, const std::shared_ptr<fs_item_t>& b) {
            return a->name() < b->name();
        });
    }

    std::shared_ptr<fs_item_t> get_child(const std::string& filename) const {
        for (auto i : children) {
            if (i->name() == filename) {
                return i;
            }
        }
        throw "unknown file";
    }
};

/// An ordinary file.
class fs_item_file : public fs_item_t {
    std::string pf_name;
    public:

    fs_item_file(const std::string& name) : fs_item_t(name) {
        this->set_name(name);
    }

    bool is_directory() const override {
        return false;
    }

    bool is_file() const override {
        return true;
    }

    const std::string& name() const override {
        return this->pf_name;
    }

    void set_name(const std::string& name) override {
        this->pf_name = name;
    }
};

class path_t {
    std::vector<std::string> fp_entities;

    inline bool part_of_filename(const char __c) const {
        return (__c <= 'z' && __c >= 'a') || __c == '.' || __c == ' ' || (__c <= 'Z' && __c >= 'A') || __c == '_' || __c == '-' || (__c <= '9' && __c >= '0') || __c == '+';
    }

    inline bool path_separator(const char __c) const {
        return __c == '/';
    }

    void _parse(const std::string& __source) {
        int _parse_status = 0;
        std::string _current_parsing_buffer = "";

        // Start parsing the path.
        for (auto _char : __source) {
            if (_parse_status == 0) {

                if (part_of_filename(_char)) {
                    _current_parsing_buffer.push_back(_char);
                    _parse_status = 1;
                }

            } else if (_parse_status == 1) {

                if (part_of_filename(_char)) {
                    _current_parsing_buffer.push_back(_char);
                } else if (path_separator(_char)) {
                    _parse_status = 0;

                    fp_entities.push_back(_current_parsing_buffer);
                    _current_parsing_buffer.clear();
                } else {
                    throw "path_t::_parse() private: unreachable";
                }

            } else {
                throw "path_t::_parse() private: unreachable";
            }
        }

        if (_current_parsing_buffer != "") {
            fp_entities.push_back(_current_parsing_buffer);
        }

    } 

    public:
    path_t(const std::string& path) : fp_entities() {
        _parse(path);
    }

    const std::vector<std::string>& entities() const {
        return this->fp_entities;
    }

    std::string to_string() const {
        std::string result;
        for (auto i : entities()) {
            result += i + "/";
        }
        return result;
    }
};

class virtual_file_system_t {
    std::shared_ptr<fs_item_directory> pf_root;
    public:
    virtual_file_system_t(const std::shared_ptr<fs_item_directory>& root) : pf_root(root) {}

    const std::shared_ptr<fs_item_directory>& root() {
        return pf_root;
    }

    bool exists(const path_t& path) const {
        std::shared_ptr<fs_item_directory> _pwd = pf_root;
        bool last_is_file = false;
        bool is_first = true;
        for (auto i : path.entities()) {
            if (last_is_file) {
                return false;
            }
            if (is_first) {
                is_first = false;
                continue;
            }
            if (_pwd->exists_file(i)) {
                std::shared_ptr<fs_item_t> _f = _pwd->get_child(i);
                if (_f->is_directory()) {
                    _pwd = std::dynamic_pointer_cast<fs_item_directory>(_f);
                } else {
                    last_is_file = true;
                }
            } else {
                return false;
            }
        }
        return true;
    }

    void create_file(const path_t& path) {
        std::shared_ptr<fs_item_directory> _pwd = pf_root;
        for (auto i = path.entities().begin()+1; i != path.entities().end(); i++) {
            if (i == path.entities().end() - 1) {
                debug_do({
                    cout << "Handling last" << endl;
                    cout << "Path: " << path.to_string() << endl;
                })
                _pwd->add_child(std::shared_ptr<fs_item_t>(new fs_item_file(*i)));
            } else {
                if (_pwd->exists_file(*i)) {
                    auto _f = _pwd->get_child(*i);
                    if (_f->is_directory()) {
                        _pwd = std::dynamic_pointer_cast<fs_item_directory>(_f);
                    } else {
                        debug_do({
                            if (i != path.entities().begin()) {
                                cout << "parent: " << *(i-1) << endl;
                            }
                        })
                        throw (std::string("in virtual_file_system_t::create_file(): unreachable (_f ") + _f->name() + " is a file)\nInfo: \nFilename: " + _f->name() + ", Is Directory: " + (_f->is_directory() ? "YES" : "NO") + ", Is File: " + (_f->is_file() ? "YES": "NO")).c_str();
                    }
                } else {
                    debug_do({
                        cout << "Creating " << *i << endl;
                    })
                    std::shared_ptr<fs_item_directory> _f(new fs_item_directory(*i));
                    _pwd->add_child(_f);
                    _pwd = _f;
                }
            }
        }
    }
};

void print_file_with_indent(const std::shared_ptr<fs_item_t>& _fobj, int _indent) {
    if (_indent != 0) {
        for (int i = 0; i < _indent-1; i++) {
            cout << "|    ";
        }
        cout << "|----";
    }
    cout << _fobj->name() << endl;
    if (_fobj->is_directory()) {
        auto _dir = std::dynamic_pointer_cast<fs_item_directory>(_fobj);
        _dir->sort_children();
        for (auto i : _dir->get_children()) {
            print_file_with_indent(i, _indent+1);
        }
    }
}

int main() {
    std::vector<path_t> paths;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        std::string s;
        cin >> s;
        paths.push_back(path_t(s));
    }
    virtual_file_system_t vfs(std::shared_ptr<fs_item_directory>(new fs_item_directory(paths[0].entities()[0])));
    for (auto i : paths) {
        try {
            vfs.create_file(i);
        } catch (const char *e) {
            std::cerr << e << endl;
            return -1;
        }
    }
    print_file_with_indent(vfs.root(), 0);
}
