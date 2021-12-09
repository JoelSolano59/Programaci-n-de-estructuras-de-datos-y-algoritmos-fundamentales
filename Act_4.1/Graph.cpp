#include "Graph.h"
#include "Queue.h"

//Complejidad temporal: O(1)
Graph::Graph() {
  numEdges = 0;
  numNodes = 0;
  representation = 1;
}

//Complejidad temporal: O(1)
Graph::Graph(int representa, std::istream& input) {
  if (representa == 1) {
    loadGraphList(input);
    representation = 1;
  }
  else {
    loadGraphMatrix(input);
    representation = 2;
  }
  visited.resize(numNodes+1);
}

//Complejidad temporal: 
//Mejor caso: O(1)
//Peor caso: O(n)
Graph::~Graph() {
  if (representation == 1) {
    adjList.clear();
  }
  else {
    for (int i = 0; i < numNodes+1; i++) 
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
  visited.clear();
}

//Complejidad temporal: 
//Mejor caso: O(1)
//Peor caso: O(n)
void Graph::loadGraphList(std::istream& input) {
  std::string line;
  int i = 0;
  while (std::getline(input, line)) {
    if (i == 0) {
      i++;
      continue;
    }
    if (i == 1) {
      std::vector<int> res;
      split(line, res);
      numNodes = res[0];
      numEdges = res[2];
      // Reservar memoria para la lista de adyacencia
      adjList.resize(numNodes+1);
      i++;
      continue; 
    }
    std::vector<int> res;
    split(line, res);
    int u = res[0];
    int v = res[1];
    // Grafos no dirigidos
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    i++;
  }
}

//Complejidad temporal: 
//Mejor caso: O(1)
//Peor caso: O(n)
void Graph::loadGraphMatrix(std::istream& input) {
  std::string line;
  int i = 0;
  while (std::getline(input, line)) {
    if (i == 0) {
      i++;
      continue;
    }
    if (i == 1) {
      std::vector<int> res;
      split(line, res);
      numNodes = res[0];
      numEdges = res[2];
      // Reserva memoria para los renglones de la matriz de adyacencia
      adjMatrix = new int*[numNodes+1];
      // Para cada renglon reserva memoria para las columnas de la matriz de adyacencia
      for (int j=0; j < numNodes+1; j++) {
        adjMatrix[j] = new int[numNodes+1];
        for (int k = 0; k < numNodes+1; k++)
          adjMatrix[j][k] = 0;
      }
      i++;
      continue; 
    }
    std::vector<int> res;
    split(line, res);
    int u = res[0];
    int v = res[1];
    // Grafos no dirigidos
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
    i++;
  }
}

//Complejidad temporal: 
//Mejor caso: O(1)
//Peor caso: O(n)
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

void Graph::printAdjList(){
  std::cout << "Adjacency List" << std::endl;
  for (int i = 1; i <= numNodes; i++){
    std::cout << "vertex " << i << ": ";
    for (int j = 0; j < (int)adjList[i].size(); j ++){
      std::cout << " " << adjList[i][j];
    }
    std::cout << std::endl;
  }
}

//Complejidad temporal: O(n^2)
void Graph::printAdjMatrix(){
  std::cout << "Adjacency Matrix" << std::endl;
  for (int i = 1; i < numNodes+1; i++){
    for (int j = 1; j < numNodes+1; j++) {
      std::cout << adjMatrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

//Complejidad temporal: O(1)
void Graph::printGraph() {
  if (representation == 1)
    printAdjList();
  else
    printAdjMatrix();
}

//Complejidad temporal: O(n)
void Graph::explore(int v) {
  visited[v] = true;
  std::cout << v << " ";
  // Lista de adyacencia
  if (representation == 1) {
    // Recorrer nodos adyacente a v
    for (int j = 0; j < (int)adjList[v].size(); j ++) {
      int u = adjList[v][j];
      if (!visited[u])
        explore(u);
		}
  }
  else { // Matriz de adyacencia
    // Recorrer nodos adyacentes a v
    for (int j = 1; j < numNodes+1; j++) {
      int c = adjMatrix[v][j];
      if (c != 0) {
        if (!visited[j])
          explore(j);
			}
    }
  }
}

//g1.copyGraph(1, g2);
// Reservar memoria para grafo g2, y copiar todos los datos de g1 a other
//Complejidad temporal: O(n^2)
void Graph::copyGraph(int representaElegida, Graph &other) {
  other.representation = representaElegida;
  other.numNodes = numNodes;
  other.numEdges = numEdges;
  
  // Copia de lista de adyacencia a lista de adyacencia
  if (representaElegida == 1 && representation == 1) {
    // Reservar memoria para la lista de adyacencia
    other.adjList.resize(numNodes+1);
    // copiar los datos de las aristas
    for (int i = 0; i <= numNodes; i++) {
      for (int j = 0; j < (int)adjList[i].size(); j++){
        other.adjList[i].push_back(adjList[i][j]); 
      }
    }
  }

  if (representaElegida == 2 && representation == 2) {
    other.adjMatrix = new int*[numNodes+1];
    for (int i = 0; i <= numNodes+1; i++) {
      other.adjMatrix[i] = new int [numNodes+1];
      for (int j = 0; j < numNodes+1; j++){
        other.adjMatrix[i][j] = 0; 
      }
    }
    for (int i = 0; i <= numNodes+1; i++) {
      for (int j = 0; j < numNodes+1; j++) {
        if (adjMatrix[i][j] != 0)
          other.adjMatrix[i][j] = adjMatrix[i][j]; 
      }
    }
  }

  if (representaElegida == 1 && representation == 2) {
    other.adjMatrix = new int*[numNodes+1];
    for (int i = 0; i <= numNodes+1; i++) {
      other.adjMatrix[i] = new int[numNodes+1];
      for (int j = 0; j < numNodes+1; j++){
        other.adjMatrix[i][j] = 0;
      }
    }
    for (int i = 0; i <= numNodes+1; i++) {
      for (int j = 0; j < (int)adjList[i].size(); j++){
        other.adjMatrix[i][adjList[i][j]] = 1;
      }
    }
  }

  if (representaElegida == 2 && representation == 1) {
    other.adjList.resize(numNodes+1);
    for (int i = 0; i <= numNodes+1; i++) {
      for (int j = 0; j < numNodes+1; j++){
        if (adjMatrix[i][j] != 0)
          other.adjList[i].push_back(j);
      }
    }
  }
  visited.resize(numNodes+1);
}

//Complejidad temporal: O(n)
void Graph::DFS(int v) {
  int i;
  for (i = 0; i < numNodes+1; i++)
    visited[i] = false;
  std::cout << "Recorrido DFS " << std::endl;
  visited[v] = true;
  explore(v);
  for (i = 1; i < numNodes+1; i++) {
    if (!visited[i])
      explore(i);
  }
  std::cout << std::endl;
}

//Complejidad temporal: O(n)
void Graph::BFS(int v) {
  // Mark all the vertices as not visited
  for (int i = 0; i < numNodes+1; i++)
    visited[i] = false;
  // Create a queue for BFS
  Queue<int> queue;
  // Mark the current node as visited and enqueue it
  visited[v] = true;
  std::cout << "Recorrido BFS " << std::endl;
  queue.enqueue(v);
  while(!queue.isEmpty()) {
    // Dequeue a vertex from queue and print it
    v = queue.dequeue();
    std::cout << v << " ";
    // Get all adjacent vertices of the dequeued
    // vertex s. If a adjacent has not been visited,
    // then mark it visited and enqueue it
    if (representation == 1) { // Lista de adyacencia
      // Recorrer nodos adyacente a v
      for (int j = 0; j < (int)adjList[v].size(); j ++) {
        int u = adjList[v][j];
        if (!visited[u]) {
          visited[u] = true;
          queue.enqueue(u);
        }
      }
    }
    else { // Matriz de adyacencia
      // Recorrer nodos adyacentes a v
      for (int j = 1; j < numNodes+1; j++) {
        if (adjMatrix[v][j] != 0) {
          if (!visited[j]) {
            visited[j] = true;
            queue.enqueue(j);
          }
        }
      }
    }
  }
  std::cout << std::endl;
}