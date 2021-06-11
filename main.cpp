#include <iostream>
#include "OpenClosePrinciple.h"

int main()
{
    Product p1{"Apple", Color::Red, Size::Small};
    Product p2{"Banana", Color::Orange, Size::Small};
    Product p3{"Banana", Color::Green, Size::Large};
    Product p4{"Pear", Color::Green, Size::Medium};
    Product p5{"Pomegranate", Color::Red, Size::Medium};

    ProductFilter::Items items{&p1, &p2, &p3, &p4, &p5};
    ProductFilter filter;

    // std::cout<<"Filtered by Size\n";
    // filter.printItems( filter.bySize(items, Size::Large));
    // std::cout<<"Filtered by Color\n";
    // filter.printItems( filter.byColor(items, Color::Red));
    // std::cout<<"Filtered by Color and Size\n";
    // filter.printItems( filter.byColorNSize(items, Color::Green,  Size::Large));

    ColorSpecification red{Color::Red};
    SizeSpecification medium{Size::Medium};
    AndSpecification<Product> customSpec{red, medium};

    BetterFilter bf;

    std::cout<<"Better Filter by Color Red\n";
    filter.printItems(bf.filter(items, red));
    std::cout<<"Better Filter by Medium\n";
    filter.printItems(bf.filter(items, medium));

    // auto customSpec = red && medium;
    std::cout<<"Better Filter by Red and Medium\n";

    bf.print(bf.filter(items, customSpec));
    return 0;
}