#include <cstdio>
#include <climits>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

int main() {
    std::printf("Compiler standard set to: %ld\n", __cplusplus);
    std::printf("sizeof(int) = %lu, INT_MAX = " STR(INT_MAX) ", INT_MIN = " STR(INT_MIN) "\n",
                sizeof(int));
    return 0;
}
