#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

  #include <climits>
  #include "Node.h"

  template <class T>
  class LinkedList {
      private:
        Node<T>* head;
        int numElements;

      public:
        LinkedList();
        ~LinkedList();
        int getNumElements();
        void addFirst(T value);
        void addLast(T value);
        bool deleteData(T value);
        bool deleteAt(int position); 
        Node<T>* getHead();
        T getData(int position);
        void printList();
        void updateData(T value, T nuevo);
        void updateAt(int posicion, T value);
        void clearMemory();
        int findData(T value);
        T operator [](int posicion);
        void operator=(LinkedList<T> &other);
  };

  //Complejidad temporal: O(1)
  template<class T>
  LinkedList<T>::LinkedList() {
      std::cout << "--->Creando una lista vacia" << std::endl;
      head = NULL;
      numElements = 0;
  }
  
  //Complejidad temporal: O(n)
  template<class T>
  LinkedList<T>::~LinkedList() {
    std::cout << "--->Liberando memoria de la lista" << std::endl;
    Node<T> *p, *q;
    p = head;
    while (p != NULL) {
      q = p->next;
      delete p;
      p = q;
    }
    head = NULL;
    numElements = 0;
  }
 
  //Complejidad temporal: O(1)
  template<class T>
  int LinkedList<T>::getNumElements() {
    return numElements;
  }
  
  //Complejidad temporal: O(n)
  template<class T>
  void LinkedList<T>::printList() {
    Node<T> *ptr = head;
    while (ptr != NULL) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
  }

  //Complejidad temporal: O(1)
  template<class T>
  Node<T>* LinkedList<T>::getHead(){
    return head;
  }
  
  //Complejidad temporal: O(1)
  template<class T>
  void LinkedList<T>::addFirst(T value) {
    Node<T> *newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
    numElements++;
  }
  
  //Complejidad temporal: 
  // + Mejor caso: O(1)
  // - Peor caso: O(n)
  template<class T>
  void LinkedList<T>::addLast(T value) {
    if (head == NULL) { 
      addFirst(value);
    }
    else {
      Node<T> *newNode = new Node<T>(value);
      Node<T> *p;
      p = head;
      while (p->next != NULL) {
        p = p->next;
      }
      newNode->next = NULL;
      p->next = newNode;
      numElements++;
    }    
  }

  //Complejidad temporal: 
  // + Mejor caso: O(1)
  // - Peor caso: O(n)
  template<class T>
  bool LinkedList<T>::deleteData(T value) {
    Node<T> *p, *prev;
    p = head;
    prev = NULL;
    // head existe y contiene el valor a borrar
    if (p != NULL && p->data == value) {
      head = p->next;
      delete p;
      numElements--;
      return true;
    }
    else {
      // buscar value en la lista
      while (p != NULL && p->data != value) {
        prev = p;
        p = p->next;
      }
      // Si no existe value
      if (p == NULL)
        return false;
      // Si existe value
      prev->next = p->next;
      delete p;
      numElements--;
      return true;
    }
  }
  
  //Complejidad temporal: 
  // + Mejor caso: O(1)
  // - Peor caso: O(n)
  template<class T>
  bool LinkedList<T>::deleteAt(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return false;
    }
    else {
      Node<T> *p = head, *prev;
      // Si se debe borrar head
      if (position == 0) {
        head = p->next;
        delete p;
        numElements--;
        return true;
      }
      // Si se debe borrar algun otro nodo
      // Encontrar el nodo previo
      p = head;
      prev = NULL;
      int index = 0;
      // buscar value en la lista
      while (index != position) {
        prev = p;
        p = p->next;
        index++;
      }
      prev->next = p->next;
      delete p;
      numElements--;
      return true;     
    }     
  }
  
  //Complejidad temporal: 
  // + Mejor caso: O(1)
  // - Peor caso: O(n)
  template<class T>
  T LinkedList<T>::getData(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return -1;
    }
    else {
      if (position == 0)
        return head->data;
      Node<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (index == position)
          return p->data;
        index++;
        p = p->next;
      }
      return -1;
    }
  }

  //Complejidad temporal: 
  // + Mejor caso: O(1)
  // - Peor caso: O(n)
  template<class T>
  void LinkedList<T>::updateData(T value, T nuevo){
    Node<T> *p;
    p = head;
    // Head existe y contiene el valor a actualizar
    if (p != NULL && p->data == value) {
      p->data = nuevo;
    }
    else {
      // Buscar value en la lista
      while (p != NULL && p->data != value) {
        p = p->next;
      }
      // Determinar si existe o no
      if (p == NULL){
        std::cout << "Indice fuera de rango" << std::endl;
      }else{
        p->data = nuevo;
      }
    }
  }

  //Complejidad temporal: 
  // + Mejor caso: O(1)
  // - Peor caso: O(n)
  template<class T>
  void LinkedList<T>::updateAt(int position, T value) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
    }
    else {
      Node<T> *p = head;
      // Si la posicion es 0
      if (position == 0) {
        p->data = value;
      }
      p = head;
      int index = 0;
      // buscar posicion en la lista
      while (index != position) {
        p = p->next;
        index++;
      }
      p->data = value;   
    }     
  }

  template<class T>
  void LinkedList<T>::clearMemory(){
    std::cout << "--->Clearing Memory" << std::endl;
    Node<T> *p, *q;
    p = head;
    while (p != NULL) {
      q = p->next;
      delete p;
      p = q;
    }
    head = NULL;
    numElements = 0;
  }

  //Complejidad temporal: 
  // + Mejor caso: O(1)
  // - Peor caso: O(n)
  template<class T>
  int LinkedList<T>::findData(T value) {
    Node<T> *p;
    p = head;
    int index = 0;
    // value esta en la posicion 0
    if (p != NULL && p->data == value) {
      return 0;
    }
    else {
      // buscar value en la lista
      while (p != NULL && p->data != value) {
        p = p->next;
        index++;
      }
      // Si no existe value
      if (p == NULL)
        return -1;
      // Si existe value
      return index;
    }
  }

  //Complejidad temporal: 
  // + Mejor caso: O(1)
  // - Peor caso: O(n)
  template<class T>
  T LinkedList<T>::operator[](int position){
    T value = -1;
    try{
      if (position < 0 || position >= numElements) {
        throw position;
      }
      if (position == 0){
        return head->data;  
      }
      Node<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (index == position){
          return p->data;
        }
        index++;
        p = p->next;
      }
    }
    catch(int i){
      std::cout << "El método regresa -1 porque " << i << " se encuentra fuera del rango" << std::endl;
      return value;
    }
    return value;
  }

  //Complejidad temporal: O(n)
  template<class T>
  void LinkedList<T>::operator=(LinkedList<T> &other){
    this->clearMemory();
    Node<T> *ptr = other.getHead();
    while (ptr != NULL) {
      this->addLast(ptr->data);
      ptr = ptr->next;
    }
  }

#endif // _LINKEDLIST_H_