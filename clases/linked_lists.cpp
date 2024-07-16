/*Una list enlazada consta de un nro de nodos con dos componentes
(campos), un enlace al sgte nodo de la list y un valor, que puede ser de
cualquier tipo Tipos:
1. lists simplemente enlazadas: cada nodo contiene un unico enlace que conecta
ese nodo al sgte nodo, es eficiente en recorridos directos (adelante ->)
2.lists doblemente enlazadas:  cada nodo contiene dos enlaces, su predecedor y
sucesor, es eficiente en recorridos directos e inversos (<- atras)
3. lists circular simplemente enlazada: el ultimo elemento se enlaza con el
primer elemento, de tal modo que puede ser recorrida de forma circular
4. list circular  doblemente enlazada: el primer elemento esta enlazado con el
ultimo y viceversa, de tal modo que se puede recorrer de forma circular hacia
adelante y hacia atras*/

#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

// Para agregar un elemento a una lista
void insert_list(Node *&list, int n) {
  Node *new_node = new Node;
  new_node->data = n;

  Node *aux1 = list;
  Node *aux2;

  while ((aux1 != nullptr) && (aux1->data < n)) {
    aux2 = aux1;
    aux1 = aux1->next;
  }

  if (list == aux1) {
    list = new_node;
  } else {
    aux2->next = new_node;
  }

  new_node->next = aux1;

  cout << "[" << n << "] ingresado exitosamende" << endl;
}

// Mostrar lista
void print_list(Node *list) {
  Node *current = new Node;
  current = list;

  while (current != nullptr) {
    cout << "[" << current->data << "] -> ";

    current = current->next;
  }
  cout << "NULL" << endl;
}

// Buscar elemento
void search_element(Node *list, int n) {
  Node *current = new Node;
  current = list;

  while (current != nullptr) {

    if (current->data == n) {
      cout << "El elemento [" << n << "] esta en la lista" << endl;
      break;
    }

    current = current->next;
  }
  if (current == nullptr) {
    cout << "El elemento [" << n << "] no esta en la lista" << endl;
  }
}

// Eliminar un elemento de una lista
void pop_element(Node *&list, int element) {
  Node *current = list;
  Node *prev;

  while (current != nullptr) {
    if (current->data == element) {
      prev->next = current->next;
      delete current;
      break;
    }
    prev = current;
    current = current->next;
  }
}

int main() {
  Node *list = nullptr;
  int num;

  for (int i = 0; i <= 3; i++) {
    cout << "Ingresa el dato\n: ";
    cin >> num;

    insert_list(list, num);
  };
  print_list(list);

  cout << "Que nro deseas buscar?\n: ";
  cin >> num;

  search_element(list, num);

  cout << "Que nro deseas borrar?\n: ";
  cin >> num;

  pop_element(list, num);

  print_list(list);

  return 0;
}
