#include <iostream>
using namespace std;
// Operaciones básicas de Colas, faltan validaciones
// Elaborado por Lia Mendoza

struct Cola {
  int dato;
  Cola *prox;
};

Cola *crearCola(int valor) {
  Cola *nuevo = new Cola;
  nuevo->dato = valor;
  nuevo->prox = NULL;
  return nuevo;
}

bool ColaVacia(Cola *col) { return col == NULL; }

Cola *PrimeroCola(Cola *col) {
  if (!ColaVacia(col))
    return col;
  else
    return nullptr;
}

void Encolar(Cola **col, int valor) {
  Cola *nuevo = crearCola(valor);

  if (ColaVacia(*col)) {
    *col = nuevo;
  } else {
    Cola *auxiliar = *col;
    while (auxiliar->prox != NULL) {
      auxiliar = auxiliar->prox;
    }
    auxiliar->prox = nuevo;
  }
}

void Desencolar(Cola **col) {
  if (!ColaVacia(*col))
    *col = (*col)->prox;
  else
    cout << "Cola vacia imposible desencolar " << endl;
}

// no es primitiva
void mostrarCola(Cola *col) {
  if (ColaVacia(col))
    cout << "La cola esta vacía " << endl;
  else {
    while (!ColaVacia(col)) {
      cout << PrimeroCola(col)->dato << "  ";
      Desencolar(&col);
    }
    cout << endl;
  }
}

// no es primitiva
void llenarCola(Cola **col) {
  int cantidad, i, valor;
  cout << "Indica cantidad de elementos a ser colocados en la Cola: ";
  cin >> cantidad;
  i = 0;
  while (i != cantidad) {
    cout << "Indica valor a colocar: ";
    cin >> valor;
    Encolar(*&col, valor);
    i++;
  }
}

// no es primitiva
Cola *crearCola() {

  Cola *cola = NULL;

  for (int i = 1; i < 11; i++) {
    Encolar(&cola, i);
  }
  return cola;
}
