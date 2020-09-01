// cesun, 5/15/20 1:24 AM.

#include <iostream>
#include <climits>
#include <iomanip>
//#include <format>
#include "../util/type_name.cc"

using std::cout;
using std::endl;

#define TYPE_PRINT(x) cout << #x "\t type:" << type_name<decltype(x)>() << endl
#define VALUE_TYPE_PRINT(x) cout << #x " = " << x << "\t type:" << type_name<decltype(x)>() << endl

namespace integer_literal {
    void radix_prefix() {
        // binary: 0b or 0B
        VALUE_TYPE_PRINT(0b1111111111111111111111111111111);
        VALUE_TYPE_PRINT(0B1111111111111111111111111111111);
        // octal: 0
        VALUE_TYPE_PRINT(017777777777);
        // hex: 0x or 0X; case insensitive for a to f
        VALUE_TYPE_PRINT(0x7fFfFfFf);
        VALUE_TYPE_PRINT(0x7fFfFfFf);
    }

    void single_quote_sep() {
        // Can use single quotes as separator for readability.
        // For binary literal, cannot place ' after b or B
        VALUE_TYPE_PRINT(0b0'1'1'1111'1111'1111111'111'11111'1111'11);
        VALUE_TYPE_PRINT(0'1'7'7'7'7'7'7'7'7'7'7);
        // For hex literal, cannot place ' after x or X
        VALUE_TYPE_PRINT(0x7'fFfFfFf);
    }

    // Sign is not a part of integer-literal, and integer-literal token is always viewed as positive integer.
    // integer literal type fitting rule: see 5.13.2.3
    void type() {
        // none suffix; decimal
        VALUE_TYPE_PRINT(2147483647);
        VALUE_TYPE_PRINT(2147483648);
        VALUE_TYPE_PRINT(9223372036854775807);
        TYPE_PRINT(9223372036854775808);// TODO
        // non suffix; non-decimal
        VALUE_TYPE_PRINT(0x7fffffff);
        VALUE_TYPE_PRINT(0x80000000);
        VALUE_TYPE_PRINT(0xffffffff);
        VALUE_TYPE_PRINT(0x100000000);
        VALUE_TYPE_PRINT(0x7fffffffffffffff);
        VALUE_TYPE_PRINT(0x8000000000000000);
        VALUE_TYPE_PRINT(0xffffffffffffffff);
        // (u | U) and [ ( l | L ) or ( ll | LL) ] can be combined to force the type of integer literal
        VALUE_TYPE_PRINT(1ULL);
        VALUE_TYPE_PRINT(1LLU);
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
        // 5.13.3.7: There is no limit to the number of digits in a hexadecimal sequence.
        // but if value fall out of range of its type:
        //      char(no prefix) & wchar_t(L): value is implementation-defined
        //      utf8(u8)/16(u)/32(U) char: program is ill-formed
        VALUE_TYPE_PRINT('\x6');
        VALUE_TYPE_PRINT('\x61');
        VALUE_TYPE_PRINT('\x616161');
        wchar_t wc = L'\xafafafaf';

        // UCN is not treated as escape in standard, but syntax is similar
        char ucn[] = {'\u0000', '\u0061', '\u007f'};
    }

    void encoding_prefix() {
        //      none:    5.13.3.1 `ordinary character literal`
        char c0 = 'x';
        VALUE_TYPE_PRINT('21'); // conditionally-supported multicharacter literal
//        VALUE_TYPE_PRINT('旅');  // 旅 is turned into UCN \u65c5 in phase 1 TODO: (undefined behav?)
        // gcc 10.1 treats this as a multicharacter literal; clang10 doesn't compile.

        //      u8:      `UTF-8 character literal` of type char8_t
        char8_t utf8char = u8'x'; // [U+00, U+7f] ; 1 utf-8 code unit = 1 byte
        //      u:       `UTF-16 character literal` of type char16_t
        char16_t utf16char = u'猫';  // [U+0000, U+FFFF] i.e. Basic Multilingual Plane; 1 utf-16 code unit = 16 bits
        //      U:       `UTF-32 character literal` of type char32_t
        char32_t utf32char = U'\U0001f34c'; // can represent any code point; TODO: use emoji after JBR-410 fixed
        //      L:       wide-character literal of type wchar_t
        wchar_t wide_char = L'猫'; // TODO
    }
}


namespace floating_point_literal {
    // 5.13.4.2: the numeric part before the exp part (i.e. before e/E/p/P) is called `significand`.

    void floating_point_suffix() {
        // Different from integer literal, there is no type fitting scheme for floating-point-literal,
        // and the type is solely determined by its suffix:
        VALUE_TYPE_PRINT(3.1415); // no suffix: double
        VALUE_TYPE_PRINT(3.1415f); // f or F for float
        VALUE_TYPE_PRINT(3.1415F);
        VALUE_TYPE_PRINT(3.1415l); // l or L for long double
        VALUE_TYPE_PRINT(3.1415L);
    }

    void decimal() {
        VALUE_TYPE_PRINT(31415.92653);
        VALUE_TYPE_PRINT(.92653);
        VALUE_TYPE_PRINT(31415.);
        // both e and E works; exp sign is optional; only decimal integer exp accepted.
        VALUE_TYPE_PRINT(3.1415e42);
        VALUE_TYPE_PRINT(3.1415e+42);
        VALUE_TYPE_PRINT(3.1415E-13);
        VALUE_TYPE_PRINT(3e5); //definite floating-point literal of type double, regardless of whether a decimal dot exists in the significand.
    }

    void hexadecimal() {
        // binary-exponent-part is required; both p and P is accepted; exp must be decimal integer.
        // value = s * 2^(exp)
        VALUE_TYPE_PRINT(0xaBc.dEfp0);
        VALUE_TYPE_PRINT(0x.dEfP12);
        VALUE_TYPE_PRINT(0xAbc.p24);
        VALUE_TYPE_PRINT(0xAbCP3);//definite floating-point literal of type double, regardless of whether a decimal dot exists in the significand.
    }

    void single_quote_split() {
        // single quote can be used to split both digit-seq and hex-digit-seq
        VALUE_TYPE_PRINT(3'1'4'1'5E1'2'3);
        VALUE_TYPE_PRINT(0xA'b'C.d'E'fp1'2);
    }

    void demo() {
        floating_point_suffix();
        cout << "---------------------------------" << endl;
        decimal();
        cout << "---------------------------------" << endl;
        hexadecimal();
        cout << "---------------------------------" << endl;
        single_quote_split();
    }
}

namespace string_literal {
    // 5.13.5.14 Evaluating a string-literal results in a string
    // literal object with static storage duration

    void encoding_prefix() {
        // "ordinary string literal"
        // type: const char [n]
        TYPE_PRINT("ordinary string literal");
        TYPE_PRINT("廃線「ぶらり廃駅下車の旅」"); // TODO: undefined behavior?

        // type: const char8_t [n]
        TYPE_PRINT(u8"廃線「ぶらり廃駅下車の旅」");

        // type: const char16_t [n]
        TYPE_PRINT(u"廃線「ぶらり廃駅下車の旅」");

        // type: const char32_t [n]
        TYPE_PRINT(U"廃線「ぶらり廃駅下車の旅」");

        // type: const wchar_t [n]
        TYPE_PRINT(L"廃線「ぶらり廃駅下車の旅」");
    }

    void raw_string_literal() {
        // delimiter:
        // - must be member(s) of BSCS, but cannot contain: space ( ) \ tab vtab formfeed newline
        // - terminating deli must be the same as the prefix deli
        // - at most 16 characters
        TYPE_PRINT(R"x("(" ")")x");
        TYPE_PRINT(R"(("""))"); // empty delimiter, r-char-sequence cannot contain )"
        TYPE_PRINT(u8R"(廃線「ぶらり廃駅下車の旅」)"); // orthogonal to encoding
        TYPE_PRINT(u8R"(a newline within raw string in source
produce a newline in the literal.)");
    }

    void concat() {
        TYPE_PRINT(U"廃線「ぶらり" U"廃駅下車の旅」"); // same + same = still the same
        TYPE_PRINT("none prefix" u8"廃線「ぶらり廃駅下車の旅」"); // none + (u8/u/U/L) = u8/u/U/L
        //TYPE_PRINT(u8"廃線「ぶらり" L"廃駅下車の旅」"); // u8 + L is explicitly prohibited

        // any other concatenation is conditionally-supported
//        TYPE_PRINT(u8"廃線「ぶらり廃駅下車の旅」" u"\U00001f34c"); // gcc 10.1 and clang 10.0 don't compile
    }

    void demo() {
        encoding_prefix();
        cout << "---------------------------------" << endl;
        raw_string_literal();
        cout << "---------------------------------" << endl;
        concat();
    }
}

void boolean_literal() {
    VALUE_TYPE_PRINT(true);
    VALUE_TYPE_PRINT(false);
}

void pointer_literal() {
    VALUE_TYPE_PRINT(nullptr);
}

namespace user_defined_literal {
    //TODO
}

int main() {
//    integer_literal::Demo();
//    floating_point_literal::demo();
//    string_literal::demo();
    boolean_literal();
    pointer_literal();
}
