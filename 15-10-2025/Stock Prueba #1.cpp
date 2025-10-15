// NOTA: Si Prices=[10,9,2,11,2] (n=5) no funciona. Arreglar eso xd - Creo que ya quedó arreglado (?)
// NOTA: Si alguno de los precios es 0 no funciona [10,9,2,0,6]
#include <iostream>
#include <vector>
#include <algorithm>                                        // Para usar las funciones "min" y "max"
using namespace std;

void fx (vector<int>Prices) {
    int Max=*max_element(Prices.begin(),Prices.end());      // Se busca el valor máximo y mínimo del vector
    int Min=*min_element(Prices.begin(),Prices.end());
    int cycle=0, cycle1=0, cycle2=0, Buy=0, Sell=0;
    for (int x=0;x<Prices.size();x++) {                     // Ciclo para hallar la posición del valor máximo y mínimo dentro del vector
        // Ciclo while para comprar: Max >= Prices[x] >=Min
        // while (Min<=Prices[x] && Prices[x]<=Max)
        if ((Prices[x]==Min && Max!=Min) && cycle1==0) {
            Buy+=(x+1);
            cycle+=1;
            cycle1+=1;
        }
        // Ciclo while para vender: Max>= Prices[x] >= Min
        /*while (Prices[x]<=Max) {
        
        }*/
       /*
       if (x>0) {
        for (int y=1;y<(Prices.size()-1);y++) {
            if (Prices[y]>Prices[x]) {
            Sell==(x+1);
            cycle+=1;
            cycle2+=1;
            }
        }
       } */
       if ((x>0 && Prices.size()>x) && (Prices[x]>Prices[x+1])) {
            Sell==(x);
            cycle+=1;
            cycle2+=1;
       }
       /*
        else if (((Prices[x]==Max && x>0) || Max!=Min) && cycle2==0) {
            Sell+=(x+1);
            cycle+=1;
            cycle2+=1;
        }*/
        else if (cycle==2) {
            break;
        }
    }
    cout<<"Buy: "<<Buy<<endl;
    cout<<"Sell: "<<Sell<<endl;
    if (Sell>Buy) {                                         // Se imprimen los dos casos posibles
        cout<<"Compre acciones el día "<<Buy<<endl;
        cout<<"Venda acciones el día "<<Sell<<endl;
    }
    else if (Sell==Buy || Sell<Buy) {
        cout<<"No es posible obtener rentabilidad en las condiciones dadas"<<endl;
    }
}

int main () {
    int n;
    cout<<"Cuándo Comprar y Vender Acciones"<<endl;
    cout<<"Ingrese el número de días: ";
    cin>>n;
    cout<<"\n";
    cout<<"Ingrese los precios: "<<endl;
    vector<int>Prices(n);
    for (int x=0;x<n;x++) {
        cout<<"Precio (día "<<x+1<<"): $";
        cin>>Prices[x];
        while (Prices[x]<0) {
            cout<<"El precio de la acción no puede ser menor a cero"<<endl;
            cout<<"Precio (día "<<x+1<<"): $";
            cin>>Prices[x];
        }
    }
    cout<<"\n";
    fx (Prices);

}
/*
1. Find max value
2. Find min value
3. Max Value = Sell | Min Value = Buy
*/
