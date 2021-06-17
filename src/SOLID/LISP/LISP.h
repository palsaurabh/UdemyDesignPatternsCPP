#ifndef SRP_H
#define SRP_H

#include <vector>
#include <iostream>

//This is an example of breaking up the Liskov Substitution Principle
//LISP: Extended types should be substitutable in the at all places where the base type can be used

class Rectangle
{
protected:
    int height, width;
public:
    Rectangle(int h, int w): height{h}, width{w} {}

    int getHeight() const 
    {
        return height;
    }

    virtual void setHeight(int h)
    {
        height = h;
    }

    int getWidth() const 
    {
        return width;
    }

    virtual void setWidht(int w)
    {
        width = w;
    }

    int getArea()
    {
        return width * height;
    }

};

class Square: public Rectangle
{
    public:
    Square(int s): Rectangle(s, s) {}

    void setHeight(int h) override
    {
        height = width = h;
    }

    void setWidht(int w) override
    {
        width = height = w;
    }

}
;
int process(Rectangle &rect)
{
    rect.setWidht(10);
    int area = rect.getHeight() * rect.getWidth();

    std::cout<<"Result: "<< area<<'\n';

    return area;
}

#endif /*SRP_H*/