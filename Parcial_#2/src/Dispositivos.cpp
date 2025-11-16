// * @author Juan Francisco Correa
// * @author Sergio Andrés Montaña
// * @date 30 de octubre de 2025
#include <iostream>
#include <string>
#include <vector>
#include "../include/archivo.h"

int main () {
    // * @see Se invoca el constructor de la clase "DispositivoInteligente"
    DispositivoInteligente D1 ("nombre","estado",false,0);
    std::cout<<"Todo en este programa es Case Sensitive"<<std::endl;
    // * @brief Se le pregunta al usuario si desea usar valores predeterminados o suyos propios
    std::cout<<"¿Desea usar valores predeterminados? (si/no)"<<std::endl;
    std::string choose;
    std::cin>>choose;
    if (choose=="si") {
        D1.Default();
    }
    else if (choose=="no") {
        D1.Input();
    }
    // * @return d es el número del dispositivo a retornar por la función "device"
    int d=D1.device();
    // * @brief Se invoca la función Print para mostrarle los valores al usuario
    D1.Print(d);
    return 0;
}