// cesun, 5/15/20 11:28 AM.

#include <cstdio>

/*
Preprocessor constant expression that evaluates to 1 if the file name is found (on disk)
and ​0​ if not. The program is ill-formed if the argument would not be a valid argument to
 the #include directive.
 */
int main() {
#if __has_include(<sstream>)
#define has_sstream 1
#else
#define has_sstream 0
#endif

#if __has_include(<sys/stat.h>)
#define has_stat 1
#else
#define has_stat 0
#endif
    std::printf("%d\n", has_stat);
    std::printf("%d\n", has_sstream);
}
