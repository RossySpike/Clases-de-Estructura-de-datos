// Listas Doblemente enlazadas.
/*
Contiene un puntero hacia el nodo siguiente y el anterior
El ultimo nodo en su apuntador anterior apunta hacia NULL
*/
#include <iostream>
using namespace std;
struct Nodo {
  int dato;
  Nodo *previo;
  Nodo *prox;
};

bool listaVacia(Nodo *inicio) { return inicio == nullptr; }

Nodo *crearNodo(int dato) {
  Nodo *nuevoNodo = new Nodo;
  nuevoNodo->dato = dato;
  nuevoNodo->previo = nullptr;
  nuevoNodo->prox = nullptr;
  return nuevoNodo;
}

void insertarInicio(int valor, Nodo **inicio) {
  Nodo *nuevoNodo = crearNodo(valor);
  nuevoNodo->prox = *inicio;
  if (*inicio != nullptr) {
    (*inicio)->previo = nuevoNodo; // El parentesis es necesario.
  }
  *inicio = nuevoNodo;
}

void insertarUltimo(Nodo **inicio, int valor) {
  Nodo *nuevo = crearNodo(valor);
  if (listaVacia(*inicio))
    cout << "Lista esta vacia" << endl;
  else {
    Nodo *actual = *inicio;
    while (actual->prox != nullptr) {
      actual = actual->prox;
    }
    actual->prox = nuevo;
    actual->prox->previo = actual;
  }
}

void eliminar(Nodo **inicio, int dato) {
  Nodo *actual = *inicio;
  if (listaVacia(*inicio))
    cout << "Lista esta vacia" << endl;
  else {
    while (actual != nullptr && actual->dato != dato) {
      actual = actual->prox;
    }
    if (actual == nullptr)
      cout << "El elemento no se encuentra en la lista" << endl;
    else {
      if (actual->previo == nullptr) {
        *inicio = actual->prox;
        (*inicio)->previo = nullptr;
      } else {
        if (actual->prox == nullptr)
          actual->previo->prox = nullptr;
        else {
          actual->previo->prox = actual->prox;
          actual->prox->previo = actual->previo;
        }
      }
      delete actual;
    }
  }
}

void mostrarlista(Nodo *inicio) {
  if (!listaVacia(inicio)) {
    Nodo *actual = inicio;
    while (actual != nullptr) {
      cout << actual->dato << " -> ";
      actual = actual->prox;
    }
    cout << "nullptr" << endl;
  } else {
    cout << "Lista esta vacia" << endl;
  }
}

void moverizq(Nodo *inicio) {
  Nodo *actual;
  actual = inicio;
  while (actual->prox != nullptr) {
    actual = actual->prox;
  }
  while (actual != nullptr) {
    cout << actual->dato << " -> ";
    actual = actual->previo;
  }
  cout << "Inicio" << endl;
}

Nodo *mezclarAlternado(Nodo *inicio1, Nodo *inicio2) {
  if (listaVacia(inicio1))
    return inicio2;
  if (listaVacia(inicio2))
    return inicio1;
  Nodo *listamezclada = nullptr;
  Nodo *actual1 = inicio1;
  Nodo *actual2 = inicio2;
  while (actual1 != nullptr && actual2 != nullptr) {
    insertarUltimo(&listamezclada, actual1->dato);
    actual1 = actual1->prox;
    insertarUltimo(&listamezclada, actual2->dato);
    actual2 = actual2->prox;
  }
  while (actual1 != nullptr) {
    insertarUltimo(&listamezclada, actual1->dato);
    actual1 = actual1->prox;
  }

  while (actual2 != nullptr) {
    insertarUltimo(&listamezclada, actual2->dato);
    actual2 = actual2->prox;
  }
  return listamezclada;
}

int pedir_valor() {
  int valor;
  cout << "Indica valor: ";
  cin >> valor;
  return valor;
}
