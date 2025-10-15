#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int fx (int num) {                                              // Función para Sacar Coeficientes
    int n;
    int k;
    int coef;                                                   // Variable para los coeficientes del binomio
    int count=0;
    cout<<"[";
    for (n=0;n<num;n++) {
        cout<<"[";
        for (k=0;k<=n;k++) {
            coef=tgamma(n+1) / (tgamma(k+1) * tgamma((n-k)+1)); // Coeficiente binomial según Teorema del Binomio (se usa la Función Gamma)
            cout<<coef;
            if ((k>=1 || n>0) && k<n) {                         // Para imprimir con el formato igual al de Leetcode
                cout<<",";
            }
            else if (k==n || n>0) {
                cout<<"";
            }
        }
        cout<<"]";
        if (n<(num-1)) {
            cout<<",";
        }
    }
    cout<<"]\n";
    return 0;
}

int main () {
    int numrows;
    cout<<"Triángulo de Pascal"<<endl;
    cout<<"Número de filas: ";
    cin>>numrows;
    int num=fx(numrows);
    return 0;
}

/*
1. Use the gamma function to get factorials
2. Use Newton's Binomial Theorem to find the coefficients for the triangle
3. Max n = 29 (30 rows in the triangle) */
