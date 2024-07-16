// Ordenar una pila de forma ascendente
// LISTAS SIMPLEMENTE ENLAZADASSSSSSS AAAA AAAAAAAAA
#include "primitivaspilas.cpp"
void OrdenarPila(Pila **pila) {
  Pila *pilaAuxiliar = nullptr;
  while (!PilaVacia(*pila)) {
    int temp = Tope(*pila)->dato;
    Desapilar(pila);
    while (!PilaVacia(pilaAuxiliar) && Tope(pilaAuxiliar)->dato < temp) {
      Apilar(pila, Tope(pilaAuxiliar)->dato);
      Desapilar(pila);
    }
    Apilar(&pilaAuxiliar, temp);
  }
  Pila *pilaAux = nullptr;
  while (!PilaVacia(pilaAuxiliar)) {
    Apilar(&pilaAux, Tope(pilaAuxiliar)->dato);
    Desapilar(&pilaAuxiliar);
  }
  while (!PilaVacia(pilaAux)) {
    Apilar(pila, Tope(pilaAux)->dato);
    Desapilar(&pilaAux);
  }
}

void mostrarPilarRecursiva(Pila *pila) {
  if (!PilaVacia(pila)) {
    cout << Tope(pila)->dato << " ";
    Desapilar(&pila);
    mostrarPilarRecursiva(pila);
  }
}

void invertirPilaIterativoCOPILOT(Pila **pila) {
  Pila *pilaAux = nullptr;
  while (!PilaVacia(*pila)) {
    Apilar(&pilaAux, Tope(*pila)->dato);
    Desapilar(pila);
  }
  while (!PilaVacia(pilaAux)) {
    Apilar(pila, Tope(pilaAux)->dato);
    Desapilar(&pilaAux);
  }
}

void InvertirPilaItera(Pila **pila) {
  Pila *pilaAux1 = nullptr;
  Pila *pilaAux2 = nullptr;
  while (!PilaVacia(*pila)) {
    Apilar(&pilaAux1, Tope(*pila)->dato);
    Desapilar(pila);
  }
  while (!PilaVacia(pilaAux1)) {
    Apilar(&pilaAux2, Tope(pilaAux1)->dato);
    Desapilar(&pilaAux1);
  }
  while (!PilaVacia(pilaAux2)) {
    Apilar(*&pila, Tope(pilaAux2)->dato);
    Desapilar(&pilaAux2);
  }
}

void insertarAlfondo(Pila **pila, int valor) {
  if (PilaVacia(*pila)) {
    Apilar(*&pila, valor);
  } else {
    int dat1 = Tope(*pila)->dato;
    Desapilar(*&pila);
    insertarAlfondo(*&pila, valor);
    Apilar(*&pila, dat1);
  }
}

void invertirPilaRecursiva(Pila **pila) {
  if (!PilaVacia(*pila)) {
    int dat2 = Tope(*pila)->dato;
    Desapilar(*&pila);
    invertirPilaRecursiva(pila);
    insertarAlfondo(pila, dat2);
  }
}

void mostrarPilaRecu(Pila *pila) {
  if (!PilaVacia(pila)) {
    cout << Tope(pila)->dato << " ";
    Desapilar(&pila);
    mostrarPilaRecu(pila);
  }
}
