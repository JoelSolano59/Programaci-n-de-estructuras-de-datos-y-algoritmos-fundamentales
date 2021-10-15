#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <iostream>
#include "dateTime.h"

class Registro
{
private:
    dateTime date;
    std::string mes;
    std::string dia;
    std::string hora;
    std::string minuto;
    std::string segundo;
    std::string ip;
    std::string descripcion;

public:
    Registro();
    Registro(std::string m, std::string d, std::string h, std::string mi, std::string s, std::string ipa, std::string desc, dateTime date);
    dateTime getDate();
    std::string getAll();
};

#endif // _REGISTRO_H_