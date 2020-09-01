// cesun, 5/19/20 3:26 PM.

/*
 * Each entity declared by a declaration is also defined by that declaration unless:
 */

// 2.1 it declares a function without specifying the function’s body (9.5)
int foo();

// 2.2 it contains the extern specifier (9.2.1) or a linkage-specification (9.11)
// and neither an initializer nor a function-body
extern int bar;
//TODO

// 2.3 it declares a non-inline static data member in a class definition
class A {
    static int data;// TODO
};

// 2.4 it declares a static data member outside a class definition and the
// variable was defined within the class with the constexpr specifier
// (this usage is deprecated; see D.6)


// 2.5 it is introduced by an elaborated-type-specifier
//TODO

// 2.6 it is an opaque-enum-declaration
// TODO

// 2.7 it is a template-parameter (13.2)


// 2.8 it is a parameter-declaration (9.3.3.5) in a function declarator that is not the declarator of a function-
//definition

// 2.9 it is a typedef declaration (9.2.3)


// 2.10 it is an alias-declaration (9.2.3),
//(2.11) — it is a using-declaration (9.9),
//(2.12) — it is a deduction-guide (13.7.1.2),
//(2.13) — it is a static_assert-declaration (9.1),
//(2.14) — it is an attribute-declaration (9.1),
//(2.15) — it is an empty-declaration (9.1),
//(2.16) — it is a using-directive (9.8.3),
//(2.17) — it is a using-enum-declaration (9.7.2),

//(2.18) — it is a template-declaration (13.1) whose template-head is not followed
// by either a concept-definition or a declaration that defines a function, a class,
// a variable, or a static data member.

//(2.19) — it is an explicit instantiation declaration (13.9.2), or
//(2.20) — it is an explicit specialization (13.9.3) whose declaration is not a definition.