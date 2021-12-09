#ifndef __HASH_TABLE_H_
#define __HASH_TABLE_H_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <map>
#include "HashNode.h"
#include "IPAddress.h"

template<class K, class T>
class HashTable {
  private:
    std::vector<HashNode<K,T>> table;
    int size;
    int colision;
    int maxSize; // preferible un numero primo

  public:
    HashTable(int selectedMaxSize);
    int getHashIndex(K keyVal);
    std::vector<HashNode<K,T>> getTable();
    int getSize();
    int getColision();
    void print();
    void add(K keyVal, T value);
    int find(K keyVal);
    T getDataAt(int index);
    void remove(K keyVal);
    void functionHash(std::vector<std::pair<IPAddress, std::vector<IPAddress>>>& list);
    void getIpSummary(); 
};

template<class K, class T>
HashTable<K, T>::HashTable(int selectedMaxSize) {
  maxSize = selectedMaxSize;
  size = 0;
  table = std::vector<HashNode<K,T>>(maxSize);
}

template<class K, class T>
int HashTable<K, T>::getHashIndex(K keyVal) {
  return keyVal % maxSize;
}

template<class K, class T>
std::vector<HashNode<K,T>> HashTable<K, T>::getTable() {
  return table;
}

template<class K, class T>
int HashTable<K, T>::getSize() {
  return size;
}

template<class K, class T>
int HashTable<K, T>::getColision() {
  return colision;
}

template<class K, class T>
void HashTable<K,T>::print() {
  std::cout << "Content of the hash table: " << std::endl;
  for (int i = 0; i < maxSize; i++) {
    if (table.at(i).getStatus()==1) // Cell is used
      std::cout << "Cell: " << i << " Key: " << table.at(i).getKey() << ", Value: " << table.at(i).getData() << ", Overflow.size: " << table.at(i).getOverflowSize() << std::endl;
  }
}

template<class K, class T>
void HashTable<K,T>::add(K keyVal, T value) {
  if (size == maxSize) {
    throw std::out_of_range("Hash Table is full");
  }
  // Compute the index of the table using a key and a hash function
  int hashVal = getHashIndex(keyVal); 
  HashNode<K, T> node = table.at(hashVal);
  // The cell in the table is not taken
  if (node.getStatus() != 1) {
    node.setKey(keyVal);
    node.setData(value);
    table.at(hashVal) = node;
  }
  else { // The cell in the table is already taken
    // Find next free space using quadratic probing
    int i = 1;
    int currentHashVal = getHashIndex(hashVal + i * i);
    HashNode<K, T> currentNode = table.at(currentHashVal);
    while (currentNode.getStatus() == 1) {
      i++;
      currentHashVal = getHashIndex(hashVal + i * i);
      currentNode = table.at(currentHashVal);
      colision++;
    }
    currentNode.setKey(keyVal);
    currentNode.setData(value);
    node.addToOverflow(currentHashVal);
    table.at(currentHashVal) = currentNode;
    table.at(hashVal) = node;
    colision++;
  }
  size++;
}  

template<class K, class T>
int HashTable<K,T>::find(K keyVal) {
  int hashVal = getHashIndex(keyVal); 
  HashNode<K, T> node = table.at(hashVal);
  // Cell in the table is taken
  if (node.getStatus() == 1) {
    if (node.getKey() == keyVal) {
      return hashVal;
    }
    for (int i = 0; i < node.getOverflowSize(); i++) {
      int overflowIndex = node.getOverflowAt(i);
      if (table.at(overflowIndex).getKey() == keyVal) {
        return overflowIndex;
      }
    }
    return -1;
  }
  return -1;
}

template<class K, class T>
T HashTable<K,T>::getDataAt(int index) {
  return table.at(index).getData();
}

template<class K, class T>
void HashTable<K,T>::remove(K keyVal) {
  int pos, hashVal;
  pos = find(keyVal);
  if (pos == -1) {
    throw std::invalid_argument("Element does not exist in hash table");
  }
  hashVal = getHashIndex(keyVal);
  if (pos != hashVal) {
    HashNode<K, T> node = table.at(hashVal);
    node.removeFromOverflow(pos);
    table.at(hashVal) = node;
  }
  table.at(pos).clearData(); 
}

template<class K, class T>
void HashTable<K,T>::functionHash(std::vector<std::pair<IPAddress, std::vector<IPAddress>>>& list){
  for (int i = 0; i < list.size(); i++){
    list[i].first.setAdjListIp(list[i].second);
    add(list[i].first.getIpDecimal(), list[i].first);
  }
    std::cout << "function hash end" << std::endl;
}

template<class K, class T>
void HashTable<K,T>::getIpSummary(){
  int i = -1;
  std::string direccionIP;
  do {
    std::cout << "Ingresa una direccion IP: ";
    std::cin >> direccionIP;
    IPAddress tmpIP1(direccionIP, 0);
    i = find(tmpIP1.getIpDecimal());
    if (i == -1) {
      std::cout << "No se encontro la direccion IP proporsionada. Vuelva a intentarlo." << std::endl;
    }
  } while (i == -1);
  IPAddress tmpIP2 = getDataAt(i);
  tmpIP2.heapSort(tmpIP2.getAdjListIp().size()-1);
  std::vector<IPAddress> tmpAdjListIP = tmpIP2.getAdjListIp();
  tmpIP2.getResumen().printResumen();
  for (int i = 0; tmpAdjListIP.size(); i++) {
    //std::cout << tmpAdjListIP[i] << std::endl;
  }
}

#endif // __HASH_TABLE_H_