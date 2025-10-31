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
    std::vector<std::string>name;
    std::vector<float>usage;
    std::vector<bool>state;
    std::vector<bool>blocked;
    DispositivoInteligente (std::string n, bool e, bool b, float c) : nombre(n), estado(e), bloqueado (b), consumoEnergia(c) {}
    void Default () {
        name={"Lavadora","Impresora"};
        usage={0,34.52};
        state={false,true};
        blocked={true,false};
        /*
        for (int x=0;x<name.size();x++) {
            std::cout<<"Name : "<<name[x]<<std::endl;
        } 
        */
    }
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
    
    int disp;
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

};
#endif