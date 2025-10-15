#include <iostream>
#include <cmath>
using namespace std;

int x;
int Palindrome () {
    int y=0;
    int Y=0; // Para reversar
    int remain; // Para último dígito
    y+=x; // Copia de x
    if (y<0) {
        return y+1;
    }
    while (y>0) {
        remain=y%10;
        Y*=10;
        Y+=remain;
        y/=10;
    }
    return Y;
}

int main () {
    cout<<"Palindrome Numbers \n";
    cout<<"Insert Number: ";
    cin>>x;
    int Y=Palindrome();
    if (Y==x) {
        cout<<"The number "<<x<<" is palindrome \n";
    }
    else {
        cout<<"The number "<<x<<" is not palindrome \n";
    }
    return 0;
}
