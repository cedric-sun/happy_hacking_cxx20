// cesun, 6/12/20 6:51 PM.

//A class type T must be complete if:
//(12.1) — an object of type T is defined (6.2), or


//(12.2) — a non-static class data member of type T is declared (11.4), or


//(12.3) — T is used as the allocated type or array element type in a new-expression (7.6.2.7), or
//(12.4) — an lvalue-to-rvalue conversion is applied to a glvalue referring to an object of type T (7.3.1), or
//(12.5) — an expression is converted (either implicitly or explicitly) to type T (7.3, 7.6.1.3, 7.6.1.6, 7.6.1.8, 7.6.3), or
//(12.6) — an expression that is not a null pointer constant, and has type other than cv void*, is converted to the type pointer to T or reference to T using a standard conversion (7.3), a dynamic_cast (7.6.1.6) or a static_cast (7.6.1.8), or
//(12.7) — a class member access operator is applied to an expression of type T (7.6.1.4), or
//(12.8) — the typeid operator (7.6.1.7) or the sizeof operator (7.6.2.4) is applied to an operand of type T, or
//(12.9) — a function with a return type or argument type of type T is defined (6.2) or called (7.6.1.2), or
//(12.10) — a class with a base class of type T is defined (11.7), or
//(12.11) — an lvalue of type T is assigned to (7.6.19), or
//(12.12) — the type T is the subject of an alignof expression (7.6.2.5), or
//(12.13) — an exception-declaration has type T, reference to T, or pointer to T (14.4).
