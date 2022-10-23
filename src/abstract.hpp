#ifndef CPP_PRACTICE_SRC_ABSTRACT_H
#define CPP_PRACTICE_SRC_ABSTRACT_H

#include "fmt/format.h"

class Abstract
{
public:
    virtual void DoA() = 0;

    virtual void DoB() = 0;

    Abstract()
    {
        fmt::print("Abstract constructing\n");
    }

    virtual ~Abstract()
    {
        fmt::print("Abstract destructing\n");
    }
};

class Foo : public Abstract
{
public:
    void DoA() override;

    void DoB() override;

    Foo();

    ~Foo();
};

void TestAbstract();

#endif
