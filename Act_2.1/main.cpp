#include <iostream>
#include "LinkedList.h"


int main() {
  std::cout << "Ejemplo de listas ligadas\n";

  LinkedList<int> miLista;
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  std::cout << "Agregando 5 elementos al frente..." << std::endl;
  for (int i = 1; i < 6; i++) {
    miLista.addFirst(i);
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << "Agregando 5 elementos al final..." << std::endl;
  for (int i = 10; i < 15; i++) {
    miLista.addLast(i);
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  
  std::cout << "Delete 12: " << std::endl;
  miLista.deleteData(12);
  std::cout << "numElements ..: " << miLista.getNumElements() << std::endl;
  miLista.printList();
   

  std::cout << "DeleteAt 8: " << std::endl;
  miLista.deleteAt(8);
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList(); 

  std::cout << "getData(0): " << miLista.getData(0) << std::endl;
  std::cout << "getData(3): " << miLista.getData(3) << std::endl;
  
  //Mis test
  std::cout << "Mis test..." << std::endl;
  miLista.printList();
  miLista.updateData(5, 7);
  miLista.printList();
  std::cout << "" << std::endl;
  miLista.updateAt(7, 20);
  miLista.printList();
  std::cout << miLista.findData(20) << std::endl;
}