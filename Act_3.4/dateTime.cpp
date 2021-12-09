#include "dateTime.h"

dateTime::dateTime(std::string mes, int dia, int horas, int minutos, int segundos)
{
  dateStruct.tm_sec = segundos;
  dateStruct.tm_min = minutos;
  dateStruct.tm_hour = horas;
  dateStruct.tm_mday = dia;
  for (int i = 0; i < meses.size(); i++)
  {
    if (meses[i] == mes)
      dateStruct.tm_mon = i;
  }
  dateStruct.tm_year = 2021 - 1900;
  date = mktime(&dateStruct);
}

dateTime::dateTime(){};

time_t dateTime::getDate()
{
  return date;
}

bool dateTime::operator==(const dateTime &other)
{
  return this->date == other.date;
}

bool dateTime::operator!=(const dateTime &other)
{
  return this->date != other.date;
}

bool dateTime::operator>(const dateTime &other)
{
  return this->date > other.date;
}

bool dateTime::operator<(const dateTime &other)
{
  return this->date < other.date;
}