#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int ordenaIntercambio(vector<int> v){

}

int ordenaBurbuja(vector<int> v){

}

int ordenaMerge(vector<int> v){

}

int busquedaSecuencialOrd(vector<int> v){

}

int busquedaBinaria(vector<int> v){

}

vector<int> obtenerTest(string path){
    string filename(path);
    vector<int> v;
    int num;
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
        } else {
            cont++;
        }
    }
    for (const auto &j : v){
        cout << j << ";";
    }
    // switch (ord){
    // case 1:
    //     ordenaIntercambio(v);
    //     break;
    // case 2:
    //     ordenaBurbuja(v);
    //     break;
    // case 3:
    //     ordenaMerge(v);
    //     break;
    // default:
    //     break;
    // }
    // switch (bus){
    // case 1:
    //     busquedaSecuencialOrd(v);
    //     break;
    // case 2:
    //     busquedaBinaria(v);
    //     break;
    // default:
    //     break;
    // }
}

int main(){
    vector<int> t1, t2, t3, t4;
    t1 = obtenerTest("test/test01.txt");
    t2 = obtenerTest("test/test02.txt");
    t3 = obtenerTest("test/test03.txt");
    t4 = obtenerTest("test/test04.txt");
    realizarTest(t1);
}