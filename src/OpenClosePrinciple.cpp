#include "OpenClosePrinciple.h"

ProductFilter::Items ProductFilter::byColor(Items items, Color color)
{
    Items result;
    for(auto& i : items)
    {
        if(i->color == color)
            result.push_back(i);
    }
    return result;
}

ProductFilter::Items ProductFilter::bySize(Items items, Size size)
{
    Items result;
    for(auto& i : items)
    {
        if(i->size == size)
            result.push_back(i);
    }
    return result;
}

ProductFilter::Items ProductFilter::byColorNSize(Items items, Color color, Size size)
{
    Items result;
    for(auto& i : items)
    {
        if(i->color == color && i->size == size)
            result.push_back(i);
    }
    return result;
}

void ProductFilter::printItems(Items items)
{
    for(auto item : items)
    {
        std::cout<<item->name<<'\n';
    }    
}

