#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fibonacciRecursivo(int x){
    if (x == 1){
        return 0;
    }
    else if (x == 2){
        return 1;
    }
    else{
        return (fibonacciRecursivo(x-1)+fibonacciRecursivo(x-2));
    }
}

int main(){
    cout << fibonacciRecursivo(9) << endl;