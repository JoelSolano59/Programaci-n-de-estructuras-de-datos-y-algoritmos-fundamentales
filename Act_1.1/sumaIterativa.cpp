#include <iostream>

//Iterativo
//Orden total O(n)
unsigned int sumaIterativa(unsigned int n){
    unsigned int sum = 0;
    for (int i = 1; i <= n; i++){ //O(n)
        sum = sum + i; //O(1)
        std::cout << sum << std::endl;
    }
    return sum;
}

int main(){
    std::cout << std::endl << "20:" << std::endl << sumaIterativa(20) << std::endl;
    std::cout << std::endl << "50:" << std::endl << sumaIterativa(50) << std::endl;
    std::cout << std::endl << "100:" << std::endl << sumaIterativa(100) << std::endl;
    std::cout << std::endl << "1000:" << std::endl << sumaIterativa(1000) << std::endl;
}