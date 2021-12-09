#include "Graph.h"

Graph::Graph() {
    numNodes = 0;
    numEdges = 0;
}

Graph::~Graph() {
  adjListGraph.clear();
}

//Complejidad temporal: O(n)
void Graph::loadDirectedGraph(std::string archivo) {
  std::ifstream inputFile(archivo);
  std::string line;
  std::vector<IPAddress> tmpAdjList;
  std::map<long int, IPAddress> tmpMapIP;
  int i = 0;
  if (inputFile.is_open()) {
    while (std::getline(inputFile, line)) {
      if (i == 0) {
        std::vector<int> res;
        split(line, res);
        numNodes = res[0];
        numEdges = res[1];
        adjListGraph.resize(numNodes+1);
        std::cout << numNodes << " " << numEdges << std::endl;
      } else if (i > 0 && i <= numNodes) {
        IPAddress tmpIPAddress(line, i);
        adjListGraph.push_back(make_pair(tmpIPAddress, tmpAdjList));
        tmpMapIP.insert({tmpIPAddress.getIpDecimal(), tmpIPAddress});
      } else {
        //Se buscan las 2 IP's en la bitacora
        std::size_t found = line.find(":", 16);
        std::string ip1 = line.substr(16, found-16);
        std::size_t found2 = line.find(" ", found);
        std::size_t found3 = line.find(":", found2+1);
        std::string ip2 = line.substr(found2+1, (found3-found2)-1);

        //Se crean 2 objetos temporales de tipo IPAddress
        IPAddress tmpIP1(ip1, 0);
        IPAddress tmpIP2(ip2, 0);
        
        //Se encuentran los indices de cada IP, se suman sus grados y se hace push_back
        std::map<long int, IPAddress>::iterator j;
        std::map<long int, IPAddress>::iterator k;
        j = tmpMapIP.find(tmpIP1.getIpDecimal());
        int u = -1;
        if (j != tmpMapIP.end()) {
          u = j->second.getIpIndex();
        }
        k = tmpMapIP.find(tmpIP2.getIpDecimal());
        int v = -1;
        if (k != tmpMapIP.end()) {
          v = k->second.getIpIndex();
        }
        if (v != -1 && u != -1) {
          adjListGraph[u].second.push_back(tmpIP2);
          adjListGraph[u].first.updateIpGradoSalida();
          adjListGraph[v].first.updateIpGradoEntrada();
        }
      }
      i++;
    }
  }
  inputFile.close();
  HashTable<long int, IPAddress> miHashTable(25411);
  std::cout << "-->functionHash" << std::endl;
  for (std::map<long int, IPAddress>::iterator it = tmpMapIP.begin(); it != tmpMapIP.end(); it++){
    miHashTable.add(it->first, it->second);
  }
  int c = miHashTable.getColision();
  std::cout << "Colisiones: " << c << std::endl;

  std::cout << "-->getIpSummary" << std::endl;
  std::map<long int, IPAddress>::iterator l;
  std::string direccionIP;
  int m;
  do {
    std::cout << "Ingresa una direccion IP: ";
    std::cin >> direccionIP;
    IPAddress tmpIP3(direccionIP, 0);
    l = tmpMapIP.find(tmpIP3.getIpDecimal());
    m = -1;
    if (l != tmpMapIP.end()) {
      m = l->second.getIpIndex();
    }
    if (m == -1) {
      std::cout << "No se encontro la direccion IP proporsionada. Vuelva a intentarlo." << std::endl;
    }
  } while (m == -1);
  IPAddress tmpIP4(direccionIP, 0);
  //tmpIP4.heapSort(adjListGraph.size());
  tmpIP4.getResumen().printResumen();
  // for (int i = 0; adjListGraph.size(); i++) {
  // //   std::cout << adjListGraph[i] << std::endl;
  // }
}

// Complejidad temporal: O(n)
void Graph::split(std::string line, std::vector<int> & res) {
  size_t strPos = line.find(" ");
  size_t lastPos = 0;
  while (strPos != std::string::npos) {
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
    lastPos = strPos + 1;
    strPos = line.find(" ", lastPos);
  }
  res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

std::vector<std::pair<IPAddress,std::vector<IPAddress>>> Graph::getAdjListGraph(){
  return adjListGraph;
}