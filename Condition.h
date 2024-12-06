#pragma once

#include "Context.h"


#define AND(a , b) a && b

#define OR(a , b) a || a

#define LESSTHAN(a , b) (a < b)

#define MORETHAN(a , b) (a > b)


#define CONDITION(name, a) bool  name ## function() {return a;} \
                           bool (*name)() = name ## function;

/*
- Sub
- Mult
- Div
- Abs
- Get
- Mod
- ~~Palindrome~~
*/

/*
- Or
- Not
- LessThan
- GreaterThan
- Value
*/
