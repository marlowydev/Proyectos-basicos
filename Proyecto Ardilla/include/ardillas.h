#pragma once
#include <string>

class Ardilla {
protected:
    // Estadísticas básicas de la ardilla.
    std::string nombre;
    int vida;
    int vidaMaxima;
    int energia;
    int energiaMaxima;
    int numero = 0; // ID único para identificarla en la tienda y en futuras mejoras.

    // Sistema de combate simplificado.
    int ataqueBase;
    std::string nombreAtaqueEspecial;
    int multiplicadorDanio;
    int costoEnergiaEspecial;

public:
    // Constructor base para inicializar los atributos de una ardilla.
    Ardilla(std::string nombre, int vida, int energia, int ataqueBase,
            std::string nombreAtaqueEspecial, int multiplicadorDanio, int costoEnergiaEspecial);
    virtual ~Ardilla() = default;

    // Getters públicos básicos.
    std::string getNombre();
    int getVida();
    int getEnergia();
    int getNumero();
    int getVidaMaxima();
    int getEnergiaMaxima();
    std::string getNombreAtaqueEspecial();
    int getCostoEnergiaEspecial();
    int getAtaqueBase() const;
    int getMultiplicadorDanio() const;

    // Comprueba si tiene energía suficiente para el ataque especial.
    bool tieneEnergiaSuficiente() const;

    // Permite asignar o actualizar el ID de una ardilla desde la tienda.
    void setNumero(int nuevoNumero);

    // Métodos de combate comunes.
    void recibirDanio(int cantidad);
    void usarAtaqueBasico(Ardilla& objetivo);
    void usarAtaqueEspecial(Ardilla& objetivo);
};

class ArdillaNoob : public Ardilla {
public:
    // Crea una ardilla básica con el nombre fijo "Ardilla Noob".
    ArdillaNoob();
};

class ArdillaPro : public Ardilla {
public:
    // Crea una ardilla más fuerte con el nombre fijo "Ardilla Pro".
    ArdillaPro();
};