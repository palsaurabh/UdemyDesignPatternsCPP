#ifndef DIP_H
#define DIP_H

#include <iostream>
#include <vector>
#include <tuple>

// A. High-level modules should not depend on low-level modules.
//    Both should depend on abstractions.
// B. Abstractions should not depend on details.
//    Details should depend on abstractions.

enum class Relationship
{
    child,
    parent,
    sibling
};

class Person
{
public:
    std::string name;
    Person(std::string n) : name{n} {};
};

struct RelationShipBrowser
{
    virtual std::vector<Person> findAll(const Relationship relationShip, const std::string &parentName) const = 0;
};

class RelationShips: public RelationShipBrowser
{
private:
    std::vector<std::tuple<Person, Relationship, Person>> relations;

public:
    const std::vector<std::tuple<Person, Relationship, Person>>& getRelations() const
    {
        return relations;
    }
    void addParentandChild(Person &parent, Person &child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    void addSiblings(Person &p1, Person &p2)
    {
        relations.push_back({p1, Relationship::sibling, p2});
        relations.push_back({p2, Relationship::sibling, p1});
    }

    std::vector<Person> findAll(const Relationship relationShip, const std::string &p) const override
    {
        std::vector<Person> result;
        for (auto &&[first, rel, second] : relations)
        {
            // std::cout<<"first.name: "<<first.name<<"PersonName: "<<p<<'\n';
            if (first.name == p && rel == relationShip)
            {
                result.push_back(second);
            }
        }

        return result;
    }
    RelationShips(/* args */);
    ~RelationShips();
};

RelationShips::RelationShips(/* args */)
{
}

RelationShips::~RelationShips()
{
}

std::string getRelationName(const Relationship &rel) 
{
    switch (rel)
    {
    case Relationship::parent:
        return "parent";
        break;    
    case Relationship::sibling:
        return "sibling";
        break;
    case Relationship::child:
        return "child";
        break;
    default:
        break;
    }
}


class Research
{
private:
    const Relationship &relation;
    std::string relationName;
    const std::string &person_name;

public:
    void applyResearch(const RelationShipBrowser& relationshipBrowser);
    Research(const Relationship &rel, const std::string &name);
    ~Research();
};

// void Research::applyResearch(const RelationShips& relationships)
// {   
//     const auto& rel = relationships.getRelations();
//     for(auto&& [p1, reln, p2] : rel)
//     {
//         if(p1.name == person_name && reln == relation)
//         {
//             std::cout<<person_name<< " is "<< relationName<<" of "<< p2.name<<'\n';
//         }
//     }
// }
void Research::applyResearch(const RelationShipBrowser& relationshipBrowser)
{   
    const std::vector<Person> persons = relationshipBrowser.findAll(relation, person_name);
    for(auto& p1 : persons)
    {
            std::cout<<person_name<< " is "<< relationName<<" of "<< p1.name<<'\n';
    }
}


Research::Research(const Relationship &rel, const std::string &name) : relation{rel}, person_name{name}
{
    relationName = getRelationName(rel);
}

Research::~Research()
{
}

#endif /*DIP_H*/