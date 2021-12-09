/*
Programación de estructuras de datos y algoritmos fundamentales Gpo. 12
Joel Isaias Solano Ocampo  A01639289

Archivos necesarios:
+ main.cpp
+ bitacoraHeap.txt
+ dateTime.cpp
+ dateTime.h
+ IPAddress.cpp
+ IPAddress.h
+ IPFrequent.h
+ MaxHeap.h
+ Registro.cpp
+ Registro.h

Instrucciones de uso:
1. Compilar el archivo main.cpp
3. En consola se desplegaran las 5 direcciones IPs con mayor freecuencia
4. Como resultado se generaran los archivos: "bitacora_ordenada.txt" y "ips_con_mayor_acceso.txt"
5. Para intentar de nuevo, volver a compilar main.cpp
*/

#include <iostream>
#include <fstream>
#include "MaxHeap.h"
#include "Registro.h"
#include "IPAddress.h"
#include "IPFrequent.h"

int main() {
  MaxHeap<Registro> myHeap(16808);
  myHeap.cargarBitacoraHeap("bitacoraHeap.txt");
  myHeap.BitacoraHeapOrdenada();
  myHeap.BitacoraHeapIPAcceso();

  MaxHeap<IPFrequent> myIPHeap(800);
  myIPHeap.nuevoRegistro();
  myIPHeap.IPMayorAcceso("ips_con_mayor_acceso.txt");
}