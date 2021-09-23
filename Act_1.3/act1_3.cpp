/*
Programación de estructuras de datos y algoritmos fundamentales Gpo. 12
Joel Isaias Solano Ocampo  A01639289

Archivos necesarios:
+ act1_3.cpp
+ bitacora.txt
+ dateTime.h

Instrucciones de uso:
1. Compilar el archivo act1_3.cpp
2. Introducir la fecha minima y maxima en consola.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include "dateTime.h"
using namespace std;

// Creeamos una estructura para los reegistros de la bitacora
struct log{
    dateTime dateT;
    string dateS;
    string errorM;
} logs;

// Funcion para intercambiar el valor de dos logs
void swap(log* x, log* y){
    log temp = *x;
    *x = *y;
    *y = temp;
}

// Funcion para obtener los registros de bitacora.txt
void obtenerBitacora(vector<log> &v, int &n){
    n = 0;
    string month = "", day = "", time = "";
    ifstream file;
    file.open("bitacora.txt");
    string line;
    while (getline(file, line)){
        string month = line.substr(0,3);
        int day = stoi(line.substr(4,6));
        int hour = stoi(line.substr(7,9));
        int min = stoi(line.substr(10,12));
        int sec = stoi(line.substr(13,15));
        string fdate = line.substr(0,15);
        string mens = line.substr(16, line.size());
        dateTime date(month, day, hour, min, sec);

        log newLog;
        newLog.dateT = date;
        newLog.dateS = fdate;
        newLog.errorM = mens;
        v.push_back(newLog);
        n++;
    }
}

// Funcion para particionar el vector, usada en la funcion quickSort
int partition(vector<log> &v, int l, int h){
    dateTime p = v[h].dateT;
    int i = (l-1);
    for (int j = l; j <= h-1; j++){
        dateTime di = v[j].dateT;
        if (di <= p){
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i+1], &v[h]);
    return (i+1);
}

// Funcion para ordenar el vector de registros de bitacora
void quickSort(vector<log> &v, int l, int h){
    if (l < h){
        int p = partition(v, l, h);
        quickSort(v, l, p-1);
        quickSort(v, p+1, h);
    }
}

// Funcion para generar un archivo con los registros ordenados llamado bitacora_ordenada.txt 
void generarTxt(vector<log> v, int n){  
    ofstream out("bitacora_ordenada.txt");
    for (int i = 0; i < n; i++){
        string line;
        if (i == n - 1){
            line = v[i].dateS + " " + v[i].errorM;
            out << line;
        }else {
            line = v[i].dateS + " " + v[i].errorM + "\n";
            out << line;
        }
    }
    out.close();
}

// Funcion que busca determinada fecha en los registro de la bitacora ordenada
int binarySearch(vector<log> v, int n, dateTime k){
    int l = 0;
    int h = n-1;
    while (l <= h){
        int m = l + (h - l)/2;
        if (k == v[m].dateT){
            return m;
        } else if (k < v[m].dateT){
            h = m-1;
        } else {
            l = m+1;
        }
    }
    return -1;
}

// Funcion que imprime el rango de fechas de los registros de la bitacora ordenada
void imprimirRango(vector<log> v, int n, int l, int h){
    cout << endl << "Resultado: " << (h-l)+1 << " registros." << endl;
    for (int j = l; j <= h; j++){
        cout << v[j].dateS << " ";
        cout << v[j].errorM << endl;
    }
}

// Funcion main.
int main(){
    // Declaramos nuestro vector, nuestros Strings y nuestros Ints
    vector<log> vb;
    string fechaMin, fechaMax;
    int n = 0, bs1 = -1, bs2 = -2;

    // Obtenemos los datos de bitacora.txt
    obtenerBitacora(vb, n);
    // Ordenamos dichos datos
    quickSort(vb, 0, n-1);
    // Una vez ordenados los datos, generamos bitacora_ordenada.txt
    generarTxt(vb, n);

    // Ingresamos la fecha minima
    cout << "Fecha 1: ";
    getline(cin, fechaMin);

    // Obtenemos nuestro mes, dia, hora, minuto y segundo de nuestra fecha minima
    string month = fechaMin.substr(0,3);
    int day = stoi(fechaMin.substr(4,6));
    int hour = stoi(fechaMin.substr(7,9));
    int min = stoi(fechaMin.substr(10,12));
    int sec = stoi(fechaMin.substr(13,15));
    // Generamos un objeto de tipo dateTime con los valores de la fecha minima
    dateTime dat1(month, day, hour, min, sec);
    try{
        // Buscamos la fecha minima en la bitacora ordenada
        bs1 = binarySearch(vb, n, dat1);
    }
    catch(const exception& e){
        // En caso de ingresar una fecha minima con formato no valido
        cerr << e.what() << '\n';
        return 0;
    }
    if (bs1 == -1){
        // Si no encuentra la fecha minima ingresada en la bitacora ordenada
        cout << "Error. No se encontro ninguna fecha que corresponda con " << fechaMin << "." << endl;
        return 0;
    }

    // Ingresamos la fecha maxima
    cout << "Fecha 2: ";
    getline(cin, fechaMax);

    // Obtenemos nuestro mes, dia, hora, minuto y segundo de nuestra fecha maxima
    month = fechaMax.substr(0,3);
    day = stoi(fechaMax.substr(4,6));
    hour = stoi(fechaMax.substr(7,9));
    min = stoi(fechaMax.substr(10,12));
    sec = stoi(fechaMax.substr(13,15));
    // Generamos un objeto de tipo dateTime con los valores de la fecha maxima
    dateTime dat2(month, day, hour, min, sec);
    try{
        // Buscamos la fecha maxima en la bitacora ordenada
        bs2 = binarySearch(vb, n, dat2);
    }
    catch(const exception& e){
        // En caso de ingresar una fecha minima con formato no valido
        cerr << e.what() << '\n';
    }
    if (bs2 == -1){
        // Si no encuentra la fecha maxima ingresada en la bitacora ordenada
        cout << "Error. No se encontro ninguna fecha que corresponda con " << fechaMax << "." << endl;
        return 0;
    }

    // Si la fecha minima es menor a la fecha maxima
    if (bs1 <= bs2){
        // Imprimimos los rangos de las fechas de la bitaacora ordenada
        imprimirRango(vb, n, bs1, bs2);
    } else {
        // Si la fecha minima es mayor a la fecha maxima
        cout << "Error. " << fechaMin << " no es menor que " << fechaMax << "." << endl;
        return 0;
    }

    // Fin del programa
    return 0;
}