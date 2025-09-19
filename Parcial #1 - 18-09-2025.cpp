#include <iostream>
#include <cmath>
#include <cctype>
#include <limits>
#include <vector>

struct Point {
    double x, y;
};

double calcularMagnitud(const Point& p) {
    return std::sqrt(std::pow(p.x, 2) + std::pow(p.y, 2));
}

void leerPuntos(std::vector<Point>& puntos, int n) {
    char respuesta;
    std::cout << "\n¿Desea ingresar los vectores manualmente? (s/n): ";
    std::cin >> respuesta;

    if (std::tolower(respuesta) == 's') {
        for (int i = 0; i < n; i++) {
            std::cout << "\nVector " << i + 1 << ":\n";
            std::cout << "Ingrese la coordenada en x: ";
            std::cin >> puntos[i].x;
            std::cout << "Ingrese la coordenada en y: ";
            std::cin >> puntos[i].y;
        }
    } else {
        std::cout << "Usando vectores predeterminados...\n";
        Point defaults[] = { {0, 0}, {3, 4}, {6, 8}, {9, 12} };
        int tam = sizeof(defaults) / sizeof(defaults[0]);

        for (int i = 0; i < n; i++) {
            puntos[i] = defaults[i % tam];
        }
    }
}

double calcularMasCercano(const Point& referencia, const std::vector<Point>& puntos, int n, int& indiceCercano) {
    double menorDistancia = std::numeric_limits<double>::max();
    indiceCercano = 0;

    for (int i = 0; i < n; i++) {   
        double distancia = std::sqrt(std::pow(puntos[i].x - referencia.x, 2) +
                                     std::pow(puntos[i].y - referencia.y, 2));
        if (distancia < menorDistancia) {
            menorDistancia = distancia;
            indiceCercano = i;
        }
    }
    return menorDistancia;
}

int main() {
    Point obligatorio;
    std::cout << "Ingrese el vector obligatorio:\n";
    std::cout << "Coordenada en x: ";
    std::cin >> obligatorio.x;
    std::cout << "Coordenada en y: ";
    std::cin >> obligatorio.y;

    double magnitudObligatorio = calcularMagnitud(obligatorio);
    std::cout << "\nLa magnitud del vector obligatorio es: " << magnitudObligatorio << "\n";

    char respuesta;
    std::cout << "\n¿Desea ingresar vectores a comparar? (s/n): ";
    std::cin >> respuesta;

    int n = 0;
    if (std::tolower(respuesta) == 's') {
        std::cout << "¿Cuántos vectores desea ingresar? ";
        std::cin >> n;
    } else {
        n = 4; 
    }

    std::vector<Point> puntos(n);
    leerPuntos(puntos, n);

    int indiceCercano;
    double distancia = calcularMasCercano(obligatorio, puntos, n, indiceCercano);

    std::cout << "\nEl vector más cercano es: (" 
              << puntos[indiceCercano].x << ", " 
              << puntos[indiceCercano].y << ")\n";
    std::cout << "Su magnitud es: " << calcularMagnitud(puntos[indiceCercano]) << "\n";
    std::cout << "La distancia al vector obligatorio es: " << distancia << "\n";

    return 0;
}
