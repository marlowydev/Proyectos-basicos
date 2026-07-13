#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include <random>
#include <vector>
#include <cstdlib>

class Autos {
public:
    int numero;
    std::string marca;
    std::string modelo;
    double velocidadmax;
    int precio;
    bool comprado = false;
};
class Auto_oponente {
public:
    std::string marca;
    std::string modelo;
    double velocidadmax;
};

int generarNumeroAleatorio(int max) {
    static std::mt19937 rng((unsigned)std::time(nullptr));
    if (max <= 1) return 1;
    std::uniform_int_distribution<int> dist(1, max);
    return dist(rng);
}
void comienzo(int &contador) {
    std::cout << "##################################" << std::endl;
    std::cout << "#         Console Forza          #" << std::endl;
    std::cout << "##################################" << std::endl;
    std::cout << "1: Tienda" << std::endl;
    std::cout << "2: Garaje" << std::endl;
    std::cout << "3: Seleccionar Auto/Carrera" << std::endl;
    std::cout << "4: Salir"<<std::endl;

    if (contador == 1) {
        std::cout << "Bienvenido, presione el digito para entrar al menu" << std::endl;
        contador++;
    } else {
        std::cout << std::endl;
    }
}

bool comprarAuto(std::vector<Autos> &catalogo, int &dinero, int eleccion) {
    for (size_t i = 0; i < catalogo.size(); ++i) {
        if (catalogo[i].numero == eleccion) {
            if (catalogo[i].comprado) {
                std::cout << "Ya tienes este auto." << std::endl;
                return false;
            }

            if (dinero >= catalogo[i].precio) {
                dinero -= catalogo[i].precio;
                catalogo[i].comprado = true;
                std::cout << "Compraste el " << catalogo[i].marca << " "
                          << catalogo[i].modelo << " por " << catalogo[i].precio
                          << " de dinero." << std::endl;
                std::cout << "Dinero restante: " << dinero << std::endl;
                return true;
            
            
            }

            std::cout << "No tienes suficiente dinero para comprar este auto." << std::endl;
            return false;
           
        }
       
    }

    std::cout << "No se encontro ese auto." << std::endl;
    return false;
}

void tienda(std::vector<Autos> &catalogo, int &dinero) {
    int eleccion = 0;
    std::cout << "Tu dinero disponible: " << dinero << std::endl;
    std::cout << "Los autos disponibles actualmente son:" << std::endl;

    for (size_t i = 0; i < catalogo.size(); ++i) {
        std::cout << catalogo[i].numero << ": " << catalogo[i].marca << " "
                  << catalogo[i].modelo << " | Vel. Max: " << catalogo[i].velocidadmax
                  << " km/h | Precio: ";
        if (catalogo[i].comprado) {
            std::cout << "Adquirido" << std::endl;
             
        
        } else {
            std::cout << catalogo[i].precio << std::endl;

        }
    }

    std::cout << "Elige el auto que deseas comprar (0 para salir): ";
    std::cin >> eleccion;

    if (eleccion == 0) {
        std::cout << "Saliendo de la tienda..." << std::endl;
        return;
    }

    comprarAuto(catalogo, dinero, eleccion);
       std::cout << "Volviendo al menu en 3 segundos, no presione ninguna tecla..." << std::endl;
                        Sleep(3000);
            system("cls");
}

void garaje(std::vector<Autos> &catalogo) {
    char eleccion = ' ';
    std::cout << "Autos en tu garaje:" << std::endl;
    bool hayAutos = false;

    for (size_t i = 0; i < catalogo.size(); ++i) {
        if (catalogo[i].comprado) {
            hayAutos = true;
            std::cout<<catalogo[i].numero<<": " << catalogo[i].marca << " " << catalogo[i].modelo
                      << " | " << catalogo[i].velocidadmax << " km/h" << std::endl;
                  
        }
       
    } 
        
    if (!hayAutos) {
        std::cout << "No tienes autos en tu garaje." << std::endl;
       Sleep(3000);
            system("cls");
            return;
    }
}

int seleccionarAuto (std::vector<Autos> &catalogo) {
    int eleccion = 0;
    garaje(catalogo);
    std::cout << "Selecciona un auto para la carrera (0 para salir): ";
    std::cin >> eleccion;

    for (size_t i = 0; i < catalogo.size(); ++i) {
        if (catalogo[i].numero == eleccion && catalogo[i].comprado) {
            return (int)i; // devolver indice en catalogo
        }
    }

    std::cout << "No se encontro ese auto o no lo has comprado." << std::endl;
    return -1;
}

