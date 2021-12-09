#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

struct MyNodeLL{
    string key;
    int data;
    MyNodeLL* next;

    MyNodeLL(string key, int data, MyNodeLL* next){
        this->key = key;
        this->data = data;
        this->next = next;
    }

    MyNodeLL(string key, int data):MyNodeLL(key, data, nullptr){ }
};

struct datos{
    string key;
    int data;
    datos(string key, int data):key{key}, data{data}{ }
};

class MyLinkedList{
    private:
        MyNodeLL* head;
        MyNodeLL* tail;
        int size;
    public:
        MyLinkedList();                     
        ~MyLinkedList();                                          
        int length();                       
        void insertFirst(string key, int data); 
        int getAt(string key); 
        bool isEmpty(); 
        datos getFirst(); 
        int iterador(string key);                 
        void removeFirst();                             
        void removeAt(int pos);           
};

#endif //MYLINKEDLIST_H
