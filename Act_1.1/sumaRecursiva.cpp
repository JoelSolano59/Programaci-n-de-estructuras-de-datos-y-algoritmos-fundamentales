#include <iostream>

//Recursivo
//Orden total O(n)
unsigned int sumaRecursiva(unsigned int n){
    if (n == 0){
        return 0; //O(1)
    } else {
        unsigned int sum = sumaRecursiva(n-1); //O(n)
        std::cout << sum + n << std::endl;
        return(sum + n);
    }
}

int main(){
    std::cout << std::endl << "20:" << std::endl << sumaRecursiva(20) << std::endl;
    std::cout << std::endl << "50:" << std::endl << sumaRecursiva(50) << std::endl;
    std::cout << std::endl << "100:" << std::endl << sumaRecursiva(100) << std::endl;
    std::cout << std::endl << "1000:" << std::endl << sumaRecursiva(1000) << std::endl;
}