#ifndef _IPADDRESS_H_
#define _IPADDRESS_H_

#include <iostream>
#include <string>
#include <math.h>

class IPAddress
{
public:
  IPAddress();
  IPAddress(std::string);
  int getIpDecimal();
  bool operator==(const IPAddress &);
  bool operator!=(const IPAddress &);
  bool operator>(const IPAddress &);
  bool operator<(const IPAddress &);
  bool operator >=(const IPAddress &);
  bool operator <=(const IPAddress &);

private:
  int ip1;
  int ip2;
  int ip3;
  int ip4;
  int port;
  int decIP;
};

#endif // _IPADDRESS_H_