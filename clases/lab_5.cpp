#include "primitivaspilas.cpp"
int CARTON = 0;
int DESECHABLES = 1;
int PORCELANA = 2;

int PlatosAFregar(Pila *pila) {
  int PlatosPorcelana = 0;
  while (pila != NULL) {
    if (pila->dato == PORCELANA)
      PlatosPorcelana++;
    Desapilar(&pila);
  }
  return PlatosPorcelana;
}

int main() {
  Pila *pila = crearPila(CARTON);
  Apilar(&pila, PORCELANA);
  Apilar(&pila, CARTON);
  Apilar(&pila, PORCELANA);
  Apilar(&pila, DESECHABLES);
  Apilar(&pila, CARTON);
  cout << "Cantidad de platos a fregar: " << PlatosAFregar(pila) << endl;
  return 0;
}
