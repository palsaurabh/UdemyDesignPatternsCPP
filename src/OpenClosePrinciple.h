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

template <typename T>
class Specification
{
    public:
    virtual ~Specification() = default;
    virtual bool is_satisfied(T* item) const = 0;
};



template <typename T>
class AndSpecification : public Specification<T>
{
    public:
    const Specification<T>& first;      //TODO::Why it doesnt compile without '&'
    const Specification<T>& second;

    AndSpecification(Specification<T>& f, Specification<T>& s):
        first{f}, second{s} {}
    
    // bool is_satisfied(T* item) const override;
    bool is_satisfied(T* item) const
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

//A better filter that is extensible
template <typename T>
class Filter
{
    public:
    virtual std::vector<T *> filter(std::vector<T *> items,
                                        Specification<T>& spec) = 0;
};

class BetterFilter: public Filter<Product>
{
    public:
    std::vector<Product *> filter(std::vector<Product *> items,
                                        Specification<Product>& spec) override;
    void print(std::vector<Product *> items) const;

};

class ColorSpecification : public Specification<Product>
{
    public:
    Color color;
    ColorSpecification(Color c): color{c}{};
    bool is_satisfied(Product *item) const override;
};

class SizeSpecification : public Specification<Product>
{
    public:
    Size size;
    SizeSpecification(Size s): size{s}{};
    bool is_satisfied(Product *item) const override;
};


#endif /*SRP_H*/