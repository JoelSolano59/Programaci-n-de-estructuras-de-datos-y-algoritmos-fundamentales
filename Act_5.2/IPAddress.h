#ifndef _IPADDRESS_H_
#define _IPADDRESS_H_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Resumen.h"

class IPAddress
{
public:
  IPAddress();
  IPAddress(std::string, int);
  long int getIpDecimal();
  int getIpIndex();
  void updateIpGradoSalida();
  void updateIpGradoEntrada();
  void split(std::string line, std::vector<int> & res);
  void setAdjList(std::vector<IPAddress> al);
  Resumen getResumen();
  void setAdjListIp(std::vector<IPAddress> ali);
  std::vector<IPAddress> getAdjListIp();
  void heapify(int n, int i);
  void heapSort(int n);
  void merge(int l, int r, int m);
  void mergeSort(int l, int r);
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
  long int decIP;
  Resumen resumen;
  std::vector<IPAddress> adjListIP;
};

#endif // _IPADDRESS_H_