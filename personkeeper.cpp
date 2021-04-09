#include "personkeeper.h"
#include <typeinfo>

PersonKeeper *PersonKeeper:: _instance;

/***    Производиться чтение данных с файла iLink.
 ***    Данные разделяются на 3 строковые переменных(Имя, Отчество, Фамилия)
 ***    Создается объект класса Person и его мы закидываем в стэк
 ***    Все действия происходят в цикле
***/

EStack<Person> PersonKeeper::readPerson(std::string ilink){
   std::ifstream iFile(ilink);      //..    Читаем из Файла с именем iLink
   std::string fName,lName,fHood;
    //.. Проверяем открыт ли файл
   if(iFile.is_open()){
       //.. Проверяем на пустоту peek() - достает символ из файла не смещая указатель строки
       if(iFile.peek()!= EOF){
       //.. Считываем пока можно считать строковые данные
        while(iFile >> lName >> fName >>fHood){
            PersonKeeper::getInstance()->_users.push(Person(lName,fName,fHood));
        }

       }
    /* Иначе выдаем исключения */
       else if(iFile.peek() == EOF){
           throw exc::fileIsEmpty("File is empty");
           iFile.close();
       }

   }
   else if(!iFile.is_open()){
       throw exc::fileNotOpen("File cant be open");
       iFile.close();
    }
   iFile.close();   //..    Закрываем файл
   return PersonKeeper::getInstance()->_users; //.. Возвращаем стэк
};

/***    Производиться чтение данных со Стэка в файл oLink.
 ***    Объект типа Person достается из Стэка
 ***    и с помощью методов get...Name() из него достаются 3 переменных(Ф.И.О);
 ***    Далее с помощью потокового ввода мы записываем эти переменные в нужном формате в Файл oLink;
 ***    Все действия происходят в цикле, выходом из которого является условие, что указатель вершины стал 0;
***/

void PersonKeeper::writePerson(std::string olink) {
    std::ofstream oFile(olink,std::ios::trunc);
    Person pers;
    //.. Проверяем открыт ли файл
    if(oFile.is_open()){
        //.. Вытаскиваем все данные из стека пока указатель стэка не будет в нуле
        while(PersonKeeper::getInstance()->_users.getTop()!= 0){
            pers = PersonKeeper::getInstance()->_users.pop();
            oFile << pers.getLastName()<<' '<<pers.getFirstName()<<' '<<pers.getFatherHood()<<'\n';
        }
    } else if(!oFile.is_open()){
        throw exc::fileNotOpen("File cant be open");    //..    Выдаем исключения
        oFile.close();  }
    oFile.close();      //.. Закрываем файл
};

