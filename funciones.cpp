#include <iostream>
using namespace std;
#include <cstring>
#include "funciones.h"
#include "clases.h"
#include <windows.h>

void elegirVideojuego(){
    int numJuego;
    archivoVideoJuego archJuego("archivos/videoJuego.dat");
    int tam = archJuego.contarRegistros();
    while (true)
    {
        system("CLS");
        listarVideojuegos();
        setConsoleColor(4, 0);
        cout<<endl<<"0 - ATRAS" << endl;
        setConsoleColor(8, 0);
        cout<<endl<<"INGRESE EL NUMERO DEL JUEGO DESEADO: ";
        cin>>numJuego;
        if(numJuego >= 0){
            if (numJuego == 0 ){break;}
            else if (numJuego > tam)
                {
                    cout << "NUMERO DE JUEGO NO ENCONTRADO."<<endl;
                    system("pause");
                }
        }
        caracteristicasVideojuego(numJuego);
        system("PAUSE");
    }
}

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


void listarVideojuegos()
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");
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
    archivoVideoJuego arcV("archivos/videoJuego.dat");
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
    archivoVideoJuego arcV("archivos/videoJuego.dat");
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

void cargarCadena(char *pal, int tam)
{
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}
