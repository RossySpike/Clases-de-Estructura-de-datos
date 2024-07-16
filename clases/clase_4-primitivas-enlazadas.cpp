// Si tiene P son primitivas basicas, se pueden llamar en el parcial sin
// necesidad de escribirlas.

#include <iostream>

using namespace std;

struct Nodo {
  int dato;
  Nodo *prox;
};
// P
Nodo *CrearNodo(int valor) {
  Nodo *nuevo = new Nodo;
  nuevo->dato = valor;
  nuevo->prox = nullptr;

  return nuevo;
}
// P
bool ListaVacia(Nodo *inicio) { return inicio == nullptr; }

void mostrarlista(Nodo *inicio) {
  Nodo *mover;
  if (!ListaVacia(inicio)) {
    mover = inicio;
    while (mover != nullptr) {
      cout << mover->dato << " -> ";
      mover = mover->prox;
    }
    cout << "nullptr" << endl;
  } else
    cout << "Lista vacia" << endl;
}
// P
// **inicio lo pasa por referencia.
void InsertarPrimero(Nodo **inicio, int valor) {
  Nodo *nuevo = CrearNodo(valor);
  nuevo->prox = *inicio;
  *inicio = nuevo;
}
// P
void InsertarUltimo(Nodo **inicio, int valor) {
  Nodo *nuevo = CrearNodo(valor);
  if (ListaVacia(*inicio))
    *inicio = nuevo;
  else {
    Nodo *Auxiliar = *inicio;
    while (Auxiliar->prox == nullptr) {
      Auxiliar = Auxiliar->prox;
    }
    Auxiliar->prox = nuevo;
  }
}
void BuscarElemento(Nodo *inicio, int valor) {
  Nodo *aux = inicio;
  bool encontrado = false;
  if (ListaVacia((inicio)))
    cout << "Lista vacia" << endl;
  else {
    while (aux != nullptr && encontrado == false) {
      if (aux->dato == valor) {
        cout << "El elemento: [" << aux->dato << "] fue encontrado" << endl;
        encontrado = true;
      } else {
        aux = aux->prox;
      }
      if (encontrado == false)
        cout << "Valor no encontrado" << endl;
    }
  }
}

void eliminar(Nodo **inicio, int valor) {
  Nodo *mover, *anterior = nullptr;

  if (ListaVacia(*inicio))
    cout << "Lista esta vacia imposible eliminar" << endl;
  else {
    mover = *inicio;
    while (mover != nullptr && mover->dato != valor) {
      anterior = mover;
      mover = mover->prox;
    }
    if (mover == nullptr)
      cout << "El elemento no se encuentra en la lista" << endl;
    else {
      if (mover == *inicio)
        *inicio = (*inicio)->prox;
      else
        anterior->prox = mover->prox;
      delete mover;
    }
  }
}
int main() { return 0; }
