// cesun, 5/15/20 1:24 AM.

#include <iostream>
#include <climits>
#include <iomanip>
//#include <format>
#include "../util/type_name.cc"

using std::cout;
using std::endl;

#define PRETTY_PRINT(x) cout << #x " in decimal = " << x << "\t type:" << type_name<decltype(x)>() << endl

namespace integer_literal {
    void radix_prefix() {
        // binary: 0b or 0B
        PRETTY_PRINT(0b1111111111111111111111111111111);
        PRETTY_PRINT(0B1111111111111111111111111111111);
        // octal: 0
        PRETTY_PRINT(017777777777);
        // hex: 0x or 0X; case insensitive for a to f
        PRETTY_PRINT(0x7fFfFfFf);
        PRETTY_PRINT(0x7fFfFfFf);
    }

    void single_quote_sep() {
        // Can use single quotes as separator for readability.
        // For binary literal, cannot place ' after b or B
        PRETTY_PRINT(0b0'1'1'1111'1111'1111111'111'11111'1111'11);
        PRETTY_PRINT(0'1'7'7'7'7'7'7'7'7'7'7);
        // For hex literal, cannot place ' after x or X
        PRETTY_PRINT(0x7'fFfFfFf);
    }

    // Sign is not a part of integer-literal, and integer-literal token is always viewed as positive integer.
    // integer literal type fitting rule: see 5.13.2.3
    void type() {
        // none suffix; decimal
        PRETTY_PRINT(2147483647);
        PRETTY_PRINT(2147483648);
        PRETTY_PRINT(9223372036854775807);
//        PRETTY_PRINT(9223372036854775808); // __int128
        // non suffix; non-decimal
        PRETTY_PRINT(0x7fffffff);
        PRETTY_PRINT(0x80000000);
        PRETTY_PRINT(0xffffffff);
        PRETTY_PRINT(0x100000000);
        PRETTY_PRINT(0x7fffffffffffffff);
        PRETTY_PRINT(0x8000000000000000);
        PRETTY_PRINT(0xffffffffffffffff);
        // (u | U) and [ ( l | L ) or ( ll | LL) ] can be combined to force the type of integer literal
        PRETTY_PRINT(1ULL);
        PRETTY_PRINT(1LLU);
    }

    void Demo() {
        radix_prefix();
        cout << "---------------------------------" << endl;
        single_quote_sep();
        cout << "---------------------------------" << endl;
        type();
    }
}

namespace character_literal {
    void escape() {
        // 11 simple escapes
        char simple_escape[] = {'\'', '\"', '\?', '\\', '\a', '\b', '\f', '\n', '\r', '\t', '\v'};
        cout << std::hex << std::left;
        for (char c : simple_escape) cout << "0x" << std::setw(4) << static_cast<int>(c);
        cout << endl;

        // 1,2,3 digit(s) of octal escapes are all legal
        char octal_escape[] = {'\7', '\07', '\007'}; // bell
        for (char c : octal_escape) cout << "0x" << std::setw(4) << static_cast<int>(c);
        cout << endl;

        // hex escape

        // UCN is not treated as escape in standard, but syntax is similar
        char ucn[] = {'\u0000','\u0061','\u007f'};
    }

    void encoding_prefix() {
        //      none:    ???
        //      u8:      UTF-8 character literal of type char8_t
        //      u:       UTF-16 character literal of type char16_t
        //      U:       UTF-32 character literal of type char32_t
        //      L:       wide-character literal of type wchar_t
    }
}


void floating_point_literal() {

}

void string_literal() {

}

void boolean_literal() {

}

void pointer_literal() {

}

void user_defined_literal() {

}

int main() {
//    integer_literal::Demo();
    character_literal::escape();
}
