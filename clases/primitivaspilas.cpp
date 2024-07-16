#include <iostream>
using namespace std;
// Operaciones básicas de Pilas
// Elaborado por Lia Mendoza

struct Pila {
  int dato;
  Pila *prox;
};

Pila *crearPila(int valor) {
  Pila *nuevo = new Pila;
  nuevo->dato = valor;
  nuevo->prox = NULL;
  return nuevo;
}

bool PilaVacia(Pila *pila) { return pila == NULL; }

Pila *Tope(Pila *pila) {
  if (!PilaVacia(pila))
    return pila;
  else
    return nullptr;
}

void Apilar(Pila **pila, int valor) {
  Pila *nuevo = crearPila(valor);
  nuevo->prox = *pila;
  *pila = nuevo;
}

void Desapilar(Pila **pila) {
  Pila *temp;
  if (!PilaVacia(*pila)) {
    temp = *pila;
    *pila = (*pila)->prox;
    delete temp;
  } else
    cout << "Pila vacia imposible desapilar " << endl;
}

void mostrarPila(Pila *pila) {
  while (!PilaVacia(pila)) {
    cout << Tope(pila)->dato << "  ";
    Desapilar(&pila);
  }
}

Pila *LlenarPila(Pila **pila) {
  int valor;
  int i = 0;
  cout << "Ingr elementos de la pila";
  cin >> valor;
  while (i < valor) {
    Apilar(pila, i);
    i++;
  }
  return *pila;
}
