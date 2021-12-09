#ifndef _NODE_BST_H_
#define _NODE_BST_H_

  #include<iostream>

  template <class T>
  class NodeTree { 
  public: 
      T data; 
      NodeTree<T>* left;
      NodeTree<T>* right;
      NodeTree();
      NodeTree(T);
  }; 

  template<class T>
  NodeTree<T>::NodeTree(){
      left = NULL;
      right = NULL;
  }
  template<class T>
  NodeTree<T>::NodeTree(T val){
      data = val;
      left = NULL;
      right = NULL;
  }

#endif // _NODE_BST_H_