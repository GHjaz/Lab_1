#pragma once
#include "person.h"
#include "EStack.h"
#include <string.h>
#include <error.h>
#include <fstream>
#include <iostream>

/*.. Singleton реализация класса PersonKeeper */

class PersonKeeper{
private:
    static PersonKeeper* _instance;
    PersonKeeper(){};   //.. Скрываем конструктор и деструктор
    ~PersonKeeper(){};

public:

    static PersonKeeper* getInstance(){ //.. Задаем метод Instance для вызова единственного обекта класса PersonKeeper
       if (_instance == 0){
       _instance = new PersonKeeper;
       }
        return _instance;
    };//.. Создаем статический указатель на Singleton
    EStack<Person> _users;  //.. Стэк классов персон
    PersonKeeper(PersonKeeper &other) = delete; //.. Удаляем конструктор копирования и присваивания
    void operator=(const PersonKeeper &) = delete;
    EStack<Person>* readPerson(std::string);
    //.. Читает из файла, пишет в стэк
    //static PersonKeeper* readPerson(std::ostream& stream);
    //.. writePerson()
    //.. Читает из стека пишет файл
    void writePerson(std::string);
};


