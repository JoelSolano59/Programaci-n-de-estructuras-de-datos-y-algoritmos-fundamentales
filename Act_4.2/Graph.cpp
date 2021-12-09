#include "Graph.h"
#include "Queue.h"

Graph::Graph(int representa, std::istream& input) {
    loadDirectedGraph(input);
    visited.resize(numNodes+1);
}

Graph::~Graph() {
  adjList.clear();
  visited.clear();
}

//Complejidad temporal: O(n)
void Graph::loadDirectedGraph(std::istream& input) {
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
      int w = res[2];
      // Grafos dirigidos
      std::pair<int, int> p (v, w);
      adjList[u].push_back(p);
      i++;
    }
}

//Complejidad temporal: O(n)
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

//Complejidad temporal: O(n^2)
void Graph::printAdjList(){
	  std::cout << "Adjacency List" << std::endl;
		for (int i = 1; i <= numNodes; i++){
	        std::cout << "vertex " << i << ": ";
	        for (int j = 0; j < (int)adjList[i].size(); j ++){
							 std::cout << " (" << adjList[i][j].first << ", " << adjList[i][j].second << ") ";
					}
	        std::cout << std::endl;
    }
}

//Complejidad temporal: O(1)
void Graph::printGraph() {
  printAdjList();
}

//Complejidad temporal: O(n)
void Graph::explore(int v) {
  visited[v] = true;
  std::cout << v << " ";
  for (int j = 0; j < (int)adjList[v].size(); j++) {
    int u = adjList[v][j].first;
    if (!visited[u])
      explore(u);
  }
}

//Complejidad temporal: O(2n)
void Graph::DFS(int v) {
  int i;
  for (i = 0; i < numNodes+1; i++)
    visited[i] = false;
  std::cout << "Recorrido DFS " << std::endl;
  for (i = 1; i < numNodes+1; i++) {
    if (!visited[i])
      explore(i);
  }
  std::cout << std::endl;
}

//Complejidad temporal: O(n)
void Graph::exploreTopologicalSort(int v) {
  visited[v] = true;
  // Recorrer nodos adyacente a v
  for (int j = 0; j < (int)adjList[v].size(); j++) {
    int u = adjList[v][j].first;
    if (!visited[u])
      exploreTopologicalSort(u);
  }
  // Almacena el vertice v después de 
  // explorar todos sus nodos adyacentes
  tmpStack.push(v);
}

//Complejidad temporal: O(n^2)
bool Graph::BFS(int s, int d, int pr[], int di[]){
  std::list<int> queue;
  bool visited[numNodes+1];
  for (int i = 0; i < numNodes+1; i++) {
    visited[i] = false;
    di[i] = INT_MAX;
    pr[i] = -1;
  }
  visited[s] = true;
  di[s] = 0;
  queue.push_back(s);
  while (!queue.empty()){
    int u = queue.front();
    queue.pop_front();
    for (int j = 0; j < adjList[u].size(); j++) {
      int node = adjList[u][j].first;
      if (visited[node] == false) {
        visited[node] = true;
        di[node] = di[u] + adjList[u][j].second;
        pr[node] = u;
        queue.push_back(node);
        if (node == d){
          return true;
        }
      }
    }
  }
  return false;
}

//Complejidad temporal: O(2n)
void Graph::shortestPath(int s, int d){
  std::cout << "Shortest Path" << std::endl;
  int pr[numNodes+1], di[numNodes+1];
  if (BFS(s, d, pr, di) == false) {
    std::cout << "El origen y el dino no estan conectados";
    return;
  }
  std::vector<int> path;
  int crwl = d;
  path.push_back(crwl);
  while (pr[crwl] != -1){
    path.push_back(pr[crwl]);
    crwl = pr[crwl];
  }
  std::cout << "Longitud del camino mas corto: " << di[d];
  std::cout << "\nPath: ";
  for (int i = path.size() - 1; i >= 0; i--)
    std::cout << path[i] << " ";
  std::cout << std::endl;
}

//Complejidad temporal: O(3n)
void Graph::topologicalSort(int v) {
  int i;
  for (i = 0; i < numNodes+1; i++)
    visited[i] = false;
  tmpStack = std::stack<int>();
  std::cout << "Topological sort " << std::endl;
  for (i = 1; i < numNodes+1; i++) {
    if (!visited[i])
      exploreTopologicalSort(i);
  }
  while(!tmpStack.empty()) {
    std::cout << tmpStack.top() << " ";
    tmpStack.pop();
  }
  std::cout << std::endl;
}

//Complejidad temporal: Log2(n)
bool Graph::isBipartite(){
  int v = 1;
  std::vector<int> color(numNodes + 1);
  visited[1] = true;
  color[1] = 0;

  for (int j = 0; j < (int)adjList[v].size(); j++){
    if (visited[j] == false){
      visited[j] = true;
      color[j] = !color[v];
      if (!isBipartite()){
        return false;
      }
    }
    else if (color[j] == color[v]){
      std::cout << "El grafo no es bipartita" << std::endl;
      return false;
    }
  }
  std::cout << "Subconjunto 1:" << std::endl;
  for(int i = 1; i <= color.size(); i++){
    if(color[i] == 0){
      std::cout << i << " ";
    }
  }
  std::cout << std::endl << "Subconjunto 2:" << std::endl;
  for(int i = 1; i <= color.size(); i++){
    if(color[i] == 1)
      std::cout << i << " ";
  }
  std::cout << std::endl;
  return true;
}