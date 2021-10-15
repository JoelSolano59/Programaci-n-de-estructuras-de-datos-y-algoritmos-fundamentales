#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

#include <climits>
#include <fstream>
#include "Node.h"
#include "Stack.h"
#include "dateTime.h"
#include "Registro.h"

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
  void cargarBitacora(std::string txtName);
  void swap(Node<T> *a, Node<T> *b);
  Node<T> *partition(Node<T> *l, Node<T> *h);
  void quickSortIterative();
  void bitacoraOrdenada();
  int busquedaBinaria(dateTime tiempo);
  void printListByDates();
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
    std::cout << ptr->data.getAll() << std::endl;
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
      return head->data.getAll();
    Node<T> *p = head;
    int index = 0;
    while (p != NULL)
    {
      if (index == position)
        return p->data.getAll();
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
  if (p != NULL && p->data.getAll() == value)
  {
    return 0;
  }
  else
  {
    // buscar value en la lista
    while (p != NULL && p->data.getAll() != value)
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

// Complejidad temporal: O(n)
template <class T>
void DoubleLinkedList<T>::cargarBitacora(std::string txtName)
{
  std::string month, day, hour, min, sec, ipa, desc;
  std::ifstream in(txtName);
  while (std::getline(in, month, ' '))
  {
    std::getline(in, day, ' ');
    std::getline(in, hour, ':');
    std::getline(in, min, ':');
    std::getline(in, sec, ' ');
    std::getline(in, ipa, ' ');
    std::getline(in, desc);
    dateTime dt(month, stoi(day), stoi(hour), stoi(min), stoi(sec));
    Registro tmpReg(month, day, hour, min, sec, ipa, desc, dt);
    addLast(tmpReg);
  }
}

// Complejidad temporal: O(1)
template <class T>
void DoubleLinkedList<T>::swap(Node<T> *a, Node<T> *b)
{
  T t = a->data;
  a->data = b->data;
  b->data = t;
}

// Complejidad temporal:
//  + Mejor caso: O(1)
//  - Peor caso: O(n)
template <class T>
Node<T> *DoubleLinkedList<T>::partition(Node<T> *l, Node<T> *h)
{
  Registro x = h->data;
  Node<T> *i = l->prev;

  for (Node<T> *j = l; j != h; j = j->next)
  {
    if (j->data.getDate() < x.getDate() || j->data.getDate() == x.getDate())
    {
      i = (i == NULL) ? l : i->next;

      swap(i, j);
    }
  }
  i = (i == NULL) ? l : i->next;
  swap(i, h);
  return i;
}

// Complejidad temporal:
//  + Mejor caso: O(1)
//  - Peor caso: O(n)
template <class T>
void DoubleLinkedList<T>::quickSortIterative()
{
  Node<T> *l = head;
  Node<T> *h = tail;
  Stack<Node<T> *> stk;

  stk.push(l);
  stk.push(h);

  while (!stk.isEmpty())
  {
    h = stk.pop();
    l = stk.pop();

    Node<T> *p = partition(l, h);

    if (p->data.getDate() > l->data.getDate())
    {
      stk.push(l);
      stk.push(p->prev);
    }

    if (p->data.getDate() < h->data.getDate())
    {
      stk.push(p->next);
      stk.push(h);
    }
  }
}

// Complejidad temporal: O(n)
template <class T>
void DoubleLinkedList<T>::bitacoraOrdenada()
{
  quickSortIterative();
  std::ofstream outFile{"bitacora_ordenada.txt"};
  std::string line;
  Node<T> *p = head;
  while (p != NULL)
  {
    outFile << p->data.getAll() << std::endl;
    p = p->next;
  }
}

// Complejidad temporal:
//  + Mejor caso: O(1)
//  - Peor caso: O(n)
template <class T>
int DoubleLinkedList<T>::busquedaBinaria(dateTime tiempo)
{
  Node<T> *temp = head;
  int pos = 0;

  while (temp->data.getDate() != tiempo && temp->next != NULL)
  {
    pos++;
    temp = temp->next;
  }
  if (temp->data.getDate() != tiempo)
  {
    return -1;
  }
  return (pos);
}

// Complejidad temporal:
//  + Mejor caso: O(1)
//  - Peor caso: O(n)
template <class T>
void DoubleLinkedList<T>::printListByDates()
{
  std::string m, d, h, mi, s;
  int fecha1 = -1, fecha2 = -1;

  do
  {
    std::cout << "Fecha inicial (Mes Dia Hora:Min:Seg): " << std::endl;
    getline(std::cin, m, ' ');
    getline(std::cin, d, ' ');
    getline(std::cin, h, ':');
    getline(std::cin, mi, ':');
    getline(std::cin, s);
    dateTime dt1(m, stoi(d), stoi(h), stoi(mi), stoi(s));
    Registro reg1(m, d, h, mi, s, "", "", dt1);
    fecha1 = busquedaBinaria(dt1);
    if (fecha1 == -1)
    {
      std::cout << "Error. La fecha inicial ingresada no se encuentra en la bitacora." << std::endl;
    }
    else
    {
      break;
    }
  } while (fecha1 == -1);

  do
  {
    std::cout << "Fecha final (Mes Dia Hora:Min:Seg): " << std::endl;
    getline(std::cin, m, ' ');
    getline(std::cin, d, ' ');
    getline(std::cin, h, ':');
    getline(std::cin, mi, ':');
    getline(std::cin, s);
    dateTime dt2(m, stoi(d), stoi(h), stoi(mi), stoi(s));
    Registro reg2(m, d, h, mi, s, "", "", dt2);
    fecha2 = busquedaBinaria(dt2);
    if (fecha2 == -1)
    {
      std::cout << "Error. La fecha final ingresada no se encuentra en la bitacora." << std::endl;
    }
    else if (fecha2 == fecha1)
    {
      std::cout << "Error. La fecha inicial y fecha final no pueden ser la misma." << std::endl;
    }
    else if (fecha1 >= fecha2)
    {
      std::cout << "Error. La fecha inicial debe ser menor o diferente a la fecha final." << std::endl;
    }
  } while (fecha2 == -1 || fecha2 == fecha1 || fecha1 >= fecha2);

  if (fecha1 != -1 && fecha2 != -1 && fecha2 != fecha1 && fecha1 < fecha2)
  {
    std::ofstream outFile{"resultado_busqueda.txt"};
    std::string line;
    Node<T> *p = head;
    int index = 0;

    std::cout << "\nResultado: " << fecha2 + 1 - fecha1 << " Registros" << std::endl;
    outFile << "Resultado: " << fecha2 + 1 - fecha1 << " Registros" << std::endl;
    do
    {
      if (index >= fecha1 && index <= fecha2)
      {
        std::cout << p->data.getAll() << std::endl;
        outFile << p->data.getAll() << std::endl;
      }
      index++;
      p = p->next;
    } while (index <= fecha2);
  }
}

#endif // _DOUBLELINKEDLIST_H_