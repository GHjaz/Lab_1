#pragma once
#include "person.h"
#include "EStack.h"
#include <string.h>
#include <error.h>
#include <fstream>
#include <iostream>




class PersonKeeper{
private:
    PersonKeeper(){};
    ~PersonKeeper(){};
    static PersonKeeper *_instance;

public:
    EStack<Person> _users;
    PersonKeeper(PersonKeeper &other) = delete;
    void operator=(const PersonKeeper &) = delete;
    static PersonKeeper* getInstance(){
        if (_instance == 0) {
        _instance = new PersonKeeper;
        }
        return _instance;
    };

    EStack<Person>* readPerson();
    //.. Читает из файла, пишет в стэк
    //static PersonKeeper* readPerson(std::ostream& stream);


    //.. writePerson()
    //.. Читает из стека пишет файл
    void writePerson();
};


