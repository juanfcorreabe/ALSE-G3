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
    DispositivoInteligente (std::string n, bool e, bool b, float c) : nombre(n), estado(e), bloqueado (b), consumoEnergia(c) {}
    void encender () {
        bool encendido;
        std::cin>>encendido;
        if (encendido==true) {
            estado=true;
        }
        else {
            estado=false;
        }
    }
    void apagar () {
        bool apagado;
        std::cin>>apagado;
        if (apagado==true) {
            estado=false;
        }
        else {
            estado=true;
        }
    }
    float medirConsumo (float horas) {
        float consumo;

        return consumo;
    }
    void bloquearControlRemoto (bool bloqueado) {

    }

};
#endif