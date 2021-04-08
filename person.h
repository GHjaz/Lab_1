#pragma once

#include <iostream>
#include <EStack.h>

class Person
{
private:
    std::string last_name; // Имя
    std::string first_name; // Фамилия
    std::string fatherhood; // Отчество
public:
    Person();
    Person(const Person&);
    Person(std::string l,std::string f, std::string fh);
    const std::string& getLastName() const {return last_name; } //..Возвращаем Фамилию
    const std::string& getFirstName() const {return first_name; }   //..Возвращаем имя
    const std::string& getFatherHood() const{return fatherhood; }   //..Возвращаем отчество
    void setLastName(const std::string&);
    void setFirstName(const std::string&);
    void setFatherHood(const std::string&);
};

