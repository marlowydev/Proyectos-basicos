#include "combate.h"
#include <iostream>
#include <limits>
#include <vector>

Combate::Combate(std::shared_ptr<Ardilla> jugador, std::shared_ptr<Ardilla> enemigo)
    : jugador(jugador), enemigo(enemigo) {}

void Combate::mostrarEstado() const {
    std::cout << "\n=========================================\n";
    std::cout << " JUGADOR: " << jugador->getNombre() 
              << " [HP: " << jugador->getVida() << "/" << jugador->getVidaMaxima() << "] "
              << "[EN: " << jugador->getEnergia() << "/" << jugador->getEnergiaMaxima() << "]\n";
    std::cout << " ENEMIGO: " << enemigo->getNombre() 
              << " [HP: " << enemigo->getVida() << "/" << enemigo->getVidaMaxima() << "]\n";
    std::cout << "=========================================\n";
}

void Combate::turnoJugador() {
    int eleccion = 0;
    bool turnoFinalizado = false;

    while (!turnoFinalizado) {
        mostrarEstado();
        std::cout << "Turno de " << jugador->getNombre() << ":\n";
        std::cout << "1. Ataque Basico\n";
        
        // Verificamos si tiene energía para el ataque especial
        std::cout << "2. " << jugador->getNombreAtaqueEspecial();
        if (jugador->tieneEnergiaSuficiente()) {
            std::cout << " [Ataque listo]";
        }
        std::cout << " (" << jugador->getCostoEnergiaEspecial() << " EN)\n";

        std::cout << "Selecciona una accion: ";
        
        if (!(std::cin >> eleccion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opcion no valida.\n";
            continue;
        }

        if (eleccion == 1) {
            jugador->usarAtaqueBasico(*enemigo);
            turnoFinalizado = true;
        } else if (eleccion == 2) {
            if (jugador->tieneEnergiaSuficiente()) {
                jugador->usarAtaqueEspecial(*enemigo);
                turnoFinalizado = true;
            } else {
                std::cout << "No tienes suficiente energia para este ataque!\n";
            }
        } else {
            std::cout << "Opcion no valida.\n";
        }
    }
}

void Combate::turnoEnemigo() {
    if (enemigo->getVida() <= 0) return;

    std::cout << "\nTurno de " << enemigo->getNombre() << " (Enemigo):\n";
    
    // IA simple: Si tiene energía usa especial, si no, básico.
    if (enemigo->tieneEnergiaSuficiente()) {
        enemigo->usarAtaqueEspecial(*jugador);
    } else {
        enemigo->usarAtaqueBasico(*jugador);
    }
}

bool Combate::iniciar() {
    std::cout << "¡Comienza el combate entre " << jugador->getNombre() 
              << " y " << enemigo->getNombre() << "!\n";

    while (jugador->getVida() > 0 && enemigo->getVida() > 0) {
        turnoJugador();
        if (enemigo->getVida() <= 0) {
            std::cout << "\n¡" << enemigo->getNombre() << " ha sido derrotado!\n";
            std::cout << "¡Has ganado el combate!\n";
            return true;
        }

        turnoEnemigo();
        if (jugador->getVida() <= 0) {
            std::cout << "\n¡" << jugador->getNombre() << " ha sido derrotado!\n";
            std::cout << "Has perdido el combate...\n";
            return false;
        }
    }
    return false;
}
