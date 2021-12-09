#include "IPAddress.h"

IPAddress::IPAddress(){}

IPAddress::IPAddress(std::string fullIp){
  ip1 = stoi(fullIp.substr(0,2));
  ip2 = stoi(fullIp.substr(3,5));
  ip3 = stoi(fullIp.substr(6,9));
  ip4 = stoi(fullIp.substr(10,13));
  port = stoi(fullIp.substr(14,17));
  decIP = (pow(256, 3) * ip1) + (pow(256, 2) * ip2) + (pow(256, 1) * ip3) + (pow(256, 0) * ip4);
}

int IPAddress::getIpDecimal(){
  return decIP;
}

bool IPAddress::operator==(const IPAddress &other) {
  return this->decIP == other.decIP;
}

bool IPAddress::operator!=(const IPAddress &other) {
  return this->decIP != other.decIP;
}

bool IPAddress::operator>(const IPAddress &other) {
  return this->decIP > other.decIP;
}

bool IPAddress::operator<(const IPAddress &other) {
  return this->decIP < other.decIP;
}

bool IPAddress::operator>=(const IPAddress &other) {
  return this->decIP >= other.decIP;
}

bool IPAddress::operator<=(const IPAddress &other) {
  return this->decIP <= other.decIP;
}