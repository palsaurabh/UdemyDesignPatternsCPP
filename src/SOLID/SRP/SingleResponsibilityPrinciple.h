#ifndef SRP_H
#define SRP_H

#include <vector>
#include <iostream>

class Journal
{
private:
    std::string title;
    std::vector<std::string> entries;

public:
    Journal(const std::string &name) : title{name} {};
    ~Journal(){};

    const std::string &getName();
    void add(const std::string &entry);
    const std::vector<std::string> &getEntries() const;
    void print();
};

// Responsibility of persistence of Journal left to PersistenceManager Class
class PersistenceManager
{
public:
    static void save(const Journal &j, const std::string &filename);
};

#endif /*SRP_H*/