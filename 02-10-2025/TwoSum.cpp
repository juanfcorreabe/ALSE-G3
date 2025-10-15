#include <iostream>
#include <cmath>
using namespace std;

int Array[5];   // Arreglo para almacenar los enteros
int target;     // Suma de ambos enteros
struct Result { // Punto para almacenar los indices "x" y "y"
    int posx;
    int posy;
    int sum;
};

Result fx () {
    Result r; // Punto para devolver el resultado
    int sum;
    int posx;
    int posy;
    for (int x=0;x<5;x++) { // Doble ciclo para sumar cada entero con los demás (excluyéndose a sí mismo)
        for (int y=0;y<5;y++) {
            if (x!=y) {
                sum=Array[x]+Array[y];
                if (sum==target) {
                    r.posx=x;
                    r.posy=y;
                    r.sum=sum;
                    break;
                }
            }
        }
    }
    return r;
}

int main () {
    cout<<"Arreglo de Enteros \n";
    for (int x=0;x<5;x++) {
        cout<<"Posición ["<<x<<"]: ";
        cin>>Array[x];
    }
    cout<<"Arreglo: [";
    for (int x=0;x<5;x++) {
        cout<<Array[x]<<" ";
    }
    cout<<"]";
    cout<<"\nTarget: ";
    cin>>target;
    cout<<"\n";
    Result r=fx();
    if (r.sum==target) {      // En caso de ser posible hacer la suma
        if (r.posx<r.posy) {  // Se imprime primero r.posx al ser menor
            cout<<"["<<r.posx<<","<<r.posy<<"]"<<endl;
            cout<<"Arreglo["<<r.posx<<"] + Arreglo["<<r.posy<<"] = "<<target<<endl;
        }
        else {                // Se imprime primero r.posy al ser menor (r.posx y r.posy no pueden ser iguales)
            cout<<"["<<r.posy<<","<<r.posx<<"]"<<endl;
            cout<<"Arreglo["<<r.posy<<"] + Arreglo["<<r.posx<<"] = "<<target<<endl;
        }
    }
    else {
        cout<<"No se encontraron dos enteros que sumados resulten en "<<target<<endl;
    }
    return 0;
}
