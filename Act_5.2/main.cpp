/** 
* Joel Isaias Solano Ocampo  A01639289
* Mauricio Cantu Torres      A01633805
*                                                          
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    valgrind --leak-check=full ./main
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main
**/

#include <iostream>
#include "Graph.h"

int main() {
  Graph miGrafo;
  miGrafo.loadDirectedGraph("bitacoraGrafos.txt");
} 