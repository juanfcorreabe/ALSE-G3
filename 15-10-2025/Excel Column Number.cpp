#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

void fx (string columntitle) {
    vector<int>Number;
    for (int x=0;x<26;x++) {
        Number.push_back(x+1);
    }
    char A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z;
    vector<char>Letters={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int n=-1, power=0, column=0;            // Se inicializa n=-1 para que la potencia de 26 con la última letra sea 0
    for (char x:columntitle) {              // Ciclo para llevar n hasta la potencia máxima de 26
        n+=1;
    }
    for (char x:columntitle) {              // Ciclo para contar en base 26
        power=pow(26,n);
        column+=power*(x-'A'+1);            // Se resta x al código ASCII de A (65) y se suma 1 para obtener el abecedario
        n-=1;
    }
    cout<<"Número de la Columna: "<<column<<endl;
}

int main () {
    string columntitle;
    cout<<"Número de Columna en Excel"<<endl;
    cout<<"Ingrese la columna: ";
    cin>>columntitle;
    cout<<"\n";
    fx(columntitle);
}