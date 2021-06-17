#ifndef SRP_H
#define SRP_H

#include <vector>
#include <iostream>

//Interface segregation Principle says that its better to not stuff a lot of interface in a single class, but to
//Divide them into separate smaller interfaces give more flexibility

//Below example explains that creating an interface class that has multiple methods to be implement is not suitable

class IMultiFunctionMachine
{
    virtual void printer() = 0;
    virtual void scanner() = 0;
    virtual void faxer() = 0;
};

class MultifunctionMachine: public IMultiFunctionMachine
{
    void printer() override
    {
        //Write code or leave empty if it does/doesnt provide printer functionality
        //But this is not a good idea as it gives an idea that machine can print but actually doesnt 
    }
    void scanner() override
    {

    }
    void faxer() override
    {

    }
};

//Instead we can do it like this
class IPrint
{
public:
    virtual void print() = 0;
};

class IFax
{
public:
    virtual void fax() = 0;
};

class IScan
{
public:
    virtual void scan() = 0;
};

//Implement the interfaces
class Scanner : public IScan
{
    void scan() override
    {

    }
};

class Printer : public IPrint
{
    void print() override
    {

    }
};

#endif /*SRP_H*/