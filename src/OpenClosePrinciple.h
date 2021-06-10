#ifndef OCP_H
#define OCP_H

#include <iostream>
#include <vector>

enum class Color
{
    Orange,
    Red,
    Green
};
enum class Size
{
    Small,
    Medium,
    Large
};

class Product
{
public:
    Product(const std::string &n, Color c, Size s) : name{n}, color{c}, size{s} {}

    std::string name;
    Color color;
    Size size;
};

class ProductFilter //This impementation breaks OCP because for each type of filter criterion, we modify the class.
{
public:
    typedef std::vector<Product *> Items;
    static Items byColor(Items items, Color color);
    static Items bySize(Items items, Size size);
    static Items byColorNSize(Items items, Color color, Size size);

    static void printItems(Items items);
};


#endif /*SRP_H*/