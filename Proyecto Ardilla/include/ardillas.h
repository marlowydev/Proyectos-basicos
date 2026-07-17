#pragma once
#include <string>

class Ardilla {
protected:
    // Estadísticas básicas
    std::string nombre;
    int vida;
    int vidaMaxima;
    int energia;
    int energiaMaxima;
    int numero = 0; // ID para la tienda y skins

    // Sistema de combate simplificado
    int ataqueBase;
    std::string nombreAtaqueEspecial;
    int multiplicadorDanio;
    int costoEnergiaEspecial;

public:
    Ardilla(std::string nombre, int vida, int energia, int ataqueBase,
            std::string nombreAtaqueEspecial, int multiplicadorDanio, int costoEnergiaEspecial);
    virtual ~Ardilla() = default;

    // Getters públicos básicos
    std::string getNombre();
    int getVida();
    int getEnergia();
    int getNumero();

    // Métodos de combate comunes
    void recibirDanio(int cantidad);
    void usarAtaqueBasico(Ardilla& objetivo);
    void usarAtaqueEspecial(Ardilla& objetivo);
};

class ArdillaNoob : public Ardilla {
public:
    ArdillaNoob(std::string nombre);
};

class ArdillaPro : public Ardilla {
public:
    ArdillaPro(std::string nombre);
};