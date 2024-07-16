// Supongamos que tenemos una impresora que imprime en una cola, cada trabajo
// tiene un tiempo de impresion estimado y una prioridad
// si hay varios trabajos con la misma prioridad se imprimen en orden de llegada
// implementa una cola de trabajo de impresion que permita

struct trabajo {
  int id;
  int tiempo;
  int prioridad;
  trabajo *prox;
};
trabajo *crearTrabajo() {
  trabajo *nuevo = new trabajo;
  nuevo->id = generar_tiempo_id(500, 900);
  nuevo->tiempo = generar_tiempo_id(5, 20);
  nuevo->prioridad = generar_tiempo_id(1, 3);
  nuevo->prox = NULL;
  return nuevo;
}

void encolar(Trabajo **col) {
  if (ColaVacia(*col))
    *col = crearTrabajo();
  else {
    trabajo *aux = *col;
    trabajo *anterior = NULL;
    while (actual != NULL && actual->prioridad ||
           actual->prioridad == nuevo->prioridad && actual->id < nuevo->id)){
        anterior = actual;
        actual = actual->prox;
      }
    if (anterior == NULL) {
      nuevo->prox = *col;
      *col = nuevo;
    } else {
      nuevo->prox = anterior->prox;
      anterior->prox = nuevo
    }
  }
}
