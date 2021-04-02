#pragma once
#include "person.h"
#include "EStack.h"
#include <string.h>

class PersonKeeper //.. Надо додумать структуру классов Наследование от person ??? и стэка ,,,
{
private:
   EStack<std::string> T;
   Person P;
public:
    PersonKeeper();
    //.. readPerson()
    //.. Читает из файла, пишет в стэк


    //.. writePerson()
    //.. Читает из стека пишет файл
};

