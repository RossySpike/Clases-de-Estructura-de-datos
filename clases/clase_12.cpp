// Colas  -> estructura FIFO, First in First out
#include <iostream>
struct Cola {
  int dato;
  Cola *prox;
};

Cola *Crearcola(int valor) {
  Cola *nuevo = new Cola;
  nuevo->dato = valor;
  nuevo->prox = nullptr;
  return nuevo;
}
bool ColaVacia(Cola *col) { return col == nullptr; }
void Desencolar(Cola **col) {
  if (!ColaVacia(*col))
    *col = (*col)->prox;
  else
    std::cout << "Cola vacia " << std::endl;
}

void Encolar(Cola **col, int valor) {
  Cola *nuevo = Crearcola(valor);
  if (ColaVacia(*col))
    *col = nuevo;
  else {
    Cola *Auxiliar = *col;
    while (Auxiliar->prox != nullptr) {
      Auxiliar = Auxiliar->prox;
    }
    Auxiliar->prox = nuevo;
  }
}

void mostrarCola(Cola *col) {
  if (ColaVacia(col))
    std::cout << "la cola esta vacia." << std::endl;
  else {
    while (!ColaVacia(col)) {
      std::cout << PrimeroCola(col)->dato << "->";
      Desencolar(&col);
    }
    std::cout << std::endl;
  }
}

void llenarCola(Cola **col, std::string mensaje) {
  int cantidad, i, valor;
  std::cout << "Indica cant de elem a ser colocados en la: " << mensaje
            << std::endl;
  std::cin >> cantidad;
  i = 0;
  while (i != cantidad) {
    std::cout << "indica el valor a colocar: ";
    std::cin >> valor;
    Encolar(*&col, valor);
    i++;
  }
}
void IntercalarColas(Cola *c1, Cola *c2, Cola **resultado) {
  while (!ColaVacia(c1) || !ColaVacia(c2)) {
    if (!ColaVacia(c1)) {
      Encolar(resultado, PrimeroCola(c1)->dato);
      Desencolar(&c1);
    }
    if (!ColaVacia(c2)) {
      Encolar(resultado, PrimeroCola(c2)->dato);
      Desencolar(&c2);
    }
  }
}

main() {
  Cola *cola1 = nullptr, *cola2 = nullptr, *resul = nullptr;
  llenarCola(&cola1, "cola 1: ");
  std::cout << "Contenido Cola 1: " << std::endl;
  mostrarCola(cola1);
  std::cout << "Contenido Cola 2: " << std::endl;
  mostrarCola(cola2);
  IntercalarColas(cola1, cola2, &resul);
  std::cout << "Contenido de la cola intercalada: " << std::endl;
  mostrarCola(resul);
}

Cola *MultiplicarElementos(Cola *c, int valor) {
  int numero;
  Cola *temp = nullptr;
  while (!ColaVacia(c)) {
    numero = PrimeroCola(c)->dato;
    Encolar(&temp, numero * valor);
    Desencolar(&c);
  }
  return temp;
}

main() {
  int valor = 0;
  Cola *cola = nullptr;
  llenarCola(&cola, "Cola original: ");
  std::cout << "Contenido de la cola original: " << std::endl;
  mostrarCola(cola);
  std::cout << "Indica el valor por el cual vas a multiplicar cada elemento: ";
  std::cin >> valor;
  Cola *resultado = MultiplicarElementos(cola, valor);
  std::cout << "Contenido de la cola multiplicado: " << std::endl;
  mostrarCola(resultado);
}

bool ExisteEnCola(Cola *c, int valor) {
  bool encontrado = false;
  while (!ColaVacia(c)) {
    if (PrimeroCola(c)->dato == valor)
      encontrado = true;
    Desencolar(&c);
  }
  return encontrado;
}

void EliminarRepetidos(Cola **c) {
  Cola *temp = nullptr;
  while (!ColaVacia(*c)) {
    int valor = PrimeroCola(*c)->dato;
    Desencolar(c);
    if (!ExisteEnCola(temp, valor))
      Encolar(&temp, valor);
  }
  while (!ColaVacia(temp)) {
    Encolar(c, PunteroCola(temp)->dato);
    Desencolar(&temp);
  }
}

main() {
  Cola *cola = nullptr;
  llenarCola(&cola, "Cola Original: ");
  std::cout << "Cantidad de l acola original: ";
  mostrarCola(cola);
  EliminarRepetidos(&cola);
  std::cout << "Contenido de la cola sin repeticiones: " << std::endl;
  mostrarCola(cola);
}
