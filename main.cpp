#include <iostream>
#include "DIP.h"

int main()
{
    Person parent("John");
    Person child1("Chris");
    Person child2("Matt");

    RelationShips relationships;
    relationships.addParentandChild(parent, child1);
    relationships.addParentandChild(parent, child2);
    relationships.addSiblings(child1, child2);

    std::cout<<"Applying research on John\n";
    Research research(Relationship::sibling, "Chris");
    research.applyResearch(relationships);
    return 0;
}