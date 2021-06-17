#include "LISP.h"



int main()
{
    Rectangle r(2,3);
    std::cout<<"Area: "<<r.getArea()<<'\n';
    process(r);
    Square sq(5);
    process(sq);
    //So square cannot be substituted here in place of rectangle
    return 0;
}