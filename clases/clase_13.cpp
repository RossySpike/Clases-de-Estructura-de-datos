#include "PrimitivasColas.cpp"
// Quedan 4 temas colas, tablas hash, arboles y grafo

// Existen 2 colas en un supermercado donde los clientes se forman para comprar.
// Primero seleccionan la cola con menos clientes, pero en caso de que tengan el
// mismo nro de clientes Se elegira que pueda atender a los clientes mas rapido
// (es decir aquella cola cuyo tiempo de procesamiento total de todos los
// clientes sea la menor)
struct Cliente {
  int idcli;
  int tiempo;
  Cliente *prox;
};
// AQUI VA UNA FUNCION
void mostrarCola(Cliente *col) {
  Cliente *auxiliar = col;
  while (!ColaVacia(auxiliar)) {
    auxiliar = PrimeroCola(col);
    cout << "Id Cliente: " << auxiliar->idcli << endl;
    cout << "Tiempo estimado: " << auxiliar->tiempo << endl;
    Desencolar(&auxiliar);
  }
}

int CantidadClientes(Cliente *col) {
  int cantidad = 0;
  while (!ColaVacia(col)) {
    cantidad++;
    Desencolar(&col);
  }
  return cantidad;
}
int CantidadTiempo(Cliente *col) {
  int TiempoTotal = 0;
  Cliente *auxiliar = NULL;
  while (!ColaVacia(col)) {
    auxiliar = PrimeroCola(col);
    TiempoTotal += auxiliar->tiempo;
    Desencolar(&col);
  }
  return TiempoTotal;
}

void formarEnColasMasCorta(Cliente **col1, Cliente **col2) {
  if (ColaVacia(*col1))
    Encolar(*&col1);
  else if (ColaVacia(*col2))
    Encolar(*&col2);
  else {
    int tamcola1 = CantidadClientes(*col1);
    int tamcola2 = CantidadClientes(*col2);
    if (tamcola1 < tamcola2)
      Encolar(*&col1);
    else if (tamcola2 < tamcola1)
      Encolar(*&col2);
    else {
      int TiempoTotal1 = CantidadTiempo(*col1);
      int TiempoTotal2 = CantidadTiempo(*col2);
      if (TiempoTotal1 <= TiempoTotal2)
        Encolar(*&col1);
      else
        Encolar(*&col2);
    }
  }
}
