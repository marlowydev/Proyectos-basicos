#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cstdlib>   // Para std::system
#include <windows.h> // Para SetConsoleTitleA y gestión nativa en Windows


void limpiarConsola() {
    std::system("cls");
}

void esperarTecla() {
    std::cout << "\nPresiona Enter para continuar!";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}



int main() {
    // Configura el título en la ventana de la consola de Windows
    SetConsoleTitleA("Ardillas Beta");

    int opcion = 0;

    while (opcion != 4) {
        limpiarConsola();
        std::cout << "=========================================\n";
        std::cout << "              Ardillas Beta              \n";
        std::cout << "=========================================\n";
        std::cout << " 1. Empezar Nueva Partida\n";
        std::cout << " 2. Tienda de Bellotas \n";
        std::cout << " 3. Ver Galeria de Ardillas (Skins)\n";
        std::cout << " 4. Salir del Juego\n";
        std::cout << "-----------------------------------------\n";
        std::cout << "Elige una opcion (1-4): ";
        
        //Por si ocurre un error al ingresar la opcion
        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n¡Error! Por favor, introduce un numero valido.\n";
            esperarTecla();
            continue;
        }

        switch (opcion) {
            case 1:
               
                break;
            case 2:
              
                break;
            case 3:
               
                break;
            case 4:
              
                break;
            default:
                std::cout << "\nOpcion no valida. Intentalo de nuevo.\n";
                esperarTecla();
                break;
        }
    }

    return 0;
}