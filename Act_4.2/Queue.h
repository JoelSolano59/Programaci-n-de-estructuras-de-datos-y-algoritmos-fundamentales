#ifndef _QUEUE_H  
#define _QUEUE_H

  #include <climits>
  #include "Node.h"

  template <class T>
  class Queue {   
      private:
        Node<T>* front;
        Node<T>* rear;
        int numElements;

      public:
        Queue();
        ~Queue();
        bool isEmpty();
        int getNumElements();
        void printQueue();
        void enqueue(T value);
        T dequeue();
        T top();

  };

  //Complejidad temporal: O(1)
  template<class T>
  Queue<T>::Queue() {
    front = rear = NULL;
    numElements = 0;
  }
  
  //Complejidad temporal: O(n)
  template<class T>
  Queue<T>::~Queue() {
    if (!isEmpty()) {
      Node<T> *p, *q;
      p = front;
      while (p != NULL) {
        q = p->next;
        delete p;
        p = q;
      }
      front = NULL;
      rear = NULL;
      numElements = 0;
    }
  }
  
  //Complejidad temporal: O(1)
  template<class T>
  bool Queue<T>::isEmpty(){
    if (front == NULL && rear == NULL) {
      return true;
    }
    return false;
  }
  
  //Complejidad temporal: O(1)
  template<class T>
  int Queue<T>::getNumElements() {
    return numElements;
  }

  //Complejidad temporal: O(n)
  template <class T>
  void Queue<T>::printQueue(){
    Node<T> *ptr = front;
    while (ptr != NULL) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
  }

  //Complejidad temporal: O(1)
  template <class T>
  void Queue<T>::enqueue(T value) {
    Node<T> *p = new Node<T>(value);
    numElements++;
    // Si la fila esta vacia
    if (isEmpty()) {
      front = p;
      rear = p;
    }
    else { // La lista ya contiene elementos
      rear->next = p;
      rear = p;
    }
  }


  //Complejidad temporal: O(1)
  template <class T>
  T Queue<T>::dequeue() {
    T value = -1;
    if (isEmpty()) {
      return value;
    }
    else {
      Node<T>* p = front;
      value = p->data;
      front = front->next;
      if (front == NULL)
        rear = NULL;
      delete p;
      numElements--;
      return value;
    }
  }    
 
#endif //_QUEUE_H