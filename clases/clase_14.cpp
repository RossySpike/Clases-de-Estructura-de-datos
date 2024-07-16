struct Cola {
  int idPaciente;
  int gravedad;
  int OrdenLlegada;
  Cola *prox;
};

Cola *CrearCola(int idPaciente, int gravedad, int OrdenLlegada) {
  Cola *nuevo = new Cola;
  nuevo->idPaciente = idPaciente;
  nuevo->gravedad = gravedad;
  nuevo->OrdenLlegada = OrdenLlegada;
  nuevo->prox = NULL;
  return nuevo;
}

void Encolar(Cola **col, int idPaciente, int gravedad, int OrdenLlegada) {
  Cola *nuevo = CrearCola(idPaciente, gravedad, OrdenLlegada);
  if (ColaVacia(*col))
    *col = nuevo;
  else {
    if (gravedad < (*col)->gravedad ||
        (gravedad == (*col)->gravedad && OrdenLlegada < (*col)->OrdenLlegada)) {
      nuevo->prox = *col;
      *col = nuevo;
    } else {
      Cola *aux = *col;
      while (aux->prox != NULL && (aux->prox->gravedad < gravedad ||
                                   (aux->prox->gravedad == gravedad &&
                                    aux->prox->OrdenLlegada < OrdenLlegada))) {
        aux = aux->prox;
      }

      nuevo->prox = aux->prox;
      aux->prox = nuevo;
    }
  }
}

void LlenarCola(Cola **col) {
  int cantidad, i, idpaciente, gravedad;
  static int OrdenLlegada = 1;
  std::cout << "Indica cantidad de pacientes a ser colocadas en la colar: ";
  std::cin >> cantidad;
  for (i = 0; i < cantidad; i++) {
    std::cout "Indica el ID del paciente: ";
    std::cin >> idpaciente;
    std::cout << "Indica la gravedad del paciente: ";
    std::cin >> gravedad;
    Encolar(col, idpaciente, gravedad, OrdenLlegada++);
  }
}

void AtenderPacientes(Cola **col) {
  std::cout << "Atendiendo pacientes...\n";
  while (!ColaVacia(*col)) {
    Cola *paciente = PrimeroCola(*col);
    std::cout << "Atendiendo paciente con ID: " << paciente->idPaciente << "\n";
    std::cout << "Gravedad: " << paciente->gravedad << "\n";
    std::cout << "Orden de llegada: " << paciente->OrdenLlegada << "\n";
    std::cout << "---------------------------\n";
    Desencolar(col);
  }
}

int main() {
  Cola *cola = nu;
  ;
  LlenarCola(&cola);
  AtenederPacientes(&cola);
  return 0;
