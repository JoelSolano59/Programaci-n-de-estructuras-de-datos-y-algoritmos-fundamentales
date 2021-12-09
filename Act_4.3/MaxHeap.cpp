#include "MaxHeap.h"

template <class T>
MaxHeap<T>::MaxHeap(int cap)
{
  std::cout << "--->Creando un MaxHeap: " << this << std::endl;
  size = 0;
  maxSize = cap;
  data.resize(maxSize);
}

template <class T>
MaxHeap<T>::~MaxHeap()
{
  std::cout << "--->Liberando memoria del MaxHeap: " << this << std::endl;
  data.clear();
}

template <class T>
bool MaxHeap<T>::isEmpty()
{
  return (size <= 0);
}

template <class T>
int MaxHeap<T>::getSize()
{
  return size;
}

template <class T>
int MaxHeap<T>::getCapacity()
{
  return maxSize;
}

template <class T>
void MaxHeap<T>::printMaxHeap()
{
  for (int i = 0; i < size; i++)
    std::cout << data[i].getAll() << std::endl;
}

template <class T>
int MaxHeap<T>::parent(int i)
{
  return (i-1)/2;
}

template <class T>
int MaxHeap<T>::left(int i)
{
  return (2*i+1);
}

template <class T>
int MaxHeap<T>::right(int i)
{
  return (2*i+2);
}

template <class T>
void MaxHeap<T>::push(T key)
{
  if (size == maxSize)
  {
    std::cout << "Overflow: no se puede insertar la llave: " << std::endl;
    return;
  }
  int i = size;
  data[i] = key;
  size++;
  while (i != 0 && data[parent(i)].getIp() < data[i].getIp())
  {
    std::swap(data[i], data[parent(i)]);
    i = parent(i);
  }
}

template <class T> 
T MaxHeap<T>::top()
{
  T result;
  if (isEmpty())
  {
    std::cout << "El MaxHeap está vacio" << std::endl;
    return result;
  }
  return data[0];
}

template <class T>
void MaxHeap<T>::writeToNewTxt(std::string txtArchivo, int inicio, int fin)
{
  std::ofstream out(txtArchivo);
  for (int i = inicio; i <= fin; i++)
  {
    std::string line;
    if (i == data.size() - 1)
    {
      line = data[i].getIpNoPort() + "  " + std::to_string(data[i].getIpGrade());
      out << line;
    }
    else
    {
      line = data[i].getIpNoPort() + "  " + std::to_string(data[i].getIpGrade()) + "\n";
      out << line;
    }
  }
  out.close();
}

template <class T>
void MaxHeap<T>::writeFive(std::string txtArchivo)
{
  std::ofstream out(txtArchivo);
  std::cout << "\nIPs with more connections:\n\n";
  for (int i = 0; i < 6; i++)
  {
    pop();
    if (i > 0)
    {
      out << top().getIpNoPort() + " // " + std::to_string(top().getIpGrade()) + "\n";
      std::cout << top().getIpNoPort() + " // " + std::to_string(top().getIpGrade()) << std::endl;
    }
  }
  std::cout << "\n";
  out.close();
}

template <class T>
void MaxHeap<T>::heapify(int n, int i)
{
  int max = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && data[l].getIpGrade() > data[max].getIpGrade())
  {
    max = l;
  }
  if (r < n && data[r].getIpGrade() > data[max].getIpGrade())
  {
    max = r;
  }
  if (max != i)
  {
    std::swap(data[i], data[max]);
    heapify(n, max);
  }
}

template <class T>
void MaxHeap<T>::heapSort()
{
  int n = size;
  for (int i = (n / 2) - 1; i >= 0; i--)
  {
    heapify(n, i);
  }
  for (int i = n - 1; i > 0; i--)
  {
    std::swap(data[0], data[i]);
    heapify(i, 0);
  }
}

template <class T>
void MaxHeap<T>::moveDown(int i)
{
  int maxInd = i;
  if (left(i) <= size && data[left(i)].getIp() > data[maxInd].getIp())
  {
    maxInd = left(i);
  }
  if (right(i) <= size && data[right(i)].getIp() > data[maxInd].getIp())
  {
    maxInd = right(i);
  }
  if (i != maxInd)
  {
    std::swap(data[i], data[maxInd]);
    moveDown(maxInd);
  }
}

template <class T>
void MaxHeap<T>::pop()
{
  if (size < 1)
  {
    std::cout << "No hay ningún dato en el heap" << std::endl;
    return;
  }
  data[0] = data.back();
  data.pop_back();
  heapify(size, 0);
  size--;
  return;
}