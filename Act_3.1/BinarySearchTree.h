#ifndef _BinarySearchTree_H_
#define _BinarySearchTree_H_

  #include<iostream>
  #include "NodeTree.h"

  template <class T>
  class BinarySearchTree { 
  private:
    NodeTree<T> *root;
     NodeTree<T>* insertRecursive(NodeTree<T> *p, T value);
     NodeTree<T>* getSuccessor(NodeTree<T> *p);
     NodeTree<T>* deleteRecursive(NodeTree<T> *p, T value);
     void inorder(NodeTree<T> *p);
     void postorder(NodeTree<T> *p);
     void preorder(NodeTree<T> *p);

  public: 
      BinarySearchTree();
      ~BinarySearchTree();
      NodeTree<T>* getNode(T value);
      void clearMemory(NodeTree<T> *p);
      void insert(T value);
      bool search(T value);
      void deleteNode(T value);
      void callInorder();
      void callPostorder();
      void callPreorder();
      NodeTree<T>* newNode(int data);
      int _height(NodeTree<T>* node);
      void height();
      void currentLevel(NodeTree<T>* root, int level);
      void levelByLevel(NodeTree<T>* root);
      bool _ancestors(NodeTree<T>* r, T target);
      void ancestors(T value);
      void callLevelByLevel();
      int getLevel(NodeTree<T>* node, int data, int level);
      int whatLevelAmI(int data);
  }; 

  //Complejidad temporal: O(1)
  template<class T>
  BinarySearchTree<T>::BinarySearchTree() {
    std::cout << "--->Creando un BinarySearchTree vacio: " <<  this << std::endl;
    root = NULL;
  }
  
  //Complejidad temporal: O(1)
  template<class T>
  BinarySearchTree<T>::~BinarySearchTree() {
    std::cout << "--->Liberando memoria del BinarySearchTree: " << this << std::endl;
    clearMemory(root);
  }

  //Complejidad temporal: 
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template<class T>
  NodeTree<T>* BinarySearchTree<T>::getNode(T value){
    NodeTree<T> *p = root;
    while (p != NULL) {
      if (p->data == value) {
        return p;
      }
      else {
        p = (value < p->data ? p->left : p->right);
      }
    }
    return NULL;
  }

  //Complejidad temporal: O(n)
  template<class T>
  void BinarySearchTree<T>::clearMemory(NodeTree<T> *p) {
    if (p != NULL) {
      clearMemory(p->left);
      clearMemory(p->right);
      delete p;
      p = NULL;
    }
  }
  
  //Complejidad temporal:
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template<class T>
  NodeTree<T>* BinarySearchTree<T>::insertRecursive(NodeTree<T> *p, T value) {
    if (p == NULL) // Arbol esta vacio
      p = new NodeTree<T>(value);
    else if (value < p->data)
      p->left = insertRecursive(p->left, value);
    else if (value > p->data)
      p->right = insertRecursive(p->right, value);
    else
      std::cout << "El elemento " << value << " ya existe en el BST" << std::endl;
    return p;
  }
  
  //Complejidad temporal: O(1)
  template<class T>
  void BinarySearchTree<T>::insert(T value) {
    root = insertRecursive(root, value);
  }

  //Complejidad temporal:
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template<class T>
  bool BinarySearchTree<T>::search(T value) {
    NodeTree<T> *p = root;
    while (p != NULL) {
      if (p->data == value) {
        return true;
      }
      else {
        p = (value < p->data ? p->left : p->right);
      }
    }
    return false;
  }

  //Complejidad temporal:
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template<class T>
  NodeTree<T> * BinarySearchTree<T>::getSuccessor(NodeTree<T> *p) {
    NodeTree<T> *current = p;
    while (current && current->left != NULL) {
      current = current->left;
    }
    return current;
  }

  //Complejidad temporal: O(1)
  template<class T>
  void BinarySearchTree<T>::deleteNode(T value) {
    root = deleteRecursive(root, value);
  }

  //Complejidad temporal:
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template<class T> 
  NodeTree<T>* BinarySearchTree<T>::deleteRecursive(NodeTree<T> *p, T value) {
    NodeTree<T> *current = p;
    // caso base 
    if (p == NULL)
      return p;
    if (value < p->data)
      p->left = deleteRecursive(p->left, value);
    else if (value > p->data)
      p->right = deleteRecursive(p->right, value);
    else { // Hemos localizado el nodo a borrar
      // El nodo a borrar no tiene ningun hijo
      if (p->left == NULL && p->right == NULL) {
        delete p;
        p = NULL;
        return p;
      }
      else if (p->left == NULL) { // El nodo a borrar solo tiene hijo derecho
        current = p->right;
        delete p;
        p = NULL;
        return current;
      } 
      else if (p->right == NULL) { // El nodo a borrar solo tiene hijo izquierdo
        current = p->left;
        delete p;
        p = NULL;
        return current;
      }
      // El nodo a borrar tiene dos hijos
      current = getSuccessor(p->right);
      p->data = current->data;
      p->right = deleteRecursive(p->right, current->data);
    }
    return p;
  }

  //Complejidad temporal:
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template<class T>
  void BinarySearchTree<T>::inorder(NodeTree<T> *p) {
    if (p != NULL) {
      inorder(p->left);
      std::cout << p->data << " ";
      inorder(p->right);
    }
  }

  //Complejidad temporal: O(1)
  template<class T>
  void BinarySearchTree<T>::callInorder() {
    inorder(root);
    std::cout << std::endl;
  }

  //Complejidad temporal:
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template<class T>
  void BinarySearchTree<T>::postorder(NodeTree<T> *p) {
    if (p != NULL) {
      postorder(p->left);
      postorder(p->right);
      std::cout << p->data << " ";
    }
  }

  //Complejidad temporal: O(1)
  template<class T>
  void BinarySearchTree<T>::callPostorder() {
    postorder(root);
    std::cout << std::endl;
  }

  //Complejidad temporal:
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template<class T>
  void BinarySearchTree<T>::preorder(NodeTree<T> *p) {
    if (p != NULL) {
      std::cout << p->data << " ";
      preorder(p->left);
      preorder(p->right);
    }
  }

  //Complejidad temporal: O(1)
  template<class T>
  void BinarySearchTree<T>::callPreorder() {
    preorder(root);
    std::cout << std::endl;
  }

  //Complejidad temporal: O(1)
  template<class T>
  NodeTree<T>* BinarySearchTree<T>::newNode(int data){
    NodeTree<T>* Node = new NodeTree<T>();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
  }

  //Complejidad temporal:
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template<class T>
  int BinarySearchTree<T>::_height(NodeTree<T>* node){
    if (node == NULL){
      return 0;
    }else{
      int leftHeight = _height(node->left);
      int rightHeight = _height(node->right);

      if (leftHeight > rightHeight){
        return (leftHeight+1);
      }else{
        return (rightHeight+1);
      }
    }
  }

  //Complejidad temporal: O(1)
  template<class T>
  void BinarySearchTree<T>::height() {
    std::cout << _height(root) << std::endl;
  }

  //Complejidad temporal:
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template<class T>
  void BinarySearchTree<T>::currentLevel(NodeTree<T>* root, int level){
    if (root == NULL){
      return;
    }
    if (level == 1){
      std::cout << root->data << " ";
    }else if (level > 1){
      currentLevel(root->left, level-1);
      currentLevel(root->right, level-1);
    }
  }
  
  //Complejidad temporal:
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template<class T>
  void BinarySearchTree<T>::levelByLevel(NodeTree<T>* root){
    int h = _height(root);
    for (int i = 1; i <= h; i++){
      currentLevel(root, i);
    }
  }

  //Complejidad temporal: O(1)
  template<class T>
  void BinarySearchTree<T>::callLevelByLevel() {
    levelByLevel(root);
    std::cout << std::endl;
  }

  //Complejidad temporal:
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template<class T>
  bool BinarySearchTree<T>::_ancestors(NodeTree<T>* p, T target){
    if (p == NULL){
      return false;
    }
    if (p->data == target){
      return true;
    }
    bool l = _ancestors(p->left, target);
    bool r = false;
    if (!l){
        r = _ancestors(p->right, target);
    }
    if (l || r){
      std::cout << p->data << " ";
    }
    return l || r;
  }

  //Complejidad temporal: O(1)
  template<class T>
  void BinarySearchTree<T>::ancestors(T value){
    _ancestors(root, value);
    std::cout << "\n";
  }

  //Complejidad temporal:
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template<class T>
  int BinarySearchTree<T>::getLevel(NodeTree<T>* node, int data, int level){
    if (node == NULL){
      return -1;
    }

    if (node->data == data){
      return level;
    }

    int abajo = getLevel(node->left, data, level+1);
    if (abajo != -1){
      return abajo;
    }

    abajo = getLevel(node->right, data, level+1);
    return abajo;
  }

  //Complejidad temporal: O(1)
  template<class T>
  int BinarySearchTree<T>::whatLevelAmI(int data){
    NodeTree<T>* tree = this->root;
    return getLevel(tree, data, 1);
  }

#endif //_BinarySearchTree_H_