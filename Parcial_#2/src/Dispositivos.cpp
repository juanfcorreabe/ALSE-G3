#include <iostream>
#include <string>
#include <vector>
#include "../include/archivo.h"

int main () {
    DispositivoInteligente D1 ("nombre","estado",false,0);
    std::cout<<"Todo en este programa es Case Sensitive"<<std::endl;
    std::cout<<"¿Desea usar valores predeterminados? (si/no)"<<std::endl;
    std::string choose;
    std::cin>>choose;
    if (choose=="si") {
        D1.Default();
    }
    else if (choose=="no") {
        D1.Input();
    }
    int d=D1.device();
    D1.Print(d);
    return 0;
}