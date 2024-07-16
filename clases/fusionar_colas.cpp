#include "PrimitivasColas.cpp"
/*2) Dadas dos colas, elabora un procedimiento o función que permita fusionar
dichas colas a partir de un elemento inicial y otro elemento final de la primera
cola (validar que existan) desde la mitad de la segunda cola. Ejemplo: Cola1 =
{1,2,3,4,5,6,7,8,9,10} Elemento inicial = 5, Elemento final=9 Cola2 =
{11,22,33,44,55,66} Cola fusionada= {11,22,33,5,6,7,8,9,44,55,66}*/
bool elem_existe(Cola *col, int elem) {
  while (col != NULL) {
    if (PrimeroCola(col)->dato == elem)
      return true;
    Desencolar(&col);
  }
  return false;
}

int tam_cola(Cola *col) {
  int contador = 0;
  while (col != NULL) {
    Desencolar(&col);
    contador++;
  }
  return contador;
}

Cola *
fusionar_en_mitad(Cola *col1, Cola *col2, int desde,
                  int hasta) { // La cola a tomar en cuenta el rango es col1
  if (!elem_existe(col1, desde) && !elem_existe(col1, hasta))
    return NULL;
  Cola *fusion = NULL;
  for (int i = 0; i < tam_cola(col2); i++) {
    Encolar(&fusion, PrimeroCola(col2)->dato);
    Desencolar(&col2);
  }
  for (int i = 0; i < desde - 1; i++) {
    Desencolar(&col1);
  }
  for (int i = desde; i < hasta + 1; i++) {
    Encolar(&fusion, PrimeroCola(col1)->dato);
    Desencolar(&col1);
  }
  while (col2 != NULL) {

    Encolar(&fusion, PrimeroCola(col2)->dato);
    Desencolar(&col2);
  }
  return fusion;
}

int main() {
  Cola *col2 = NULL;
  Encolar(&col2, 11);
  Encolar(&col2, 22);
  Encolar(&col2, 33);
  Encolar(&col2, 44);
  Encolar(&col2, 55);
  Encolar(&col2, 66);
  mostrarCola(fusionar_en_mitad(crearCola(), col2, 5, 9));
  return 0;
}
