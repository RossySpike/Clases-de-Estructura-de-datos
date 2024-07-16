#include "clase_7.cpp"
int DER = 0;
int IZQ = 1;
// 1->2->2->10->77->2
bool compAscendente(Nodo *inicio, int direccion) {
  Nodo *actual = inicio;
  int valor = actual->dato;
  if (direccion == DER) {
    while (actual != nullptr) {
      if (actual->dato < valor)
        return false;
      actual = actual->prox;
    }
  }
  if (direccion == IZQ) {
    while (actual != nullptr) {
      if (actual->dato > valor)
        return false;
      actual = actual->prox;
    }
  }
  return true;
}

bool compDescendente(Nodo *final, int direccion) {
  Nodo *actual = final;
  int valor = actual->dato;
  if (direccion == DER) {
    while (actual != nullptr) {
      if (actual->dato > valor)
        return false;
      actual = actual->previo;
    }
  }
  if (direccion == IZQ) {
    while (actual != nullptr) {
      if (actual->dato < valor)
        return false;
      actual = actual->previo;
    }
  } // 1 -> 2 -> 3
  return true;
}

Nodo *obtUltimo(Nodo *inicio) {
  Nodo *actual = inicio;
  while (actual->prox != nullptr) {
    actual = actual->prox;
  }
  return actual;
}

void verificarOrden(Nodo *inicio) {
  Nodo *actual = inicio;
  Nodo *ultimo = obtUltimo(inicio);
  if (compAscendente(actual, IZQ) && compDescendente(ultimo, IZQ))
    cout << "La lista esta ordenada de forma Ascendente de izq a der" << endl;
  if (compAscendente(actual, DER) && compDescendente(ultimo, DER))
    cout << "La lista esta ordenada de forma Ascendente de der a izq" << endl;
  else {
    cout << "La lista no esta ordenada en ninguna direccion" << endl;
  }
}

int main() {
  cout << "De cuantos nodos quiere la lista" << endl;
  int valor = pedir_valor();
  int cont = 0;
  Nodo *primero = nullptr;
  while (cont != valor) {
    insertarInicio(pedir_valor(), &primero);
    cont++;
  }
  verificarOrden(primero);
  mostrarlista(primero);

  return 0;
}
