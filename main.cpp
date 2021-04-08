#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include "personkeeper.h"
#include <string.h>

using namespace std;

int main()
{
    //.. Русская раскладк
    setlocale(0,"");
    //.. Отлавливаем исключения
    try {
    //.. Читаем из файла input в стек
        PersonKeeper::getInstance()->readPerson();
    //.. Записываем из стека в файл Output
        PersonKeeper::getInstance()->writePerson();
    //.. Проверяем стэк на целостность
        std::cout << PersonKeeper::getInstance()->_users.getPtr()->getLastName() << std::endl;
    }  catch (const exc::Exception& ex) {
    //.. Выкидываем исключения
       std::cout << ex.what() << std::endl;
    }

    return 0;
}
