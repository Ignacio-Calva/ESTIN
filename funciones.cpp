#include <iostream>
using namespace std;
#include <cstring>
#include "funciones.h"
#include "VIDEOJUEGO.h"
#include "USUARIO.h"
#include <windows.h>

int idIniciada; //declaro variable global (WENNER DIJO QUE SE PUEDE, NO MUCHO, PERO UNA O DOS VECES SES)

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

    usuario usu;
    archivoUsuario arcU("archivos/Usuario.dat");

    usu = arcU.leerRegistros(datosUsuarioIniciado());

    int cantReg = arcV.contarRegistros();
    setConsoleColor(11, 0);
    cout<<"VideoJuegos: " << endl << endl;
    for (int i = 0; i < cantReg; i++)
    {
        game = arcV.leerRegistros(i);

        if (usu.getEdad() >= game.getRestriccion())
        {
            setConsoleColor(15, 0);
            cout<< i+1 << " - " << game.getTitulo() << endl;
        }
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
    usuario obj, objAux;
    archivoUsuario archivo("archivos/Usuario.dat");
    bool existe ;
    obj.cargarDatos();
    int tam=archivo.contarRegistros();
    objAux = archivo.leerRegistros(tam-1); //CARGA LOS DATOS DEL ULTIMO REGISTRO
    obj.setID(objAux.getID()+1); //AUTOMATICAMENTE ASIGNA COMO ID EL NUMERO SIGUIENTE
    for (int i = 0 ; i < tam ; i++)
    {
        objAux = archivo.leerRegistros(i);
        if (strcmp(obj.getNombre(),objAux.getNombre())!=0){existe = false;}
        else{existe = true;}
    }
    if (existe)
    {
        cout << "USUARIO EXISTENTE." << endl;
        system("pause");
        return;
    }
    cout << "ID DEL NUEVO USUARIO SETEADA COMO: " << obj.getID() << endl;
    system("pause");
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

    int pos=0; ///USADA POR REFERENCIA PARA GUARDAR DONDE FUE ENCONTRADO EL NOMBRE EN LA FUNCION buscarNombre()
    if (buscarNombre(nombre, pos))
    {
        usu = arcU.leerRegistros(pos);
        cout << "USUARIO CORRECTO." << endl;
        cout << "INGRESE LA CONTRASENIA: " ;
        cargarCadena(contrasenia, 19);
        if (strcmp(usu.getContrasenia(),contrasenia) == 0)
        {
            idIniciada = usu.getID(); //asignar ID iniciada
            cout << "SESION INICIADA CORRECTAMENTE." << endl;
            system("pause");
            system("cls");
            menuPrincipal();
        }
        else
        {
            cout << "CONTRASENIA INCORRECTA." << endl;
            system("pause");
        }
    }
    else
    {
        cout << "NOMBRE DE USUARIO INCORRECTO." << endl;
        system("pause");
    }
}

void menuPrincipal()
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
        case 1: menuFiltro(); break;
        case 2: buscarVideojuego(); break;
        case 4:   break;
        case 5: infoCuenta(); break; //AGREGO LA FUNCION AL MENU
        case 0: ;break;
        default: cout<< "Opcion invalida."; break;

        }
    }
}

void menuFiltro()
{
int opcion = 1;
while(opcion != 0){

    system("CLS");
    setConsoleColor(8, 0);
    cout<<"Listar videojuegos"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"1- Listar todos los videojuegos"<<endl;
    cout<<"ELEGIR FITROS" <<endl;
    cout<< "2- Listar por genero"<<endl;
    cout<< "3- Proximamente"<<endl;
    cout<< "0- ATRAS"<<endl;
    cin>> opcion;
    switch (opcion)
    {
    case 1: elegirVideojuego(); break;
    case 2: listarPorGenero(); break;
    default: cout<< "Opcion invalida."; break;
    }
  }
}

void infoCuenta() //nueva funcion
{
    int opcion = 1;

    usuario usu;
    archivoUsuario arcU("archivos/Usuario.dat");

    int cantReg = arcU.contarRegistros();

    for (int i = 0; i < cantReg; i++)
        {
            usu = arcU.leerRegistros(i);
            if (usu.getID() == idIniciada)
                {
                   while (opcion != 0){
                   system("CLS");
                   usu.mostrarDatos();

                   cout<<"1 - ELIMINAR CUENTA!"<<endl;
                   cout<<"0 - Salir"<<endl;
                   cin>>opcion;
                   switch (opcion)
                   {
                   case 1: cout<<"PROXIMAMENTE" << endl; system("PAUSE"); break;
                   case 0: break;
                   default: system("CLS"); cout<<"Opcion invalida" <<endl;
                       break;
                   }
                   }
                }
        }
}

bool buscarNombre(const char *_nombre, int &posicion)
{
    archivoUsuario archivo("archivos/Usuario.dat");
    usuario obj;
    int tam = archivo.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        obj = archivo.leerRegistros(i);
        if (strcmp(obj.getNombre(),_nombre) == 0)
        {
            posicion = i;
            return true;
        }
    }
    return false;
}

void listarPorGenero() //nueva funcion xdddddd (todavia esta en proceso)
{
    system("CLS");
    archivoVideoJuego arcV ("archivos/videojuego.dat");
    videoJuego game;
    char genero[30];
    cout<<"INGRESE EL GENERO QUE DESEA BUSCAR"<<endl;
    cargarCadena(genero, 29);
    int cantReg =arcV.contarRegistros();
    system("CLS");
    cout<<"FILTRO: "<< genero <<endl;
    for (int i = 0; i< cantReg ; i++ )
    {
    game = arcV.leerRegistros(i);
    if(strcmp(game.getGenero(), genero) == 0){ cout<< i+1<< " - "<< game.getTitulo() <<endl; }
    }
    system("PAUSE");
  }

int datosUsuarioIniciado()
{
    usuario usu;
    archivoUsuario arcU("archivos/Usuario.dat");

    int cantReg = arcU.contarRegistros();

    for (int i = 0; i < cantReg; i++)
    {
        usu = arcU.leerRegistros(i);
        if (usu.getID() == idIniciada)
        {
            return i;
        }
    }
}
