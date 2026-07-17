#include "ardillas.h"
#include <iostream>

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

std::string Ardilla::getNombre() {
    return nombre;
}

int Ardilla::getVida() {
    return vida;
}

int Ardilla::getEnergia() {
    return energia;
}

int Ardilla::getNumero() {
    return numero;
}

void Ardilla::recibirDanio(int cantidad) {
    vida -= cantidad;
    if (vida < 0) {
        vida = 0;
    }
}

void Ardilla::usarAtaqueBasico(Ardilla& objetivo) {
    if (vida <= 0) {
        std::cout << nombre << " no puede atacar porque ya está derrotada.\n";
        return;
    }

    objetivo.recibirDanio(ataqueBase);
    std::cout << nombre << " usa ataque básico y hace " << ataqueBase << " de daño.\n";
}

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

ArdillaNoob::ArdillaNoob(std::string nombre)
    : Ardilla(nombre, 100, 80, 15, "Bastón de nuez", 2, 20) {
}

ArdillaPro::ArdillaPro(std::string nombre)
    : Ardilla(nombre, 140, 120, 25, "Megacabezazo", 3, 35) {
}
