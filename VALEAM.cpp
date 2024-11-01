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
    //PRUEBA FECHAS
    Fecha fecha1,fecha2, fechaAnterior;
    cout << "CARGANDO FECHA 1" << endl;
    fecha1.cargar();
    cout << "CARGANDO FECHA 2" << endl;
    fecha2.cargar();
    fechaAnterior = compararFecha(fecha1,fecha2);
    fechaAnterior.mostrar();
    system("pause");
    //

    int opcion1 = 1;
    while (opcion1 != 0)
    {   setConsoleColor(15, 0);
        system("CLS");
        cout << "===============================" << endl;
        cout << "         STIM                 " << endl;
        cout << "===============================" << endl;
        setConsoleColor(15, 0);
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

/*Cuentas... Nombre: Chorizo, Contraseña: lol
             Nombre: cande, Contraseña: cande
             Nombre: nacho, Contraseña: nacho
             Nombre: valen, Contraseña: valen*/
