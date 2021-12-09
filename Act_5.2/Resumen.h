#ifndef _RESUMEN_H_
#define _RESUMEN_H_

#include <iostream>

class Resumen
{
  private:
    std::string ipRes;
    int salida;
    int entrada;

  public:
    Resumen();
    Resumen(std::string ipRes);
    std::string getIpRes();
    int getSalida();
    int getEntrada();
    void updateSalida();
    void updateEntrada();
    void printResumen();
};

#endif // _RESUMEN_H_