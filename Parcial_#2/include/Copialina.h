#ifndef Archivo_h
#define Archivo_h
#include <iostream>
#include <string>
#include <vector>
class DispositivoInteligente {
    private:
    std::string nombre;
    bool estado;
    bool bloqueado;
    float consumoEnergia;
    public:
    std::vector<std::string>name={"Lavadora","Impresora"};
    std::vector<float>usage={0,34.52};
    std::vector<bool>state={false,true};
    std::vector<bool>blocked={true,false};
    DispositivoInteligente (std::string n, bool e, bool b, float c) : nombre(n), estado(e), bloqueado (b), consumoEnergia(c) {}
    int disp;
    int device () {
        std::cout<<"Escoja el dispositivo (0 o 1)"<<std::endl;
        std::cin>>disp;
        while (disp!=0 && disp!=1) {
            std::cout<<"Eso no sirve"<<std::endl;
            std::cout<<"Escoja el dispositivo (0 o 1)"<<std::endl;
            std::cin>>disp;
        }
        return disp;
    }
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
    void bloquearControlRemoto (bool bloqueado, int d) {
        d=disp;
        blocked[d]=true;
    }
    void desbloquearControlRemoto (bool bloqueado, int d) {
        d=disp;
        blocked[d]=false;
    }
    void Print (int d) {
        d=disp;
        std::cout<<"Nombre: "<<name[d]<<std::endl;
        std::cout<<"Consumo "<<usage[d]<<" Watts/hora"<<std::endl;
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

};
#endif