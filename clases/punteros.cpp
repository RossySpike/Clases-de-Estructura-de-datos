#include <iostream>
/*
&n = la direccion de memoria de la variable n
*n = la variable cuya direccion esta almacenada en n 
*/

using namespace std;

int main (){

    int num, *dir_num;

    num = 20; dir_num = &num;

    cout << "Valor de num = " << *dir_num << " Su direccion en memoria : " << dir_num << endl;
     
    //Iterar sobre un arreglo

    int array [] = {1,2,3,4,5}, *array_ptr;

    array_ptr = array; //array contiene la direccion de memoria del primer elemento del arrego, por lo que es mas sencillo escribirlo de esa manera antes que = &arreglo[0]

    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++){
        cout << "Los elementos del arreglo son ["<<i<<"]: " << *array_ptr++ << endl; 
    } 
    

    return 0;
}