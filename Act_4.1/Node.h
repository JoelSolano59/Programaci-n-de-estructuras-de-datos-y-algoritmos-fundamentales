#ifndef _NODE_H_
#define _NODE_H_

#include<iostream>

  template <class T>
  class Node { 
    public: 
      T data; 
      Node<T>* next;
      Node();
      Node(T);        
  }; 

  template<class T>
  Node<T>::Node(){
    data = 0;
    next = NULL;
  }

  template<class T>
  Node<T>::Node(T val){
    data = val;
    next = NULL;
  }

#endif // _NODE_H_
