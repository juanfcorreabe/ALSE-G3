// * @author Juan Francisco Correa
// * @author Sergio Andrés Montaña
// * @date 30 de octubre de 2025
#ifndef Archivo_h
#define Archivo_h
#include <iostream>
#include <string>
#include <vector>

class DispositivoInteligente {
    // * @brief Se declaran los atributos de la clase
    private:
    std::string nombre;
    bool estado;
    bool bloqueado;
    float consumoEnergia;
    public:
    // * @brief Estos vectores almacenan la información de cada dispositivo
    std::vector<std::string>name;
    std::vector<float>usage;
    std::vector<bool>state;
    std::vector<bool>blocked;
    // * @brief Se declara el constructor
    DispositivoInteligente (std::string n, bool e, bool b, float c) : nombre(n), estado(e), bloqueado (b), consumoEnergia(c) {}
    // * @brief Esta función asigna los valores de los dispositivos predeterminados a cada vector
    void Default () {
        name={"Lavadora","Impresora"};
        usage={0,34.52};
        state={false,true};
        blocked={true,false};
    }
    // * @brief Esta función asigna a cada vector los valores
    void Input () {
        int n;
        std::string name1;
        std::string state1, blocked1;
        float usage1;
        std::cout<<"Cantidad de dispositivos: "<<std::endl;
        std::cin>>n;
        for (int x=0;x<n;x++) {
            std::cout<<"Nombre: ";
            std::cin>>name1;
            name.push_back(name1);
            std::cout<<std::endl;
            std::cout<<"Estado (Apagado/Encendido): ";
            std::cin>>state1;
            if (state1=="Apagado") {
                state.push_back(false);
            }
            else if (state1=="Encendido") {
                state.push_back(true);
            }
            std::cout<<std::endl;
            std::cout<<"Consumo de Energía (Watt/hora): ";
            std::cin>>usage1;
            usage.push_back(usage1);
            std::cout<<"Control Remoto (Bloqueado/Desbloqueado): ";
            std::cin>>blocked1;
            if (blocked1=="Bloqueado") {
                blocked.push_back(false);
            }
            else if (blocked1=="Desbloqueado") {
                blocked.push_back(true);
            }
        }    
    }
    // * @brief "disp" es utilizado como parámetro de la mayoría de funciones, esto después de invocar la función device
    int disp;
    // * @brief Esta función escoge el dispositivo
    int device () {
        std::cout<<"Escoja el dispositivo para visualizar (1 o 2)"<<std::endl;
        std::cin>>disp;
        while (disp!=1 && disp!=2) {
            std::cout<<""<<std::endl;
            std::cout<<"Escoja el dispositivo (1 o 2)"<<std::endl;
            std::cin>>disp;
        }
        return (disp-1);
    }
    // * @brief Esta función enciende el dispositivo
    void encender (int d) {
        d=disp;
        bool encendido;
        std::cin>>encendido;
        if (encendido==true) {
            estado=true;
        }
        else {
            estado=false;
        }
        state[d]=estado;
    }
    // * @brief Esta función apaga el dispositivo
    void apagar (int d) {
        d=disp;
        bool apagado;
        std::cin>>apagado;
        if (apagado==true) {
            estado=false;
        }
        else {
            estado=true;
        }
        state[d]=estado;
    }
    float medirConsumo (float horas, int d) {
        float consumo;

        return consumo;
    }
    // * @brief Esta función bloquea el control remoto
    void bloquearControlRemoto (bool bloqueado, int d) {
        d=disp;
        blocked[d]=true;
    }
    // * @brief 
    void desbloquearControlRemoto (bool bloqueado, int d) {
        d=disp;
        blocked[d]=false;
    }
    // * @brief Esta función le muestra al usuario la información de cada dispositivo
    void Print (int d) {
        d=disp;
        std::cout<<"Nombre: "<<name[d]<<std::endl;
        std::cout<<"Consumo: "<<usage[d]<<" Watts/hora"<<std::endl;
        if (state[d]==false) {
        std::cout<<"Estado: Apagado"<<std::endl;
        }
        else {
            std::cout<<"Estado: Encendido"<<std::endl;
        }
        if (blocked[d]==false) {
        std::cout<<"Control Remoto: Bloqueado"<<std::endl;
        }
        else {
        std::cout<<"Control Remoto: Desbloqueado"<<std::endl;
        }
    }
    // * @brief Se invoca al destructor
    ~DispositivoInteligente();
};
#endif