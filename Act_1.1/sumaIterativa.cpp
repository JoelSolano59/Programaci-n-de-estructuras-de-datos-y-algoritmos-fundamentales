#include <iostream>

//Iterativo
unsigned int sumaIterativa(unsigned int n){
    unsigned int sum = 0;
    for (int i = 1; i <= n; i++){
        sum = sum + i;
        std::cout << sum << std::endl;
    }
    return sum;
}

int main(){
    std::cout << sumaIterativa(5) << std::endl;
}