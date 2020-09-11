// cesun, 9/3/20 3:07 PM.

#include <vector
#include <string>

using std::vector;
using std::string;

struct foo {
    foo(const string &ref);

    string s;
};

foo::foo(const string &ref) : s(ref) {

}

int main() {
    vector<foo> v;
    string x{"123123123"};
    // v.push_back(x); // Clang-Tidy: Use emplace_back instead of push_back
    foo f{x};
    v.push_back(f); // clang tidy is satisfied :)
}