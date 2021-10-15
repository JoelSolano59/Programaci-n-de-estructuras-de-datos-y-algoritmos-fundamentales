/*
Programación de estructuras de datos y algoritmos fundamentales Gpo. 12
Joel Isaias Solano Ocampo  A01639289

Archivos necesarios:
+ bitacora.txt
+ dateTime.cpp
+ dateTime.h
+ DoubleLinkedList.h
+ main.cpp
+ Node.h
+ Registro.cpp
+ Registro.h
+ Stack.h

Instrucciones de uso:
1. Compilar el archivo main.cpp
2. Introducir la fecha incial y final con sus respectivos formatos en consola
3. En consola se desplegaran el numero total de resultados de registros por orden de fecha y entre el rango establecido
4. Como resultado se generaran los archivos: "bitacora_ordenada.txt" y "resultado_busqueda.txt"
5. Para intentar otro test, volver a compilar main.cpp
*/

#include <iostream>
#include "DoubleLinkedList.h"
#include "Registro.h"

int main()
{
  DoubleLinkedList<Registro> miLista;
  miLista.cargarBitacora("bitacora.txt");
  miLista.bitacoraOrdenada();
  miLista.printListByDates();
}