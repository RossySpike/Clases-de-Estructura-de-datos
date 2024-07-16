// new: guarda espacio en memoria
// delete libera memoria
#include <iostream>
// Listas multiplemente enlazadas.
using namespace std;

struct Nodo {
  int dato;
  Nodo *prox;
};

int main() {
  Nodo *primero, *p, *q, *auxiliar;

  primero = new Nodo;
  primero->dato = 10;
  primero->prox = nullptr;

  p = new Nodo;
  p->dato = 20;
  p->prox = nullptr;

  primero->prox = p;

  p = new Nodo;
  p->dato = 30;
  p->prox = nullptr;

  primero->prox->prox = p;

  p = primero;

  while (p != nullptr) {
    cout << p << " ";
    p = p->prox;
  }

  cout << "NULL" << endl;

  p = primero;

  while (p->prox != nullptr && p->dato) { // No se ejecuta
    p = p->prox;
  }

  q = p->prox->prox;
  auxiliar = p->prox;
  p->prox = q;
  delete auxiliar;

  p = primero;

  while (p != nullptr) {
    cout << p->dato << " ";
    p = p->prox;
  }
  cout << "NULLL";

  return 0;
};
