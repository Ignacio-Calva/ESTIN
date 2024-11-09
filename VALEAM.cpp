#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;
#include "funciones.h"
#include "VIDEOJUEGO.h"
#include "USUARIO.h"
#include "BIBLIOTECA.h"
#include "rlutil.h"
//#include <locale.h>

int main()
{
    //setlocale(LC_ALL, "");
    int opcion1 = 1;
    while (opcion1 != 0)
    {
        setConsoleColor(15, 3);
        system("cls");
        rlutil::locate(40,10);
        cout << char(201);
        ponerChar(205,28);
        cout << char(187);
        rlutil::locate(40,11);
        cout << char(186) <<"           ESTIM            " << char(186) << endl;
        rlutil::locate(40,12);
        cout << char(204);
        ponerChar(205,28);
        cout << char(185);
        rlutil::locate(40,13);
        cout << char(186) << "      1 - REGISTRARSE       " << char(186) << endl;
        rlutil::locate(40,14);
        cout << char(186) << "     2 - INICIAR SESION     " << char(186) << endl;
        rlutil::locate(40,15);
        cout << char(186) ;
        setConsoleColor(4, 3);
        cout << "         0 - SALIR          ";
        setConsoleColor(15, 3);
        cout << char(186);
        rlutil::locate(40,16);
        cout << char(204);
        ponerChar(205,28);
        cout << char (185);
        rlutil::locate(40,17);
        cout << char(186) <<"INGRESE UNA OPCION:         " << char(186) << endl;
        rlutil::locate(40,18);
        cout << char(200);
        ponerChar(205,28);
        cout << char (188);
        rlutil::locate(63,17);
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

