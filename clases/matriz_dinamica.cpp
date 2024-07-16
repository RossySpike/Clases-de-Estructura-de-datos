#include <iostream>

using namespace std;

int **puntero_matriz, nFilas, nCol;

void pedir_datos();

void mostrar_datos();

int main (){
    
    pedir_datos();
    mostrar_datos();

    for (int loop = 0; loop < nFilas; loop++){
        delete[] puntero_matriz[loop];
    }

    delete[] puntero_matriz;

    return 0;
}

void pedir_datos(){
    cout << "Escribe el nro de filas: ";
    cin >> nFilas;
    cout << "\nEscribe el nro de columnas: ";
    cin >> nCol;

    puntero_matriz = new int*[nFilas];

    for (int loop = 0; loop < nFilas; loop++){
        puntero_matriz[loop] = new int[nCol]; 
    }

    cout << "\nintro los elementos de la matriz";
    for(int loop = 0; loop < nFilas; loop ++){
        for (int loop2 = 0; loop2< nCol; loop2++){
            cout << "\nEscribe un nro ["<<loop<<"] ["<<loop2<<"]";
            cin >> *(*(puntero_matriz + loop) + loop2);
        }
    }
}

void mostrar_datos(){
    for (int loop = 0; loop < nFilas; loop++){
        for (int loop2 = 0; loop2 < nCol; loop2++){
            cout << "\n Matriz ["<<loop<<"] ["<<loop2<<"] = ["<<*(*(puntero_matriz + loop)+loop2)<<"]" << endl;
        }
    }
}