#pragma once
#include <memory>
#include "ardillas.h"

class Combate {
private:
    std::shared_ptr<Ardilla> jugador;
    std::shared_ptr<Ardilla> enemigo;

    void mostrarEstado() const;
    void turnoJugador();
    void turnoEnemigo();

public:
    Combate(std::shared_ptr<Ardilla> jugador, std::shared_ptr<Ardilla> enemigo);
    
    // Inicia el bucle de combate hasta que alguien sea derrotado.
    // Devuelve true si el jugador gana, false si pierde.
    bool iniciar();
};
