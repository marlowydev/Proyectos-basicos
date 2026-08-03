#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "ardillas.h"
#include "ardillasSkin.h"
#include "tienda.h"
#include "combate.h"

void limpiarConsola() {
    std::system("cls");
}

void esperarTecla() {
    std::cout << "\nPresiona Enter para continuar!";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}




int main() {
    SetConsoleTitleA("Ardillas Beta");
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    Tienda tienda;
    int opcion = 0;
    int monedas = 100;

    std::cout << "En este universo Ardillezco, tu objetivo es tener bajo tu mando a las ardillas mas fuertes...\n";
    esperarTecla();
    limpiarConsola();
    std::cout << "Pero te advierto... este es un juego muy random Y NO puedes guardar partida (por ahora).\n";
    esperarTecla();
    std::cout << "Se te ha dado 100 monedas para que empieces tu aventura, haz una buena eleccion no seas tonto.\n";
    esperarTecla();
    limpiarConsola();

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
                std::vector<int> compradas = tienda.GetArdillasCompradas();
                if (compradas.empty()) {
                    std::cout << "No tienes ardillas para combatir. Ve a la tienda primero.\n";
                    esperarTecla();
                    break;
                }

                std::cout << "\nElige una ardilla para combatir:\n";
                for (int id : compradas) {
                    if (id == 1) std::cout << "[1] Ardilla Noob  ";
                    else if (id == 2) std::cout << "[2] Ardilla Pro  ";
                    else if (id == 3) std::cout << "[3] Ardilla Pol  ";
                }
                std::cout << "\nSelecciona el ID: ";

                int eleccion;
                std::cin >> eleccion;

                bool posee = false;
                for (int id : compradas) {
                    if (id == eleccion) { posee = true; break; }
                }

                if (!posee) {
                    std::cout << "No tienes esa ardilla.\n";
                    esperarTecla();
                    break;
                }

                std::unique_ptr<Ardilla> ardillaJugador;
                if (eleccion == 1) ardillaJugador = std::make_unique<ArdillaNoob>();
                else if (eleccion == 2) ardillaJugador = std::make_unique<ArdillaPro>();
                else if (eleccion == 3) ardillaJugador = std::make_unique<ArdillaPol>();
                iniciarCombate(*ardillaJugador, monedas);
                esperarTecla();
                break;
            }
            case 2:
                int eleccionTienda;
                std::cout << "Bienvenido a la tienda, aqui podras comprar ardillas para tu equipo.\n";
                esperarTecla();
                limpiarConsola();
                std::cout << "Ardillas disponibles:\n";
                tienda.MostrarArdillasDisponibles(monedas);
                std::cout << "Elige el ID de la ardilla que deseas comprar: ";
                std::cin >> eleccionTienda;
                tienda.ComprarArdilla(eleccionTienda, monedas);
                esperarTecla();

                break;
                        case 3: {
                limpiarConsola();
                std::cout << "=========================================\n";
                std::cout << "          Tus ardillas compradas         \n";
                std::cout << "=========================================\n";
                
                std::vector<int> compradas = tienda.GetArdillasCompradas();
                
                if (compradas.empty()) {
                    std::cout << "No tienes ardillas...? Como es posible?, Lamento decir que eres muy malo...\n";
                } else {
                    for (int id : compradas) {
                        if (id == 1) {
                            std::cout << "--- Ardilla Noob ---\n";
                            std::cout << Skins::Ardilla_Noob() << "\n";
                        } else if (id == 2) {
                            std::cout << "--- Ardilla Pro ---\n";
                            std::cout << Skins::Ardilla_Pro() << "\n";
                        }
                        else if (id == 3) {
                            std::cout << "--- Ardilla Pol ---\n";
                            std::cout << Skins::Ardilla_Pol() << "\n";
                        }
                    }
                }
                esperarTecla();
                break;
            }
            default:
                std::cout << "\nOpcion no valida. Intentalo de nuevo.\n";
                esperarTecla();
                break;
        }
    }

    return 0;
}