#include "PrimitivasColas.cpp"
// 1) Desarrolla una función que divida una cola en dos colas, una con la
// primera mitad de los elementos y otra con la segunda mitad.

int obt_elem_cola(Cola *col) {
  int contador = 0;
  while (col != NULL) {
    Desencolar(&col);
    contador++;
  }
  return contador;
}

void div_cola(Cola *cola_orig, Cola **prim_mitad, Cola **seg_mitad) {
  int i;
  int tam_col = obt_elem_cola(cola_orig);
  for (i = 0; i < int(tam_col / 2); i++) {
    Encolar(*&prim_mitad, PrimeroCola(cola_orig)->dato);
    Desencolar(&cola_orig);
  }
  while (cola_orig != NULL) {

    Encolar(*&seg_mitad, PrimeroCola(cola_orig)->dato);
    Desencolar(&cola_orig);
  }
}

int main() {
  Cola *prim = NULL;
  Cola *seg = NULL;
  div_cola(crearCola(), &prim, &seg);
  mostrarCola(prim);
  mostrarCola(seg);
  return 0;
}
