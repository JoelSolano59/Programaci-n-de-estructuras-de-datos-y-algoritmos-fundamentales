#include <iostream>
#include "Graph.h"

/*
Programación de estructuras de datos y algoritmos fundamentales Gpo. 12
Joel Isaias Solano Ocampo  A01639289
Mauricio Cantu Torres      A01633805

* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < test01.txt o bien, ./main < test02.txt
*/

int main() {
  std::cout << "Ejemplo de DFS en grafos!\n";
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf(); 

  // Construye un grafo a partir de la consola
  Graph g1(1, inputInfo);

  //Imprimir un grafo con printGraph
  g1.printGraph();

  //Imprimir el recorrido DFS 
  g1.DFS(7);

  //Imprimir el recorrido BFS
  g1.BFS(7);

  //Creamos un grafo nuevo
  Graph g2;

  //Copiamos la informacion del grafo g1 al grafo g2
  g1.copyGraph(1, g2);
  g2.printGraph();
} 