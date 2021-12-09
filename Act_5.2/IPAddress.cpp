#include "IPAddress.h"

IPAddress::IPAddress(){
  ip = "0.0.0.0";
  port = "0000";
}

IPAddress::IPAddress(std::string fullIp, int i){
  ip = fullIp;
  ipIndex = i;
  port = "0";
  std::vector<int> ipArray;
  split(fullIp, ipArray);
  std::string ipString = std::to_string(ipArray[0]) + "." + std::to_string(ipArray[1]) + "." + std::to_string(ipArray[2]) + "." + std::to_string(ipArray[3]);
  resumen = Resumen(ipString);
  //std::cout << ipString << std::endl;
  decIP = (pow(256, 3) * ipArray[0]) + (pow(256, 2) * ipArray[1]) + (pow(256, 1) * ipArray[2]) + (ipArray[3]);
}

// Complejidad temporal: O(n)
void IPAddress::split(std::string line, std::vector<int> & res) {
  size_t strPos = line.find(".");
  size_t lastPos = 0;
  while (strPos != std::string::npos) {
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
    lastPos = strPos+1;
    strPos = line.find(".", lastPos);
  }
  res.push_back(stoi(line.substr(lastPos, line.size()-lastPos)));
}

void IPAddress::heapify(int n, int i) {
  int largest = i;
  int l = 2*i+1;
  int r = 2*i+2;
  if (l < n && adjListIP[l] > adjListIP[largest]) {
    largest = l;
  }
  if (r < n && adjListIP[r] > adjListIP[largest]) {
    largest = r;
  }
  if (largest != i) {
    std::swap(adjListIP[i], adjListIP[largest]);
    heapify(n, largest);
  }
}

void IPAddress::heapSort(int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(n, i);
  }
  for (int i = n - 1; i > 0; i--) {
    std::swap(adjListIP[0], adjListIP[i]);
    heapify(i, 0);
  }
}

void IPAddress::updateIpGradoSalida() {
  resumen.updateSalida();
}

void IPAddress::updateIpGradoEntrada() {
  resumen.updateEntrada();
}

long int IPAddress::getIpDecimal(){
  return decIP;
}

int IPAddress::getIpIndex(){
  return ipIndex;
}

Resumen IPAddress::getResumen(){
  return resumen;
}

void IPAddress::setAdjListIp(std::vector<IPAddress> ali){
  adjListIP = ali;
}

std::vector<IPAddress> IPAddress::getAdjListIp(){
  return adjListIP;
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