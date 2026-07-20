#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <cstdlib>   // Para std::system
#include <windows.h> // Para SetConsoleTitleA y gestión nativa en Windows
#include "ardillas.h"

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
        std::cout << " 3. Ver tus ardillas\n";
        std::cout << " 4. Salir del Juego\n";
        std::cout << "-----------------------------------------\n";
        std::cout << "Elige una opcion (1-4): ";

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nIntroduce un texto valido >:c\n";
            esperarTecla();
            continue;
        }

     
       
        switch (opcion) {
            case 1: {
                std::cout << "En este universo Ardillezco, tu objetivo es tener bajo tu mando a las ardillas mas fuertes...\n";
                esperarTecla();
                limpiarConsola();
                std::cout << "Pero te advierto... este es un juego muy random Y NO puedes guardar partida (por ahora).\n";
                esperarTecla();
                std::cout << "Se te ha dado 100 monedas para que empieces tu aventura, haz una buena eleccion no seas tonto.\n";
                esperarTecla();
                break;
            }
            case 2:
                std::cout << "La tienda aun se encuentra en desarrollo.\n";
                break;
            case 3:
               
                break;
            default:
                std::cout << "\nOpcion no valida. Intentalo de nuevo.\n";
                esperarTecla();
                break;
        }
    }

    return 0;
}