#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include "personkeeper.h"
#include <string.h>

using namespace std;

/***    Функция, которая пытается прочитать данные из не найденного или не существующего файла    ***/

void Test1(){
    try {
       PersonKeeper::getInstance()->readPerson("input1.txt");

    }  catch (const exc::Exception& ex) {

       std::cout << "Test - 1:   " << ex.what() << std::endl;
    }
}

/***    Функция достает данные из пустого стэка и ничего не записывает    ***/

void Test2(){
    try {
       PersonKeeper::getInstance()->writePerson("..\\Lab_1\\output2.txt");

    }  catch (const exc::Exception& ex) {

       std::cout<< "Test -2:   " << ex.what() << std::endl;
    }
}

/***    Функция пытается прочитать данные из пустого файла, и выдает исключение Пустой Файл    ***/

void Test3(){
    try {
        PersonKeeper::getInstance()->readPerson("..\\Lab_1\\inputEmpty.txt");

        PersonKeeper::getInstance()->writePerson("..\\Lab_1\\output.txt");

    }  catch (const exc::Exception& ex) {

         std::cout<< "Test - 3:   " << ex.what() << std::endl;
    }
}

/***    Проверка чтения и записи данных, где разделитель /n      ***/

void Test4(){
    try {
        PersonKeeper::getInstance()->readPerson("..\\Lab_1\\input.txt");

        PersonKeeper::getInstance()->writePerson("..\\Lab_1\\output.txt");

    }  catch (const exc::Exception& ex) {

       std::cout<< "Test - 4:   " << ex.what() << std::endl;
    }
}

/***    Проверка чтения и записи данных, где исходные данные записаны в строку через табуляцию    ***/

void Test5(){
    try {

        PersonKeeper::getInstance()->readPerson("..\\Lab_1\\inlineInput.txt");

        PersonKeeper::getInstance()->writePerson("..\\Lab_1\\test_output.txt");

    }  catch (const exc::Exception& ex) {

       std::cout<< "Test - 5:   " << ex.what() << std::endl;
    }
}

/***    Чтение из Стэка, после извлечения данных из него        ***/

void Test6(){
    try {
        PersonKeeper::getInstance()->writePerson("..\\Lab_1\\output.txt");
        PersonKeeper::getInstance()->writePerson("..\\Lab_1\\output.txt");

    }  catch (const exc::Exception& ex) {

       std::cout<< "Test - 6:   " << ex.what() << std::endl;   }
}

/***    Тест на извлечение данных из стэка через push    ***/

void Test7(){
    try {

        while(PersonKeeper::getInstance()->_users.getTop())
        PersonKeeper::getInstance()->_users.pop();

    }  catch (const exc::Exception& ex) {

       std::cout<< "Test - 7:   " << ex.what() << std::endl;   }
}

/***    Тест на переполнение стэка с помощью Stack.push()    ***/
void Test8(){
    try {
        for (int i = 0;i<20;i++){
            PersonKeeper::getInstance()->_users.push(Person("a","b","c"));
        }
    }  catch (const exc::Exception& ex) {

       std::cout<< "Test - 8:   " << ex.what() << std::endl;   }
}

/***    Тест на пустоту стэка через Stack.pop()    ***/

void Test9(){
    try {

    for (int i = 0;i<40;i++){
        PersonKeeper::getInstance()->_users.pop();
    }
    }  catch (const exc::Exception& ex) {

       std::cout<< "Test - 9:   " << ex.what() << std::endl;   }
}

/***    Тест Singleton на возможность создания нового объекта и извлечения из него данных     ***/

void Test10(){
    try {
        PersonKeeper* T = PersonKeeper::getInstance();
        std::cout << T->_users.getPtr()->getLastName() << std::endl;
    }  catch (const exc::Exception& ex) {
    //.. Выкидываем исключения
       std::cout<< "Test - 10:   " << ex.what() << std::endl;   }
}

int main()
{
    //.. Русская раскладка
    setlocale(0,"");
    //.. Тестирования

    Test1();    //..    Тест на чтение не существующего или не найденого файла
    Test2();    //..    Тест на запись из пустого стэка (ничего не записывается, тк данных нет)
    Test3();    //..    Тест на чтение из пустого файла (должен выдать исключение FileEmpty)
    Test4();    //..    Тест на чтение, с разделителем в виде переноса
    Test5();    //..    Тест на чтение через одну строку, с табуляцией без переноса

    Test7();    //..    Тест изъятия из стэка
    Test6();    //..    Тест чтения из стека после изъятия из него элементов
    Test8();    //..    Тест переполнения стэка
    Test9();    //..    Тест на пустоту стэка

    /***    Обычная реализация задания    ***/
    try {
    //.. Читаем из файла input в стек
        PersonKeeper::getInstance()->readPerson("..\\Lab_1\\input.txt");
    //.. Записываем из стека в файл Output
        PersonKeeper::getInstance()->writePerson("..\\Lab_1\\output.txt");
    }  catch (const exc::Exception& ex) {
    //.. Выкидываем исключения
       std::cout << ex.what() << std::endl;
    }

    Test10();   //..    Тест на проверку сохраности данных в стэке после прочтения и записи.
                //..    На выходе должна быть выведенна фамилия последнего человека в стэке

    return 0;
}
