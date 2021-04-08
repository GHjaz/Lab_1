#include "personkeeper.h"

PersonKeeper* PersonKeeper::_instance = 0;

EStack<Person>* PersonKeeper::readPerson(){
   std::ifstream iFile("..\\Lab_1\\input.txt");
   std::string fName,lName,fHood;
   if(iFile.is_open()){
       while(iFile >> lName >> fName >>fHood){
           PersonKeeper::getInstance()->_users.push(Person(lName,fName,fHood));
       }
   }
   iFile.close();
   return &PersonKeeper::getInstance()->_users;
};

void PersonKeeper::writePerson() {
    std::ofstream oFile("..\\Lab_1\\output.txt",std::ios::trunc);
    Person pers;
    if(oFile.is_open()){
        while(PersonKeeper::getInstance()->_users.getTop()!= 0){
            pers = PersonKeeper::getInstance()->_users.pop();
            oFile << pers.getLastName()<<' '<<pers.getFirstName()<<' '<<pers.getFatherHood()<<'\n';
        }
    }
    oFile.close();
};

