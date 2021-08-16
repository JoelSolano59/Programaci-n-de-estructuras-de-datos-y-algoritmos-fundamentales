#include <iostream>

//Recursivo
unsigned int fibonacciRecursivo(unsigned int n){
    if (n == 0){
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        unsigned int actual = fibonacciRecursivo(n-2);
        unsigned int next = fibonacciRecursivo(n-1);
        return actual + next;
    }
}

int main(){
    std::cout << fibonacciRecursivo(10) << std::endl;
}