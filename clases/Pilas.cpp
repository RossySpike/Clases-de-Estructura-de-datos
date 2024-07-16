/*Pilas (Stack): Una pila es una estructura de datos de entradas ordenadas
tales que solo se pueden se pueden introducir y eliminar por un
extremo, llamado cima.
Tambien son llamadas estructuras IFO (Input first Output)
porque el ultimo elemento en entrar es el primero en salir

Operaciones:
Insertar (push): Agrega un elemento a la cima de la pila y operacion
Quitar (pop): Elimina o saca un elemento de la pila

Cada elemento de una pila tiene 2 valores, el dato que almacena (int, double char...)
y un puntero hacia el elemento que le sigue, Caso de ser el primer
elemento el puntero es vacia (NULL) ej:

struct Nodo{
    int dato;
    Nodo *siguiente;
};
*/
#include <iostream>

struct Node{
    int Data;
    Node *next;
};

void pushStack(Node *&Stack, int n);
void popStack(Node *&Stack, int &n);

int main (){
    Node *Stack = NULL;

    int n1 = 2;
    for (int i = 0; i < 2; i++){
        pushStack(Stack, n1);
    }

    popStack(Stack, n1);

    return 0;
}

void pushStack(Node *&Stack, int n){
    Node *new_Node = new Node();
    new_Node -> Data = n;
    new_Node -> next = Stack;
    Stack = new_Node;

    std:: cout << "Valor ["<<n<<"] ingresado a la pila" << std:: endl;
}

void popStack(Node *&Stack, int &n){
    Node *aux = Stack;
    n = aux -> Data;
    Stack = aux -> next;
    delete aux;
}