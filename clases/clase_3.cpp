#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *prox;
};

int main (){
    Nodo *primero;
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo -> dato = 10;
    nuevoNodo -> prox = nullptr;

    primero = nuevoNodo;
    nuevoNodo = new Nodo;
    nuevoNodo -> prox = nullptr;
    primero -> prox = nuevoNodo;//Error!
    primero -> prox -> dato = primero -> dato + 5;//Error!
    
    nuevoNodo = new Nodo;
    nuevoNodo -> dato = 30;
    nuevoNodo -> prox = primero;//Error!
    primero = nuevoNodo;
    
    Nodo *actual = primero;
    while (actual != nullptr){
        cout << actual -> dato << " ";
        actual = actual -> prox;//Error!
    }

    cout << "NULL";
    return 0;
}