#ifndef __GRAPH_H_
#define __GRAPH_H_
#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include <sstream>
#include <stack>
#include <list>

class Graph {
  private:
    int numNodes;
    int numEdges;
  
    std::vector<std::vector<std::pair<int,int>>> adjList;
    std::vector<bool> visited;
    std::stack<int> tmpStack;

    void loadDirectedGraph(std::istream& input);
    void split(std::string line, std::vector<int> & res);
    void printAdjList();
    void explore(int v);
    void exploreTopologicalSort(int v);
  
  public:
    Graph(int representacion, std::istream& input);
    ~Graph();
    void printGraph();
    void DFS(int v);
    void shortestPath(int s, int d);
    void topologicalSort(int v);
    bool isBipartite();
    void bipartiteGraph();
    bool BFS(int s, int d, int pr[], int di[]);
};

#endif // __GRAPH_H_