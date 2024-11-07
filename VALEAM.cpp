#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;
#include "funciones.h"
#include "VIDEOJUEGO.h"
#include "USUARIO.h"
#include "BIBLIOTECA.h"

int main()
{
    int opcion1 = 1;
    while (opcion1 != 0)
    {   system("cls");
     setConsoleColor(15, 1);
    cout << "==============================" << endl;
    setConsoleColor(14, 1);
    cout << "           ESTIM              " << endl;
    setConsoleColor(15, 1);
    cout << "==============================" << endl << endl;
    setConsoleColor(15, 0);
    cout << "===============================" << endl;
    setConsoleColor(15, 0);
    cout << "       1 - REGISTRARSE            " << endl;
    setConsoleColor(15, 0);
    cout << "      2 - INICIAR SESION         " << endl;
    setConsoleColor(12, 0);
    cout << "          0 - SALIR                  " << endl;
    setConsoleColor(15, 0);
    cout << "===============================" << endl << endl;
        cin>>opcion1;
        switch (opcion1)
        {
        case 1: grabarRegistroUsuario(); break;
        case 2: inicioSesion(); break;
        default: break;
        }
    }
    return 0;
}
