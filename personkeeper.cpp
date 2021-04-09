#include "personkeeper.h"
#include <typeinfo>

PersonKeeper *PersonKeeper:: _instance;

EStack<Person>* PersonKeeper::readPerson(std::string ilink){
   std::ifstream iFile(ilink);
   std::string fName,lName,fHood;
    //.. Проверяем открыт ли файл
   if(iFile.is_open()){
       //.. Считываем весь файл в Стэк типа Персон
       if(iFile.peek()!= EOF){

        while(iFile >> lName >> fName >>fHood){
            PersonKeeper::getInstance()->_users.push(Person(lName,fName,fHood));
        }

       }
       else if(iFile.peek() == EOF){
           throw exc::fileIsEmpty("File is empty");
           iFile.close();
       }

   }
   else if(!iFile.is_open()){
       throw exc::fileNotOpen("File cant be open");
       iFile.close();
    }
   iFile.close();
   return &PersonKeeper::getInstance()->_users; //.. Возвращаем стэк
};

void PersonKeeper::writePerson(std::string olink) {
    std::ofstream oFile(olink,std::ios::trunc);
    Person pers;
    if(oFile.is_open()){
        //.. Вытаскиваем все данные из стека пока указатель стэка не будет в нуле
        while(PersonKeeper::getInstance()->_users.getTop()!= 0){
            pers = PersonKeeper::getInstance()->_users.pop();
            oFile << pers.getLastName()<<' '<<pers.getFirstName()<<' '<<pers.getFatherHood()<<'\n';
        }
    } else if(!oFile.is_open()){
        throw exc::fileNotOpen("File cant be open");
        oFile.close();  }
    oFile.close();
};

