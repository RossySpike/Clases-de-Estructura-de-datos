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

int main() {
  int cantidad, i, valor;
  Pila *pila = NULL;
  cout << "Indica cantidad de elementos a ser colocados en la pila: ";
  cin >> cantidad;
  i = 0;
  while (i != cantidad) {
    cout << "Indica valor a colocar: ";
    cin >> valor;
    Apilar(&pila, valor);
    i++;
  }

  cout << "Contenido de la Pila: " << endl;
  mostrarPila(pila);
  return 0;
}
