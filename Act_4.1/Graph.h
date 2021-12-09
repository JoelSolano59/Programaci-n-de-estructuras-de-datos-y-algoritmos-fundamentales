#ifndef __GRAPH_H_
#define __GRAPH_H_
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>

class Graph {
  private:
    int numNodes;
    int numEdges;
    int representation; // 1 Adjacency list; 2 Adjacency matrix
    // Matriz de adyacencia
    int **adjMatrix;
    // Lista de adyacencia (vector de vectores)
    std::vector<std::vector<int>> adjList;
    std::vector<bool> visited;

    void loadGraphList(std::istream& input);
    void loadGraphMatrix(std::istream& input);
    void split(std::string line, std::vector<int> & res);
    void printAdjList();
    void printAdjMatrix();
    void explore(int v);

  public:
    Graph();
    Graph(int representacion, std::istream& input);
    ~Graph();
    void printGraph();
    void DFS(int v);
    void BFS(int v);
    void copyGraph(int representaElegida, Graph &other);
};

#endif // __GRAPH_H_