// cesun, 5/14/20 10:40 PM.

#include <cstdio>

/*
hex-quad :
    hexadecimal-digit hexadecimal-digit hexadecimal-digit hexadecimal-digit

universal-character-name :
    \u hex-quad                 # for Basic Multilingual Plane
    \U hex-quad hex-quad        # for other
 */
int main() {
    // as identifier; see 5.10 for UCN in syntax of identifier
    int \u732b = 42;
    std::printf("\u732b: %d\n",\u732b);
//    int 猫 = 42; // error: redefinition

//    char \u0061 = 5; // error: member of BSCS cannot be written as universal-character-name
    int 🍌 = 99;
    //int \U0001f34c = 45; //error: redeclaration of ‘int 🍌’
    std::printf("\U0001f34c: %d\n",\U0001f34c);
}

