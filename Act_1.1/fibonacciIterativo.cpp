#include <iostream>

//Iterativo
//Orden total O(n)
unsigned int fibonacciIterativo(unsigned int n){
    unsigned int next = 1, actual = 0, temp = 0;
    for (int i = 1; i <= n; i++){ //O(n)
        std::cout << actual << std::endl;
        temp = actual; //O(1)
        actual = next;
        next = next + temp;
    }
    return actual;
}

int main(){
    std::cout << std::endl << "5:" << std::endl << fibonacciIterativo(5) << std::endl;
    std::cout << std::endl << "10:" << std::endl << fibonacciIterativo(10) << std::endl;
    std::cout << std::endl << "15:" << std::endl << fibonacciIterativo(15) << std::endl;
    std::cout << std::endl << "20:" << std::endl << fibonacciIterativo(20) << std::endl;
}