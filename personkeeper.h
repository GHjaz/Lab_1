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
    PersonKeeper(){};   //.. Скрываем конструктор и деструктор
    ~PersonKeeper(){};
    static PersonKeeper *_instance; //.. Создаем статический указатель на Singleton

public:
    EStack<Person> _users;  //.. Стэк классов персон
    PersonKeeper(PersonKeeper &other) = delete; //.. Удаляем конструктор копирования и присваивания
    void operator=(const PersonKeeper &) = delete;
    static PersonKeeper* getInstance(){ //.. Задаем метод Instance для вызова единственного обекта класса PersonKeeper
        if (_instance == 0) {   //.. Проверяем был ли инцилизирован объект ранее
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


