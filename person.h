#pragma once

#include <iostream>
#include <EStack.h>

class Person
{
private:
    std::string last_name;
    std::string first_name;
    std::string fatherhood;
public:
    Person();
    Person(const Person&);
    Person(std::string l,std::string f, std::string fh);
    const std::string& getLastName() const {return last_name; }
    const std::string& getFirstName() const {return first_name; }
    const std::string& getFatherHood() const{return fatherhood; }
    void setLastName(const std::string&);
    void setFirstName(const std::string&);
    void setFatherHood(const std::string&);
};

