#include <iostream>
//las variables globales siempre ocupan espacio en memoria mientras se esye ejecutando el programa
//la memoria dinamica se libera una vez acaba la funcion
using namespace std;

void operacion(float *x, float *y){
    *x = *x * 2 + 3;
    *y = *y * 1.5 + 2;
}

void imprimir(float *x, float *y){
    cout << "Datos x = " << *x << ", y = " << *y << endl;
}

float suma (float *x, float *y){
    return *x + *y;
}

float resta (float *x, float *y){
    return *x - *y;
}

int main (){
    float x = 1.9 , y = 1.1;
    float *ptr_x = &x;// dir de memoria de x
    float *ptr_y = &y;// dir de memoria de y

    operacion(ptr_x, ptr_y);
    //x = 1.9 * 2 + 3 = 3.8 + 3 = 6.8
    //y = 1.1 *  1.5 + 2 = 1.65 + 2 = 3.65
    imprimir(ptr_x, ptr_y);
    // $ Datos de x = 6.8, y = 3.65
    cout << "Suma de X e Y : " << suma(ptr_x, ptr_y) << endl;
    // $ Suma de X e Y : 10,45
    cout << "Diferencia de X e Y : " << resta(ptr_x, ptr_y) << endl;
    // $ Diferencia de X e Y : 3,15
    return 0;
}