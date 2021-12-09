#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <iostream>
#include "dateTime.h"
#include "IPAddress.h"

class Registro
{
private:
  std::string mes;
  std::string dia;
  std::string hora;
  std::string minuto;
  std::string segundo;
  std::string ip;
  std::string descripcion;
  dateTime date;
  IPAddress ipa;

public:
  Registro();
  Registro(std::string m, std::string d, std::string h, std::string mi, std::string s, std::string i, std::string de, dateTime da, IPAddress ia);
  dateTime getDate();
  IPAddress getIP();
  std::string getAll();
};

#endif // _REGISTRO_H_