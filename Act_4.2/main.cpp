/** 
* Programación de estructuras de datos y algoritmos fundamentales Gpo. 12
* Joel Isaias Solano Ocampo  A01639289
* Mauricio Cantu Torres      A01633805
*
* Ejemplo que implementa la representacion de Grafos
* Lista de adyacencia y el ordenamiento topologico
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    valgrind --leak-check=full ./main < petersen.txt
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < petersen.txt
**/

#include <iostream>
#include "Graph.h"

int main() {
  std::cout << "Ejemplo de Ordenamiento Topologico en grafos!\n";
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf();

  // Construye un grafo a partir de la consola
  Graph g1(1, inputInfo);

  //Imprimir un grafo con printGraph
  g1.printGraph();

  //Imprimir el recorrido DFS 
  g1.DFS(1);

  //Imprimir el recorrido mas corto
  g1.shortestPath(1,10);

  //Imprimir el topological Sort
  g1.topologicalSort(1);

  //Imprimir si el grafo es Bipartita o no
  g1.isBipartite();
} 