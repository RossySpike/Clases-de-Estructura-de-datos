#include <iostream>

using namespace std;

int main (){
    
    int Entero = 15; float Flotante = 13.4; double Double = 3.141516; char Caracter = 'p'; 

    cout << Entero << endl << Flotante << endl << Double << endl << Caracter << endl;

    //Input de datos
    int Number;

    cout << "Escribe un nro\n:";
    cin >> Number;
    //Cadenas
    char Palabra [100];

    cout << "Escribe una palabra\n:"; 
    cin.getline(Palabra,100,'\n');
    return 0;
}

/*while piensa -> actua
do
while -> actua luego piensa*/