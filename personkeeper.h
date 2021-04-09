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
    static PersonKeeper* _instance;     //.. Создаем статический указатель на Singleton
    PersonKeeper(){};   //.. Скрываем конструктор и деструктор
    ~PersonKeeper(){};

public:

    static PersonKeeper* getInstance(){ //.. Задаем метод Instance для вызова единственного обекта класса PersonKeeper
       if (_instance == 0){
       _instance = new PersonKeeper;    //..    Создаем объект Singleton PersonKeeper, если он не был объявлен ранее
       }
        return _instance;
    };
    EStack<Person> _users;  //.. Стэк классов персон
    PersonKeeper(PersonKeeper &other) = delete; //.. Удаляем конструктор копирования и присваивания, чтобы не было соблазна инцилизировать новый объект Singleton, и удаляем возможность инцилизации этих двух методов досутпно (c11++)
    void operator=(const PersonKeeper &) = delete;
    EStack<Person> readPerson(std::string);
    //.. Читает из файла, пишет в стэк
    //static PersonKeeper* readPerson(std::ostream& stream);
    //.. writePerson()
    //.. Читает из стека пишет файл
    void writePerson(std::string);
};


