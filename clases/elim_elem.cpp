#include "PrimitivasColas.cpp"
/*4) Implementar una función que elimine todas las apariciones de un valor
específico en una cola. Ejemplo: C1={3,22,11,45,33,3,2,1,2,3,4,5,88,77,99,3,10}
y Elemento= 3 Cola final= {22,11,45,33,2,1,2,4,5,88,77,99,10}*/
void elim_aparciones_elem(Cola **col, int elemento) {
  Cola *aux = NULL;
  while (*col != NULL) {
    if (PrimeroCola(*col)->dato == elemento)
      Desencolar(*&col);
    else {
      Encolar(&aux, PrimeroCola(*col)->dato);
      Desencolar(*&col);
    }
  }
  while (aux != NULL) {
    Encolar(*&col, PrimeroCola(aux)->dato);
    Desencolar(&aux);
  }
}

int main() {
  Cola *col = NULL;
  Encolar(&col, 3);

  Encolar(&col, 22);
  Encolar(&col, 11);

  Encolar(&col, 35);
  Encolar(&col, 33);

  Encolar(&col, 3);

  Encolar(&col, 3);
  Encolar(&col, 3);
  elim_aparciones_elem(&col, 3);
  mostrarCola(col);
  return 0;
}
