// cesun, 5/16/20 3:44 AM.

// https://stackoverflow.com/questions/6742501/whats-the-exact-step-of-macro-expanding
// https://stackoverflow.com/questions/5459868/concatenate-int-to-string-using-c-preprocessor

#include <cstdio>
#include <climits>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

int main() {
    std::puts(STR_HELPER(INT_MAX));
    std::puts(STR(INT_MAX));
}