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
    {   setConsoleColor(15, 0);
        system("CLS");
        cout<<"VALEAM" << endl;
        cout<<"1 - REGISTRARSE" << endl;
        cout<<"2 - INICIAR SESION" << endl;
        cout<<"0 - SALIR" << endl;
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

/*Cuentas... Nombre: Chorizo, Contraseña: lol
             Nombre: cande, Contraseña: cande
             Nombre: nacho, Contraseña: nacho
             Nombre: valen, Contraseña: valen*/
