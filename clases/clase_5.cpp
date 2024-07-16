/*Dadas 2 listas contar los elementos comunes entre las mismas
Lista1
[1]->[4]->[55]->[3]
Lista2
[4]->[1]->[1]->[100]->[20]

Tarea: modfificar programa para el caso que aparezcan repetidos en la 1era
lista*/
#include "primitivas.cpp"
void ContarComunes(Nodo *inicio, Nodo *inicio2) {
  Nodo *lista1 = inicio;  // 4 4 2 1
  Nodo *lista2 = inicio2; // 3 2 4
  int contador = 0;
  bool salir;
  if (listaVacia(inicio) || listaVacia(inicio2))
    cout << "Una de las listas es vacia";
  else {
    while (lista1 != NULL) {
      salir = false;
      lista2 = inicio2;
      while (lista2 != NULL && salir == false) {
        if (lista1->dato == lista2->dato) {
          contador++;
          salir = true;
        }
        lista2 = lista2->prox;
      }
      lista1 = lista1->prox;
    }
    cout << "Total = " << contador << endl;
  }
}
Nodo *buscarAnterior(Nodo *inicio, int valor) {
  Nodo *aux = inicio;
  while (aux->dato != valor && aux == NULL) {
    aux = aux->prox;
  }
  return aux;
}
// funcion modificada
void Contarcomunes(Nodo *inicio, Nodo *inicio2) {
  Nodo *lista1 = inicio;  // 4 4 2 1 5 5
  Nodo *lista2 = inicio2; // 3 2 4 4
  Nodo *aux;
  int contador = 0;
  int comparacion = -1;
  bool salir = false;
  if (listaVacia(inicio) || listaVacia(inicio2))
    cout << "Una de las listas es vacia";
  else {
    while (lista1 != NULL) {
      lista2 = inicio2;
      salir = false;
      while (lista2 != NULL && salir == false) {
        if (lista1->dato == lista2->dato) {
          contador++;
          salir = true;
        }
        lista2 = lista2->prox;
      }
      lista1 = lista1->prox;
    }
    lista1 = inicio;
    while (lista1 != NULL) {
      lista2 = lista1;
      while (lista2 != NULL) {
        if (lista2->dato == lista1->dato && comparacion != 1) {
          comparacion++;
        }
        lista2 = lista2->prox;
      }
      if (comparacion == 1)
        contador++;
      comparacion = -1;
      while (buscarAnterior(inicio, lista1->dato)->dato == lista1->dato) {
        lista1 = lista1->prox;
      }
    }
    cout << "Total = " << contador << endl;
  }
}

int main() {
  int contador = 0;
  Nodo *lista1;
  Nodo *lista2;
  int *p = &contador;
  cout << "Lista 1" << endl;
  lista1 = crearNodo(0);
  insertarPrincipio(&lista1, 4);
  insertarPrincipio(&lista1, 4);
  insertarPrincipio(&lista1, 3);

  cout << "pre" << endl;

  lista2 = crearNodo(4);

  Contarcomunes(lista1, lista2);
  return 0;
}
