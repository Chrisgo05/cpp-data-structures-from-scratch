#include <iostream>

void modificar(int& x){
    x = 20;
}

int main(){
    int a = 10;
    modificar(a);

    std::cout << a << std::endl;

    return 0;
}