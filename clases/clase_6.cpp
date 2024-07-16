#include "Primitivas.cpp"

void LlenarLista(Nodo **inicio) {
  int cantidad, i = 1, valor;
  cout << "Indica la cantidad de nodos a ser colocados\n: ";
  cin >> cantidad;
  while (i <= cantidad) {
    cout << "Indica valor\n: ";
    cin >> valor;
    insertarUltimo(*&inicio, valor);
    i++;
  }
}

void EliminarApariciones(Nodo **inicio, int valor) {
  Nodo *aux = *inicio;
  int cant = 0;
  while (aux != NULL) {
    if (aux->dato == valor) {
      eliminar(*&inicio, valor);
      cant++;
      aux = *inicio;
    }
    if (aux->prox != NULL || aux != NULL) {
      aux = aux->prox;
    } else
      break;
  }
  cout << "Total elementos eliminados: " << cant << endl;
}

void elimrecu(Nodo **primero, int valor) {
  Nodo *aux = *primero;
  if (aux->prox != NULL) {
    eliminar(&aux, valor);
    elimrecu(&aux->prox, valor);
  } else if (aux->dato == valor) {
    eliminar(&aux, valor);
  }
}

int ContarElementos(int valor, Nodo *inicio) {
  int contador = 0;
  Nodo *aux = inicio;
  while (aux != nullptr) {
    if (aux->dato == valor)
      contador++;
    aux = aux->prox;
  }
  return contador;
}

int ContarComunes(Nodo **inicio, Nodo **inicio2) {
  Nodo *lista1 = *inicio;
  Nodo *lista2 = *inicio2;
  int cont = 0;
  if (!listaVacia(lista1) && !listaVacia(lista2)) {
    while (lista1 != nullptr) {
      Nodo *temp = lista2;
      bool encontrado = false;
      while (temp != nullptr && !encontrado) {
        if (lista1->dato == temp->dato) {
          encontrado = true;
          cont++;
          while (ContarElementos(temp->dato, *inicio2) > 0) {
            eliminar(&*inicio2, temp->dato);
          }
        }
        temp = temp->prox;
      }
      if (encontrado) {
        while (ContarElementos(lista1->dato, *inicio) > 0) {
          eliminar(&(*inicio), lista1->dato);
        }
      }
      lista1 = lista1->prox;
    }
  }
  return cont;
}
