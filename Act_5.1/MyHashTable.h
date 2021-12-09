#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <string>
#include "MyLinkedList.h"
using namespace std;

class MyHashTable{
    private:
        MyLinkedList* tabla;
        int size; //Cantidad de valores almacenados en la tabla
        int sizeA; //Tamanio del arreglo
        void rehashing(); 
    public:
        MyHashTable();
        ~MyHashTable(); 
        bool isEmpty();
        void put(string key, int value); 
        int get(string key); 
        void remove(string key); 
        int getPos(string key);
        void callHashTable();
};

#endif
