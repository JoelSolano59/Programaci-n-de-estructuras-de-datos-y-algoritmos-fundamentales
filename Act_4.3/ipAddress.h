#ifndef _IPADDRESS_H_
#define _IPADDRESS_H_

#include <iostream>
#include <vector>
#include<cmath> 

class IPAddress
{
public:
  IPAddress();
  IPAddress(std::string, int);
  long int getIpDecimal();
  int getIpIndex();
  void updateIpGradoSalida();
  int getIpGradoSalida();
  void updateIpGradoEntrada();
  int getIpGradoEntrada();
  void split(std::string line, std::vector<int> & res);
  bool operator==(const IPAddress &);
  bool operator!=(const IPAddress &);
  bool operator>(const IPAddress &);
  bool operator<(const IPAddress &);
  bool operator >=(const IPAddress &);
  bool operator <=(const IPAddress &);

private:
  std::string ip;
  std::string port;
  int ipIndex;
  int ipArray[4];
  int ipGradoSalida;
  int ipGradoEntrada;
  long int decIP;
};

#endif // _IPADDRESS_H_