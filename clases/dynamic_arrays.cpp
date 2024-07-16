#include <iostream>
//new: reserva el nro de bytes solicitado por la declaracion
//delete: Librera un bloque de byes reservado con anterioridad
using namespace std;

void getExams();
void showGrades();

int Exams, *grades_ptr;

int main (){
    
    getExams();
    showGrades();
    
    delete[] grades_ptr; //Liberar la memoria 

    return 0;
}

void getExams(){
    cout << "Cuantas calificaciones?\n: ";
    cin >> Exams;

    grades_ptr = new int [Exams];//Se crea el arreglo

    for (int loop = 0; loop < Exams; loop++){
        cout << "Ingresa la calificacion de un examen: ";
        cin >> grades_ptr [loop];
    }    
}

void showGrades(){
    cout << "\n\nSus notas fureon:\n";

    for (int loop = 0; loop < Exams; loop++){
        cout << grades_ptr[loop] << endl;
    }
}