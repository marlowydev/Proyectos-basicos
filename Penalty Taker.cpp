#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

void comienzo (){
    //menu principal
    cout<<"##############################\n";
    cout<<"        Penalty Taker         \n";
    cout<<"##############################\n";
    cout<<"Estas a punto de disparar...\n";
    cout<<"Presiona (1,2,3) para:\n";
    cout<<"1 = disparar a la izquierda\n";
    cout<<"2 = disparar al medio\n";
    cout<<"3 = disparar a la derecha\n";


}

int EleccionArquero(){
    //eleccion de arquero pseudorandom;
   
    int eleccion = (rand() % 3) + 1;
    return eleccion;
}

int main(){
//semilla para generar el numero random
srand (time(NULL));
//variables
char reinicio;
int opcionJugador = 0;
int ganadas = 0;
int perdidas = 0;
do{
int Pc = EleccionArquero();
comienzo();
cin>>opcionJugador;

while(opcionJugador > 3 || opcionJugador < 1){
cout<<"Ese no es un numero valido >:c";
cin>>opcionJugador;
}
cout<<"Estas tomando aire...\n";
Sleep(500);
cout<<"3\n";
Sleep(500);
cout<<"2\n";
Sleep(500);
cout<<"1\n";
//menu de wins
if(opcionJugador != Pc){

    cout<<"Ganaste!\n\n";
    ganadas ++;
    cout<<"Llevas "<<ganadas<<" Goles\n";
}else{
    cout<<"Perdiste!\n\n";
    perdidas ++;
    cout<<"Llevas "<<perdidas<<" Falladas\n";
}

//reinicio 
cout<<"Quieres reintentarlo? (Y/N) ";
cin>>reinicio;
}while (reinicio == 'Y' || reinicio == 'y');
return 0;
}
    
