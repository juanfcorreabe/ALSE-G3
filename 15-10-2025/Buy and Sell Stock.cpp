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
    vector<int> Profit;
    vector<int> Day1;                                       // Día para comprar
    vector<int> Day2;                                       // Día para vender
    for (int x=0;x<Prices.size();x++) {                     // Ciclo para hallar la posición del valor máximo y mínimo dentro del vector
        // CODE FROM OCTOBER 18
        for (int y=0;y<Prices.size();y++) {
            if (((Prices[y]-Prices[x])>Prices[x]) && y>x) {
                Profit.push_back(Prices[y]-Prices[x]);      // Rentabilidad entre dos días dados
                Day1.push_back(x);                          // Día de menor precio
                Day2.push_back(y);                          // Día de mayor precio
            }
        }
        // CODE FROM OCTOBER 18

        /*
        if ((Prices[x]==Min && Max!=Min) && cycle1==0) {
            Buy+=(x+1);
            cycle+=1;
            cycle1+=1;
        }
        else if ((Prices[x]==Max && x>0 && Max!=Min) && cycle2==0) {
            Sell+=(x+1);
            cycle+=1;
            cycle2+=1;
        }
        else if (cycle==2) {
            break;
        }
        */
    }
    // CODE FROM OCTOBER 18
    int max=*max_element(Profit.begin(),Profit.end());
    int min=*min_element(Profit.begin(),Profit.end());
    for (int x=0;x<Profit.size();x++) {
        if (Profit[x]==max) {
            Buy=Day1[x]+1;
        }
        else if (Profit[x]==min) {
            Sell=Day2[x]+1;
        }
    }

      // FOR TROUBLESHOOTING
    cout<<"Profit: [";
    for (int x=0;x<Profit.size();x++) {
        cout<<Profit[x]<<" ";
    }
    cout<<"]"<<endl;

    cout<<"Day1: [";
    for (int x=0;x<Day1.size();x++) {
        cout<<Day1[x]<<" ";
    }
    cout<<"]"<<endl;

    cout<<"Day2: [";
    for (int x=0;x<Day2.size();x++) {
        cout<<Day2[x]<<" ";
    }
    cout<<endl;
      // FOR TROUBLESHOOTING
    // CODE FROM OCTOBER 18
    
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
