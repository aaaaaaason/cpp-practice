#include "fmt/format.h"

#include "abstract.hpp"

void Foo::DoA()
{
    fmt::print("Foo do A\n");
}

void Foo::DoB()
{
    fmt::print("Foo do B\n");
}

Foo::Foo()
{
    fmt::print("Foo constructing\n");
}

Foo::~Foo()
{
    fmt::print("Foo destructing\n");
}

void TestAbstract()
{
    Foo f;

    Abstract &a = f;

    a.DoA();

    a.DoB();
}
