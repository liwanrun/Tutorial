/*
 * Rules of Three: If a class needs a user-defined destructor, copy constructor, or copy
 * assignment operator, it will almost certainly need all THREE.
 * If the copy-ctor/copy-assign performs "shallow copy", then implicitly defined special
 * member functions should not be used.
 * 
 * Rules of Five: Because user-defined (including declarationa as =default or ==delete) destructor,
 * copy constructor or copy assignment operators prevent the implicit definitions of move constructor,
 * and move assignment operators, so any class that needs to move semantics must declare
 * all five special memeber functions.
 * 
 * Rule of Zero: Classes with custom destructors, copy/move constructors, or copy/move assignment
 * operators should specifically handle ownership. Other classes should not have custom destructors, 
 * copy/move constructor, or copy/move assignement operators.
*/ 

#include <cstddef>
#include <cstring>
#include <iostream>
#include <utility>

class rule_of_three
{
    char* cstring;

public:
    explicit rule_of_three(const char* s = "") : cstring(nullptr)
    {
        if (s)
        {
            cstring = new char[std::strlen(s) + 1];
            std::strcpy(cstring, s);
        }
    }

    ~rule_of_three()
    {
        delete cstring;
    }

    rule_of_three(const rule_of_three& other)
    : rule_of_three(other.cstring)
    {

    }

    rule_of_three& operator=(const rule_of_three& other)
    {
        rule_of_three temp(other);
        std::swap(cstring, temp.cstring);
        return *this;
    }

    const char* c_str() const
    {
        return cstring;
    }
};

void run_ex2_ruleOfThree()
{
    rule_of_three o1{"abc"};
    std::cout << o1.c_str() << ' ';

    auto o2{o1};
    std::cout << o2.c_str() << ' ';
    
    rule_of_three o3{"def"};
    std::cout << o3.c_str() << ' ';
    o3 = o2;
    std::cout << o3.c_str() << '\n';
}