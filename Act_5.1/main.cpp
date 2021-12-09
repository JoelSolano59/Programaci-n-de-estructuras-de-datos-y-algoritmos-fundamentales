/*
* Programación de estructuras de datos y algoritmos fundamentales  * Gpo. 12
* Joel Isaias Solano Ocampo  A01639289
* Mauricio Cantu Torres      A01633805
* 
* Instrucciones para ejecucion:
* Compilar con: g++ -std=c++17 main.cpp -o main
* Ejecutar: ./main 
*/

#include "MyHashTable.cpp"
#include "MyLinkedList.cpp"

int main(){
    MyHashTable data;
    data.put("15", 136345843);
    data.put("23", 431730129);
    data.put("34", 321637389);
    data.put("41", 345564022);  
    data.put("56", 31639943);
    data.put("67", 431685923);
    data.put("74", 761745691);
    data.put("89", 781639261);
    data.put("98", 431648389);  
    data.put("122", 311732569);
    data.put("244", 25143259);
    data.put("333", 98164849); 
    data.put("455", 78163249); 

    data.callHashTable();
    data.~MyHashTable();
    
    return 0;
}