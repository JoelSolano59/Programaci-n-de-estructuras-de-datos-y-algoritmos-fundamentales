#include <iostream>

//Recursivo
//Orden total O(n)
int fibonacciRecursivo(int rango, int primero=0, int segundo=1){
    std::cout << primero << std::endl;
    if (rango >= 2 ){
        return(fibonacciRecursivo(rango-1, segundo, primero+segundo)); //O(n)
    }
    return 0; 
}

int main(){
    std::cout << std::endl << "5:" << std::endl << fibonacciRecursivo(5) << std::endl;
    std::cout << std::endl << "10:" << std::endl << fibonacciRecursivo(10) << std::endl;
    std::cout << std::endl << "15:" << std::endl << fibonacciRecursivo(15) << std::endl;
    std::cout << std::endl << "30:" << std::endl << fibonacciRecursivo(30) << std::endl;
}