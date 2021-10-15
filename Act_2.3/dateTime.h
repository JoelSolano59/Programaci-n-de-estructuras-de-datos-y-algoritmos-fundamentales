#ifndef _DATETIME_H_
#define _DATETIME_H_

#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>

class dateTime
{
public:
  dateTime(std::string mes, int dia, int horas, int minutos, int segundos);
  time_t getDate();
  bool operator==(const dateTime &);
  bool operator!=(const dateTime &);
  bool operator>(const dateTime &);
  bool operator<(const dateTime &);
  dateTime();

private:
  std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  struct tm dateStruct;
  time_t date;
};

#endif // _DATETIME_H_