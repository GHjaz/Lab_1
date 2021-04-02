#pragma once

#include <iostream>
#include <EStack.h>

class Person
{
private:
    long key;
    std::string last_name;
    std::string first_name;
public:
    Person();
    Person(const Person&);
    const std::string& getLastName() const { return last_name; }
    const std::string& getFirstName() const { return first_name; }
    void setLastName(const std::string&);
    void setFirstame(const std::string&);
};

