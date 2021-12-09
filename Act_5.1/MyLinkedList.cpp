#include <iostream>
#include <limits>
#include "MyLinkedList.h"
using namespace std;


// Complejidad O(1)
MyLinkedList::MyLinkedList(){
    this->head = this->tail = nullptr;
    this->size = 0;
}

// Complejidad O(n)
MyLinkedList::~MyLinkedList(){
    MyNodeLL *current;
    while(this->head != NULL){
        current = this->head;
        this->head = this->head->next;
        delete(current);
        this->size--;
    }
}

// Complejidad O(1)
int MyLinkedList::length(){
    return this->size;
}

// Complejidad O(1)
void MyLinkedList::insertFirst(string key, int data){
    this->head = new MyNodeLL(key, data, this->head);
    if (this->size == 0){
        this->tail = this->head;
    }
    this->size++;
}

// Complejidad O(n)
int MyLinkedList::getAt(string key){
    MyNodeLL* current = this->head;
    for (int i = 0; i < this->size; i++){
        if (current->key == key){
            return current->data;
        }
        current = current->next;
    }
    throw invalid_argument ("No se escontro la llave " + key + " en la tabla");
}

// Complejidad O(1)
bool MyLinkedList::isEmpty(){
    return this->size == 0;
}

// Complejidad O(1)
datos MyLinkedList::getFirst(){
    datos info(this->head->key, this->head->data);
    removeFirst();
    return info;    
}

// Complejidad O(n)
int MyLinkedList::iterador(string key){
    int cont = 0;
    MyNodeLL *current = this->head;
    for (int i = 0; i < this->size; i++){
        if (current->key == key){
            return cont;
        }else{
            current = current->next;
            cont++;
        }
    }
    return -1;
}

// Complejidad O(1)
void MyLinkedList::removeFirst(){
    if(this->size > 0 ){
        MyNodeLL *tmp = this->head;
        this->head = head->next;
        delete tmp;
        this->size--;
        if (this->size == 0){
            this->tail = nullptr;
        }
    }else{
        throw invalid_argument("No se puede borrar el primer elemnto de una lista vacia.");
    }
}

// Complejidad O(n)
void MyLinkedList::removeAt(int pos){
    if(pos >=1 && pos<this->size){
        MyNodeLL *current = this->head, *del;
        for(int i=0; i < pos-1; i++){
            current = current->next;
        }
        del = current->next;
        current->next = del->next;
        delete(del);
        this->size--;
    }
    else if(pos == 0){
        removeFirst();
    }
    else{
        throw("No se puede eliminar la posicion " + to_string(pos) + " en la lista de tamanio " + to_string(this->size));
    }
}

