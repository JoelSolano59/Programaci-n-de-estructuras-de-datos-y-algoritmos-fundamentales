#include <iostream>
#include <bits/stdc++.h>
#include "DoubleLinkedList.h"

/*
Programación de estructuras de datos y algoritmos fundamentales Gpo. 12
Joel Isaias Solano Ocampo  A01639289
Mauricio Cantu Torres      A01633805
*/

int main()
{
    std::cout << "\nEjemplo de listas doblemente ligadas:\n\n";

    // Creamos un objeto llamado 'miLista' de tipo LinkedList<int>
    DoubleLinkedList<int> miLista;

    // Obtenemos el numero de elementos de 'miLista'
    std::cout << "\nnumElements: " << miLista.getNumElements() << std::endl;

    // Agregamos 5 valores al principio de 'miLista'
    std::cout << "Agregando 5 elementos al frente..." << std::endl;
    for (int i = 1; i < 6; i++)
    {
        miLista.addFirst(i);
    }

    // Volvemos a desplegar el numero de elementos de la lista
    std::cout << "numElements: " << miLista.getNumElements() << std::endl;

    // Imprimimos los elementos de la lista
    miLista.printList();

    // Agregamos 5 valores al final de 'miLista'
    std::cout << "\nAgregando 5 elementos al final..." << std::endl;
    for (int i = 10; i < 15; i++)
    {
        miLista.addLast(i);
    }

    std::cout << "numElements: " << miLista.getNumElements() << std::endl;
    miLista.printList();

    // Usamos deleteData para borrar un elemento de la lista usando un valor
    std::cout << "\ndeleteData(12): " << std::endl;
    miLista.deleteData(12);
    std::cout << "numElements : " << miLista.getNumElements() << std::endl;
    miLista.printList();

    // Usamos deleteAt para borrar un elemento de la lista usando un indice
    std::cout << "\ndeleteAt(8): " << std::endl;
    miLista.deleteAt(8);
    std::cout << "numElements: " << miLista.getNumElements() << std::endl;
    miLista.printList();

    // Usamos getData para acceder a elementos de la lista
    std::cout << "\ngetData(0): " << miLista.getData(0) << std::endl;
    std::cout << "getData(3): " << miLista.getData(3) << std::endl;

    // Usamos updateData para modificar elementos de la lista
    std::cout << "\nupdateData(10,8): " << std::endl;
    miLista.updateData(10, 8);
    miLista.printList();

    // Usamos updateAt para modificar elementos de la lista usando un indice
    std::cout << "\nupdateAt(1,15): " << std::endl;
    miLista.updateAt(1, 15);
    miLista.printList();

    // Usamos findData para encontrar un elemento en la lista
    std::cout << "\nfindData(15): " << miLista.findData(15) << std::endl;

    // Usamos la sobrecarga del operador [] para leer un elemento de la lista
    std::cout << "\nmiLista[3]: " << miLista[3] << std::endl;

    // Crear una segunda lista
    DoubleLinkedList<int> miLista2;

    for (int i = 14; i < 21; i++)
    {
        miLista2.addLast(i);
    }

    // Usamos la sobrecarga del operador = para asignar los valores de una lista a otra
    std::cout << "\nmiLista1 = miLista2: " << std::endl;
    miLista = miLista2;
    miLista.printList();

    // Usamos clear para borrar los elementos de la lista
    miLista.clear();

    // Creamos una nueva lista para utilizar otros métodos
    std::cout << "\nCreando una lista nueva..." << std::endl;
    DoubleLinkedList<int> miLista3;
    miLista3.addLast(3);
    miLista3.addLast(9);
    miLista3.addLast(1);
    miLista3.addLast(7);
    miLista3.addLast(8);
    miLista3.addLast(9);
    miLista3.addLast(9);
    miLista3.addLast(2);
    miLista3.printList();

    // Ordenamos la lista usando sort
    std::cout << "\nmiLista3.sort(): " << std::endl;
    miLista3.sort();
    miLista3.printList();

    // Duplicamos cada elemento de la lista usando duplicate
    std::cout << "\nmiLista3.duplicate(): " << std::endl;
    miLista3.duplicate();
    miLista3.printList();

    // Borramos los elementos repetidos en la lista con removeDuplicates
    std::cout << "\nmiLista3.removeDuplicates(): " << std::endl;
    miLista3.removeDuplicates();
    miLista3.printList();

    // Obtenemos un intervalo de la lista al reves con getReversedSublist
    std::cout << "\nmiLista3.getReversedSublist(1, 4, miLista4): " << std::endl;
    DoubleLinkedList<int> miLista4;
    miLista3.getReversedSublist(1, 4, miLista4);
    miLista4.printList();
}