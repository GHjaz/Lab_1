#include "person.h"

Person::Person()
{
    last_name = "";
    first_name = "";
    fatherhood = "";
}

Person::Person(const Person& T){

    last_name = T.getLastName();
    first_name = T.getFirstName();
    fatherhood = T.getFatherHood();

}

void Person::setFirstName(const std::string& _fName){
    first_name = _fName;
}

void Person::setLastName(const std::string& _lName){
    last_name = _lName;
}

void Person::setFatherHood(const std::string & _fHood){
    fatherhood = _fHood;
}

Person::Person(std::string a,std::string b,std::string e){
    last_name = a;
    first_name = b;
    fatherhood = e;
}

