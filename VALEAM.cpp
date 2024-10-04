#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

#include "puntoH.h"

void setConsoleColor(int textColor, int backgroundColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute = textColor + (backgroundColor * 16);
    SetConsoleTextAttribute(hConsole, colorAttribute);
}


void mostrarTitulo(const string &titulo)
{
    setConsoleColor(15, 1);
    cout << "----- " << titulo << " -----" << endl;
    setConsoleColor(8, 0);
}


void grabarRegistros()
{
    videoJuego obj;
    FILE *P;
    obj.cargar();
    P = fopen("videoJuego.dat", "ab");
    fwrite(&obj, sizeof (videoJuego),1,P);
    fclose(P);
}

void listarVideojuegos()
{
    archivoVideoJuego arcV("videoJuego.dat");
    videoJuego game;

    int cantReg = arcV.contarRegistros();
    setConsoleColor(11, 0);
    cout<<"VideoJuegos: " << endl << endl;

    for (int i = 0; i < cantReg; i++)
    {
        game = arcV.leerRegistros(i);
        setConsoleColor(15, 0);
        cout<< i+1 << " - " << game.getTitulo() << endl;
    }
}

void caracteristicasVideojuego(int j)
{
    archivoVideoJuego arcV("videoJuego.dat");
    videoJuego game;

    game = arcV.leerRegistros(j-1);
    system("CLS");
    setConsoleColor(15, 0);
    game.mostrar();
    setConsoleColor(8, 0);
    return;

}

void buscarPorNombre(const char *n)
{
    archivoVideoJuego arcV("videoJuego.dat");
    videoJuego game;

    int cantReg = arcV.contarRegistros();

    for (int i = 0; i < cantReg; i++)
    {
        game = arcV.leerRegistros(i);
        if (game.getTitulo()==n)
        {
            system("CLS");
            setConsoleColor(15, 0);
            game.mostrar();
            setConsoleColor(8, 0);
            return;
        }
    }
    setConsoleColor(12, 0);
    cout<<"Titulo no encontrado, intente nuevamente." << endl;
    setConsoleColor(8, 0);
}

int main()
{

//grabarRegistros();


    int opcion = 1;

    while (opcion!=0)
    {

        int numJuego = 100;
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
            while (numJuego!=0)
            {
                system("CLS");
                listarVideojuegos();
                setConsoleColor(4, 0);
                cout<<"0 - ATRAS" << endl;
                setConsoleColor(8, 0);
                cin>>numJuego;
                if (numJuego == 0)
                {
                    break;
                }
                caracteristicasVideojuego(numJuego);
                system("PAUSE");
            }
            break;

        case 2:
            system("CLS");
            setConsoleColor(14, 0);
            cout<< "BUSCADOR: ";
            setConsoleColor(8, 0);
            cargarCadena(titJuego, 49);
            buscarPorNombre(titJuego);
            system("PAUSE");

        default:
            break;
        }
    }

    return 0;
}
