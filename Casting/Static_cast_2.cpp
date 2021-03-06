#include <iostream>

class Base
{
};

// class Derived : private Base
// error: conversion to inaccessible base class "Base" is not allowed
class Derived : public Base
{
};

class AnotherDerived : public Base
{
};

int main()
{
    Derived *derived = new Derived();

    // upcast - implicit
    Base *base = derived;

    // downcast - explicit
    // Derived *d = (Derived *)base; C style
    Derived *d = static_cast<Derived *>(base);

    AnotherDerived *ad = static_cast<AnotherDerived *>(base);

    if (d)
        std::cout << "d is not NULL" << std::endl;
    else
        std::cout << "d is NULL" << std::endl;

    if (ad)
        std::cout << "ad is not NULL" << std::endl;
    else
        std::cout << "ad is NULL" << std::endl;
}

// Output:
// d is not NULL
// ad is not NULL