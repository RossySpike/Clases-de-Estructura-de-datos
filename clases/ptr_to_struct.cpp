#include <iostream>

using namespace std;

struct Persona{
    char Name [30];
    int Lvl;
}persona, *ptr_persona = &persona;

void getData();
void showData();

int main (){
    
    getData();
    showData();

    return 0;
}

void getData(){
    cout << "Enter Persona name: ";
    cin.getline(ptr_persona -> Name,30,'\n');
    cout << "Enter Persona lvl: ";
    cin >> ptr_persona -> Lvl;
}

void showData(){
    cout << "\nPersona list:\n\n["<<ptr_persona -> Name<<"]\nLevel: ["<<ptr_persona -> Lvl<<"]\n" << endl;
}