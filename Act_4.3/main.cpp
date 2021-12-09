//    g++ -std=c++17 -O3 -o main *.cpp 
//    ./main */
/*
Programación de estructuras de datos y algoritmos fundamentales Gpo. 12
Joel Isaias Solano Ocampo  A01639289
Mauricio Cantú Torres      A01633805

Archivos necesarios:
+ main.cpp
+ bitacoraGrafos.txt
+ Graph.cpp
+ Graph.h
+ IPAddress.cpp
+ IPAddress.h
+ MaxHeap.h

Instrucciones de uso:
1. Compilar el archivo main con el siguiente comando en consola:
  - g++ -std=c++17 -O3 -o main *.cpp
2. Ejecutar el archivo main con el siguiente comando en consola:
  - ./main
3. En consola se desplegara la direccion IP con mayor grado
4. Como resultado se generaran los archivos: "grados_ips.txt" y "mayor_grados_ips.txt"
5. Para intentar de nuevo, volver a compilar y ejecutar por medio de consola.
*/

#include <iostream>
#include "Graph.h"

int main(){
  Graph miGrafo;
  miGrafo.loadDirectedGraph("bitacoraGrafos.txt");
}