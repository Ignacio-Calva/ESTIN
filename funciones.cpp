#include <iostream>
using namespace std;
#include <cstring>
#include "funciones.h"
#include "VIDEOJUEGO.h"
#include "USUARIO.h"
#include <windows.h>

void elegirVideojuego()
{
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
        if(numJuego >= 0)
        {
            if (numJuego == 0 )
            {
                break;
            }
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

void buscarVideojuego()
{
    system("CLS");
    char titJuego[50];
    setConsoleColor(14, 0);
    cout<< "BUSCADOR: ";
    setConsoleColor(8, 0);
    cargarCadena(titJuego, 49);
    buscarPorNombre(titJuego);
    system("PAUSE");
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

void grabarRegistroUsuario()
{
//    usuario obj;
//    FILE *P;
//    obj.cargarDatos();
//    P = fopen("Usuario.dat", "ab");
//    fwrite(&obj, sizeof (videoJuego),1,P);
//    fclose(P); ///COMENTE ESTA FUNCION PORQUE EL GRABAR UN REGISTRO SE USA DESDE EL METODO DE LA CLASE
///BORRAR ESA PARTE COMENTADA (LA DEJE PARA QUE SE VEAN LOS CAMBIOS)
    usuario obj;
    archivoUsuario archivo("archivos/Usuario.dat");
    obj.cargarDatos();
    archivo.grabarRegistros(obj);
}

void inicioSesion()
{
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;

    char nombre[30];
    char contrasenia[20];

    cout<<"INGRESE EL NOMBRE DE USUARIO: " ;
    cargarCadena(nombre, 29);
    cout << "INGRESE LA CONTRASENIA: " ;
    cargarCadena(contrasenia, 19);

    int cantReg = arcU.contarRegistros();

    for (int i = 0; i < cantReg; i++)
    {
        usu = arcU.leerRegistros(i);

        if ( (strcmp(usu.getNombre(),nombre) == 0) && (strcmp(usu.getContrasenia(),contrasenia) == 0) ) ///SE USA STRCMP PARA COMPARAR CADENAS DE CARACTERES. SI SON IGUALES DEVUELVE 0
        {
            int opcion = 1;

            while (opcion!=0)
            {
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
                    buscarVideojuego();
                    break;
                case 4:

                    break;

                default:
                    break;
                }
            }
        } else{
            cout << "USUARIO O CONTRASENIA INCORRECTOS." << endl;
            system("pause");
        }

    }

}
