#include "Resumen.h"

Resumen::Resumen(){
  ipRes = "0";
  salida = 0;
  entrada = 0;
}

Resumen::Resumen(std::string ipRes){
  ipRes = ipRes;
  salida = 0;
  entrada = 0;
}

std::string Resumen::getIpRes(){
  return ipRes;
}

int Resumen::getSalida(){
  return salida;
}

int Resumen::getEntrada(){
  return entrada;
}

void Resumen::updateSalida(){
  salida++;
}

void Resumen::updateEntrada(){
  entrada++;
}

void Resumen::printResumen(){
  std::cout << "IP: " << ipRes << "\tEntrada: " << entrada << "\tSalida: " << salida << std::endl;
}