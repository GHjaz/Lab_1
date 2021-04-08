#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include "personkeeper.h"
#include <string.h>

using namespace std;

int main()
{
    PersonKeeper::getInstance()->readPerson();
    PersonKeeper::getInstance()->writePerson();
    return 0;
}
