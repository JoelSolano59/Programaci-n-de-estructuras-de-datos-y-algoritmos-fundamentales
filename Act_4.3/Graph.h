#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include <map>
#include "IPAddress.h"
#include "MaxHeap.h"

class Graph {
  private:
    int numNodes;
    int numEdges;
    std::vector<std::vector<std::pair<int,int>>> adjList;
    std::map<long int, IPAddress> mapIP;
    void split(std::string line, std::vector<int> & res);

  public:
    Graph();
    ~Graph();
    void loadDirectedGraph(std::string archivo);
    void printGraph();
};

#endif // __GRAPH_H_