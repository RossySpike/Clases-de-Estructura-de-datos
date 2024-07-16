#include "Primitivas.cpp"
#include <future>
struct Materias {
  char nombre;
  int horas;
  Materias *proxMate;
};

struct Estudiante {
  int cedula;
  char nombre;
  int semestre;
  Estudiante *proxEst;
  Materias *listaMate;
};

Estudiante *crearEstudiante(int ced, char nombre, int sem) {
  Estudiante *estud = new Estudiante;
  estud->cedula = ced;
  estud->nombre = nombre;
  estud->semestre = sem;
  estud->proxEst = nullptr;
  estud->listaMate = nullptr;
  return estud;
}

Materias *crearMate(char nombre, int tiempo) {
  Materias *mate = new Materias;
  mate->nombre = nombre;
  mate->horas = tiempo;
  mate->proxMate = nullptr;
  return mate;
}

void insertarUltimoEst(Estudiante **listaEstud, int ced, char nom, int sem) {
  Estudiante *nuevoEst = crearEstudiante(ced, nom, sem);
  if (*listaEstud == nullptr)
    *listaEstud = nuevoEst;
  else {
    Estudiante *auxiliar = *listaEstud;
    while (auxiliar->proxEst != nullptr) {
      auxiliar = auxiliar->proxEst;
    }
    auxiliar->proxEst = nuevoEst;
  }
}

void insertarUltimoMate(Materias **listaMate, char nom, int horas) {
  Materias *nuevaMate = crearMate(nom, horas);
  if (*listaMate == nullptr)
    *listaMate = nuevaMate;
  else {
    Materias *auxiliar = *listaMate;
    while (auxiliar->proxMate != nullptr) {
      auxiliar = auxiliar->proxMate;
    }
    auxiliar->proxMate = nuevaMate;
  }
}

Estudiante *buscar(Estudiante *listaEstud, int ced) {
  Estudiante *aux = listaEstud;
  bool encontrado = false;
  if (listaEstud == nullptr) {
    return nullptr;
  } else {
    while (aux != nullptr && encontrado == false) {
      if (aux->cedula == ced)
        encontrado = true;
      else {
        aux = aux->proxEst;
      }
    }
  }
  return aux;
}
// LA PROFE EN CLASE LO HIZO DE OTRA FORMA (FOTOS TLF)
void agregarMataEst(Estudiante **listaEstud, int ced, int horas, int nom) {
  Estudiante *aux = buscar(*listaEstud, ced);
  if (aux == nullptr)
    return;
  else {
    insertarUltimoMate(&aux->listaMate, nom, horas);
  }
}
void *EliminarEstudiante(Estudiante **listaEstud, int ced) {
  Estudiante *mover, *anterior = nullptr;
  Materias *borrarMate = nullptr;
  if (*listaEstud == nullptr)
    cout << "No se encuentra el estudiante perra " << endl;
  else {
    mover = *listaEstud;
    while (mover != nullptr && mover->cedula != ced) {
      anterior = mover;
      mover = mover->proxEst;
    }
    if (mover == nullptr)
      cout << "El estudiante no esta inscrito" << endl;
    else {
      borrarMate = mover->listaMate;
      if (mover == *listaEstud)
        *listaEstud = (*listaEstud)->proxEst;
      else
        anterior->proxEst = mover->proxEst;
      if (borrarMate != nullptr) {
        Materias *aux = borrarMate;
        while (aux != nullptr) {
          borrarMate = aux->proxMate;
          delete aux;
          aux = borrarMate;
        }
      }
      delete mover;
    }
  }
}
