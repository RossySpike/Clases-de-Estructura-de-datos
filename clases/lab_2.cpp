#include "primitivas.cpp"
#include <cstddef>
#include <iostream>

Nodo *buscarelemento(Nodo *inicio, int valor) {
  Nodo *aux = inicio;
  bool encontrado = false;
  if (listaVacia(inicio))
    cout << "Lista vacia" << endl;
  else {
    while (aux != NULL && encontrado == false) {
      if (aux->dato == valor) {
        cout << "El dato " << valor << " fue encontrado con exito" << endl;
        return aux;
      } else
        aux = aux->prox;
    }
  }
  cout << "Valor no encontrado en la lista " << endl;
  return NULL;
}

void borrarElementos(Nodo **inicio, int valor) {
  Nodo *aux = *inicio;
  Nodo *aux2;
  while (aux != NULL) {
    aux2 = aux;
    if (aux->dato == valor) {
      if (aux->prox != NULL) {
        aux2->prox = aux->prox;
        delete aux;
        aux = aux2;
      } else {
        delete aux;
        aux2->prox = NULL;
      }
    }
    aux = aux->prox;
  }
}

int buscarRepetidos(Nodo *inicio, int valor) {
  int repetidos = 0;
  Nodo *aux = inicio;
  while (aux != NULL) {
    if (aux->dato == valor) {
      repetidos++;
    }
    aux = aux->prox;
  }
  return repetidos;
}

float PorcentajeRepeticiones(int repeticiones, int cant_elem) {
  return float(float(repeticiones) / cant_elem) * 100;
}

int main() {
  int cant_nodos, valor;
  int i = 0;
  Nodo *primero = NULL;
  cout << "Indique cuantos nodos quiere agregar\n:";
  cin >> cant_nodos;
  while (i < cant_nodos) {
    cout << "Nodo nro " << i + 1 << endl;
    insertarUltimo(&primero, pedir_valor());
    i++;
  }
  cout << "Indique de que nro quiere calcular el % apariciones" << endl;
  valor = pedir_valor();
  cout << "El porcentaje es de: "
       << PorcentajeRepeticiones(buscarRepetidos(primero, valor), cant_nodos)
       << "%" << endl;

  cout << "Indique el valor que quiere borrar" << endl;
  valor = pedir_valor();
  borrarElementos(&primero, valor);
  mostrarLista(primero);
  return 0;
}
