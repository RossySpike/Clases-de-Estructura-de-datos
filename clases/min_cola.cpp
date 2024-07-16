#include "PrimitivasColas.cpp"
// 3) Dada una cola determinar el valor mínimo de la cola sin perder la cola
// original.
int min_elem(Cola *col) {
  int menor = PrimeroCola(col)->dato;
  while (col != NULL) {
    if (PrimeroCola(col)->dato < menor)
      menor = PrimeroCola(col)->dato;
    Desencolar(&col);
  }
  return menor;
}
int main() {
  cout << min_elem(crearCola()) << endl;
  return 0;
}
