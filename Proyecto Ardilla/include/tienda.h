#pragma once
#include <vector>
#include <string>
#include "ardillas.h"

class Tienda {
private:
    // Guarda los IDs de las ardillas que ya fueron compradas.
    std::vector<int> ardillas_Compradas;

    // Precios fijos y constantes para cada ardilla.
    static const int PRECIO_ARDILLA_NOOB = 30;
    static const int PRECIO_ARDILLA_PRO = 70;

public:
    // Constructor que inicializa la tienda y deja una ardilla base disponible.
    Tienda();

    // Verifica si un ID de ardilla ya está comprado.
    bool EstaComprada(int numero) const;

    // Comprueba si el precio se puede pagar con el dinero disponible en el main.
    bool SePuedeComprar(int numero, int& monedasDisponibles) const;

    // Compra una ardilla si aún no ha sido adquirida y descuenta el precio de las monedas del main.
    void ComprarArdilla(int numero, int& monedasDisponibles);

        // Muestra el estado de las ardillas disponibles o compradas y recibe las monedas del main para mostrarlas.
    void MostrarArdillasDisponibles(int monedasDisponibles) const;

    // Devuelve los IDs de las ardillas compradas.
    std::vector<int> GetArdillasCompradas() const;
};