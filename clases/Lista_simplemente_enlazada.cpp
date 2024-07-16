//Tipo de dato abstracto (TDA)
//Lista simplemente enlazada
#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *prox;
};

int main (){
    Nodo *primero = new Nodo;
    primero -> dato = 5;
    primero -> prox = nullptr;
    Nodo *segundo = new Nodo;
    segundo -> dato = 10;
    segundo -> prox = nullptr;
    primero -> prox = segundo;
    Nodo *tercero = new Nodo;
    tercero -> dato = 20;
    tercero -> prox = nullptr;
    segundo -> prox = tercero;
    segundo -> dato += 5;
    Nodo *actual = primero;

    while (actual != nullptr){
        cout << actual -> dato << " ";
        actual = actual -> prox;
    }
    cout << "NULL" << endl;

    return 0;
}