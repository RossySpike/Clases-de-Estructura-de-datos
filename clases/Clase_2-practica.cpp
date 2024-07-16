#include <iostream>

using namespace std;

int main (){
    int *p, *q, valor = 54; /*Mejor en minusculas xq es buena practica usar mayusculas en constantes y no variables
    Ademas, se tiene que declarar el tipo de dato de la varible valor, en este caso int*/
    //2)p = 54 no se le puede asignar a un puntero (*) un valor int
    q = &valor; //3) se enlaza el puntero q a la direccion de la variable valor 
    //*p = *q; //4)
    //5)p = &q; tendria que ser p = q xq como es un puntero al no agregarle * te indica su ubic de memoria
    cout << *&q << endl; //6)se imprime la ubic en memoria
    cout << &*q << endl; //7)se imprime la ubic en memoria
    p = q; //8)se asigna al puntero p la direccion de q que a su vez contiene a la variable valor
    cout << p << "\n" << *p;//9) << **p << &&p; no sirve
    //10) p = valor; Asi no se le puede asignar un valor a un ptr


    return 0;
}