int carrera (std::vector<Autos> &catalogo, std::vector<Auto_oponente> &oponentes, int idx, int &dinero) {
    if (idx < 0 || idx >= (int)catalogo.size()) {
        std::cout << "Auto seleccionado invalido.\n";
        return 0;
    }

    Autos &miAuto = catalogo[idx];

    // elegir oponente aleatorio
    int oppIdx = catalogo[idx].numero - 1; // 0..n-1
    Auto_oponente &op = oponentes[idx];

    int puntoscarrerajugador = 0;
    int puntoscarreraoponente = 0;

    // comparacion inicial por velocidad maxima
    if (miAuto.velocidadmax > op.velocidadmax) puntoscarrerajugador+=2;
    else if (miAuto.velocidadmax < op.velocidadmax) puntoscarreraoponente+=2;
    else { puntoscarrerajugador++; puntoscarreraoponente+=1; }

    // evento adicional aleatorio
    if (generarNumeroAleatorio(2) == 1) puntoscarrerajugador++;
    else puntoscarreraoponente++;

    std::cout << "Tu auto: " << miAuto.marca << " " << miAuto.modelo << " (" << miAuto.velocidadmax << " km/h)" << std::endl;
    std::cout << "Oponente: " << op.marca << " " << op.modelo << " (" << op.velocidadmax << " km/h)" << std::endl;
Sleep(1000);
Beep(750, 200);
Sleep(1000);
Beep(750, 200);
Sleep(1000);
Beep(900, 200);
std::cout << "La carrera ha comenzado!" << std::endl;
Sleep(200);
    // simulacion de 10 eventos
    for (int i = 0; i < 10; ++i) {
        int evento = generarNumeroAleatorio(11); // 1..11
        switch (evento) {
            case 1:
                std::cout << "El auto del rival pierde traccion!" << std::endl;
                puntoscarreraoponente -= 1;
                Sleep(500);
                break;
            case 2:
                std::cout << "El auto del jugador pierde traccion!" << std::endl;
                puntoscarrerajugador -= 1;
                Sleep(500);
                break;
            case 3:
                std::cout << "El auto del rival tiene un aumento de potencia repentina" << std::endl;
                puntoscarreraoponente += 1;
                Sleep(500);
                break;
            case 4:
                std::cout << "El auto del jugador tiene un aumento de potencia repentina" << std::endl;
                puntoscarrerajugador += 1;
                Sleep(500);
                break;
            case 5:
                std::cout << "El rival se ha chocado contra la muralla!" << std::endl;
                puntoscarreraoponente -= 2;
                Sleep(500);
                break;
            case 6:
                std::cout << "El jugador se ha chocado contra la muralla!" << std::endl;
                puntoscarrerajugador -= 2;
                Sleep(500);
                break;
            case 7:
                std::cout << "El rival pincha una rueda!" << std::endl;
                puntoscarreraoponente -= 2;
                Sleep(500);
                break;
            case 8:
                std::cout << "El jugador gano terreno!" << std::endl;
                puntoscarrerajugador += 1;
                Sleep(500);
                break;
            case 9:
                std::cout << "El rival gano terreno!" << std::endl;
                puntoscarreraoponente += 1;
                Sleep(500);
                break;
            case 10:
                std::cout << "El jugador gano terreno!" << std::endl;
                puntoscarrerajugador += 1;
                Sleep(500);
                break;
            case 11:
                std::cout << "El rival gano terreno!" << std::endl;
                puntoscarreraoponente += 1;
                Sleep(500);
                break;
            default:
                break;
        }
    }

    if (puntoscarrerajugador > puntoscarreraoponente) {
        std::cout << "El jugador ha ganado la carrera!" << std::endl;
        dinero += 20000;
        return 1;
        
    } else if (puntoscarrerajugador < puntoscarreraoponente) {
        std::cout << "El rival ha ganado la carrera!" << std::endl;
        return -1;
         
    } else {
        std::cout << "La carrera ha terminado en empate!" << std::endl;
        return 0;
         
}
}
int main() {
    int dinero = 20000;

    std::vector<Autos> catalogo = {
        {1, "Toyota", "AE86 Trueno", 200, 10000},
        {2, "Subaru", "22b STI", 250, 12000},
        {3, "Bugatti", "Bolide", 300, 20000},
        {4, "Lamborghini", "Aventador SVJ", 400, 25000}
    };
    std::vector<Auto_oponente> oponentes = {
        {"Nissan", "Skyline R34", 205},
        {"Mitsubishi", "Lancer Evo X", 240},
        {"Ferrari", "F40", 320},
        {"BMW", "M8 Competition", 405}
        
    };

    int contador = 1;
    char eleccion = ' ';

do{
  
        comienzo(contador);
        std::cin >> eleccion;

        switch (eleccion) {
        case '1':
 
            tienda(catalogo, dinero);
            break;
        case '2':
        
            garaje(catalogo);
            break;
        case '3': {
              
            int idx = seleccionarAuto(catalogo);
            if (idx >= 0) {
                std::cout << "Has seleccionado el auto numero: " << catalogo[idx].numero << " (" << catalogo[idx].marca << " " << catalogo[idx].modelo << ")" << std::endl;
                carrera(catalogo, oponentes, idx, dinero);
            }
            break;
        }
        case '4':
      
            std::cout << "Saliendo del juego..." << std::endl;
            return 0;
            break;
        default:
            std::cout << "Opcion no disponible." << std::endl;
            break;
        }

        if (eleccion != '4') {
            
        }
    } while (eleccion != '4');
       
    
}
