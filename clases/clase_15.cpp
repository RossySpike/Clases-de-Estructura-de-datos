#include <iostream>
// Arbol: es una estructura no lineal compuesta por nodos conectados entre si.
// Cada nodo es rama del Arbol, puede tener cero o mas "hijo" conectados a el
// Organizan la informacion de manera jerargica. Los arboles son utiles para:
// Busqueda, Ordenamiento, Almacenamiento de datos, Representacion de relaciones
// jerargicas
//
// Los algoritmos que estan en m7 son solo para arboles Binarios de busqueda
// (ABB) Arboles Binarios: Is un tipo especial de arbol en el que cada nodo
// puede tener como maximo dos hijos, denominados hijo izquierdo e hijo derecho
// Los arboles binarios de busqueda (ABB) son una sub-categoria de los arboles
// binarios en la que los valores de los nodos estan ordenandos de forma
// ascendente o descendente a medida que se recorren desde la raiz hasta las
// hojas
//
// Ilementos claves de un arbol binarios
//
//*Raiz-> el nodo superior del arbol, sin padres
//*Hojas-> Los nodos que no tienen hijos
//*Nivel -> la distancia de un nodo a la raiz
//*SubArbol-> un arbol formado por un nodo y todos sus descendientes
//*Padre->El nodo que esta conectado a un nodo hijo
//*Hermanos -> Los nodos que comparten el mismo padre
//
// Aplicaciones de los ABB
// Composicion de datos
// Busqueda de palabras en diccionarios
// prioridades (Se emplean para implementar estructuras de datos como colas de
// prioridad) Ivaluar expresiones aritmeticas
//
//

struct arbol {
  int dato;
  arbol *izq, *der;
};

arbol *crearArbol(int n) {
  arbol *nuevo = new arbol;
  nuevo->dato = n;
  nuevo->izq = nuevo->der = nullptr;
  return nuevo;
}

bool arbolVacio(arbol *arb) { return arb == nullptr; }

void insertarArbol(arbol **arb, int n) {
  if (arbolVacio(*arb)) {
    arbol *nuevo = crearArbol(n);
    *arb = nuevo;
  } else {
    int raiz = (*arb)->dato; // Se debe saber cuanto vale la raiz
    if (n < raiz)
      insertarArbol(&(*arb)->izq, n);
    else
      insertarArbol(&(*arb)->der, n);
  }
}

void mostrarArbol(arbol *arb, int nivel) {
  const int factor_escalar = 4; // para dejar espaciado
  if (!arbolVacio(arb)) {
    mostrarArbol(arb->der, nivel + 1);
    for (int i = 0; i < nivel * factor_escalar; i++) {
      std::cout << " ";
    }
    std::cout << arb->dato << std::endl;
    mostrarArbol(arb->izq, nivel + 1);
  }
}

bool buscarArbol(arbol *arb, int n) {
  if (arbolVacio(arb))
    return false;

  else {
    if (arb->dato == n)
      return true;
    else if (n < arb->dato)
      return buscarArbol(arb->izq, n);
    else
      return buscarArbol(arb->der, n);
  }
}

void recorridoInOrden(arbol *arb) { // IRD (Izquierda -> Raiz -> Derecha)
  if (arb == nullptr)
    return;
  recorridoInOrden(arb->izq);
  std::cout << arb->dato << "-";
  recorridoInOrden(arb->der);
}

void recorridoPreOrden(arbol *arb) { // RID
  if (arb == nullptr)
    return;
  std::cout << arb->dato << "-";
  recorridoPreOrden(arb->izq);
  recorridoPreOrden(arb->der);
}

void recorridoPostOrden(arbol *arb) { // IDR
  if (arb == nullptr)
    return;
  recorridoPostOrden(arb->izq);
  recorridoPostOrden(arb->der);
  std::cout << arb->dato << "-";
}

// Dado un arbol y un nivel contar todos los nodos que existen en ese nivel
int contarNodosNivel(arbol *arb, int nivel) {
  if (arb == nullptr)
    return 0;
  if (nivel == 0)
    return 1;
  return contarNodosNivel(arb->izq, nivel - 1) +
         contarNodosNivel(arb->der, nivel - 1);
}
