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

std::vector<Product *> BetterFilter::filter(std::vector<Product *> items,
                                    Specification<Product>& spec)
{
    std::vector<Product *> result;
    for(auto& product: items)
    {
        if(spec.is_satisfied(product))
            result.push_back(product);
    }

    return result;
}

bool ColorSpecification::is_satisfied(Product *item) const
{
    return (item->color == color);
}

bool SizeSpecification::is_satisfied(Product *item) const
{
    return (item->size == size);
}

void BetterFilter::print(std::vector<Product *> items) const
{
    for(auto item : items)
    {
        std::cout<<item->name<<'\n';
    }    
}
// template <typename T>
// bool AndSpecification<T>::is_satisfied(T* item) const
// {
//     return first.is_satisfied(item) && second.is_satisfied(item);
// }