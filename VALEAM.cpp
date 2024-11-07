#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;
#include "funciones.h"
#include "VIDEOJUEGO.h"
#include "USUARIO.h"
#include "BIBLIOTECA.h"


/*
void añadirVideojuegos()
{
    videoJuego obj;
    FILE *P;
    obj.cargar();
    P = fopen("archivos/videoJuego.dat", "ab");
    fwrite(&obj, sizeof (videoJuego),1,P);
    fclose(P);
}
*/
int main()
{
    int opcion1 = 1;
    while (opcion1 != 0)
    {   system("cls");
        setConsoleColor(15, 1);
        cout<<"==============================" << endl;
        cout<<"            ESTIM             "<<endl;
        cout<<"==============================" << endl<<endl;
        setConsoleColor(15,0);
        cout << "1 - REGISTRARSE              " << endl;
        cout << "2 - INICIAR SESION           " << endl;
        cout << "0 - SALIR                    " << endl;
        cout << "===============================" << endl;
        cout << "Seleccione una opcion:        " << endl;
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
