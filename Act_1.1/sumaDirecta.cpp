#include <iostream>

//Directo
//Orden total O(1)
unsigned int sumaDirecta(unsigned int n){ //O(1)
    unsigned int sum = (n*(n+1))/2;
    return sum;
}

int main(){
    std::cout << std::endl << "20:" << std::endl << sumaDirecta(20) << std::endl;
    std::cout << std::endl << "50:" << std::endl << sumaDirecta(50) << std::endl;
    std::cout << std::endl << "100:" << std::endl << sumaDirecta(100) << std::endl;
    std::cout << std::endl << "1000:" << std::endl << sumaDirecta(1000) << std::endl;
}