#include "ardillas.h"
#include <iostream>

// Constructor base que inicializa la vida, energía y estadísticas de combate.
Ardilla::Ardilla(std::string nombre, int vida, int energia, int ataqueBase,
                 std::string nombreAtaqueEspecial, int multiplicadorDanio, int costoEnergiaEspecial)
    : nombre(nombre),
      vida(vida),
      vidaMaxima(vida),
      energia(energia),
      energiaMaxima(energia),
      numero(0),
      ataqueBase(ataqueBase),
      nombreAtaqueEspecial(nombreAtaqueEspecial),
      multiplicadorDanio(multiplicadorDanio),
      costoEnergiaEspecial(costoEnergiaEspecial) {
}

// Devuelve el nombre visible de la ardilla.
std::string Ardilla::getNombre() {
    return nombre;
}

// Devuelve la vida actual de la ardilla.
int Ardilla::getVida() {
    return vida;
}

// Devuelve la energía actual disponible para usar ataques especiales.
int Ardilla::getEnergia() {
    return energia;
}

// Devuelve el ID de la ardilla para verificarla en la tienda.
int Ardilla::getNumero() {
    return numero;
}

int Ardilla::getVidaMaxima() {
    return vidaMaxima;
}

int Ardilla::getEnergiaMaxima() {
    return energiaMaxima;
}

std::string Ardilla::getNombreAtaqueEspecial() {
    return nombreAtaqueEspecial;
}

int Ardilla::getCostoEnergiaEspecial() {
    return costoEnergiaEspecial;
}

int Ardilla::getAtaqueBase() const {
    return ataqueBase;
}

int Ardilla::getMultiplicadorDanio() const {
    return multiplicadorDanio;
}

bool Ardilla::tieneEnergiaSuficiente() const {
    return energia >= costoEnergiaEspecial;
}

// Permite cambiar el ID de la ardilla cuando se registra en la tienda.
void Ardilla::setNumero(int nuevoNumero) {
    numero = nuevoNumero;
}

// Reduce la vida cuando recibe daño, sin permitir valores negativos.
void Ardilla::recibirDanio(int cantidad) {
    vida -= cantidad;
    if (vida < 0) {
        vida = 0;
    }
}

// Hace daño básico al objetivo si la ardilla atacante sigue viva.
void Ardilla::usarAtaqueBasico(Ardilla& objetivo) {
    if (vida <= 0) {
        std::cout << nombre << " no puede atacar porque ya está derrotada.\n";
        return;
    }

    objetivo.recibirDanio(ataqueBase);
    std::cout << nombre << " usa ataque básico y hace " << ataqueBase << " de daño.\n";
}

// Usa un ataque especial que consume energía y causa más daño.
void Ardilla::usarAtaqueEspecial(Ardilla& objetivo) {
    if (vida <= 0) {
        std::cout << nombre << " no puede usar su ataque especial porque ya está derrotada.\n";
        return;
    }

    if (energia < costoEnergiaEspecial) {
        std::cout << nombre << " no tiene suficiente energía para " << nombreAtaqueEspecial << ".\n";
        return;
    }

    energia -= costoEnergiaEspecial;
    objetivo.recibirDanio(ataqueBase * multiplicadorDanio);
    std::cout << nombre << " usa " << nombreAtaqueEspecial << " y hace "
              << (ataqueBase * multiplicadorDanio) << " de daño.\n";
}

// Crea una ardilla básica con características sencillas y un nombre fijo.
ArdillaNoob::ArdillaNoob()
    : Ardilla("Ardilla Noob", 100, 80, 15, "Bastón de nuez", 2, 20) {
    setNumero(1);
}

// Crea una ardilla más poderosa con un nombre fijo.
ArdillaPro::ArdillaPro()
    : Ardilla("Ardilla Pro", 140, 120, 25, "Megacabezazo", 3, 35) {
    setNumero(2);
}
