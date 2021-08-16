#include <iostream>

//Iterativo
unsigned int fibonacciIterativo(unsigned int n){
    unsigned int next = 1, actual = 0, temp = 0;
    for (int i = 1; i <= n; i++){
        std::cout << actual << std::endl;
        temp = actual;
        actual = next;
        next = next + temp;
    }
    return actual;
}

int main(){
    std::cout << fibonacciIterativo(10) << std::endl;
}