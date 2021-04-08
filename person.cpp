#include "person.h"
    //.. Конструктор по умолчанию
Person::Person()
{
    last_name = "";
    first_name = "";
    fatherhood = "";
}
    //.. Конструктор копирования
Person::Person(const Person& T){

    last_name = T.getLastName();
    first_name = T.getFirstName();
    fatherhood = T.getFatherHood();

}
    //.. Задаем имя
void Person::setFirstName(const std::string& _fName){
    first_name = _fName;
}
    //.. Задаем фамилию
void Person::setLastName(const std::string& _lName){
    last_name = _lName;
}
    //.. Задаем Отчество
void Person::setFatherHood(const std::string & _fHood){
    fatherhood = _fHood;
}
    //.. Конструктор с входными параметрами
Person::Person(std::string a,std::string b,std::string e){
    last_name = a;
    first_name = b;
    fatherhood = e;
}

