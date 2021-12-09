#include "Registro.h"

Registro::Registro()
{
  mes = "";
  dia = "";
  hora = "";
  minuto = "";
  segundo = "";
  ip = "";
  descripcion = "";
}

Registro::Registro(std::string m, std::string d, std::string h, std::string mi, std::string s, std::string i, std::string de, dateTime da, IPAddress ia)
{
  mes = m;
  dia = d;
  hora = h;
  minuto = mi;
  segundo = s;
  ip = i;
  descripcion = de;
  date = da;
  ipa = ia;
}

dateTime Registro::getDate()
{
  return date;
}

IPAddress Registro::getIP()
{
  return ipa;
}

std::string Registro::getAll()
{
  return mes + " " + dia + " " + hora + ":" + minuto + ":" + segundo + " " + ip + " " + descripcion + "\0";
}