#include <iostream>

//Directo
unsigned int sumaDirecta(unsigned int n){
    unsigned int sum = (n*(n+1))/2;
    return sum;
}

int main(){
    std::cout << sumaDirecta(5) << std::endl;
}