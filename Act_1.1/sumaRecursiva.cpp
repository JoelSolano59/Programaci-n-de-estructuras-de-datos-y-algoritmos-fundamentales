#include <iostream>

//Recursivo
unsigned int sumaRecursiva(unsigned int n){
    if (n == 0){
        return 0;
    } else {
        unsigned int sum = sumaRecursiva(n-1);
        std::cout << sum + n << std::endl;
        return(sum + n);
    }
}

int main(){
    std::cout << sumaRecursiva(5) << std::endl;
}