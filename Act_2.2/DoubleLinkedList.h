#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

#include <climits>
#include "Node.h"
#include "Stack.h"

template <class T>
class DoubleLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int numElements;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    int getNumElements();
    void printList();
    void addFirst(T value);
    void addLast(T value);
    bool deleteData(T value);
    bool deleteAt(int position);
    Node<T> *getHead();
    T getData(int position);
    void updateData(T value, T nuevo);
    void updateAt(int position, T value);
    void clear();
    int findData(T value);
    T operator[](int position);
    void operator=(DoubleLinkedList<T> &other);
    void sort();
    void duplicate();
    void removeDuplicates();
    void getReversedSublist(int min, int max, DoubleLinkedList<T> &other);
};

// Complejidad temporal: O(1)
template <class T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    std::cout << "--->Creando una lista vacia " << this << std::endl;
    head = NULL;
    tail = NULL;
    numElements = 0;
}

// Complejidad temporal: O(n)
template <class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    std::cout << "--->Liberando memoria de la lista " << this << std::endl;
    Node<T> *p, *q;
    p = head;
    while (p != NULL)
    {
        q = p->next;
        delete p;
        p = q;
    }
    head = NULL;
    tail = NULL;
    numElements = 0;
}

// Complejidad temporal: O(1)
template <class T>
int DoubleLinkedList<T>::getNumElements()
{
    return numElements;
}

// Complejidad temporal: O(n)
template <class T>
void DoubleLinkedList<T>::printList()
{
    Node<T> *ptr = head;
    while (ptr != NULL)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

// Complejidad temporal: O(1)
template <class T>
Node<T> *DoubleLinkedList<T>::getHead()
{
    return head;
}

// Complejidad temporal: O(1)
template <class T>
void DoubleLinkedList<T>::addFirst(T value)
{
    Node<T> *newNode = new Node<T>(value);
    // Si la lista esta vacia
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    numElements++;
}

// Complejidad temporal:
//  + Mejor caso: O(1)
//  - Peor caso: O(n)
template <class T>
void DoubleLinkedList<T>::addLast(T value)
{
    // La lista esta vacia
    if (head == NULL)
    {
        addFirst(value);
    }
    else
    {
        Node<T> *newNode = new Node<T>(value);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        numElements++;
    }
}

// Complejidad temporal:
//  + Mejor caso: O(1)
//  - Peor caso: O(n)
template <class T>
bool DoubleLinkedList<T>::deleteData(T value)
{
    Node<T> *p, *q;
    p = head;
    q = NULL;
    // Si la lista esta vacia
    if (p == NULL)
    {
        return false;
    }
    else
    {
        // buscar value en la lista
        while (p != NULL && p->data != value)
        {
            q = p;
            p = p->next;
        }
        // Si no existe value en la lista
        if (p == NULL)
            return false;
        // Si debe borrarse el primer elemento
        if (p->prev == NULL)
        {
            head = p->next;
            if (head != NULL)
                head->prev = NULL;
        }
        else if (p->next == NULL)
        {
            // Si debe borrarse el último elemento
            q->next = NULL;
            tail = q;
        }
        else
        {
            // Cualquier otro elemento entre la lista
            q->next = p->next;
            p->next->prev = q;
        }
        delete p;
        numElements--;
        return true;
    }
}

// Complejidad temporal:
//  + Mejor caso: O(1)
//  - Peor caso: O(n)
template <class T>
bool DoubleLinkedList<T>::deleteAt(int position)
{
    if (position < 0 || position >= numElements)
    {
        std::cout << "Indice fuera de rango" << std::endl;
        return false;
    }
    else if (position == 0)
    { // Si debe borrarse el primer elemento
        Node<T> *p = head;
        // Si la lista contiene solo un nodo
        if (head != NULL && head->next == NULL)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = p->next;
            head->prev = NULL;
        }
        delete p;
        numElements--;
        return true;
    }
    else
    {
        Node<T> *p = head, *q = NULL;
        int index = 0;
        while (index != position)
        {
            q = p;
            p = p->next;
            index++;
        }
        // Si debe borrarse el último elemento
        if (p->next == NULL)
        {
            q->next = NULL;
            tail = q;
        }
        else
        { // Cualquier otro elemento entre la lista
            q->next = p->next;
            p->next->prev = q;
        }
        delete p;
        numElements--;
        return true;
    }
}

// Complejidad temporal:
//  + Mejor caso: O(1)
//  - Peor caso: O(n)
template <class T>
T DoubleLinkedList<T>::getData(int position)
{
    if (position < 0 || position >= numElements)
    {
        std::cout << "Indice fuera de rango: " << position << std::endl;
        return -1;
    }
    else
    {
        if (position == 0)
            return head->data;
        Node<T> *p = head;
        int index = 0;
        while (p != NULL)
        {
            if (index == position)
                return p->data;
            index++;
            p = p->next;
        }
        return -1;
    }
}

