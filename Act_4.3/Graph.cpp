#include "Graph.h"

Graph::Graph() {
    numNodes = 0;
    numEdges = 0;
}

Graph::~Graph() {
  adjList.clear();
  mapIP.clear();
}

//Complejidad temporal: O(n)
void Graph::loadDirectedGraph(std::string archivo) {
  std::ifstream inputFile(archivo);
  std::string line;
  int i = 0;
  if (inputFile.is_open()) {
    while (std::getline(inputFile, line)) {
      if (i == 0) {
        std::vector<int> res;
        split(line, res);
        numNodes = res[0];
        numEdges = res[1];
        std::cout << numNodes << " " << numEdges << std::endl;
        adjList.resize(numNodes+1);
      } else if (i > 0 && i <= numNodes) {
        IPAddress tmpIPAddress(line, i);
        mapIP.insert({tmpIPAddress.getIpDecimal(), tmpIPAddress});
      } else {
        //Se buscan las 2 IP's en la bitacora
        std::size_t found = line.find(":", 15);
        std::string ip1 = line.substr(15, found-15);
        std::size_t found2 = line.find(" ", found+1);
        std::size_t found3 = line.find(":", found2+1);
        std::string ip2 = line.substr(found2, found3-found2);

        // //Se crean 2 objetos temporales de tipo IPAddress
        IPAddress tmpIP1(ip1, 0);
        IPAddress tmpIP2(ip2, 0);

        // //Se hace un mapeo de la IP y el objeto como iteradores
        std::map<long int, IPAddress>::iterator j;
        std::map<long int, IPAddress>::iterator k;

        j = mapIP.find(tmpIP1.getIpDecimal());
        int u = -1;
        if (j != mapIP.end()) {
          u = j->second.getIpIndex();
        }
        k = mapIP.find(tmpIP2.getIpDecimal());
        int v = -1;
        if (k != mapIP.end()) {
          v = k->second.getIpIndex();
        }
        if (v != -1 && u != -1) {
          adjList[u].push_back({v,1});
          j->second.updateIpGradoSalida();
          k->second.updateIpGradoEntrada();
        }
      }
      i++;
    }
    inputFile.close();

    // for (std::map<long int, IPAddress>::iterator it = mapIP.begin(); it != mapIP.end(); it++) {
    //   it = mapIP.find(tmpIPAddress.getIpDecimal());
    // }
/*
    //grados_ips.txt
    std::ifstream inputFile(archivo);
    std::string line;
    int i = 0;
    std::ofstream out("grados_ips.txt");
    std::cout << "--->Genrando archivo: grados_ips.txt" << std::endl;
    while (std::getline(inputFile, line)){
      if (i > 0 && i <= numNodes){
        IPAddress tmpIPAddress(line, i);
        std::map<long int, IPAddress>::iterator j;
        j = mapIP.find(tmpIPAddress.getIpDecimal());
        int u = -1;
        if (j != mapIP.end()) {
          u = j->second.getIpIndex();
          out << line << "\t\tGrado Entrada: " << j->second.getIpGradoEntrada() << "\t\tGrado Salida: " << j->second.getIpGradoSalida() << std::endl;
        }
      }
      i++;
    }
    out.close();
    inputFile.close();


    //mayores_grados_ips.txt
    MaxHeap<IPAddress> IpHeap(numNodes);
    //IpHeap.updateCapacity(13370);
    for (int i = 0; i < mapIP.size(); i++){
      IpHeap.push(mapIP[i]);
      //std::cout << typeid(mapIP[i]).name()<<std::endl;
    }
    //IpHeap.IPMayorAcceso("mayores_grados_ips.txt");
  }
  return;
  */
  // Ejemplo de cómo iterar el objeto map para insertar en el MaxHeap
    MaxHeap<IPAddress> IpHeap(numNodes+1);
    std::cout << "map size: " << mapIP.size() << std::endl;
    std::ofstream out1("grados_ips.txt");
    for (std::map<long int, IPAddress>::iterator it = mapIP.begin(); it != mapIP.end(); it++){
      IpHeap.push(it->second);
      out1 << "Ip: " << it->second.getIpDecimal() << "\t\tGrado Entrada: " << it->second.getIpGradoEntrada() << "\t\tGrado Salida: " << it->second.getIpGradoSalida() << std::endl;
    }
    out1.close();
    // Ejemplo de cómo recuperar el top del MaxHeap
    std::ofstream out2("mayores_grados_ips.txt");
    std::cout << "Ip: " << IpHeap.top().getIpDecimal() << "\t\tGrado: " << IpHeap.top().getIpGradoSalida() << std::endl;
    out2 << "Ip: " << IpHeap.top().getIpDecimal() << "\t\tGrado: " << IpHeap.top().getIpGradoSalida() << std::endl;
    IpHeap.pop();
    for (int i = 0; i < 4; i++) {
      out2 << "Ip: " << IpHeap.top().getIpDecimal() << "\t\tGrado: " << IpHeap.top().getIpGradoSalida() << std::endl;
      IpHeap.pop();
    }
    out2.close();
  }
}

//Complejidad temporal: O(n^2)
void Graph::printGraph(){
	  std::cout << "Adjacency List" << std::endl;
		for (int i = 1; i <= numNodes; i++){
	        std::cout << "vertex " << i << ": ";
	        for (int j = 0; j < (int)adjList[i].size(); j ++){
							 std::cout << " (" << adjList[i][j].first << ", " << adjList[i][j].second << ") ";
					}
	        std::cout << std::endl;
    }
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