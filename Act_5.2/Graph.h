#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <utility> 
#include <exception>
#include "IPAddress.h"
#include "HashTable.h"

class Graph {
  private:
    int numNodes;
    int numEdges;
    std::vector<std::pair<IPAddress, std::vector<IPAddress>>> adjListGraph;
    void split(std::string line, std::vector<int> & res);

  public:
    Graph();
    ~Graph();
    void loadDirectedGraph(std::string archivo);
    std::vector<std::pair<IPAddress,std::vector<IPAddress>>> getAdjListGraph();
};

#endif // __GRAPH_H_