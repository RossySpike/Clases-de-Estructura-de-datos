#include <iostream>
using namespace std;
int main (){
    float x = 1.9, *p, *q, y = 1.1;
    p = &y; //direccion de la var y
    x = *p + x; // x = 3.0
    q = p; //direccion de la variable p
    *q = y * 2; // 2.2 -> y = 2.2; 
    cout << "*p = " << *p << endl; //2.2 
    cout << "*q = " << *q << endl; //2.2
    cout << "y = " << y << endl; //2.2
    cout << "x = " << x << endl; //3.0
    p = &x; //direccion de memoria de x
    y = y + *p; //y = 2.2 + 3.0 = 5.2
    x = y + x + *q; //5.2 + 3.0 + 5.2 = 13.4
    return 0;
}