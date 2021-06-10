#include "SingleResponsibilityPrinciple.h"
#include "fstream"

void Journal::add(const std::string &entry)
{
    static int entryNo = 1;

    entries.push_back(std::to_string(entryNo++) + ". " + entry);
}

void Journal::print()
{
    for(auto entry : entries)
    {
        std::cout<<entry<<'\n';
    }
}

const std::string& Journal::getName()
{
    return title;
}

const std::vector<std::string>& Journal::getEntries() const
{
    return entries;
}

void PersistenceManager::save(const Journal& j, const std::string& filename)
{
    std::ofstream os(filename);
    if(os)
    {
        for(auto entry : j.getEntries())
        {
            os<<entry<<'\n';
        }       
    }
}