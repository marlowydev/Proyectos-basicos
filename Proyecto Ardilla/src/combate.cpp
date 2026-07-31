#include "combate.h"
#include "ardillas.h"
#include "ardillasSkin.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <limits>

void iniciarCombate(Ardilla& jugador, int& monedas) {
    std::system("cls");

    std::unique_ptr<Ardilla> enemigo;
    std::string skinJugador;
    std::string skinEnemigo;

    if (jugador.getNumero() == 1) {
        enemigo = std::make_unique<ArdillaNoob>();
        skinJugador = Skins::Ardilla_Noob();
        skinEnemigo = Skins::Ardilla_Noob_enemigo();
    } else {
        enemigo = std::make_unique<ArdillaPro>();
        skinJugador = Skins::Ardilla_Pro();
        skinEnemigo = Skins::Ardilla_Pro_enemigo();
    }

    std::cout << "=========================================\n";
    std::cout << "              iCOMBATE!\n";
    std::cout << "=========================================\n\n";
    std::cout << "Una " << enemigo->getNombre() << " Quiere golpearte!, dejaras que lo haga?\n\n";
    std::cout << skinEnemigo << "\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Presiona Enter para comenzar la batalla...\n";
    std::cin.get();

    while (jugador.getVida() > 0 && enemigo->getVida() > 0) {
        std::system("cls");

        std::cout << "=========================================\n";
        std::cout << "             ESTADO DEL COMBATE\n";
        std::cout << "=========================================\n\n";

        std::cout << "TU: " << jugador.getNombre() << "\n";
        std::cout << skinJugador;
        std::cout << "HP: " << jugador.getVida() << "/" << jugador.getVidaMaxima()
                  << "  ENERGIA: " << jugador.getEnergia() << "/" << jugador.getEnergiaMaxima() << "\n\n";

        std::cout << "                     VS\n\n";

        std::cout << "ENEMIGO: " << enemigo->getNombre() << "\n";
        std::cout << skinEnemigo;
        std::cout << "HP: " << enemigo->getVida() << "/" << enemigo->getVidaMaxima()
                  << "  ENERGIA: " << enemigo->getEnergia() << "/" << enemigo->getEnergiaMaxima() << "\n\n";

        std::cout << "--- TU TURNO ---\n";
        std::cout << "1. Ataque basico (" << jugador.getAtaqueBase() << " de danio)\n";
        std::cout << "2. Ataque especial: " << jugador.getNombreAtaqueEspecial()
                  << " (" << (jugador.getAtaqueBase() * jugador.getMultiplicadorDanio()) << " de danio, "
                  << jugador.getCostoEnergiaEspecial() << " energia)\n";
        std::cout << "Elige (1-2): ";

        int eleccion;
        std::cin >> eleccion;

        if (eleccion == 1) {
            jugador.usarAtaqueBasico(*enemigo);
        } else if (eleccion == 2) {
            jugador.usarAtaqueEspecial(*enemigo);
        } else {
            std::cout << "Accion no valida. Pierdes el turno.\n";
        }

        if (enemigo->getVida() <= 0) {
            std::cout << "\n" << enemigo->getNombre() << " ha sido derrotado!\n";
            break;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nPresiona Enter para el turno del enemigo...\n";
        std::cin.get();

        std::system("cls");
        std::cout << "--- TURNO DEL ENEMIGO ---\n\n";

        if (enemigo->tieneEnergiaSuficiente()) {
            enemigo->usarAtaqueEspecial(jugador);
        } else {
            enemigo->usarAtaqueBasico(jugador);
        }

        if (jugador.getVida() <= 0) {
            std::cout << "\n" << jugador.getNombre() << " ha sido derrotado!\n";
            break;
        }

        std::cout << "\nPresiona Enter para continuar...\n";
        std::cin.get();
    }

    std::system("cls");
    std::cout << "=========================================\n";
    if (jugador.getVida() > 0) {
        int recompensa = 30;
        monedas += recompensa;
        std::cout << "             VICTORIA!\n";
        std::cout << "=========================================\n";
        std::cout << "Has ganado " << recompensa << " monedas.\n";
        std::cout << "Monedas actuales: " << monedas << "\n";
    } else {
        std::cout << "             DERROTA\n";
        std::cout << "=========================================\n";
        std::cout << "Has perdido el combate. Intentelo de nuevo!\n";
    }
}