// Complejidad temporal:
//  + Mejor caso: O(1)
//  - Peor caso: O(n)
template <class T>
void DoubleLinkedList<T>::updateData(T value, T nuevo)
{
    Node<T> *p;
    p = head;
    // Head existe y contiene el valor a actualizar
    if (p != NULL && p->data == value)
    {
        p->data = nuevo;
    }
    else
    {
        // Buscar value en la lista
        while (p != NULL && p->data != value)
        {
            p = p->next;
        }
        // Determinar si existe o no
        if (p == NULL)
        {
            std::cout << "Indice fuera de rango" << std::endl;
        }
        else
        {
            p->data = nuevo;
        }
    }
}

// Complejidad temporal:
//  + Mejor caso: O(1)
//  - Peor caso: O(n)
template <class T>
void DoubleLinkedList<T>::updateAt(int position, T value)
{
    if (position < 0 || position >= numElements)
    {
        std::cout << "Indice fuera de rango" << std::endl;
    }
    else
    {
        Node<T> *p = head;
        // Si la posicion es 0
        if (position == 0)
        {
            p->data = value;
        }
        p = head;
        int index = 0;
        // buscar posicion en la lista
        while (index != position)
        {
            p = p->next;
            index++;
        }
        p->data = value;
    }
}

// Complejidad temporal: O(n)
template <class T>
void DoubleLinkedList<T>::clear()
{
    std::cout << "--->Clearing Memory" << std::endl;
    Node<T> *p, *q;
    p = head;
    while (p != NULL)
    {
        q = p->next;
        delete p;
        p = q;
    }
    head = NULL;
    numElements = 0;
}

// Complejidad temporal:
//  + Mejor caso: O(1)
//  - Peor caso: O(n)
template <class T>
int DoubleLinkedList<T>::findData(T value)
{
    Node<T> *p;
    p = head;
    int index = 0;
    // value esta en la posicion 0
    if (p != NULL && p->data == value)
    {
        return 0;
    }
    else
    {
        // buscar value en la lista
        while (p != NULL && p->data != value)
        {
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

// Complejidad temporal:
//  + Mejor caso: O(1)
//  - Peor caso: O(n)
template <class T>
T DoubleLinkedList<T>::operator[](int position)
{
    T value = -1;
    try
    {
        if (position < 0 || position >= numElements)
        {
            throw position;
        }
        if (position == 0)
        {
            return head->data;
        }
        Node<T> *p = head;
        int index = 0;
        while (p != NULL)
        {
            if (index == position)
            {
                return p->data;
            }
            index++;
            p = p->next;
        }
    }
    catch (int i)
    {
        std::cout << "El método regresa -1 porque " << i << " se encuentra fuera del rango" << std::endl;
        return value;
    }
    return value;
}

// Complejidad temporal: O(n)
template <class T>
void DoubleLinkedList<T>::operator=(DoubleLinkedList<T> &other)
{
    this->clear();
    Node<T> *ptr = other.getHead();
    while (ptr != NULL)
    {
        this->addLast(ptr->data);
        ptr = ptr->next;
    }
}

// Complejidad temporal: O(n^2)
template <class T>
void DoubleLinkedList<T>::sort()
{
    int n = this->getNumElements();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (this->getData(j) < this->getData(min_idx))
            {
                min_idx = j;
            }
        }
        T temp = this->getData(min_idx);
        this->updateAt(min_idx, this->getData(i));
        this->updateAt(i, temp);
    }
}

// Complejidad temporal: O(n)
template <class T>
void DoubleLinkedList<T>::duplicate()
{
    Node<T> *ptr = this->getHead();
    int n = this->getNumElements();
    for (int i = 0; i < n; i++)
    {
        this->addLast(ptr->data);
        ptr = ptr->next;
    }
    this->sort();
}

// Complejidad temporal:
//  + Mejor caso: O(1)
//  - Peor caso: O(n)
template <class T>
void DoubleLinkedList<T>::removeDuplicates()
{
    this->sort();
    Node<T> *ptr = this->getHead();
    int i = 0;
    while (ptr != NULL)
    {
        if (this->getData(i) == this->getData(i + 1))
        {
            this->deleteAt(i + 1);
        }
        if (ptr->next == NULL)
        {
            break;
        }
        if (this->getData(i) != this->getData(i + 1))
        {
            ptr = ptr->next;
            i++;
        }
    }
}

// Complejidad temporal: O(2n)
template <class T>
void DoubleLinkedList<T>::getReversedSublist(int min, int max, DoubleLinkedList<T> &other)
{
    Stack<T> revSublist;
    for (int i = min; i <= max; i++)
    {
        revSublist.push(this->getData(i));
    }
    while (!revSublist.isEmpty())
    {
        T v = revSublist.pop();
        other.addLast(v);
    }
}

#endif // _DOUBLELINKEDLIST_H_