#include <iostream>

using namespace std;

void wage_increment (float &wage, float percentage);

float tax (float &wage);

int main (){
    float wage, percentage, *z;

    cout << "Introduce el sueldo del trabajador\n: ";
    cin >> wage;
    z = &wage;

    cout << "Introduce el porcentaje (sin \'%\')\n: ";
    cin >> percentage;

    wage_increment(*z, percentage);

    cout << "El nuevo salario seria: " << *z << "\nAgregando impuestos: " << tax(*z) << endl;

    return 0;
}

void wage_increment (float &wage, float percentage){
    wage = wage + (wage * (percentage * 0.01));
}

float tax (float &wage){

    if (wage >= 5000){
        return wage - (wage * 0.2);

    }else if (wage < 5000 && wage >= 1000){
        return wage - (wage * 0.1);        

    }else return wage;
}
