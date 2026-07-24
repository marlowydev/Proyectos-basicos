#include <iostream>
#include "tienda.h"

// Constructor de la tienda: la ardilla básica empieza ya comprada.
Tienda::Tienda() {
    this->ardillas_Compradas.push_back(1);
}

// Revisa si el ID pasado ya existe en la lista de ardillas compradas.
bool Tienda::EstaComprada(int numero) const {
    for (int id : ardillas_Compradas) {
        if (id == numero) {
            return true;
        }
    }
    return false;
}

// Comprueba si el precio de la ardilla se puede pagar con las monedas del main.
bool Tienda::SePuedeComprar(int numero, int& monedasDisponibles) const {
    if (EstaComprada(numero)) {
        return false;
    }

    int precio = 0;
    if (numero == 1) {
        precio = PRECIO_ARDILLA_NOOB;
    } else if (numero == 2) {
        precio = PRECIO_ARDILLA_PRO;
    } else {
        return false;
    }

    return monedasDisponibles >= precio;
}

// Compra una ardilla si no estaba comprada antes y descuenta el precio de las monedas del main.
void Tienda::ComprarArdilla(int numero, int& monedasDisponibles) {
    if (EstaComprada(numero)) {
        std::cout << "La ardilla con ID " << numero << " ya está comprada.\n";
        return;
    }

    int precio = 0;
    if (numero == 1) {
        precio = PRECIO_ARDILLA_NOOB;
    } else if (numero == 2) {
        precio = PRECIO_ARDILLA_PRO;
    } else {
        std::cout << "Ese ID no existe en la tienda.\n";
        return;
    }

    if (monedasDisponibles < precio) {
        std::cout << "No tienes suficientes monedas. Necesitas " << precio
                  << " pero solo tienes " << monedasDisponibles << ".\n";
        return;
    }

    monedasDisponibles -= precio;
    ardillas_Compradas.push_back(numero);
    std::cout << "Ardilla con ID " << numero << " comprada correctamente.\n";
    std::cout << "Monedas restantes: " << monedasDisponibles << "\n";
}

// Muestra el estado de las ardillas disponibles usando sus IDs y muestra las monedas actuales del main.
void Tienda::MostrarArdillasDisponibles(int monedasDisponibles) const {
    std::cout << "Ardillas disponibles en la tienda:\n";
    std::cout << "- ID 1: Ardilla Noob (precio: " << PRECIO_ARDILLA_NOOB << ") -> "
              << (EstaComprada(1) ? "Comprada" : "Disponible") << "\n";
    std::cout << "- ID 2: Ardilla Pro (precio: " << PRECIO_ARDILLA_PRO << ") -> "
              << (EstaComprada(2) ? "Comprada" : "Disponible") << "\n";
    std::cout << "Monedas actuales: " << monedasDisponibles << "\n";
}

std::vector<int> Tienda::GetArdillasCompradas() const {
    return ardillas_Compradas;
}


