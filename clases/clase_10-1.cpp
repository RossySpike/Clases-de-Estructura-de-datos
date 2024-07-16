#include "primitivaspilas.cpp"
void intercambiarPilas(Pila **pila1, Pila **pila2) {
  Pila *aux = nullptr;
  while (!PilaVacia(*pila1)) {
    Apilar(&aux, Tope(*pila1)->dato);
    Desapilar(pila1);
  }
  while (!PilaVacia(*pila2)) {
    Apilar(pila1, Tope(*pila2)->dato);
    Desapilar(&aux);
  }
  while (!PilaVacia(aux)) {
    Apilar(pila2, Tope(aux)->dato);
    Desapilar(&aux);
  }
}
