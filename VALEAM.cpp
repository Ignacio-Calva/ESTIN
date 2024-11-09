#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;
#include "funciones.h"
#include "VIDEOJUEGO.h"
#include "USUARIO.h"
#include "BIBLIOTECA.h"
#include "rlutil.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    int opcion1 = 1;
    while (opcion1 != 0)
    {
    system("cls");
    setConsoleColor(15, 1);
    rlutil::locate(40,10);
    cout << "==============================" << endl;
    setConsoleColor(14, 1);
    rlutil::locate(40,11);
    cout << "            ESTIM             " << endl;
    setConsoleColor(15, 1);
    rlutil::locate(40,12);
    cout << "==============================" << endl << endl;
    setConsoleColor(15, 0);
    rlutil::locate(40,13);
    cout << "==============================" << endl;
    setConsoleColor(15, 0);
    rlutil::locate(40,14);
    cout << "|      1 - REGISTRARSE       |" << endl;
    setConsoleColor(15, 0);
    rlutil::locate(40,15);
    cout << "|     2 - INICIAR SESION     |" << endl;
    rlutil::locate(40,16);
    cout << "|";
    setConsoleColor(12, 0);
    cout << "         0 - SALIR          ";
    setConsoleColor(15, 0);
    cout << "|" << endl;
    rlutil::locate(40,17);
    cout << "==============================" << endl << endl;
    rlutil::locate(40,18);
    cout << "|INGRESE UNA OPCION:         |" << endl;
    rlutil::locate(40,19);
    cout << "==============================" << endl;
    rlutil::locate(63,18);
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
