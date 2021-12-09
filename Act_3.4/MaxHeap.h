#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include "Registro.h"
#include "dateTime.h"
#include "IPAddress.h"
#include "IPFrequent.h"

  template<class T>
  class MaxHeap {
    private:
      // contiene los elementos del heap
      std::vector<T> data; 
      // capacidad maxima del heap
      int maxSize;
      // tamaño actual del heap   
      int size;   

      int parent(int i);
      int left(int i);
      int right(int i);

    public:
      MaxHeap(int capacity);
      ~MaxHeap();
      bool isEmpty();
      int getSize();
      int getCapacity();
      void printMaxHeap();
      void push(T key);
      T top();
      void cargarBitacoraHeap(std::string filename);
      void BitacoraHeapOrdenada();
      void BitacoraHeapIPAcceso();
      void nuevoRegistro();
      void IPMayorAcceso(std::string filename);
      void heapify_down(int i);
      void heapify_size(int n, int i);
      int heap_pop();
      void pop();
      void heapSort();
  };

  //Complejidad temporal: O(1)
  template <class T> 
  MaxHeap<T>::MaxHeap(int capacity) {
      std::cout << "--->Creando un MaxHeap: " <<  this << std::endl;
      size = 0;
      maxSize = capacity;
      data.resize(maxSize);
  }

  //Complejidad temporal: O(1)
  template <class T> 
  MaxHeap<T>::~MaxHeap() {
      std::cout << "--->Liberando memoria del MaxHeap: " <<  this << std::endl;
      data.clear();
  }
  
  //Complejidad temporal: O(1)
  template <class T> 
  bool MaxHeap<T>::isEmpty() {
    return (size <= 0);
  }

  //Complejidad temporal: O(1)
  template <class T> 
  int MaxHeap<T>::getSize() {
    return size;
  }

  //Complejidad temporal: O(1)
  template <class T> 
  int MaxHeap<T>::getCapacity() {
    return maxSize;
  }

  //Complejidad temporal: O(n)
  template <class T> 
  void MaxHeap<T>::printMaxHeap() {
    for (int i=0; i < size; i++)
      std::cout << data[i].getAll() << std::endl;
    std::cout << std::endl;
  }

  //Complejidad temporal: O(1)
  template <class T> 
  int MaxHeap<T>::parent(int i) {
    return (i-1)/2; 
  }

  //Complejidad temporal: O(1)
  template <class T> 
  int MaxHeap<T>::left(int i) {
    return (2*i + 1); 
  }

  //Complejidad temporal: O(1)
  template <class T> 
  int MaxHeap<T>::right(int i) {
    return (2*i + 2);
  }

  //Complejidad temporal: O(n)
  template <class T> 
  void MaxHeap<T>::push(T key) {
    // Insertamos la nueva llave al final del vector
    int i = size;
    data[i] = key;
    size++;
    // Reparar las propiedades del max heap si son violadas
    while (i != 0 && data[parent(i)].getIP() < data[i].getIP()) {
      std::swap(data[i], data[parent(i)]);
      i = parent(i);
    }
  }

  //Complejidad temporal: O(1)
  template <class T> 
  T MaxHeap<T>::top() {
    T result;
    if (isEmpty()) {
        std::cout << "El MaxHeap está vacio" << std::endl;
        return result;
    }
    return data[0];
  }

  // Complejidad temporal: O(n)
  template <class T>
  void MaxHeap<T>::cargarBitacoraHeap(std::string filename)
  {
    std::string month, day, hour, min, sec, ipa, desc;
    std::ifstream in(filename);
    while (std::getline(in, month, ' '))
    {
      std::getline(in, day, ' ');
      std::getline(in, hour, ':');
      std::getline(in, min, ':');
      std::getline(in, sec, ' ');
      std::getline(in, ipa, ' ');
      std::getline(in, desc);

      dateTime dt(month, stoi(day), stoi(hour), stoi(min), stoi(sec));
      IPAddress ia(ipa);
      Registro reg(month, day, hour, min, sec, ipa, desc, dt, ia);
      push(reg);
    }
    in.close();
  }

  // Complejidad temporal: O(n)
  template <class T>
  void MaxHeap<T>::BitacoraHeapOrdenada(){
    this->heapSort();
    std::ofstream outFile{"bitacora_ordenada.txt"};
    std::string line;
    for (int i=0; i < size; i++)
      outFile << data[i].getAll() << std::endl;
  }

  //Complejidad temporal: 
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template<class T>
  void MaxHeap<T>::BitacoraHeapIPAcceso(){
    std::ofstream out("ips_con_mayor_acceso.txt");
    for (int i = 0; i < size; i++){
      std::string line;
      if (i == data.size() - 1){
          line = data[i].getAll();
          out << line;
      }else {
          line = data[i].getAll() + "\n";
          out << line;
      }    
    }
    out.close();
  }

  //Complejidad temporal: 
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template <class T>
  void MaxHeap<T>::nuevoRegistro(){
    std::string month, day, hour, min, sec, ipa, desc;
    std::ifstream in("bitacora_ordenada.txt");
    int count = 0;
    std::string temp = "";
    while(std::getline(in, month, ' ')){
      std::getline(in, day, ' ');
      std::getline(in,hour,':');
      std::getline(in,min,':');
      std::getline(in,sec,' ');
      std::getline(in,ipa,' ');
      std::getline(in,desc);
      std::string realIp = ipa.substr(0, 13);
      if (realIp == temp){
        count++;
      } else {
        if (count != 0){
          IPFrequent ia(realIp, count);
          push(ia);
        }
        count = 1;
      }
      temp = realIp;
    }
    in.close();
  }

  //Complejidad temporal: O(1)
  template<class T>
  void MaxHeap<T>::IPMayorAcceso(std::string filename){
    std::ofstream out(filename);
    std::cout << "\nIPs con mayor acceso:\n\n";
    out << top().getAll() + "\n";
    std::cout << top().getAll() << std::endl;
    for (int i = 0; i < 4; i++){
      pop();
      out << top().getAll() + "\n";
      std::cout << top().getAll() << std::endl;
    }
    std::cout << "\n";
    out.close();
  }

  //Complejidad temporal: 
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template <class T>
  void MaxHeap<T>::heapify_down(int i){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < size && data[l].getIP() > data[i].getIP()) {
        largest = l;
    }
    if (r < size && data[r].getIP() > data[largest].getIP()) {
        largest = r;
    }
    if (largest != i)
    {
      std::swap(data[i], data[largest]);
      heapify_down(largest);
    }
  }

  //Complejidad temporal: 
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template <class T>
  void MaxHeap<T>::heapify_size(int n, int i){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < n && data[l].getIP() > data[i].getIP()) {
        largest = l;
    }
    if (r < n && data[r].getIP() > data[largest].getIP()) {
        largest = r;
    }
    if (largest != i)
    {
      std::swap(data[i], data[largest]);
      heapify_size(n, largest);
    }
  }

  //Complejidad temporal: 
  //Mejor caso: O(1)
  //Peor caso: O(n)
  template <class T>
  int MaxHeap<T>::heap_pop(){
    if (size<=0) {
      std::cout << "El MaxHeap está vacio" << std::endl;
      return -1;
    }
    int curr = 0;
    int popped = data[0];
    data[0] = data[size-1];
    size--;
    while((2*curr+1) < size){
      int child;
      if((2*curr+2)==size){
        child = 2*curr+1;
      }
      else{
        if (data[2*curr+1] < data[2*curr+2]){
          child = 2*curr+1;
        } else {
          child = 2*curr+2;
        }
      }
      if (data[curr] > data[child]){
        int temp = data[curr];
        data[curr] = data[child];
        data[child] = temp;
        curr = child;
      }
      else{
        break;
      }
    }
    return popped;
  }

  //Complejidad temporal: O(1)
  template <class T>
  void MaxHeap<T>::pop(){
    if (size < 1) {
      std::cout << "No hay ningún dato en el heap" << std::endl;
      return;
    }
    data[0] = data.back();
    data.pop_back();
    heapify_down(0);
    return;
  }

  //Complejidad temporal: O(2n)
  template<class T>
  void MaxHeap<T>::heapSort(){
    int n = size;
    for (int i = n/2-1; i >= 0; i--){
      heapify_size(n, i);
    }
    for (int i = n-1; i > 0; i--){
      std::swap(data[0], data[i]);
      heapify_size(i, 0);
    }
  }

#endif // __MAXHEAP_H_