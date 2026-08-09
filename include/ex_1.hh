#include <iostream>
#include <utility>

void f(int& x)
{
    std::cout << "lvalue reference overload f(" << x << ")\n";
}

void f(const int& x)
{
    std::cout << "lvalue reference to const overload f(" << x << ")\n";
}

void f(int&& x)
{
    std::cout << "rvalue reference overload f(" << x << ")\n";
}

void run_ex1()
{
    int i = 1;
    const int ci = 2;

    f(i);
    f(ci);
    f(3);
    f(std::move(i));

    int&& x = 1;
    f(x);
    f(std::move(x));
}