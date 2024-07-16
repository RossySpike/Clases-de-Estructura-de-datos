#include "primitivas.cpp"

// Parte 1

Nodo *obtener_impares(Nodo *lista, int elementos) {
  Nodo *aux = lista;
  Nodo *lista_impar = NULL;
  if (elementos % 2 == 0) {
    while (aux != NULL) {
      if (aux->dato % 2 != 0) {
        insertarPrincipio(&lista_impar, aux->dato);
      }
      aux = aux->prox;
    }
  } else {
    while (aux != NULL) {
      if (elementos % 2 == 0 || aux->prox == NULL) {
        insertarPrincipio(&lista_impar, aux->dato);
      }
    }
  }
  return lista_impar;
}

Nodo *obtener_pares(Nodo *lista, int elementos) {
  Nodo *aux = lista;
  Nodo *lista_par = NULL;
  if (elementos % 2 == 0) {
    while (aux != NULL) {
      if (aux->dato % 2 == 0) {
        insertarPrincipio(&lista_par, aux->dato);
      }
      aux = aux->prox;
    }
  } else {
    while (aux != NULL) {
      if (elementos % 2 == 0 || aux->prox == NULL) {
        insertarPrincipio(&lista_par, aux->dato);
      }
    }
  }
  return lista_par;
}

void separar(Nodo *lista, Nodo **lista_par, Nodo **lista_impar, int elementos) {
  *lista_par = obtener_pares(lista, elementos);
  *lista_impar = obtener_impares(lista, elementos);
}

void EliminarApariciones(Nodo **inicio, int valor) {
  Nodo *aux = NULL;
  int cant = 0;
  aux = *inicio;
  while (aux != NULL) {
    if (aux->dato == valor) {
      eliminar(*&inicio, valor);
      cant++;
    }
    aux = aux->prox;
  }
  cout << "Total elementos eliminados: " << cant << endl;
}

void elim_iguales(Nodo **lista, Nodo *listap) {
  Nodo *aux = *lista;
  Nodo *aux2 = listap;
  while (aux2 != NULL) {
    EliminarApariciones(&*lista, aux2->dato);
    aux2 = aux2->prox;
  }
}

void rotar(Nodo **lista, int pasos, int elementos) {
  Nodo *primero = *lista;
  Nodo *actual = *lista;
  Nodo *swap;
  int i = 0;

  while (pasos > 0) {
    while (actual != NULL) {
      swap = actual;
      actual = actual->prox;
      swap->prox = actual;
    }
    primero = *lista;
    actual = *lista;
    pasos--;
  }
  mostrarLista(*lista);
}
// 1 1 2 2

int main() {
  Nodo *lista = NULL;
  Nodo *lista_impar = NULL;
  Nodo *lista_par = NULL;
  int elemen_list, i = 0, valor;
  cout << "Indica cuantos elementos va a tener la lista\n: ";
  cin >> elemen_list;
  cout << "Ingresa los valores:" << endl;
  while (i < elemen_list) {
    cout << i + 1 << ") ";
    valor = pedir_valor();
    insertarPrincipio(&lista, valor);
    i++;
  }
  separar(lista, &lista_par, &lista_impar, elemen_list);

  mostrarLista(lista);
  mostrarLista(lista_par);
  mostrarLista(lista_impar);

  cout << "Eliminando iguales en lista par..." << endl;

  elim_iguales(&lista_par, lista_par);
  mostrarLista(lista_par);
  cout << "Ingrese por cuantos pasos desea rotar la primera lista" << endl;
  valor = pedir_valor();
  rotar(&lista, valor, elemen_list);
  mostrarLista(lista);
  return 0;
}
