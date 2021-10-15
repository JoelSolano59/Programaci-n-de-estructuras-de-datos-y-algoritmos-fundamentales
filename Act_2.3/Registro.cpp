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

Registro::Registro(std::string m, std::string d, std::string h, std::string mi, std::string s, std::string ipa, std::string desc, dateTime dt)
{
  mes = m;
  dia = d;
  hora = h;
  minuto = mi;
  segundo = s;
  ip = ipa;
  descripcion = desc;
  date = dt;
}

dateTime Registro::getDate()
{
  return date;
}

std::string Registro::getAll()
{
  return mes + " " + dia + " " + hora + ":" + minuto + ":" + segundo + " " + ip + " " + descripcion + "\0";
}