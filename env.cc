#include <cstdio>
#include <climits>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define PRINT_TYPE_INFO(x, max, min) std::printf("sizeof("#x") = %lu, "#max" = " STR(max) ", "#min" = " STR(min) "\n", sizeof(x))

int main() {
    std::printf("Compiler standard set to: %ld\n", __cplusplus);
    PRINT_TYPE_INFO(int, INT_MAX, INT_MIN);
    PRINT_TYPE_INFO(long, LONG_MAX, LONG_MIN);
    PRINT_TYPE_INFO(long long, LONG_LONG_MAX, LONG_LONG_MIN);
    return 0;
}
