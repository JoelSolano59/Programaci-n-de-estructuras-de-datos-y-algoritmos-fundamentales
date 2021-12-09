#include <iostream>
#include "BinarySearchTree.h"

/*
Programación de estructuras de datos y algoritmos fundamentales Gpo. 12
Joel Isaias Solano Ocampo  A01639289
Mauricio Cantu Torres      A01633805
*/

int main() {
  std::cout << "Caso de prueba 1:" << std::endl;
  BinarySearchTree<int> myBST1;
  myBST1.insert(10);
  myBST1.insert(20);
  myBST1.insert(30);
  myBST1.insert(15);
  myBST1.insert(5);
  myBST1.insert(115);
  myBST1.insert(3);

  //Visaulizacion Arbol Binario:
  //      10
  //    5    20
  //  3    15  30
  //             115

  std::cout << "\nRecorrido inorder" << std::endl;
  myBST1.callInorder();
  std::cout << "Recorrido postorder" << std::endl;
  myBST1.callPostorder();
  std::cout << "Recorrido preorder" << std::endl;
  myBST1.callPreorder();
  std::cout << "Recorrido Level by level" << std::endl;
  myBST1.callLevelByLevel();

  std::cout << "\nObtener altura del arbol con height" << std::endl;
  myBST1.height();

  std::cout << "\nImprimir los ancestros de un dato con ancestors" << std::endl;
  myBST1.ancestors(115);

  std::cout << "\nObtener el nivel de un dato con whatLevelAmI" << std::endl;
  myBST1.whatLevelAmI(115);

  std::cout << "\nCaso de prueba 2:" << std::endl;
  BinarySearchTree<int> myBST2;
  myBST2.insert(6);
  myBST2.insert(8);
  myBST2.insert(21);
  myBST2.insert(2);

  //Visaulizacion Arbol Binario:
  //    6
  //  2   8
  //       21

  std::cout << "\nRecorrido inorder" << std::endl;
  myBST2.callInorder();
  std::cout << "Recorrido postorder" << std::endl;
  myBST2.callPostorder();
  std::cout << "Recorrido preorder" << std::endl;
  myBST2.callPreorder();
  std::cout << "Recorrido Level by level" << std::endl;
  myBST2.callLevelByLevel();

  std::cout << "\nObtener altura del arbol con height" << std::endl;
  myBST2.height();

  std::cout << "\nImprimir los ancestros de un dato con ancestors" << std::endl;
  myBST2.ancestors(2);

  std::cout << "\nObtener el nivel de un dato con whatLevelAmI" << std::endl;
  myBST2.whatLevelAmI(8);

  std::cout << "Caso de prueba 3:" << std::endl;
  BinarySearchTree<int> myBST3;
  myBST3.insert(2);
  myBST3.insert(5);
  myBST3.insert(9);
  myBST3.insert(1);
  myBST3.insert(23);
  myBST3.insert(13);
  myBST3.insert(16);
  myBST3.insert(20);
  myBST3.insert(11);
  myBST3.insert(6);

  //Visaulizacion Arbol Binario:
  //    2
  //  1   5
  //          9
  //      6      23
  //           13
  //         11  16
  //               20

  std::cout << "\nRecorrido inorder" << std::endl;
  myBST3.callInorder();
  std::cout << "Recorrido postorder" << std::endl;
  myBST3.callPostorder();
  std::cout << "Recorrido preorder" << std::endl;
  myBST3.callPreorder();
  std::cout << "Recorrido Level by level" << std::endl;
  myBST3.callLevelByLevel();

  std::cout << "\nObtener altura del arbol con height" << std::endl;
  myBST3.height();

  std::cout << "\nImprimir los ancestros de un dato con ancestors" << std::endl;
  myBST3.ancestors(20);

  std::cout << "\nObtener el nivel de un dato con whatLevelAmI" << std::endl;
  myBST3.whatLevelAmI(13);

  std::cout << "Caso de prueba 4:" << std::endl;
  BinarySearchTree<int> myBST4;
  myBST4.insert(9);
  myBST4.insert(38);
  myBST4.insert(1);
  myBST4.insert(23);
  myBST4.insert(13);
  myBST4.insert(16);

  //Visaulizacion Arbol Binario:
  //        9
  //  1          38
  //          23
  //       13
  //          16

  std::cout << "\nRecorrido inorder" << std::endl;
  myBST4.callInorder();
  std::cout << "Recorrido postorder" << std::endl;
  myBST4.callPostorder();
  std::cout << "Recorrido preorder" << std::endl;
  myBST4.callPreorder();
  std::cout << "Recorrido Level by level" << std::endl;
  myBST4.callLevelByLevel();

  std::cout << "\nObtener altura del arbol con height" << std::endl;
  myBST4.height();

  std::cout << "\nImprimir los ancestros de un dato con ancestors" << std::endl;
  myBST4.ancestors(20);

  std::cout << "\nObtener el nivel de un dato con whatLevelAmI" << std::endl;
  myBST4.whatLevelAmI(13);
}