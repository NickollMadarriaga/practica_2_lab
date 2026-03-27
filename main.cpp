#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    int opcion;

    cout << "Ejercicio (impar): ";
    cin >> opcion;

    if (opcion == 1) {
        int x;
        cout << "Ingrese la cantidad: ";
        cin >> x;
        cambioDinero(x);
    }

    if (opcion == 3) {
        char a[100], b[100];

        cout << "Ingrese la primera cadena: ";
        cin >> a;

        cout << "Ingrese la segunda cadena: ";
        cin >> b;

        if (compararCadenas(a, b)) {
            cout << "Iguales" << endl;
        } else {
            cout << "Diferentes" << endl;
        }
    }

    if (opcion == 5) {
        int n;
        char resultado[100];

        cout << "Ingrese un número entero: ";
        cin >> n;

        enteroACadena(n, resultado);

        cout << "Numero como texto: " << resultado << endl;
    }

    if (opcion == 7) {
        char texto[100], resultado[100];

        cout << "Ingrese un texto: ";
        cin >> texto;

        eliminarRepetidos(texto, resultado);

        cout << "Sin repetidos: " << resultado << endl;
    }

    if (opcion == 9) {
        int n;
        char cadena[100];

        cout << "Ingrese el tamaño del bloque: ";
        cin >> n;

        cout << "Ingrese la cadena de dígitos: ";
        cin >> cadena;

        int total = sumaPorBloques(cadena, n);

        cout << "Suma total: " << total << endl;
    }

    if(opcion == 11) {
        sala_cine();
    }

    if(opcion == 13) {
        int filas = 6, columnas = 8;

        int imagen[6][8] = {
            {0,3,4,0,0,0,6,8},
            {5,13,6,0,0,0,2,3},
            {2,6,2,7,3,0,10,0},
            {0,0,4,15,4,1,6,0},
            {0,0,7,12,6,9,10,4},
            {5,0,6,10,6,4,8,0}
        };

        int total = contarEstrellas(&imagen[0][0], filas, columnas);

        cout << "Numero de estrellas: " << total << endl;
    }

    if(opcion == 15) {
        rectangulo_interseccion();
    }

    if(opcion == 17) {
       numeros_amigables();
    }

    return 0;
}
