#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include "personkeeper.h"
#include <string.h>

using namespace std;

void Test1(){
    try {
       PersonKeeper::getInstance()->readPerson("input1.txt");
       PersonKeeper::getInstance()->writePerson("output1.txt");
    }  catch (const exc::Exception& ex) {
       std::cout << "Test -1:   " << ex.what() << std::endl;
    }
}
void Test2(){
    try {
       PersonKeeper::getInstance()->writePerson("..\\Lab_1\\output2.txt");
       PersonKeeper::getInstance()->readPerson("..\\Lab_1\\input2.txt");
    }  catch (const exc::Exception& ex) {
       std::cout<< "Test -2:   " << ex.what() << std::endl;
    }
}
void Test3(){
    try {
        PersonKeeper::getInstance()->readPerson("..\\Lab_1\\inputEmpty.txt");
    //.. Записываем из стека в файл Output
        PersonKeeper::getInstance()->writePerson("..\\Lab_1\\output.txt");
    }  catch (const exc::Exception& ex) {
         std::cout<< "Test - 3:   " << ex.what() << std::endl;
    }
}

void Test4(){
    try {
    //.. Читаем из файла input в стек
        PersonKeeper::getInstance()->readPerson("..\\Lab_1\\input.txt");
    //.. Записываем из стека в файл Output
        PersonKeeper::getInstance()->writePerson("..\\Lab_1\\output.txt");
    //.. Проверяем стэк на целостность
    }  catch (const exc::Exception& ex) {
    //.. Выкидываем исключения
       std::cout<< "Test - 4:   " << ex.what() << std::endl;
    }
}
void Test5(){
    try {
    //.. Читаем из файла input в стек
        PersonKeeper::getInstance()->readPerson("..\\Lab_1\\inlineInput.txt");
    //.. Записываем из стека в файл Output
        PersonKeeper::getInstance()->writePerson("..\\Lab_1\\test_output.txt");
    }  catch (const exc::Exception& ex) {
    //.. Выкидываем исключения
       std::cout<< "Test - 5:   " << ex.what() << std::endl;
    }
}
void Test6(){
    try {

    //.. Записываем из стека в файл Output
        PersonKeeper::getInstance()->writePerson("..\\Lab_1\\output.txt");
    }  catch (const exc::Exception& ex) {
    //.. Выкидываем исключения
       std::cout<< "Test - 6:   " << ex.what() << std::endl;   }
}
void Test7(){
    try {

    //.. Записываем из стека в файл Output
        while(PersonKeeper::getInstance()->_users.getTop())
        PersonKeeper::getInstance()->_users.pop();
    }  catch (const exc::Exception& ex) {
    //.. Выкидываем исключения
       std::cout<< "Test - 7:   " << ex.what() << std::endl;   }
}

void Test8(){
    try {

    //.. Записываем из стека в файл Output
for (int i = 0;i<20;i++){
        PersonKeeper::getInstance()->_users.push(Person("a","b","c"));
}
    }  catch (const exc::Exception& ex) {
    //.. Выкидываем исключения
       std::cout<< "Test - 8:   " << ex.what() << std::endl;   }
}

void Test9(){
    try {

    //.. Записываем из стека в файл Output
for (int i = 0;i<40;i++){
        PersonKeeper::getInstance()->_users.pop();
}
    }  catch (const exc::Exception& ex) {
    //.. Выкидываем исключения
       std::cout<< "Test - 9:   " << ex.what() << std::endl;   }
}

int main()
{
    //.. Русская раскладк
    setlocale(0,"");
    //.. Отлавливаем исключения
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    Test7();
    Test6();
    Test8();
    Test9();
    try {
    //.. Читаем из файла input в стек
        PersonKeeper::getInstance()->readPerson("..\\Lab_1\\input.txt");
    //.. Записываем из стека в файл Output
        PersonKeeper::getInstance()->writePerson("..\\Lab_1\\output.txt");
    //.. Проверяем стэк на целостность
        std::cout << PersonKeeper::getInstance()->_users.getPtr()->getLastName() << std::endl;
    }  catch (const exc::Exception& ex) {
    //.. Выкидываем исключения
       std::cout << ex.what() << std::endl;
    }
    return 0;
}
