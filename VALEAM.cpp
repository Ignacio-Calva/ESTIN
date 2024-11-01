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

     ///LINEAS PARA PROBAR FUNCION DE COMPARAR STRINGS CON MAYUSCULAS DISTINTAS
    char texto1[30];
    char texto2[30];
    cout<<"Ingrese el texto 1: ";
    cargarCadena(texto1,29);
    cout << "Ingrese el texto 2: ";
    cargarCadena(texto2,29);
    if (compararSinMayusculas(texto1,texto2)){cout<<"Los textos son iguales"<<endl;}
    else{cout << "Los textos son distintos"<<endl;}
    system("pause");
    ///BORRAR DESPUES

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
