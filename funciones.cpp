#include <iostream>
#include "funciones.h"
using namespace std;

void cambioDinero(int cantidad) {
    int dinero[] = {50000,20000,10000,5000,2000,1000,500,200,100,50};
    int resultado[10];

    int *pDinero = dinero;
    int *pRes = resultado;

    for (int i = 0; i < 10; i++) {
        *(pRes + i) = cantidad / *(pDinero + i);
        cantidad = cantidad % *(pDinero + i);
    }

    for (int i = 0; i < 10; i++) {
        cout << *(pDinero + i) << " : " << *(pRes + i) << endl;
    }

    cout << "Faltante: " << cantidad << endl;
}

bool compararCadenas(char *a, char *b) {
    while (*a != '\0' && *b != '\0') {
        if (*a != *b) return false;
        a++;
        b++;
    }

    return (*a == '\0' && *b == '\0');
}

void enteroACadena(int numero, char *resultado) {
    int i = 0;

    if (numero == 0) {
        resultado[0] = '0';
        resultado[1] = '\0';
        return;
    }

    while (numero > 0) {
        *(resultado + i) = (numero % 10) + '0';
        numero = numero/ 10;
        i++;
    }

    *(resultado + i) = '\0';

    // invertir cadena
    int inicio = 0;
    int fin = i - 1;

    while (inicio < fin) {
        char temp = resultado[inicio];
        resultado[inicio] = resultado[fin];
        resultado[fin] = temp;
        inicio++;
        fin--;
    }
}

void eliminarRepetidos(char *texto, char *res) {
    int k = 0;

    for (int i = 0; *(texto + i) != '\0'; i++) {
        bool repetido = false;

        for (int j = 0; j < k; j++) {
            if (*(texto + i) == *(res + j)) {
                repetido = true;
                break;
            }
        }

        if (!repetido) {
            *(res + k) = *(texto + i);
            k++;
        }
    }
    cout<< &res;
    *(res + k) = '\0';
}

int sumaPorBloques(char *cadena, int n) {
    int len = 0;

    while (*(cadena + len) != '\0') len++;

    int resto = len % n;
    int suma = 0;

    int inicio;

    if (resto == 0) {
        inicio = 0;
    } else {
        inicio = resto;
    }

    if (resto != 0) {
        int num = 0;
        for (int i = 0; i < n - resto; i++) {
            num = num * 10;
        }
        for (int i = 0; i < resto; i++) {
            num = num * 10 + (*(cadena + i) - '0');
        }
        suma += num;
    }

    // resto de bloques
    for (int i = inicio; i < len; i += n) {
        int num = 0;
        for (int j = 0; j < n; j++) {
            num = num * 10 + (*(cadena + i + j) - '0');
        }
        suma += num;
    }

    return suma;
}
void sala_cine() {
    int filas = 15, columnas = 20, op;
    char *sala = new char[filas * columnas];

    for (int i = 0; i < filas * columnas; i++)
        *(sala + i) = '-';

    do {
        cout << "\n1.Mostrar 2.Reservar 3.Cancelar 4.Salir: ";
        cin >> op;

        if (op == 1) {
            cout << endl;
            for (int i = 0; i < filas; i++) {
                cout << char('A' + i) << " ";
                for (int j = 0; j < columnas; j++) {
                    cout << *(sala + i * columnas + j) << " ";
                }
                cout << endl;
            }
        }

        else if (op == 2) {
            char f; int a;
            cout << "Ingrese la fila: ";
            cin >> f;
            cout << "Ingrese asiento: ";
            cin >> a;

            int i = f - 'A';
            int j = a - 1;

            char *pos = sala + i * columnas + j;

            if (*pos == '+')
                cout << "Ocupado\n";
            else {
                *pos = '+';
                cout << "Reservado\n";
            }
        }

        else if (op == 3) {
            char f; int a;
            cout << "Ingrese la fila: ";
            cin >> f;
            cout << "Ingrese asiento: ";
            cin >> a;

            int i = f - 'A';
            int j = a - 1;

            char *pos = sala + i * columnas + j;

            if (*pos == '-')
                cout << "Ya libre\n";
            else {
                *pos = '-';
                cout << "Cancelado\n";
            }
        }

    } while (op != 4);

    delete[] sala;
}

int contarEstrellas(int *mat, int filas, int columnas) {
    int contador = 0;

    for (int i = 1; i < filas - 1; i++) {
        for (int j = 1; j < columnas - 1; j++) {

            int centro = *(mat + i * columnas + j);
            int izq    = *(mat + i * columnas + (j - 1));
            int der    = *(mat + i * columnas + (j + 1));
            int arriba = *(mat + (i - 1) * columnas + j);
            int abajo  = *(mat + (i + 1) * columnas + j);

            int promedio = (centro + izq + der + arriba + abajo) / 5;

            if (promedio > 6)
                contador++;
        }
    }

    return contador;
}

void rectangulo_interseccion() {
    int A[4], B[4], C[4];

    cout << "Ingrese rectangulo A (x y ancho alto): ";
    for (int i = 0; i < 4; i++)
        cin >> *(A + i);

    cout << "Ingrese rectangulo B (x y ancho alto): ";
    for (int i = 0; i < 4; i++)
        cin >> *(B + i);


    int xA = *(A + 0);
    int yA = *(A + 1);
    int xA_fin = *(A + 0) + *(A + 2);
    int yA_fin = *(A + 1) + *(A + 3);

    int xB = *(B + 0);
    int yB = *(B + 1);
    int xB_fin = *(B + 0) + *(B + 2);
    int yB_fin = *(B + 1) + *(B + 3);

    int xC = xA;
    if (xB > xC)
        xC = xB;

    int yC = yA;
    if (yB > yC)
        yC = yB;

    int xC_fin = xA_fin;
    if (xB_fin < xC_fin)
        xC_fin = xB_fin;

    int yC_fin = yA_fin;
    if (yB_fin < yC_fin)
        yC_fin = yB_fin;

    if (xC < xC_fin && yC < yC_fin) {
        *(C + 0) = xC;
        *(C + 1) = yC;
        *(C + 2) = xC_fin - xC;
        *(C + 3) = yC_fin - yC;
    } else {
        *(C + 0) = 0;
        *(C + 1) = 0;
        *(C + 2) = 0;
        *(C + 3) = 0;
    }

    cout << "Rectangulo interseccion: { ";
    for (int i = 0; i < 4; i++)
        cout << *(C + i) << " ";
    cout << "}" << endl;
}

void numeros_amigables() {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;

    int suma_total = 0;

    for (int i = 2; i < n; i++) {

        int suma1 = 0;
        int temp = i;
        int *ptr = &temp;

        // Suma divisores de i
        for (int k = 1; k < *ptr; k++) {
            if (*ptr % k == 0)
                suma1 += k;
        }

        int j = suma1;

        if (j != i && j < n) {

            int suma2 = 0;
            int temp2 = j;
            int *ptr2 = &temp2;

            // Suma divisores de j
            for (int k = 1; k < *ptr2; k++) {
                if (*ptr2 % k == 0)
                    suma2 += k;
            }

            if (suma2 == i && i < j) {
                suma_total += i + j;
            }
        }
    }

    cout << "El resultado de la suma es: " << suma_total << endl;
}
