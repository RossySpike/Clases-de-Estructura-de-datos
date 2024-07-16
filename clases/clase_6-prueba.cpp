#include "clase_6.cpp"

int main() {
  Nodo *primero = NULL;
  int valor = 0;
  LlenarLista(&primero);
  cout << "Indica valor a ser eliminado\n";
  cin >> valor;
  cout << "Lista Original";
  mostrarLista(primero);
  elimrecu(&primero, valor);
  cout << "Lista Modificada" << endl;
  mostrarLista(primero);
  return 0;
}
