#ifndef _STACK__H__
#define _STACK__H__

#include <climits>
#include "Node.h"

template <class T>
class Stack
{
private:
  Node<T> *top;
  int numElements;

public:
  Stack();
  ~Stack();
  int getNumElements();
  void printStack();

  void push(T value);
  T pop();
  T getTop();
  bool isEmpty();
};

template <class T>
Stack<T>::Stack()
{
  std::cout << "--->Creando un Stack vacio: " << this << std::endl;
  top = NULL;
  numElements = 0;
}

template <class T>
Stack<T>::~Stack()
{
  std::cout << "--->Liberando memoria del stack: " << this << std::endl;
  Node<T> *p, *q;
  p = top;
  while (p != NULL)
  {
    q = p->next;
    delete p;
    p = q;
  }
  top = NULL;
  numElements = 0;
}

template <class T>
int Stack<T>::getNumElements()
{
  return numElements;
}
template <class T>
void Stack<T>::printStack()
{
  Node<T> *ptr = top;
  while (ptr != NULL)
  {
    std::cout << ptr->data << " ";
    ptr = ptr->next;
  }
  std::cout << std::endl;
}

template <class T>
void Stack<T>::push(T value)
{
  Node<T> *newNode = new Node<T>(value);
  newNode->next = top;
  top = newNode;
  numElements++;
}

template <class T>
T Stack<T>::pop()
{
  T value;
  if (top != NULL)
  {
    Node<T> *p = top;
    value = top->data;
    top = p->next;
    delete p;
    numElements--;
  }
  return value;
}

template <class T>
T Stack<T>::getTop()
{
  T value;
  if (top != NULL)
  {
    value = top->data;
  }
  return value;
}

template <class T>
bool Stack<T>::isEmpty()
{
  bool result = false;
  if (top == NULL)
    result = true;
  return result;
}

#endif // _STACK_H_