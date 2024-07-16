#include "primitivaspilas.cpp"
bool buscarEnPila(Pila *pila, int valor) {
  while (!PilaVacia(pila)) {
    if (Tope(pila)->dato == valor)
      return true;
    Desapilar(&pila);
  }
  return false;
}
void elimnarDuplicados(Pila **pila) {
  Pila *pilaAux = NULL;
  if (PilaVacia(*pila))
    return;
  while (!PilaVacia(*pila)) {
    int valor = Tope(*pila)->dato;
    Desapilar(pila);
    if (!buscarEnPila(pilaAux, valor))
      Apilar(&pilaAux, valor);
  }
  while (!PilaVacia(pilaAux)) {
    Apilar(pila, Tope(pilaAux)->dato);
    Desapilar(&pilaAux);
  }
}

Pila *mezclarPila(Pila *pila1, Pila *pila2) {
  Pila *pilamezclada = NULL;
  bool Alternar = true;
  while (!PilaVacia(pila1) || !PilaVacia(pila2)) {
    if (Alternar && !PilaVacia(pila1)) {
      Apilar(&pilamezclada, Tope(pila1)->dato);
      Desapilar(&pila1);
    } else {
      if (!PilaVacia(pila2)) {
        Apilar(&pilamezclada, Tope(pila2)->dato);
        Desapilar(&pila2);
      }
    }
    Alternar = !Alternar;
  }
  return pilamezclada;
}

int main() {
  Pila *PilaInicial = NULL;
  LlenarPila(&PilaInicial);
  std::cout << "Pila con duplicados: " << std::endl;
  mostrarPila(PilaInicial);
  elimnarDuplicados(&PilaInicial);
  std::cout << std::endl << "Pila sin duplicados: " << std::endl;
  mostrarPila(PilaInicial);
  return 0;
}
