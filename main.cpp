#include <iostream>
#include "SingleResponsibilityPrinciple.h"

int main()
{
    Journal myJournal("Saurabh");
    myJournal.add("I am a good boy");
    myJournal.add("That bloody bastard");
    myJournal.add("Hello you are a buffalo");

    myJournal.print();

    PersistenceManager pm;
    pm.save(myJournal, "MyJournal.txt");
    return 0;
}