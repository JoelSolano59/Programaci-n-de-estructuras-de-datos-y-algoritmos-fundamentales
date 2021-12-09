#include <iostream>
#include <functional>
#include <cmath>
#include "MyHashTable.h"
#include "MyLinkedList.h"
using namespace std;

//Complejidad O(1)
MyHashTable::MyHashTable(){
    this->size = 0;
    this->sizeA = 11;
    this->tabla = new MyLinkedList[this->sizeA];
}

//Complejidad O(n)
MyHashTable::~MyHashTable(){
    for (int i = 0; i < this->sizeA; i++){
        this->tabla[i].~MyLinkedList();
        this->size--;
    }
    delete[] tabla;
}

//Complejidad O(1)
bool MyHashTable::isEmpty(){
    return this->size == 0;
}

//Complejidad O(1)
int MyHashTable::getPos(string key){
    size_t hashC = hash<string>{}(key);
    int hashCode = static_cast<int>(hashC);
    return abs(hashCode) % this->sizeA;
}

//Complejidad O(n)
void MyHashTable::rehashing(){
    int newTam = (2*this->sizeA) + 1;
    int oldTam = this->sizeA;
    this->sizeA = newTam;
    MyLinkedList* newTabla = new MyLinkedList[newTam];
    for (int i = 0; i < oldTam; i++){
        if (this->tabla[i].length() > 0){
            while(this->tabla[i].length() > 0){
                datos aux = this->tabla[i].getFirst();
                int pos = getPos(aux.key);
                newTabla[pos].insertFirst(aux.key, aux.data);
            }
        }
    }
    delete[] this->tabla;
    this->tabla = newTabla;
}

//Complejidad O(1)
void MyHashTable::put(string key, int value){
    float factorCarga = float(this->size)/float(this->sizeA);
    if (factorCarga >= 0.75){
        rehashing();
        int pos = getPos(key);
        this->tabla[pos].insertFirst(key, value);
        this->size++;
    }else{
        int pos = getPos(key);
        this->tabla[pos].insertFirst(key, value);
        this->size++;
    }
}

//Complejidad O(1)
int MyHashTable::get(string key){
    int pos = getPos(key);
    MyLinkedList* lista = &this->tabla[pos];
    return lista->getAt(key);
}

//Complejidad O(n)
void MyHashTable::remove(string key){
    int pos = getPos(key);
    int posData;
    if (this->tabla[pos].length() > 0){
        posData = this->tabla[pos].iterador(key);
        if (posData == -1){
            cout << "No se esta el dato" << endl;
        }else{
            this->tabla[pos].removeAt(posData);
        }
    }
}

//Complejidad O(1)
void MyHashTable::callHashTable(){
    cout << "Cell: 0 Key: 15 Data: " << this->get("15") << endl;
    cout << "Cell: 1 Key: 23 Data: " << this->get("23") << endl;
    cout << "Cell: 2 Key: 34 Data: " << this->get("34") << endl;
    cout << "Cell: 3 Key: 41 Data: " << this->get("41") << endl;
    cout << "Cell: 4 Key: 56 Data: " << this->get("56") << endl;
    cout << "Cell: 5 Key: 67 Data: " << this->get("67") << endl;
    cout << "Cell: 6 Key: 74 Data: " << this->get("74") << endl;
    cout << "Cell: 7 Key: 89 Data: " << this->get("89") << endl;
    cout << "Cell: 8 Key: 98 Data: " << this->get("98") << endl;
    cout << "Cell: 9 Key: 122 Data: " << this->get("122") << endl;
    cout << "Cell: 10 Key: 244 Data: " << this->get("244") << endl;
    cout << "Cell: 11 Key: 333 Data: " << this->get("333") << endl;
    cout << "Cell: 12 Key: 455 Data: " << this->get("455") << endl;
}