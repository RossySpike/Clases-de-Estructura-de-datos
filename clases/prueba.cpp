#include "Primitivas.cpp"
#include <iostream>

using namespace std;

void kill(Nodo **inicio) {
  Nodo *mover, *anterior = NULL;
  if (listaVacia(*inicio))
    cout << "Lista esta vacia" << endl;
  else {
    mover = *inicio;
    while (mover != NULL) {
      mostrarLista(mover);
      anterior = mover;
      mover = mover->prox;
      delete anterior;
    }
    *inicio = NULL;
  }
}

int main() {
  Nodo *primero = NULL;
  primero = crearNodo(1);
  insertarPrincipio(&primero, 2);
  insertarPrincipio(&primero, 3);
  insertarPrincipio(&primero, 4);
  mostrarLista(primero);
  kill(&primero);
  mostrarLista(primero);
  return 0;
}
