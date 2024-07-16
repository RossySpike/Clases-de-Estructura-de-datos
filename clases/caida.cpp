#include <cstddef>
#include <iostream>
//40 naipes sin 8 ni 9
struct Node_Cards{
    int Card_Numbr;
    char Palo; //'o' = oros 'c' = copas 'e' = espadas 'b' = bastos
    Node_Cards *Next;
};

void Fill_Deck(int &Stack);

int main (){
    Node_Cards *Stack = NULL;
    return 0;
}

void Fill_Deck (int &Stack){
    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 5; j++){
            
        }
    }
}