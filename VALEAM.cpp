#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;
#include "funciones.h"
#include "clases.h"


int main()
{
    int opcion = 1;

    while (opcion!=0)
    {
        char titJuego[50];
        system("CLS");
        setConsoleColor(15, 1);
        cout<<"VALEAM"<<endl;
        setConsoleColor(8, 0);
        cout<<"1 - Listar VideoJuegos"<<endl;
        cout<<"2 - Buscar VideoJuego"<<endl;
        cout<<"3 - Categorias"<<endl;
        cout<<"4 - Biblioteca"<<endl;
        cout<<"5 - Cuenta"<<endl;
        cout<<"0 - cerrar"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            elegirVideojuego();
            break;
        case 2:
            system("CLS");
            setConsoleColor(14, 0);
            cout<< "BUSCADOR: ";
            setConsoleColor(8, 0);
            cargarCadena(titJuego, 49);
            buscarPorNombre(titJuego);
            system("PAUSE");
            break;
        default:
            break;
        }
    }

    return 0;
}
