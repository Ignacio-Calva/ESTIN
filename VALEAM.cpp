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
    setConsoleColor(15, 3);
    system("cls");
    rlutil::locate(40,10);
    cout << "==============================" << endl;
    rlutil::locate(40,11);
    cout << "            ESTIM             " << endl;
    rlutil::locate(40,12);
    cout << "==============================" << endl;
    rlutil::locate(40,14);
    cout << "      1 - REGISTRARSE       " << endl;
    rlutil::locate(40,16);
    cout << "     2 - INICIAR SESION     " << endl;
    rlutil::locate(40,18);
    cout << "";
    setConsoleColor(4, 3);
    cout << "         0 - SALIR          ";
    setConsoleColor(15, 3);
    cout << "" << endl;
    rlutil::locate(40,20);
    cout << "==============================" << endl << endl;
    rlutil::locate(40,22);
    cout << "INGRESE UNA OPCION:         " << endl;
    rlutil::locate(60,22);
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
