#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int comp = 0, swaps = 0;
vector<int> vg;

void ordenaIntercambio(int t, vector<int> v){
    int temp;
    for(int i = 0; i < t-1; i++){
        for(int j = i + 1; j < t; j++){
            if(v[i] > v[j]){
                swap(v.at(i), v.at(j));
                swaps ++;
            }
            comp ++;
        }
    }
    for(int i=0; i < t; i++){
        cout << v[i] << ", ";
    }
}

void ordenaBurbuja(int t, vector<int> v){
    int temp;
    for(int i = 0; i < t-1; i++){
        for(int j = 0; j < t-i-1; j++){
            if(v[j] > v[j+1]){
                swap(v.at(j+1), v.at(j));
                swaps ++;
            }
            comp ++;
        }
    }
    for(int i=0; i < t; i++){
        cout << v[i] << ", ";
    }
}

void merge(vector<int> v, int l, int m, int h){
    int n1 = m-l+1;
    int n2 = h-m;
    // crear vectores L y R
    vector<int> L(n1), R(n2);
    // Copiar datos a L y R
    for (int i = 0; i < n1; i++){
        L[i] = v[l+i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = v[m+1+j];
    }
    // Fusionar L y R 
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        comp++;
        k++;
    }
    // Copiar los elementos restantes de L
    while (i < n1){
        v[k] = L[i];
        i++;
        k++;
    }
    // Copiar los elementos restantes de R
    while (j < n2){
        v[k] = R[j];
        j++;
        k++;
    }
    vg = v;
}

void ordenaMerge(vector<int> v, int l, int h){
    if (l >= h){
        comp++;
        return;
    }
    int m = l+(h-l)/2;
    ordenaMerge(v, l, m);   // Mitad Izq.
    ordenaMerge(v, m+1, h); // Mitad Der.
    merge(v, l, m, h);      // Fusion mitades.
}

int busquedaSecuencialOrd(vector<int> v, int t, int n) {
    int i = 0; 
    comp = 0;
        while (i < n && v[i] != n) {
        comp++;
        i++;
    }
    if (i < t) 
        return i;
    else
        return -1;
}

int busquedaBinaria(vector<int> v, int t, int n) {
    int low = 0;
    int high = t - 1;
    while (low <= high) {
        int m = low + (high - low) / 2;
        comp++;
        if (n == v[m]){
            return m;
        } else if (n < v[m]) {
            high = m - 1;
        } else {
            low = m + 1;
        } 
    }
    return -1;
}

vector<int> obtenerTest(string path){
    string filename(path);
    vector<int> v;
    ifstream input_file(filename);
    while (!input_file.eof()){
        int tmp;
        input_file >> tmp;
        v.push_back(tmp);
    }
    input_file.close();
    return v;
}

void realizarTest(vector<int> t){
    int tam = t[0];
    int ord = t[1];
    int bus = t[2];
    int num = t[3];
    int cont = 0;
    vector<int> v;
    for (const auto &i : t){
        if (cont >= 4){
            v.push_back(i);
            // cout << i << ", ";
        } else {
            cont++;
        }
    }
    // cout << endl;
    comp = 0;
    cout << "_______________________" << endl << endl;
    cout << "Ordenamiento "; 
    switch (ord){
    case 1:
        cout << "de Intercambio:" << endl; 
        ordenaIntercambio(tam, v);
        break;
    case 2:
        cout << "de Burbuja:" << endl; 
        ordenaBurbuja(tam, v);
        break;
    case 3:
        cout << "Merge:" << endl; 
        ordenaMerge(v, 0, tam);
        for (const auto &i : vg){
            cout << i << ", ";
        }
        break;
    default:
        break;
    }
    cout << endl << endl;
    cout << "Comparaciones: " << comp << endl;
    cout << "_______________________" << endl << endl;
    comp = 0;
    cout << "Busqueda "; 
    switch (bus){
    case 1:
        cout << "Secuencial Ordenada: " << busquedaSecuencialOrd(v, tam, num) << endl << endl;
        break;
    case 2:
        cout << "Binaria: " << busquedaBinaria(v, tam, num) << endl << endl;
        break;
    default:
        break;
    }
    cout << "Comparaciones: " << comp << endl;
    cout << "_______________________" << endl << endl;
}

int main(){
    vector<int> t1, t2, t3, t4;
    t1 = obtenerTest("test/test01.txt");
    t2 = obtenerTest("test/test02.txt");
    t3 = obtenerTest("test/test03.txt");
    t4 = obtenerTest("test/test04.txt");
    cout << endl << "Test 1." << endl;
    realizarTest(t1);
    cout << endl << "Test 2." << endl;
    realizarTest(t2);
    cout << endl << "Test 3." << endl;
    realizarTest(t3);
    cout << endl << "Test 4." << endl;
    realizarTest(t4);
}