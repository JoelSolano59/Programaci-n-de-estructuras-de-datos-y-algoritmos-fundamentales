#include "IPAddress.h"

IPAddress::IPAddress(){
  ip = "0.0.0.0";
  port = "0000";
  ipIndex = 0;
  ipGradoSalida = 0;
  ipGradoEntrada = 0;
}

IPAddress::IPAddress(std::string fullIp, int i){
  ip = fullIp;
  ipIndex = i;
  port = "0000";
  ipGradoSalida = 0;
  ipGradoEntrada = 0;

  std::vector<int> ipArray;
  split(fullIp, ipArray);
  decIP = (pow(256, 3) * ipArray[0]) + (pow(256, 2) * ipArray[1]) + (pow(256, 1) * ipArray[2]) + (ipArray[3]);
}

// Complejidad temporal: O(n)
void IPAddress::split(std::string line, std::vector<int> & res) {
    size_t strPos = line.find(".");
    size_t lastPos = 0;
    while (strPos != std::string::npos) {
      res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
      lastPos = strPos + 1;
      strPos = line.find(".", lastPos);
    }
    res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

void IPAddress::updateIpGradoSalida() {
  ipGradoSalida++;
}

int IPAddress::getIpGradoSalida() {
  return ipGradoSalida;
}

void IPAddress::updateIpGradoEntrada() {
  ipGradoEntrada++;
}

int IPAddress::getIpGradoEntrada() {
  return ipGradoEntrada;
}

long int IPAddress::getIpDecimal(){
  return decIP;
}

int IPAddress::getIpIndex(){
  return ipIndex;
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