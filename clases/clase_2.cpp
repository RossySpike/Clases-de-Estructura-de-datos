/*Por valor y referencia
Valor, obtiene el valor que esta almacenado en la memoria
Referencia, obtiene la direccion de memoria de la variable*/
#include <iostream>

using namespace std;

// c parametro por referencia, a y b por valor
void suma(int a, int b, int *c) { *c = a + b; }

int main() {
  int x, y, z;

  cout << "Indica el primer valor: ";
  cin >> x;

  cout << "Indica el segundo valor: ";
  cin >> y;

  z = 0;

  suma(x, y, &z);

  cout << "La suma entre ambos nros es: " << z << endl;

  return 0;
}
