#include <iostream>
using namespace std;
#include <cstring>
#include "funciones.h"
#include "VIDEOJUEGO.h"
#include "BIBLIOTECA.h"
#include "USUARIO.h"
#include "DESARROLLADOR.h"
#include "ADMIN.h"
#include "GENERO.h"
#include "rlutil.h"
#include <windows.h>
#include <conio.h>

int idIniciada;
Admin cuentaAdmin("admin","password",0,true);

///FUNCIONES MENU

void menuPrincipal()
{
    int opcion = 1;
    while (opcion!=0)
    {
        archivoUsuario arcU("archivos/Usuario.dat");
        usuario usu;
        usu = arcU.leerRegistros(idIniciada-1);
        if (usu.getActivo()==false)
        {
            return;
        }

        setConsoleColor(15, 1);
        system("CLS");

        rlutil::locate(3,2);
        cout<< "ESTIM.";

        rlutil::locate(100,2);
        cout<<"Usuario: " << usu.getNombre()<<endl;
        rlutil::locate(100,3);
        cout<<"ID: " << idIniciada<<endl;

        rlutil::locate(30,5);

        ponerChar(205,50);

        rlutil::locate(30,6);

        cout<<"        MENU PRINCIPAL        "<<endl;
        rlutil::locate(30,7);
        ponerChar(205,50);
        setConsoleColor(3,1);
        rlutil::locate(40,10);
        cout<<"1 - Listar VideoJuegos"<<endl;
        rlutil::locate(40,12);
        cout<<"2 - Buscar VideoJuego"<<endl;
        rlutil::locate(40,14);
        cout<<"3 - Biblioteca"<<endl;
        rlutil::locate(40,16);
        cout<<"4 - Cuenta"<<endl;
        setConsoleColor(4,1);
        rlutil::locate(40,18);
        cout<<"0 - Cerrar"<<endl;
        setConsoleColor(15,1);
        rlutil::locate(30,20);

        ponerChar(205,50);

        rlutil::locate(40,22);
        cout << "Ingrese una opcion: ";
        rlutil::locate(60,22);
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            menuFiltro();
            break;
        case 2:
            buscarVideojuego();
            break;
        case 3:
            menuBiblioteca();
            break;
        case 4:
            infoCuenta();
            break;
        case 0: return;
            break;
        default:
            rlutil::locate(60,22);
            cout<< "Opcion invalida.";
            system("pause");
            break;
        }
    }
}

void menuBiblioteca()
{
    int opcion = 1;
    while (opcion!=0)
    {
        setConsoleColor(15, 3);

        system("CLS");

        setConsoleColor(15, 3);

        rlutil::locate(40,3);
        cout<<"==============================" << endl;
        rlutil::locate(40,4);
        cout<<"      BIBLIOTECA ESTIM        "<<endl;
        rlutil::locate(40,5);
        cout<<"==============================" << endl<<endl;
        setConsoleColor(15,3);
        rlutil::locate(6,3);
        cout<<"ID de cuenta iniciada: " << idIniciada<<endl;

        rlutil::locate(40,10);
        cout<<"1) - Listar biblioteca personal"<<endl;
        rlutil::locate(40,12);
        cout<<"2) - Listar biblioteca por nombre"<<endl;
        rlutil::locate(40,14);
        cout<<"3) - Listar biblioteca por genero"<<endl;
        rlutil::locate(40,16);
        cout<<"4) - Listar biblioteca por desarrollador"<<endl;
        rlutil::locate(40,18);
        cout<<"5) - Registro de compras"<<endl;

        rlutil::locate(45,20);
        setConsoleColor(4,3);
        cout<<"0 - Cerrar"<<endl;

        setConsoleColor(15, 3);

        rlutil::locate(10,26);
        cout<<"Ingrese su opcion :"<<endl;
        rlutil::locate(30,26);
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            mostrarBibliotecaDeUsuario(idIniciada);
            break;
        case 2:
            bibliotecaXnombre(idIniciada);
            break;
        case 3:
            bibliotecaXgenero(idIniciada);
            break;
        case 4:
            bibliotecaXdesarrollador(idIniciada);
            break;
        case 5:
            registroCompras();
            break;
        case 0:

            break;
        default:
            rlutil::locate(30,26);
            cout<< "Opcion invalida.";
            system("pause");
            break;
        }
    }

}

void menuFiltro()
{
    int opcion = 1;
    while(opcion != 0)
    {
        archivoUsuario arcU("archivos/Usuario.dat");
        usuario usu;
        usu = arcU.leerRegistros(idIniciada-1);

        setConsoleColor(15, 1);
        system("CLS");

        rlutil::locate(3,2);
        cout<< "ESTIM.";

        rlutil::locate(100,2);
        cout<<"Usuario: " << usu.getNombre()<<endl;
        rlutil::locate(100,3);
        cout<<"ID: " << idIniciada<<endl;

        rlutil::locate(40,5);
        cout<< "==============================" << endl;
        rlutil::locate(40,6);
        cout<< "      LISTAR VIDEOJUEGOS      " << endl;
        rlutil::locate(40,7);
        cout<< "==============================" << endl<<endl;
        setConsoleColor(3,1);

        rlutil::locate(40,10);
        cout << "1. Listar todos los videojuegos" << endl;
        rlutil::locate(40,12);
        cout << "2. Listar por genero" << endl;
        rlutil::locate(40,14);
        cout << "3. Listar por creador" << endl;
        rlutil::locate(40,16);
        cout << "4. Listar por precio" << endl;
        rlutil::locate(40,18);
        cout << "5- Listar por anio"<<endl;
        rlutil::locate(40,20);
        cout << "6- Listar por gratuito"<<endl;
        setConsoleColor(4, 1);
        rlutil::locate(40,22);
        cout << "0. ATRAS" << endl;
        setConsoleColor(15, 1);
        rlutil::locate(40,24);
        cout << "=============================" << endl;
        rlutil::locate(40,26);
        cout << "Ingrese una opcion: ";
        rlutil::locate(60,26);
        cin>> opcion;
        setConsoleColor(15, 1);
        switch (opcion)
        {
        case 1:
            elegirVideojuego();
            break;
        case 2:
            listarPorGenero();
            break;
        case 3:
            listarPorCreador();
            break;
        case 4:
            mostrarPorPrecio();
            break;
        case 5:
            listarPorAnio();
            break;
        case 6:
            listarPorGratuito();
        case 0:
            break;
        default:
            rlutil::locate(60,26);
            cout<< "Opcion invalida.";
            system("pause");
            break;
        }
    }
}

void menuAdministrador()
{
    while (true)
    {
        setConsoleColor(11, 1);
        system("cls");
        archivoAdmin arcA("archivos/admin.dat");
        Admin adm;
        int tam = arcA.contarRegistros();
        for (int i = 0; i < tam; i++)
        {
            adm = arcA.leerRegistros(i);
            if (adm.getIdAdmin()==idIniciada && adm.getAdmin()==false)
            {
                return;
            }
        }
        system("cls");
        int opcion;
        rlutil::locate(40,5);
        cout<< "==============================" << endl;
        rlutil::locate(40,6);
        cout<< "       MENU ADMINISTRADOR     " << endl;
        rlutil::locate(40,7);
        cout<< "==============================" << endl<<endl;
        setConsoleColor(3,1);
        rlutil::locate(40,9);
        cout << "(1) Agregar juego a la tienda" << endl;
        rlutil::locate(40,10);
        cout << "(2) Modificar videojuego existente" << endl;
        rlutil::locate(40,11);
        cout << "(3) Deshabilitar juego de la tienda" << endl;
        rlutil::locate(40,12);
        cout << "(4) Habilitar juego de la tienda" << endl;
        rlutil::locate(40,13);
        cout << "(5) Listar todos los videojuegos+info" << endl;
        rlutil::locate(40,14);
        cout << "(6) Habilitar cuenta" << endl;
        rlutil::locate(40,15);
        cout << "(7) Deshabilitar cuenta" << endl;
        rlutil::locate(40,16);
        cout << "(8) Otorgar permisos de administrador" << endl;
        rlutil::locate(40,17);
        cout << "(9) Remover permisos de administrador" << endl;
        rlutil::locate(40,18);
        cout << "(10) Listar admins registrados" << endl;
        rlutil::locate(40,19);
        cout << "(11) Videojuegos mas vendidos" << endl;
        rlutil::locate(40,20);
        cout << "(12) Puntos de restauracion del sistema" << endl;
        rlutil::locate(40,21);
        cout << "============================================" << endl;
        setConsoleColor(4,1);
        rlutil::locate(40,22);
        cout << "(0) SALIR." << endl;
        setConsoleColor(15,1);
        rlutil::locate(40,26);
        cout << "Ingrese una opcion: ";
        rlutil::locate(60,26);
        cin>> opcion;
        switch (opcion)
        {
        case 1:
            cargarVideojuego();
            break;
        case 2:
            modificarVideojuego();
            break;
        case 3:
            deshabilitarVideojuego();
            break;
        case 4:
            habilitarVideojuego();
            break;
        case 5:
            listarVideojuegosMod();
            break;
        case 6:
            habilitarCuentaUsuario();
            break;
        case 7:
            deshabilitarCuentaUsuario();
            break;
        case 8:
            otorgarAdmin();
            break;
        case 9:
            removerAdmin();
            break;
        case 10:
            mostrarArchivoAdmin();
            break;
        case 11:
            menuVideojuegosMasVendidos();
            break;
        case 12:
            puntoRestauracion();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}


void cargarContraseniaOculta(char* contrasenia, int maxLongitud)
{
    int tam = 0;
    char ch;

    while (true)
    {
        ch = _getch();

        if (ch == 13)    // Enter
        {
            contrasenia[tam] = '\0';
            cout << endl;
            break;
        }
        else if (ch == 8 && tam > 0)      // Backspace
        {
            cout << "\b \b";
            tam--;
        }
        else if (tam < maxLongitud && ch != 8)      // Caracter válido
        {
            contrasenia[tam++] = ch;
            cout << '*';
        }
    }
}

bool menuModificarVideojuego(int idJuego)
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;
    int tam = arcV.contarRegistros();
    char pal[30];
    int num1;
    float num2;
    int opcion;
    while (true)
    {
        game = arcV.leerRegistros(idJuego-1);
        system("cls");
        rlutil::locate(40,5);
        cout << "==================================================" << endl;
        rlutil::locate(40,6);
        cout << "MODIFICACION JUEGO: " << game.getTitulo() << endl;
        rlutil::locate(40,7);
        cout << "==================================================" << endl;
        rlutil::locate(40,9);
        cout << "(1) Modificar nombre" << endl;
        rlutil::locate(40,10);
        cout << "(2) Modificar genero" << endl;
        rlutil::locate(40,11);
        cout << "(3) Modificar precio" << endl;
        rlutil::locate(40,12);
        cout << "(4) Modificar calificacion"<< endl;
        rlutil::locate(40,13);
        cout << "(5) Modificar idioma"<< endl;
        rlutil::locate(40,14);
        cout << "(6) Modificar desarrollador"<< endl;
        rlutil::locate(40,15);
        cout << "(7) Modificar peso"<< endl;
        rlutil::locate(40,16);
        cout << "(8) Modificar restriccion anio"<< endl;
        rlutil::locate(40,17);
        cout << "(9) Modificar anio"<< endl;
        rlutil::locate(40,18);
        cout << "(10) Modificar todo" << endl;
        rlutil::locate(40,19);
        cout << "=======================================" << endl;
        setConsoleColor(4,1);
        rlutil::locate(40,20);
        cout << "(0) SALIR." << endl;
        setConsoleColor(11,1);
        rlutil::locate(40,21);
        cout << "Ingrese una opcion: ";
        rlutil::locate(60,21);
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        case 1:
            rlutil::locate(40,5);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,6);
            cout<<"    Modificar Nombre    "<<endl;
            rlutil::locate(40,7);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,9);
            cout<<"Ingrese el nuevo nombre: ";
            rlutil::locate(65,9);
            cargarCadena(pal, 29);

            for (int i = 0; i < tam; i++)
            {
                game = arcV.leerRegistros(i);
                if (strcmp(pal, game.getTitulo())==0)
                {
                    rlutil::locate(65,9);
                    setConsoleColor(4, 1);
                    cout<<"Ya existe un videojuego con ese nombre.";
                    rlutil::locate(40,10);
                    setConsoleColor(11, 1);
                    return false;
                }
            }
            game = arcV.leerRegistros(idJuego-1);
            game.setTitulo(pal);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 2:
            rlutil::locate(40,5);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,6);
            cout<<"    Modificar Genero    "<<endl;
            rlutil::locate(40,7);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,9);
            cout<<"Ingrese el nuevo genero: ";
            rlutil::locate(65,9);
            cargarCadena(pal, 29);
            game = arcV.leerRegistros(idJuego-1);
            game.setGenero(pal);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 3:
            rlutil::locate(40,5);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,6);
            cout<<"    Modificar Precio    "<<endl;
            rlutil::locate(40,7);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,9);
            cout<<"Ingrese el nuevo precio: ";
            rlutil::locate(65,9);
            cin>>num2;
            if (num2 < 0)
            {
                setConsoleColor(4,1);
                rlutil::locate(65,9);
                cout<<"El precio no puede ser negativo.";
                setConsoleColor(11, 1);
                rlutil::locate(65,10);
                return false;
            }
            game = arcV.leerRegistros(idJuego-1);
            game.setPrecio(num2);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 4:
            rlutil::locate(40,5);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,6);
            cout<<" Modificar calificacion "<<endl;
            rlutil::locate(40,7);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,9);
            cout<<"Ingrese la nueva calificacion: ";
            rlutil::locate(70,9);
            cin>>num2;
            if (num2 < 0)
            {
                setConsoleColor(4,1);
                rlutil::locate(70,9);
                cout<<"La calificacion no puede ser negativa." << endl;
                setConsoleColor(11, 1);
                rlutil::locate(65,10);
                return false;
            }
            if (num2 > 100)
            {
                setConsoleColor(4,1);
                rlutil::locate(70,9);
                cout<<"La calificacion no puede ser mayor que 100 ." << endl;
                setConsoleColor(11, 1);
                return false;
            }
            game = arcV.leerRegistros(idJuego-1);
            game.setCalificacion(num2);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 5:
            rlutil::locate(40,5);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,6);
            cout<<"    Modificar Idioma    "<<endl;
            rlutil::locate(40,7);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,9);
            cout<<"Ingrese el nuevo idioma: ";
            rlutil::locate(65,9);
            cargarCadena(pal, 29);

            game = arcV.leerRegistros(idJuego-1);
            game.setIdioma(pal);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 6:
            rlutil::locate(40,5);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,6);
            cout<<"Modificar  Desarrollador"<<endl;
            rlutil::locate(40,7);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,9);
            cout<<"Ingrese el nuevo desarrollador: ";
            rlutil::locate(65,9);
            cargarCadena(pal, 29);

            game = arcV.leerRegistros(idJuego-1);
            game.setDesarrollador(pal);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 7:
            rlutil::locate(40,5);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,6);
            cout<<"     Modificar Peso     "<<endl;
            rlutil::locate(40,7);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,9);
            cout<<"Ingrese el nuevo peso: ";
            rlutil::locate(63,9);
            cin>>num1;
            if (num1 < 0)
            {
                setConsoleColor(4,1);
                rlutil::locate(63,9);
                cout<<"El peso no puede ser negativo.";
                setConsoleColor(11, 1);
                rlutil::locate(63,10);
                return false;
            }
            game = arcV.leerRegistros(idJuego-1);
            game.setPeso(num1);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 8:
            rlutil::locate(40,5);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,6);
            cout<<" Modificar  Restriccion "<<endl;
            rlutil::locate(40,7);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,9);
            cout<<"Ingrese la nueva restriccion de edad: ";
            rlutil::locate(78,9);
            cin>>num1;
            if (num1 < 0)
            {
                setConsoleColor(4,1);
                rlutil::locate(78,9);
                cout<<"La restriccion no puede ser negativa.";
                setConsoleColor(11, 1);
                rlutil::locate(78,10);
                return false;
            }
            game = arcV.leerRegistros(idJuego-1);
            game.setRestriccionEdad(num1);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 9:
            rlutil::locate(40,5);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,6);
            cout<<"     Modificar Anio     "<<endl;
            rlutil::locate(40,7);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,9);
            cout<<"Ingrese el nuevo anio de salida: ";
            rlutil::locate(65,9);
            cin>>num1;
            game = arcV.leerRegistros(idJuego-1);
            game.setAnio(num1);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 10:
            rlutil::locate(40,5);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,6);
            cout<<"    Modificar Nombre    "<<endl;
            rlutil::locate(40,7);
            cout<<"------------------------"<<endl;
            rlutil::locate(40,9);
            cout<< "---- ID: " << idJuego << " ----"<<endl;
            rlutil::locate(40,10);
            cout<<"Ingrese el nuevo nombre: ";
            rlutil::locate(65,10);
            cargarCadena(pal, 29);

            for (int i = 0; i < tam; i++)
            {
                game = arcV.leerRegistros(i);
                if (strcmp(pal, game.getTitulo())==0)
                {
                    setConsoleColor(4, 1);
                    rlutil::locate(65,10);
                    cout<<"Ya existe un videojuego con ese nombre.";
                    setConsoleColor(11, 1);
                    rlutil::locate(40, 11);
                    return false;
                }
            }
            game = arcV.leerRegistros(idJuego-1);
            game.setTitulo(pal);
            rlutil::locate(40,11);
            cout<<"Ingrese el nuevo genero: ";
            cargarCadena(pal, 29);
            game.setGenero(pal);
            rlutil::locate(40,12);
            cout<<"Ingrese el nuevo precio: ";
            cin>>num2;
            if (num2 < 0)
            {
                setConsoleColor(4,1);
                rlutil::locate(65,12);
                cout<<"El precio no puede ser negativo.";
                setConsoleColor(11, 1);
                rlutil::locate(65,13);
                return false;
            }
            game.setPrecio(num2);
            rlutil::locate(40,13);
            cout<<"Ingrese la nueva calificacion: ";
            cin>>num2;
            if (num2 < 0)
            {
                setConsoleColor(4,1);
                rlutil::locate(70,13);
                cout<<"La calificacion no puede ser negativa.";
                setConsoleColor(11, 1);
                rlutil::locate(65,14);
                return false;
            }
            if (num2 > 100)
            {

                setConsoleColor(4,1);
                rlutil::locate(65, 13);
                cout<<"La calificacion no puede ser mayor que 100 .";
                setConsoleColor(11, 14);
                return false;
            }
            game.setCalificacion(num2);
            rlutil::locate(40,14);
            cout<<"Ingrese el nuevo idioma: ";
            cargarCadena(pal, 29);
            game.setIdioma(pal);
            rlutil::locate(40,15);
            cout<<"Ingrese el nuevo desarrollador: ";
            cargarCadena(pal, 29);
            game.setDesarrollador(pal);
            rlutil::locate(40,16);
            cout<<"Ingrese el nuevo peso: ";
            cin>>num1;
            if (num1 < 0)
            {
                setConsoleColor(4,1);
                rlutil::locate(63,16);
                cout<<"El peso no puede ser negativo.";
                setConsoleColor(11, 1);
                rlutil::locate(63,17);
                return false;
            }
            game.setPeso(num1);
            rlutil::locate(40,17);
            cout<<"Ingrese la nueva restriccion: ";
            cin>>num1;
            if (num1 < 0)
            {
                setConsoleColor(4,1);
                rlutil::locate(69,17);
                cout<<"La restriccion no puede ser negativa.";
                setConsoleColor(11, 1);
                rlutil::locate(69,18);
                return false;
            }
            game.setRestriccionEdad(num1);
            rlutil::locate(40,18);
            cout<<"Ingrese el nuevo anio: ";
            cin>>num1;
            game.setAnio(num1);
            arcV.modificarVideojuego(game, idJuego-1);
        case 0:
            return true;
        default:
            break;
        }

    }
}

void menuVideojuegosMasVendidos()
{
    int opcion;
    while (true)
    {
        system("cls");
        cout << "=======================================" << endl;
        cout << "     MENU VIDEOJUEGOS MAS VENDIDOS     " << endl;
        cout << "=======================================" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "(1) Videojuego mas vendido (SIN FILTROS)" << endl;
        cout << "(2) Videojuego mas vendido SEGUN GENERO" << endl;
        cout << "(3) Videojuego mas vendido SEGUN DESARROLLADOR" << endl;
        cout << "(4) Total vendido "<< endl;
        cout << "=======================================" << endl<<endl;
        setConsoleColor(4,1);
        cout << "(0) SALIR." << endl;
        setConsoleColor(15,1);
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            system("cls");
            estadisticasJuegosMasComprados();
            break;
        case 2:
            system("cls");
            videojuegoMasVendidoGenero();
            break;
        case 3:
            system("cls");
            videojuegoMasVendidoDesarrollador();
            break;
        case 4:
            system("cls");
            juegosVendidos();
            break;
        case 0:
            return;
        default:
            break;
        }

    }

}


///FUNCIONES COMUNES

bool compararSinMayusculas(const char* texto1, const char* texto2)
{
    int longitud1 = strlen(texto1);
    int longitud2 = strlen(texto2);
    char textoPasado1[30] {};
    char textoPasado2[30] {};
    strcpy(textoPasado1,texto1);
    strcpy(textoPasado2,texto2);
    if (longitud1 == longitud2)
    {
        for (int i = 0 ; i < longitud1 ; i++)
        {
            if(texto1[i] >=65 && texto1[i] <= 90)
            {
                textoPasado1[i] += 32;
            }
            if(texto2[i] >=65 && texto2[i] <= 90)
            {
                textoPasado2[i] += 32;
            }
        }
        if (strcmp(textoPasado1,textoPasado2) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
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

void inicioSesion()
{
    while (true)
    {
        archivoUsuario arcU("archivos/Usuario.dat");
        usuario usu;
        archivoAdmin arcA("archivos/admin.dat");
        Admin adm;

        char nombre[30];
        char contrasenia[20];
        setConsoleColor(15,3);
        system("cls");
        rlutil::locate(30,10);
        cout << char(201);
        ponerChar(205,60);
        cout << char(187);
        rlutil::locate(30,11);
        cout << char(186);
        cout << "                      INICIO DE SESION                      ";
        cout << char(186);
        rlutil::locate(30,12);
        cout << char(204);
        ponerChar(205,60);
        cout << char (185);
        rlutil::locate(30,13);
        cout << char (186) <<"                                                            " << char(186) ;
        rlutil::locate(30,14);
        cout << char(186) << "Ingrese su nombre de usuario:                               " << char(186) ;
        rlutil::locate(30,15);
        cout << char(186) << "Ingrese su contrase"<< char(164) <<"a:                                      " << char(186) ;
        rlutil::locate(30,16);
        cout << char (186) <<"                                                            " << char(186) ;
        rlutil::locate(30,17);
        cout << char(200);
        ponerChar(205,60);
        cout << char(188);
        rlutil::locate(61,14);
        cargarCadena(nombre, 29);

        int pos=0; ///USADA POR REFERENCIA PARA GUARDAR DONDE FUE ENCONTRADO EL NOMBRE EN LA FUNCION buscarNombre()



        ///LOGUEO ADMIN MAIN
        if(strcmp(cuentaAdmin.getNombre(),nombre) == 0)
        {
            if (hayUnAdmin()==true)
            {
                rlutil::locate(30,18);
                setConsoleColor(4, 3);
                cout << "La cuenta de administrador principal se encuentra deshabilitada." << endl;
                rlutil::locate(42,19);
                setConsoleColor(8, 3);
                system("pause");
                system("cls");
                return;
            }///CONFIRMO QUE NO HAYA SIDO DESHABILITADA ANTERIORMENTE
            system("cls");
            rlutil::locate(30,10);
            cout << char(201);
            ponerChar(205,60);
            cout << char(187);
            rlutil::locate(30,11);
            cout << char(186);
            cout << "                      INICIO DE SESION                      ";
            cout << char(186);
            rlutil::locate(30,12);
            cout << char(204);
            ponerChar(205,60);
            cout << char (185);
            rlutil::locate(30,13);
            cout << char (186) <<"                                                            " << char(186) ;
            rlutil::locate(30,14);
            cout << char(186) << "Ingrese su nombre de usuario:                               " << char(186) ;
            rlutil::locate(61,14);
            cout << nombre;
            rlutil::locate(30,15);
            cout << char(186) << "Ingrese su contrase"<< char(164) <<"a:                                      " << char(186) ;
            rlutil::locate(30,16);
            cout << char (186) <<"                                                            " << char(186) ;
            rlutil::locate(30,17);
            cout << char(200);
            ponerChar(205,60);
            cout << char(188);
            rlutil::locate(54,15);
            cargarContraseniaOculta(contrasenia,19);
            /////



            if (strcmp(contrasenia,cuentaAdmin.getContrasenia()) == 0)
            {
                rlutil::locate(30,18);
                cout << "                    " << char(173) << "Contrase"<< char(164) <<"a correcta!                     " << endl;
                rlutil::locate(30,19);
                cout << "Se ha iniciado sesion con la cuenta de administrador principal. " << endl;
                setConsoleColor(15, 3);
                /*rlutil::locate(40, 20);
                if (cuentaAdmin.getAdmin()) cout << "Esta cuenta tiene permisos de administrador."<<endl;*/
                rlutil::locate(42,21);
                setConsoleColor(8,3);
                system("pause");
                system("cls");
                menuAdministrador();
                break;
            }
            else
            {
                rlutil::locate(54,15);
                setConsoleColor(4, 3);
                cout << "contrase"<< char(164) <<"a incorrecta" << endl;
                rlutil::locate(42,18);
                setConsoleColor(8, 3);
                system("pause");
                return;
            }
        }
        else///SI NO SE PUDO INICIAR COMO ADMIN MAIN, PRUEBA CON OTROS USUARIOS
        {
            if (buscarNombre(nombre, pos))
            {
               system("cls");
            rlutil::locate(30,10);
            cout << char(201);
            ponerChar(205,60);
            cout << char(187);
            rlutil::locate(30,11);
            cout << char(186);
            cout << "                      INICIO DE SESION                      ";
            cout << char(186);
            rlutil::locate(30,12);
            cout << char(204);
            ponerChar(205,60);
            cout << char (185);
            rlutil::locate(30,13);
            cout << char (186) <<"                                                            " << char(186) ;
            rlutil::locate(30,14);
            cout << char(186) << "Ingrese su nombre de usuario:                               " << char(186) ;
            rlutil::locate(61,14);
            cout << nombre;
            rlutil::locate(30,15);
            cout << char(186) << "Ingrese su contrase"<< char(164) <<"a:                                      " << char(186) ;
            rlutil::locate(30,16);
            cout << char (186) <<"                                                            " << char(186) ;
            rlutil::locate(30,17);
            cout << char(200);
            ponerChar(205,60);
            cout << char(188);
                usu = arcU.leerRegistros(pos);
                rlutil::locate(30, 18);

                if (usu.getActivo() == false && usu.getAdmin()==false)
                {
                    cout << "Esta cuenta esta deshabilitada"<< endl;
                    system("pause");
                    return;
                }
                rlutil::locate(30,15);
            cout << char(186) << "Ingrese su contrase"<< char(164) <<"a:                                      " << char(186) ;
            rlutil::locate(54,15);
                cargarContraseniaOculta(contrasenia, 19);
                if (strcmp(usu.getContrasenia(),contrasenia) == 0)
                {
                    idIniciada = usu.getID(); //asignar ID iniciada
                    if (usu.getAdmin()==false)
                    {
                        rlutil::locate(30,18);
                        cout << "                     Contrase"<< char(164) <<"a correcta!                     " << endl;
                        rlutil::locate(30,19);
                        cout << "                 Sesion iniciada correctamente!" << endl;
                        rlutil::locate(42,21);
                        setConsoleColor(8,3);
                        system("pause");
                        menuPrincipal();
                    }
                    else
                    {
                        rlutil::locate(30,18);
                        cout << "                     contrase"<< char(164) <<"a correcta!                     " << endl;
                        setConsoleColor(15, 3);
                        rlutil::locate(40, 20);
                        if (cuentaAdmin.getAdmin()) cout << "Esta cuenta tiene permisos de administrador."<<endl;
                        rlutil::locate(42,21);
                        setConsoleColor(8,3);
                        system("pause");
                        system("cls");
                        menuAdministrador();
                        break;
                        break;
                    }
                }
                else
                {
                    rlutil::locate(54,15);
                    setConsoleColor(4, 3);
                    cout << "contrase"<< char(164) <<"a incorrecta" << endl;
                    rlutil::locate(42,18);
                    setConsoleColor(8, 3);
                    system("pause");
                }
            }
            else
            {
                rlutil::locate(60,14);
                setConsoleColor(4, 3);
                cout << "Nombre de usuario no encontrado" << endl;
                rlutil::locate(42,18);
                setConsoleColor(8, 3);
                system("pause");
            }
            return;
        }
    }
}

///FUNCIONES USUARIO

void grabarRegistroUsuario()
{
    system("cls");
    rlutil::locate(40,5);
        cout<< "==============================" << endl;
        rlutil::locate(40,6);
        cout<< "      REGISTRAR USUARIO      " << endl;
        rlutil::locate(40,7);
        cout<< "==============================" << endl<<endl;
    usuario obj, objAux;
    archivoUsuario archivo("archivos/Usuario.dat");
    char nombre[30];
    char contra[20];
    Fecha obj2,fechaActual;
    int edad;
    int dni;
    char mail[30];
    char pais[30];
    int tam=archivo.contarRegistros();
    if (tam > 0)
    {
        objAux = archivo.leerRegistros(tam-1); //CARGA LOS DATOS DEL ULTIMO REGISTRO
        obj.setID(objAux.getID()+1); //AUTOMATICAMENTE ASIGNA COMO ID EL NUMERO SIGUIENTE
    }
    else
    {
        obj.setID(1);
    }
    rlutil::locate(40,9);
    cout << "INGRESE EL NOMBRE DE USUARIO: ";
    cargarCadena(nombre, 29);
    for (int i=0 ; i < tam ; i++)
    {
        objAux = archivo.leerRegistros(i);
        if (strcmp(nombre,objAux.getNombre())==0 || strcmp(nombre,"admin")==0)
        {
            rlutil::locate(69,9);
            setConsoleColor(4,3);
            cout << "El nombre de usuario ya esta en uso." << endl;
            rlutil::locate(40,10);
            setConsoleColor(8,3);
            system("pause");
            system("cls");
            return;
        }
        else if (strcmp(nombre,"")==0)
        {
            rlutil::locate(69,9);
            setConsoleColor(4,3);
            cout << "No puede dejar este campo vacio." << endl;
            rlutil::locate(40,10);
            setConsoleColor(8,3);
            system("pause");
            system("cls");
            return;
        }
    }
    obj.setNombre(nombre);
    rlutil::locate(40,10);
    cout << "INGRESE LA CONTRASENIA DEL USUARIO: ";
    cargarCadena(contra, 19);
    if (strcmp(contra,"")==0)
    {
        rlutil::locate(75,10);
            setConsoleColor(4,3);
            cout << "No puede dejar este campo vacio." << endl;
            rlutil::locate(40,11);
            setConsoleColor(8,3);
            system("pause");
            system("cls");
        return;
    }
    obj.setContrasenia(contra);
    rlutil::locate(40,11);
    cout<< "INGRESE SU FECHA DE NACIMIENTO..." << endl;
    if (obj2.cargarPorLocate(40,12) == false){system("pause");return;}
    fechaActual.cargarFechaActual();
    if(fechaActual.getMes() > obj2.getMes()){
        edad =  fechaActual.getAnio() - obj2.getAnio();
    } else if (fechaActual.getMes() == obj2.getMes()){
        if (fechaActual.getDia() >= obj2.getDia()){
            edad = fechaActual.getAnio() - obj2.getAnio();
        }
        else {edad = fechaActual.getAnio() - obj2.getAnio()-1;}
    } else if (fechaActual.getMes() < obj2.getMes()){
            edad = fechaActual.getAnio() - obj2.getAnio() -1;
    }


    obj.setEdad(edad);
//    rlutil::locate(1,12);
//    cout<< "                            ";
//    rlutil::locate(1,13);
//    cout<< "                            ";
//    rlutil::locate(1,14);
//    cout<< "                            ";
    rlutil::locate(40,16);

    cout<< "TU EDAD ES: " << edad << endl;
    rlutil::locate(40,17);
    cout<< "INGRESE SU DNI: ";
    cin>> dni;
    if (dni <= 0)
    {
        rlutil::locate(55,17);
        cout << "El DNI debe ser mayor a 0." << endl;
        rlutil::locate(40,18);
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < tam; i++)
    {
        objAux = archivo.leerRegistros(i);
        if (dni == objAux.getDNI())
        {
            rlutil::locate(55,17);
            cout<< "Ya existe una cuenta con dicho DNI." << endl;
            rlutil::locate(40,18);
            system("pause");
            system("cls");
            return;
        }
    }
    obj.setDNI(dni);
    rlutil::locate(40,18);
    cout<< "INGRESE SU MAIL: ";
    cargarCadena(mail, 29);
    if (strcmp(mail,"")==0)
    {
        rlutil::locate(56,18);
        cout << "No puede dejar este campo vacio." << endl;
        rlutil::locate(40,19);
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < tam; i++)
    {
        objAux = archivo.leerRegistros(i);
        if (strcmp(mail, objAux.getMail())==0)
        {
            rlutil::locate(56,18);
            cout<< "Ya existe una cuenta con dicho mail." << endl;
            rlutil::locate(40,19);
            system("pause");
            system("cls");
            return;
        }
    }
    obj.setMail(mail);
    rlutil::locate(40,19);
    cout<< "INGRESE SU PAIS: ";
    cargarCadena(pais,29);
    obj.setPais(pais);
    int IdBiblioteca = designarBiblioteca(obj.getID());
    rlutil::locate(40,20);
    cout<< "ID de biblioteca seteada como: "<< IdBiblioteca<<endl;
    rlutil::locate(40,21);
    cout << "ID DEL NUEVO USUARIO SETEADA COMO: " << obj.getID() << endl;
    obj.setTarjet(0);
    rlutil::locate(40,22);
    system("pause");
    obj.setActivo(true);
    archivo.grabarRegistros(obj);
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
            while (opcion != 0)
            {
                setConsoleColor(15,5);
                system("cls");
                rlutil::locate(40,3);
        cout<<"==============================" << endl;
        rlutil::locate(40,4);
        cout<<"      BIBLIOTECA ESTIM        "<<endl;
        rlutil::locate(40,5);
        cout<<"==============================" << endl;
        setConsoleColor(15,5);
        rlutil::locate(40,5);
                usu.mostrarDatos();
                if (usu.getActivo() == false)
                {
                    rlutil::locate(40,7);
                    setConsoleColor(4, 5);
                    cout << "-----------CUENTA DESHABILITADA-----------" << endl;
                }
                setConsoleColor(15, 5);
                rlutil::locate(40,15);
                cout<<"1 - Deshabilitar cuenta"<<endl;
                rlutil::locate(40,17);
                cout<<"2 - Asignar tarjeta"<<endl;
                rlutil::locate(40,19);
                cout<<"0 - Salir"<<endl;
                rlutil::locate(40,21);
                cout<<"======================="<<endl<<endl;
                rlutil::locate(40,23);
                cout<<"Elija una opcion: ";
                rlutil::locate(62,23);
                cin>>opcion;
                switch (opcion)
                {
                case 1:
                    bajaUsuario(idIniciada);
                    return;
                    break;
                case 2:
                    aniadirTarjeta(idIniciada);
                    return;
                    break;
                case 0:
                    break;
                default:
                    system("CLS");
                    setConsoleColor(4, 0);

                    cout<<"Opcion invalida" <<endl;
                    system("PAUSE");
                    setConsoleColor(15, 0);
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
    return -1;
}

int buscarUsuarioPorID(int id)
{
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario obj;
    int tam = arcU.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        obj = arcU.leerRegistros(i);
        if (id == obj.getID())
        {
            return i;
        }
    }
    return -1;
}

int designarBiblioteca(int idUsuario)
{
    archivoBiblioteca arcB("archivos/biblioteca.dat");
    Biblioteca libro;
    archivoUsuario arcU("archivos/usuario.dat");
    usuario usu;
    //int pos = buscarUsuarioPorID(idUsuario);
    //arcB.leerBiblioteca(pos);
    libro.setIdUsuario(idUsuario);
    Fecha fecha0;
    fecha0.setDia(0);
    fecha0.setMes(0);
    fecha0.setAnio(0);
    for (int i = 0 ; i < 150 ; i++) //DECLARA EN 0 TODOS LOS  JUEGOS Y FECHAS
    {
        libro.setIdVideojuego(i,0);
        libro.setFechaCompra(fecha0,i);
    }
    //arcB.modificarBiblioteca(pos, libro);
    arcB.grabarRegistros(libro);
    //cout<<"Tu biblioteca asignada tiene ID: "<< libro.getIdUsuario()<<endl;
    int idBibloteca = libro.getIdUsuario();
    return idBibloteca;
}

void aniadirTarjeta(int idIniciada)
{
    setConsoleColor(0,2);
    system("cls");
    rlutil::locate(40,5);
    cout<< "==============================" << endl;
    rlutil::locate(40,7);
    cout<< "        ASIGNAR TARJETA       " << endl;
    rlutil::locate(40,9);
    cout<< "==============================" << endl<<endl;
    setConsoleColor(0,2);
    usuario obj;
    archivoUsuario arcU("archivos/Usuario.dat");
    int pos = buscarUsuarioPorID(idIniciada);
    int num;
    if(pos<0)
    {
        rlutil::locate(40,11);
        cout<<"Error al aniadir tarjeta."<<endl;
        rlutil::locate(40,12);
        cout << "Codigo de error: " << pos << endl;
        system("pause");
        return;
    }
    rlutil::locate(40,11);
    cout << "REGISTRO: " << pos << endl;
    rlutil::locate(40,12);
    cout << "ID SELECCIONADA: " << idIniciada << endl;
    obj = arcU.leerRegistros(pos);
    if(obj.getActivo()==false)
    {
        setConsoleColor(0,2);
        rlutil::locate(40,11);
        cout<<"El usuario se encontraba deshabilitado" << endl;
        system("pause");
        return;
    }
    rlutil::locate(25,14);
    cout<<"Ingrese el numero de tarjeta (0 para quitar la actual): ";
rlutil::locate(81,14);
    cin>>num;
    if (num < 0)
    {
        rlutil::locate(81,14);
        setConsoleColor(4,2);
        cout<<"Un numero de tarjeta JAMAS sera negativo" << endl;
        setConsoleColor(0,2);
        system("pause");
        return;
    }
    obj.setTarjet(num);
    arcU.modificarUsuario(obj,pos);

    rlutil::locate(35,16);
    cout << "La tarjeta asignada a la cuenta es: " << obj.getTarjet() << endl;
    rlutil::locate(40,17);
    system("pause");
}

void listarOrdenAnio(archivoVideoJuego archivo)
{
    system("cls");
    videoJuego *vectorJuegos;
    int tam = archivo.contarRegistros();
    videoJuego juegoActual, juegoAnterior;
    vectorJuegos = new videoJuego [tam];
    if (vectorJuegos == nullptr)
    {
        return;
    }
    juegoAnterior = archivo.leerRegistros(0);
    for (int i=0 ; i < tam ; i++)
    {
        vectorJuegos[i] = archivo.leerRegistros(i);
    }
    for (int i = 0 ; i < tam ; i++)
    {
        for (int j = 1 ; j < tam ; j++)
        {
            if (vectorJuegos[j].getAnio() < vectorJuegos[j - 1].getAnio())
            {
                videoJuego aux = vectorJuegos[j];
                vectorJuegos[j] = vectorJuegos[j - 1];
                vectorJuegos[j - 1] = aux;
            }

        }
    }
    for (int i = 0 ; i < tam ; i++)
    {
        vectorJuegos[i].mostrar();
    }
    system("pause");
    system("cls");
    delete[]vectorJuegos;
}

void agregarVideojuegoBiblioteca(int idVideojuego, int idIniciada)
{
    system("cls");
    archivoBiblioteca arcB ("archivos/biblioteca.dat");
    Biblioteca libro;
    Fecha compra;
    rlutil::locate(45,8);
    cout<<"----------------------------"<<endl;
    rlutil::locate(45,9);
    cout<<"Cargando Videojuego nuevo: "<<endl;
    rlutil::locate(45,10);
    cout<<"----------------------------"<<endl;
    int tam = arcB.contarRegistros();
    for (int i =0; i<tam ; i++)
    {
        libro= arcB.leerBiblioteca(i);
        if(idIniciada == libro.getIdUsuario())
        {
            rlutil::locate(75, 1);
            cout << "Numero de registro de biblioteca cargado: " << i << endl;
            rlutil::locate(80,2);
            cout << "ID de Biblioteca de usuario cargada: " << libro.getIdUsuario() << endl;
//<<<<<<< HEAD
//            compra.cargar();
//            if(compra.getAnio()>2024 || compra.getMes()>12 || compra.getDia()>31){
//            cout << "No puede colocar una fecha invalida, intentalo nuevamente." << endl;
//            system("PAUSE");
//            return;
//        }
           /// if (compra.cargarPorLocate(40,12) == false) {system("pause");return;}
            compra.cargarFechaActual();
            libro.setFechaCompra(compra,idVideojuego-1);
            libro.setIdVideojuego(idVideojuego-1, idVideojuego);
            arcB.modificarBiblioteca(i,libro);
            //arcB.grabarRegistros(libro);
            rlutil::locate(30,18);
            cout<<"El videojuego ha sido agregado a tu biblioteca con exito, Disfruta!!" << endl;
            rlutil::locate(45,20);
            system("pause");
            return;
        }
    }
}

void mostrarBibliotecaDeUsuario(int idIniciada)
{
    archivoBiblioteca arcB ("archivos/biblioteca.dat");
    Biblioteca libro;

    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego juego;
    int tam = arcB.contarRegistros();
    for (int i = 0; i<tam ; i++ )
    {
        libro = arcB.leerBiblioteca(i);
        if(idIniciada == libro.getIdUsuario())
        {
            system("CLS");
            setConsoleColor(15, 3);

            rlutil::locate(3,3);
            cout << "Mostrando biblioteca ID: " << libro.getIdUsuario() << endl;
            rlutil :: locate(40, 3);
            cout<<"           BIBLIOTECA ESTIM        "<<endl;
            rlutil::locate(3,4);
            cout << "===============================================================================================================" << endl;

            setConsoleColor(15, 3);

            int cantJuegosBiblioteca; ///Para posicionar locate al final de la lista
            for (int j=0 ; j<150 ; j++)
            {
                if (libro.getIdVideojuego(j) != 0){cantJuegosBiblioteca++;}
            }
            libro.mostrar(5);
            rlutil::locate(43,cantJuegosBiblioteca+6);
            system("PAUSE");
            return;
        }
    }
    cout << "Error al cargar biblioteca." << endl;
    system("pause");
    return;
}

void comprarJuegosListados(int juegosListados[], int tam)
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    int numJuego;

    rlutil::locate(35,27);
    setConsoleColor(4, 1);
    cout << "0 - ATRAS" << endl;
    setConsoleColor(3, 1);
    rlutil::locate(30,28);
    cout << "---------------------------------------" << endl;
    setConsoleColor(15, 1);
    rlutil::locate(30,29);
    cout << "Ingrese una opcion: ";
    rlutil::locate(50,29);
    cin >> numJuego;

    if (numJuego == 0)
    {
        return;
    }

    if (numJuego < 1 || numJuego > tam)
    {

        rlutil::locate(50,29);
        setConsoleColor(4,1);
        cout << "Numero de juego no encontrado." << endl;
        rlutil::locate(37,23);
        system("pause");
        return;
    }

    int idJuegoSeleccionado = juegosListados[numJuego - 1];
    comprarJuego(idJuegoSeleccionado);
}

void bibliotecaXnombre(int idIniciada)
{

    archivoBiblioteca arcB("archivos/biblioteca.dat");
    Biblioteca libro;

    archivoVideoJuego arcV ("archivos/videojuego.dat");
    videoJuego game;

    int cantReg = arcV.contarRegistros();
    int tam = arcB.contarRegistros();
    bool salir=false;

    system("CLS");
    setConsoleColor(15, 3);
    cout<<"==============================" << endl;
    cout<<"      BIBLIOTECA ESTIM        "<<endl;
    cout<<"==============================" << endl<<endl;
    setConsoleColor(15,3);

    char nombre [30];
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Ingrese el titulo que quiere buscar en su biblioteca: ";
    cargarCadena(nombre, 29);

    system("CLS");
    setConsoleColor(15, 3);
    cout<<"==============================" << endl;
    cout<<"      BIBLIOTECA ESTIM        "<<endl;
    cout<<"==============================" << endl<<endl;
    setConsoleColor(15,3);

    for (int j = 0; j<tam ; j++)
    {
        libro = arcB.leerBiblioteca(j);
        if(libro.getIdUsuario() == idIniciada)
        {
            cout<<"BIBLIOTECA CON ID : "<< libro.getIdUsuario()<<endl;
            cout<<"Juegos obtenidos con el titulo : "<< nombre <<endl;
            cout<<"-------------------------------------------"<<endl;

            for (int i = 0; i < cantReg; i++)
            {
                game = arcV.leerRegistros(i);
                if (compararSinMayusculas(nombre, game.getTitulo()))
                {
                    for (int l = 0; l<150 ; l++)
                    {
                        if(game.getidVideojuego()== libro.getIdVideojuego(l))
                        {
                            setConsoleColor(15, 3);
                            cout<< "ID: " << game.getidVideojuego()<< " --- " << game.getTitulo()<<" $ "<< game.getPrecio() <<endl;
                            setConsoleColor(8, 3);
                            salir=true;
                        }
                    }
                }
            }
            if(salir==true)
            {

                system("PAUSE");
                return;
            }
            setConsoleColor(15,3);
            cout<<"No se encontro" << " ''" << nombre << "'' " << "en la biblioteca" <<endl;
            system("pause");
            return;
        }
    }
}

void bibliotecaXgenero(int idIniciada)
{

    archivoBiblioteca arcB("archivos/biblioteca.dat");
    Biblioteca libro;

    archivoVideoJuego arcV ("archivos/videojuego.dat");
    videoJuego game;

    archivoGenero arcG("archivos/genero.dat");
    Genero obj;

    int cantReg = arcV.contarRegistros();
    int tam = arcB.contarRegistros();
    bool salir=false;

    system("CLS");
    setConsoleColor(15, 3);
    rlutil::locate(40,1);
    cout<<"==============================" << endl;
    rlutil::locate(40,2);
    cout<<"      BIBLIOTECA ESTIM        "<<endl;
    rlutil::locate(40,3);
    cout<<"==============================" << endl<<endl;
    setConsoleColor(15,3);

    rlutil::locate(40,5);
    cout<<"Generos disponibles: "<< endl;
    int tamanio= arcG.contarRegistros();
    for (int i = 0; i<tamanio; i++ )
    {
        rlutil::locate(40,8+i);
        obj= arcG.leerRegistros(i);
        obj.mostrar();
    }

    char genero [30];
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Ingrese el genero que quiere buscar en su biblioteca: ";
    cargarCadena(genero, 29);

    system("CLS");
    setConsoleColor(15, 3);
    cout<<"==============================" << endl;
    cout<<"      BIBLIOTECA ESTIM        "<<endl;
    cout<<"==============================" << endl<<endl;
    setConsoleColor(15,3);

    for (int j = 0; j<tam ; j++)
    {
        libro = arcB.leerBiblioteca(j);
        if(libro.getIdUsuario() == idIniciada)
        {
            cout<<"BIBLIOTECA CON ID : "<< libro.getIdUsuario()<<endl;
            cout<<"Juegos obtenidos con el genero : "<< genero <<endl;
            cout<<"-------------------------------------------"<<endl;

            for (int i = 0; i < cantReg; i++)
            {
                game = arcV.leerRegistros(i);
                if (compararSinMayusculas(genero, game.getGenero()))
                {
                    for (int l = 0; l<150 ; l++)
                    {
                        if(game.getidVideojuego()== libro.getIdVideojuego(l))
                        {
                            setConsoleColor(15, 3);
                            cout<< "ID: " << game.getidVideojuego()<< " --- " << game.getTitulo()<<" $ "<< game.getPrecio() <<endl;
                            setConsoleColor(8, 3);
                            salir=true;
                        }
                    }
                }
            }
            if (salir==true)
            {
                system("PAUSE");
                return;
            }
            setConsoleColor(15,3);
            cout<<"No se encontro el genero" << " ''" << genero << "'' " << "en la biblioteca" <<endl;
            system("pause");
            return;
        }
    }
}

void bibliotecaXdesarrollador(int idIniciada)
{

    archivoBiblioteca arcB("archivos/biblioteca.dat");
    Biblioteca libro;

    archivoVideoJuego arcV ("archivos/videojuego.dat");
    videoJuego game;

    archivoDesarrollador arcD("archivos/desarrolladores.dat");
    Desarrollador obj;

    int cantReg = arcV.contarRegistros();
    int tam = arcB.contarRegistros();
    bool salir=false;

    system("CLS");
    setConsoleColor(15, 3);
    rlutil::locate(40,1);
    cout<<"==============================" << endl;
    rlutil::locate(40,2);
    cout<<"      BIBLIOTECA ESTIM        "<<endl;
    rlutil::locate(40,3);
    cout<<"==============================" << endl<<endl;
    setConsoleColor(15,3);

    rlutil::locate(40,5);
    cout<<"Generos disponibles: "<< endl;
    int tamanio= arcD.contarRegistros();
    for (int i = 0; i<tamanio; i++ )
    {
        rlutil::locate(40,8+i);
        obj= arcD.leerRegistros(i);
        obj.mostrar();
    }

    char desarrollador [30];
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Ingrese el desarrollador que quiere buscar en su biblioteca: ";
    cargarCadena(desarrollador, 29);

    system("CLS");
    setConsoleColor(15, 3);
    cout<<"==============================" << endl;
    cout<<"      BIBLIOTECA ESTIM        "<<endl;
    cout<<"==============================" << endl<<endl;
    setConsoleColor(15,3);

    for (int j = 0; j<tam ; j++)
    {
        libro = arcB.leerBiblioteca(j);
        if(libro.getIdUsuario() == idIniciada)
        {
            cout<<"BIBLIOTECA CON ID : "<< libro.getIdUsuario()<<endl;
            cout<<"Juegos obtenidos con el desarrollador : "<< desarrollador <<endl;
            cout<<"-------------------------------------------"<<endl;

            for (int i = 0; i < cantReg; i++)
            {
                game = arcV.leerRegistros(i);
                if (compararSinMayusculas(desarrollador, game.getDesarrollador()))
                {
                    for (int l = 0; l<150 ; l++)
                    {
                        if(game.getidVideojuego()== libro.getIdVideojuego(l))
                        {
                            setConsoleColor(15, 3);
                            cout<< "ID: " << game.getidVideojuego()<< " --- " << game.getTitulo()<<" $ "<< game.getPrecio() <<endl;
                            setConsoleColor(8, 3);
                            salir=true;
                        }
                    }
                }
            }
            if (salir==true)
            {
                system("PAUSE");
                return;
            }
            setConsoleColor(15,3);
            cout<<"No se encontro el desarrollador" << " ''" << desarrollador << "'' " << "en la biblioteca" <<endl;
            system("pause");
            return;
        }
    }
}

void bibliotecaXanio(int idIniciada)
{

    archivoBiblioteca arcB("archivos/biblioteca.dat");
    Biblioteca libro;

    archivoVideoJuego arcV ("archivos/videojuego.dat");
    videoJuego game;

    int cantReg = arcV.contarRegistros();
    int tam = arcB.contarRegistros();
    int anio;

    cout<<"-----------------------------------------"<<endl;
    cout<<" Ingrese el anio que quiere buscar en su biblioteca : ---->"<<endl;
    cin>> anio;

    for (int j = 0; j<tam ; j++)
    {
        libro = arcB.leerBiblioteca(j);
        if(libro.getIdUsuario() == idIniciada)
        {
            cout<<"BIBLIOTECA CON ID : "<< libro.getIdUsuario()<<endl;
            cout<<"Juegos obtenidos con el anio : "<< anio <<endl;
            cout<<"-------------------------------------------"<<endl;

            for (int i = 0; i < cantReg; i++)
            {
                game = arcV.leerRegistros(i);
                if (game.getAnio() == anio )
                {
                    for (int l = 0; l<150 ; l++)
                    {
                        if(game.getidVideojuego()== libro.getIdVideojuego(l))
                        {
                            setConsoleColor(15, 0);
                            cout<< game.getidVideojuego()<< "---> " << game.getTitulo()<<" $ "<< game.getPrecio() <<endl;
                            setConsoleColor(8, 0);
                        }
                    }
                    system("PAUSE");
                }
            }
        }
    }
}

void registroCompras()
{

    archivoBiblioteca arcB("archivos/biblioteca.dat");
    Biblioteca libro;

    archivoVideoJuego arcV ("archivos/videojuego.dat");
    videoJuego game;

    int cantReg = arcV.contarRegistros();
    int tam = arcB.contarRegistros();
    float totalGastado=0;
    int contadorJuegosListados=0;

    system("cls");
    libro = arcB.leerBiblioteca(idIniciada-1);
    rlutil::locate(20,5);
    cout<<"<<------------------COMPRAS TOTALES DE VIDEOJUEGOS----------------------->>"<<endl;
    rlutil::locate(20,6);
    cout<<"                            BIBLIOTECA CON ID: "<< libro.getIdUsuario()<<"                       "<<endl;
    rlutil::locate(20,7);
    cout<<"<<----------------------------------------------------------------------->>"<<endl;

    for (int j = 0; j<tam ; j++)
    {
        libro = arcB.leerBiblioteca(j);
        if(libro.getIdUsuario() == idIniciada)
        {
            for (int i = 0; i < cantReg; i++)
            {
                game = arcV.leerRegistros(i);
                for (int l = 0; l<150 ; l++)
                {
                    if(game.getidVideojuego()== libro.getIdVideojuego(l))
                    {
                        totalGastado+=game.getPrecio();
                        contadorJuegosListados++;
                    }
                }
            }
            setConsoleColor(15, 3);
            libro.mostrar(9); //USO 9 PARA QUE ARRANQUE UN PAR DE LINEAS ABAJO
        }
    }
    setConsoleColor(5,3);
    rlutil::locate(20,contadorJuegosListados+11); //SUMO ESAS LINEAS A LOS JUEGOS YA LISTADOS
    cout<<"El total gastado es : "<< totalGastado<<endl;
    setConsoleColor(15,3);
    rlutil::locate(20,contadorJuegosListados+12);
    system("PAUSE");
}

///FUNCIONES VIDEOJUEGOS


void comprarJuego(int idVideojuego)
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    usuario usu;
    archivoUsuario arcU("archivos/Usuario.dat");
    archivoBiblioteca arcB("archivos/biblioteca.dat");
    Biblioteca bib;

    int opcion = 1;

    while (opcion!=0)
    {
        setConsoleColor(15,1);
        system("cls");
        caracteristicasVideojuego(idVideojuego);
        int opcion2 = 1;
        setConsoleColor(15,1);
        rlutil::locate(45,23);
        cout<<"1 - Comprar"<<endl;
        setConsoleColor(4,1);
        rlutil::locate(45,24);
        cout<<"0 - Salir"<<endl;
        setConsoleColor(15,1);
        rlutil::locate(45,25);
        cout << "---------------------------------------" << endl;
        rlutil::locate(45,26);
        cout << "Ingrese una opcion: ";
        rlutil::locate(65,26);
        setConsoleColor(15,1);
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            usu = arcU.leerRegistros(idIniciada-1);
            if (usu.getTarjet() != 0)
            {
                bib = arcB.leerBiblioteca(idIniciada-1);
                for (int i = 0; i < 150; i++)
                {
                    if (bib.getIdVideojuego(i)==idVideojuego)
                    {
                        setConsoleColor(4,1);
                        rlutil::locate(45,26);
                        cout << "Ya tienes el juego en tu biblioteca. " << endl;
                        setConsoleColor(15,1);
                        rlutil::locate(45,27);
                        system("pause");
                        return;
                    }
                }
                agregarVideojuegoBiblioteca(idVideojuego,idIniciada);
                return;
            }
            else if (usu.getTarjet() == 0)
            {
                system("cls");
                rlutil::locate(40, 10);
                cout<<"No tienes ninguna tarjeta asociada."<<endl;
                rlutil::locate(40, 11);
                cout<<"Desea aniadir una a su cuenta?"<<endl<<endl;
                rlutil::locate(40, 12);
                cout<<"1 - Si"<<endl;
                rlutil::locate(40, 13);
                cout<<"2 - No"<<endl;
                rlutil::locate(40, 14);
                cout<<"Ingrese una opcion: ";
                rlutil::locate(60,14);
                cin>>opcion2;
                switch (opcion2)
                {
                case 1:
                    aniadirTarjeta(idIniciada);
                    usu = arcU.leerRegistros(idIniciada-1);
                    if (usu.getTarjet() > 0)
                        {
                           agregarVideojuegoBiblioteca(idVideojuego,idIniciada);
                           return;
                        }
                    break;
                case 2:
                    return;
                default:
                    setConsoleColor(4, 0);
                    cout << "Opcion Invalida." << endl;
                    setConsoleColor(15, 0);
                    system("pause");
                    system("cls");
                    break;
                }
            }
        case 0:
            break;
        default:
            setConsoleColor(4, 0);
            cout << "Opcion Invalida." << endl;
            setConsoleColor(15, 0);
            system("pause");
            system("cls");
            break;
        }
    }
}

void listarPorGenero()
{
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;
    usu = arcU.leerRegistros(idIniciada-1);
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    archivoGenero arcG("archivos/genero.dat");
    Genero obj;

    setConsoleColor(15, 1);
    system("CLS");

    rlutil::locate(3,2);
    cout<< "ESTIM.";

    rlutil::locate(100,2);
    cout<<"Usuario: " << usu.getNombre()<<endl;
    rlutil::locate(100,3);
    cout<<"ID: " << idIniciada<<endl;

    rlutil::locate(40,5);
    cout<< "==============================" << endl;
    rlutil::locate(40,6);
    cout<< "        LISTAR x GENERO       " << endl;
    rlutil::locate(40,7);
    cout<< "==============================" << endl;
    rlutil::locate(40,9);
    cout<<"Generos disponibles: "<< endl;
    int tamanio= arcG.contarRegistros();
    for (int i = 0; i<tamanio; i++ )
    {
        rlutil::locate(40,11+i);
        obj= arcG.leerRegistros(i);
        obj.mostrar();
    }

    char genero[30];
    ///CODIGO PARA BUSCADOR
    rlutil::locate(40,22);
    cout << "Ingrese el genero que desea buscar: " ;
    rlutil::locate(42,23); cout << char(201); ponerChar(205,30); cout << char(187);
    rlutil::locate(42,24);
    cout << char(186); rlutil::locate(73,24); cout << char(186);
    rlutil::locate(42,25); cout << char(200); ponerChar(205,30); cout << char(188);
    rlutil::locate(44,24);cargarCadena(genero,29);
    ///
    int cantReg = arcV.contarRegistros();
    int juegosListados[150] = {};
    int tam = 0;
    int contgame=0;

    system("cls");
    rlutil::locate(40,5);
    cout<< "==============================" << endl;
    rlutil::locate(40,6);
    cout<< "   Filtro aplicado: " << genero << endl;
    rlutil::locate(40,7);
    cout<< "==============================" << endl;

    usu = arcU.leerRegistros(datosUsuarioIniciado());

    for (int i = 0; i < cantReg; i++)
    {
        rlutil::locate(30, 11+(contgame));
        game = arcV.leerRegistros(i);
        if (compararSinMayusculas(genero, game.getGenero()) && usu.getEdad() >= game.getRestriccion() && game.getActivo())
        {
            cout << tam + 1 << " - " << game.getTitulo();
            rlutil::locate(64, 11+(contgame));
            cout << " --- precio: $ " << game.getPrecio() << endl;
            juegosListados[tam] = game.getidVideojuego();
            tam++;
            contgame++;
        }
        else if (compararSinMayusculas(genero, game.getGenero()) && usu.getEdad() >= game.getRestriccion() && !game.getActivo())
        {
            cout << "*JUEGO DESHABILITADO" << endl;
            contgame++;
        }
        else if (compararSinMayusculas(genero, game.getGenero()) && usu.getEdad() < game.getRestriccion() && game.getActivo())
        {
            cout << "No tienes edad suficiente para este videojuego" << endl;
            contgame++;
        }
    }
    if (contgame == 0)
    {
        rlutil::locate(38,15);
        setConsoleColor(4, 1);
        cout << "No hay juegos con ese genero :(" << endl;
        rlutil::locate(38,16);
        system("pause");
    }
    else
    {
        comprarJuegosListados(juegosListados, tam);
    }
}

void listarPorCreador()
{
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;
    usu = arcU.leerRegistros(idIniciada-1);
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    archivoDesarrollador arcD("archivos/desarrolladores.dat");
    Desarrollador obj;

    setConsoleColor(15, 1);
    system("CLS");

    rlutil::locate(3,2);
    cout<< "ESTIM.";

    rlutil::locate(100,2);
    cout<<"Usuario: " << usu.getNombre()<<endl;
    rlutil::locate(100,3);
    cout<<"ID: " << idIniciada<<endl;

    rlutil::locate(40,5);
    cout<< "==============================" << endl;
    rlutil::locate(40,6);
    cout<< "       LISTAR x CREADOR       " << endl;
    rlutil::locate(40,7);
    cout<< "==============================" << endl;
    rlutil::locate(40,9);
    cout<<"Desarrolladores disponibles: "<< endl;
    int tamanio= arcD.contarRegistros();
    for (int i = 0; i<tamanio; i++ )
    {
        rlutil::locate(40,11+i);
        obj= arcD.leerRegistros(i);
        obj.mostrar();
    }

    int tam = arcV.contarRegistros();
    char desarrolladora[30];
    int contgame = 0;
    int juegosListados[150] = {};
    int tam2 = 0;

    rlutil::locate(40,22);
    cout << "Ingrese el desarrollador que desea buscar: " ;
    rlutil::locate(42,23); cout << char(201); ponerChar(205,30); cout << char(187);
    rlutil::locate(42,24);
    cout << char(186); rlutil::locate(73,24); cout << char(186);
    rlutil::locate(42,25); cout << char(200); ponerChar(205,30); cout << char(188);
    rlutil::locate(44,24);cargarCadena(desarrolladora,29);
    system("cls");
    rlutil::locate(40,5);
    cout<< "==============================" << endl;
    rlutil::locate(40,6);
    cout<< "   Filtro aplicado: " << desarrolladora << endl;
    rlutil::locate(40,7);
    cout<< "==============================" << endl;

    for (int i = 0; i < tam; i++)
    {
        rlutil::locate(30,9+contgame);
        game = arcV.leerRegistros(i);
        if (compararSinMayusculas(desarrolladora, game.getDesarrollador()) && usu.getEdad() >= game.getRestriccion() && game.getActivo())
        {
            cout << tam2 + 1 << " - " << game.getTitulo();
            rlutil::locate(64, 9+(contgame));
            cout << " --- precio: $ " << game.getPrecio() << endl;
            juegosListados[tam2] = game.getidVideojuego();
            tam2++;
            contgame++;
        }
        else if (compararSinMayusculas(desarrolladora, game.getDesarrollador()) && usu.getEdad() >= game.getRestriccion() && !game.getActivo())
        {
            cout << "*JUEGO DESHABILITADO" << endl;
            contgame++;
        }
        else if (compararSinMayusculas(desarrolladora, game.getDesarrollador()) && usu.getEdad() < game.getRestriccion() && game.getActivo())
        {
            cout << "No tienes edad suficiente para este videojuego" << endl;
            contgame++;
        }
    }

    if (contgame == 0)
    {
        rlutil::locate(38,15);
        setConsoleColor(4, 1);
        cout << "No hay juegos con esa desarrolladora :(" << endl;
        rlutil::locate(38,16);
        system("pause");
    }
    else
    {
        comprarJuegosListados(juegosListados, tam2);
    }
}

void bajaUsuario(int idIniciada)
{
    usuario obj;
    archivoUsuario arcU("archivos/Usuario.dat");
    int pos = buscarUsuarioPorID(idIniciada);
    system("cls");
    if(pos<0)
    {
        cout<<"Error al modificar usuario."<<endl;
        cout << "Codigo de error: " << pos << endl;
        system("pause");
        return;
    }
    cout << "REGISTRO: " << pos << endl;
    cout << "ID SELECCIONADA: " << idIniciada << endl;
    obj = arcU.leerRegistros(pos);
    if(obj.getActivo()==false)
    {
        cout<<"El usuario ya se encontraba deshabilitado" << endl;
        system("pause");
        return;
    }
    obj.setActivo(false);
    arcU.modificarUsuario(obj,pos);
    system("cls");
    setConsoleColor(4,0);
    cout<< "Su cuenta se ha deshabilitado.";
    system("pause");
}

void mostrarPorPrecio()
{
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;
    usu = arcU.leerRegistros(idIniciada-1);
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    archivoDesarrollador arcD("archivos/desarrolladores.dat");
    Desarrollador obj;

    int tam = arcV.contarRegistros();
    float montoMax = 0;
    float montoMin = 0;
    int contGame = 0;
    int juegosListados[150] = {};
    int tam2 = 0;

    setConsoleColor(15, 1);
    system("CLS");

    rlutil::locate(3,2);
    cout<< "ESTIM.";

    rlutil::locate(100,2);
    cout<<"Usuario: " << usu.getNombre()<<endl;
    rlutil::locate(100,3);
    cout<<"ID: " << idIniciada<<endl;

    rlutil::locate(40,5);
    cout<< "==============================" << endl;
    rlutil::locate(40,6);
    cout<< "        LISTAR x PRECIO       " << endl;
    rlutil::locate(40,7);
    cout<< "==============================" << endl;
    rlutil::locate(40,9);
    cout << "Ingrese el monto maximo: ";
    rlutil::locate(65,9);
    cin >> montoMax;
    rlutil::locate(40,10);
    cout << "Ingrese el monto minimo: ";
    rlutil::locate(65,10);
    cin >> montoMin;

    system("cls");
    rlutil::locate(30,5);
    cout<< "=====================================================" << endl;
    rlutil::locate(30,6);
    cout << "El filtro aplicado es: desde $" << montoMin << " hasta $" << montoMax << endl;
    rlutil::locate(30,7);
    cout<< "=====================================================" << endl;

    for (int i = 0; i < tam; i++)
    {
        rlutil::locate(30,9+contGame);
        game = arcV.leerRegistros(i);
        if ((montoMin <= game.getPrecio()) && (game.getPrecio() <= montoMax) && game.getActivo() && usu.getEdad() >= game.getRestriccion())
        {
            cout << tam2 + 1 << " - " << game.getTitulo();
            rlutil::locate(64, 9+(contGame));
            cout << " --- precio: $ " << game.getPrecio() << endl;
            juegosListados[tam2] = game.getidVideojuego();
            tam2++;
            contGame++;

        }
        else if ((montoMin <= game.getPrecio()) && (game.getPrecio() <= montoMax) && !game.getActivo() && usu.getEdad() >= game.getRestriccion())
        {
            cout << "*JUEGO DESHABILITADO" << endl;
            contGame++;
        }
        else if ((montoMin <= game.getPrecio()) && (game.getPrecio() <= montoMax) && game.getActivo() && usu.getEdad() < game.getRestriccion())
        {
            cout << "No tienes edad suficiente para este videojuego" << endl;
            contGame++;
        }
    }
    if (contGame == 0)
    {
        rlutil::locate(38,15);
        setConsoleColor(4, 1);
        cout << "No hay juegos entre esos precios :(" << endl;
        rlutil::locate(38,16);
        system("pause");
    }
    else
    {
        comprarJuegosListados(juegosListados, tam2);
    }
}

void listarPorAnio()
{
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;

    int tam = arcV.contarRegistros();
    int anio;
    int contGame = 0;
    int juegosListados[150] = {};
    int tam2 = 0;

    system("CLS");

    rlutil::locate(3,2);
    cout<< "ESTIM.";

    rlutil::locate(100,2);
    cout<<"Usuario: " << usu.getNombre()<<endl;
    rlutil::locate(100,3);
    cout<<"ID: " << idIniciada<<endl;

    rlutil::locate(40,5);
    cout<< "==============================" << endl;
    rlutil::locate(40,6);
    cout<< "         LISTAR x ANIO        " << endl;
    rlutil::locate(40,7);
    cout<< "==============================" << endl;
    rlutil::locate(40,9);
    cout << "Ingrese el anio con el cual filtrar: ";
    cin >> anio;

    system("cls");
    rlutil::locate(40,5);
    cout<< "============================" << endl;
    rlutil::locate(40,6);
    cout << "El filtro aplicado es: " << anio << endl;
    rlutil::locate(40,7);
    cout<< "============================" << endl;

    usu = arcU.leerRegistros(datosUsuarioIniciado());
    for (int i = 0; i < tam; i++)
    {
        rlutil::locate(30,9+contGame);
        game = arcV.leerRegistros(i);
        if (game.getAnio() == anio && usu.getEdad() >= game.getRestriccion() && game.getActivo())
        {
            cout << tam2 + 1 << " - " << game.getTitulo();
            rlutil::locate(64, 9+(contGame));
            cout << " --- precio: $ " << game.getPrecio() << endl;
            juegosListados[tam2] = game.getidVideojuego();
            tam2++;
            contGame++;
        }
        else if (game.getAnio() == anio && usu.getEdad() >= game.getRestriccion() && !game.getActivo())
        {
            cout << "*JUEGO DESHABILITADO" << endl;
            contGame++;
        }
        else if (game.getAnio() == anio && usu.getEdad() < game.getRestriccion() && game.getActivo())
        {
            cout << "No tienes edad suficiente para este videojuego" << endl;
            contGame++;
        }
    }

    if (contGame == 0)
    {
       rlutil::locate(38,15);
        setConsoleColor(4, 1);
        cout << "No hay juegos de ese anio :(" << endl;
        rlutil::locate(38,16);
        system("pause");
    }
    else
    {
        comprarJuegosListados(juegosListados, tam2);
    }
}

void cargarVideojuego()
{
    system("CLS");
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;
    videoJuego gameAnt;
    char nombre[30];
    rlutil::locate(40,5);
    cout<< "==============================" << endl;
    rlutil::locate(40,6);
    cout<< "   CARGAR VIDEOJUEGO NUEVO!   " << endl;
    rlutil::locate(40,7);
    cout<< "==============================" << endl;
    rlutil::locate(40,9);
    cout<<"Ingrese el nombre del videojuego: ";
    rlutil::locate(74,9);
    cargarCadena(nombre, 29);

    int tam=arcV.contarRegistros();
    for (int i = 0; i < tam; i++)
    {
        game = arcV.leerRegistros(i);
        if (strcmp(nombre, game.getTitulo())==0)
        {
            rlutil::locate(74,9);
            setConsoleColor(4, 1);
            cout<<"Dicho videojuego ya se encuentra en el sistema.";
            rlutil::locate(60,10);
            setConsoleColor(8, 1);
            system("pause");
            return;
        }
    }
    game.setTitulo(nombre);
    game.cargar();
    if (game.getPrecio()<0 || game.getCalificacion() < 0 || game.getPeso() < 0 || game.getRestriccion() < 0 || game.getCalificacion() > 100)
    {
       return;
    }
    Genero gene, geneAux;
    archivoGenero arcG("archivos/genero.dat");
    bool existeG=false;
    int tamG = arcG.contarRegistros();
    gene.setNombre(game.getGenero());
    for (int i = 0; i < tamG; i++)
    {
        geneAux = arcG.leerRegistros(i);
        //cout << "Registro N" << i << " Genero: " << geneAux.getNombre() << endl;
        if (compararSinMayusculas(geneAux.getNombre(), gene.getNombre()))
        {
            existeG = true;
            break;
        }
    }
    if (existeG == false)
    {
        arcG.grabarRegistros(gene);
        //cout<<"se aniadio un nuevo genero al sistema." <<endl;
    }

    gameAnt = arcV.leerRegistros(tam-1); //CARGA LOS DATOS DEL ULTIMO REGISTRO
    game.setidVideojuego(gameAnt.getidVideojuego()+1);


    /////////////////////////////////////////////////////////////////////////////

    char dev[30];
    Desarrollador devAux;
    Desarrollador objDev;
    archivoDesarrollador archivoDev("archivos/desarrolladores.dat");
    int tamDev = archivoDev.contarRegistros();
    bool existe=false;
    strcpy(dev,game.getDesarrollador());
    //cout << "Desarrollador a grabar: " << dev << endl;
    objDev.setNombre(dev);
    for (int i=0 ; i < tamDev ; i++)
    {
        devAux = archivoDev.leerRegistros(i);
        //cout << "Registro N" << i << ". Desarrollador: " << devAux.getNombre() << endl;
        if (compararSinMayusculas(devAux.getNombre(),objDev.getNombre()))
        {
            existe = true;
            break;
        }
    }
    if (existe == false)
    {
        archivoDev.grabarRegistros(objDev);
        //cout << "Se aniadio un nuevo desarrollador al sistema. " << endl;
    }

    //cout << "ID del nuevo videojuego seteada como : " << game.getidVideojuego() << endl;

    arcV.grabarRegistros(game);
    rlutil::locate(40,18);
    system("pause");
}


void caracteristicasVideojuego(int j)
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;
    game = arcV.leerRegistros(j-1);
    system("CLS");
    setConsoleColor(15, 1);
    game.mostrar();
    setConsoleColor(8, 1);
    return;
}

void buscarPorNombre(const char *n)
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;
    int cantReg = arcV.contarRegistros();

    system("CLS");
        setConsoleColor(0, 6);

        rlutil::locate(40,5);
        cout<< "==============================" << endl;
        rlutil::locate(40,7);
        cout<< "   RESULTADO DE LA BUSQUEDA   " << endl;
        rlutil::locate(40,9);
        cout<< "==============================" << endl;
        setConsoleColor(15,6);

    for (int i = 0; i < cantReg; i++)
    {

        game = arcV.leerRegistros(i);
        if (compararSinMayusculas(n, game.getTitulo())&&game.getActivo())
        {
            setConsoleColor(15, 1);
            system("cls");
            game.mostrar();
            comprarJuego(game.getidVideojuego());
            return;
        }
    }
        rlutil::locate(38,15);
        setConsoleColor(4, 6);
        cout << "Videojuego no encontrado :(" << endl;
        rlutil::locate(38,16);
}

void elegirVideojuego()
{

    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;

    int cantReg = arcV.contarRegistros();
    int juegosListados[150] = {};
    int tam = 0;

    usu = arcU.leerRegistros(idIniciada-1);
    setConsoleColor(15, 1);
        system("CLS");

        rlutil::locate(3,2);
        cout<< "ESTIM.";

        rlutil::locate(100,2);
        cout<<"Usuario: " << usu.getNombre()<<endl;
        rlutil::locate(100,3);
        cout<<"ID: " << idIniciada<<endl;
    usu = arcU.leerRegistros(datosUsuarioIniciado());

    rlutil::locate(40,5);
        cout<< "==============================" << endl;
        rlutil::locate(40,7);
        cout<< "    TODOS LOS VIDEOJUEGOS!    " << endl;
        rlutil::locate(40,9);
        cout<< "==============================" << endl<<endl;
        setConsoleColor(3,1);

    for (int i = 0; i < cantReg; i++)
    {
        rlutil::locate(30, 11+(i));
        game = arcV.leerRegistros(i);
        if (usu.getEdad() >= game.getRestriccion() && game.getActivo())
        {
            cout << tam + 1 << " - " << game.getTitulo();
            rlutil::locate(64, 11+(i));
            cout << " --- Precio: $" << game.getPrecio() << endl;
            juegosListados[tam] = game.getidVideojuego();
            tam++;
        }
        else if (usu.getEdad() >= game.getRestriccion() && !game.getActivo())
        {
            cout << "*JUEGO DESHABILITADO" << endl;
        }
        else if (usu.getEdad() < game.getRestriccion() && game.getActivo())
        {
            cout << "No tienes edad suficiente para este videojuego" << endl;
        }
    }
    comprarJuegosListados(juegosListados, tam);
}

void buscarVideojuego()
{
    setConsoleColor(0, 6);
    system("CLS");
    char titJuego[50];
   rlutil::locate(40,5);
        cout<< "==============================" << endl;
        rlutil::locate(40,7);
        cout<< "      BUSCAR VIDEOJUEGOS!     " << endl;
        rlutil::locate(40,9);
        cout<< "==============================" << endl;
    setConsoleColor(15,6);
    rlutil::locate(35,12);
    cout<< "INGRESE NOMBRE DEL VIDEOJUEGO: ";
    setConsoleColor(8, 6);
    rlutil::locate(65,12);
    cargarCadena(titJuego, 49);
    buscarPorNombre(titJuego);
    system("PAUSE");
}

void listarPorGratuito()
{
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;
    int tam = arcV.contarRegistros();
    int contGame = 0;
    int juegosListados[150] = {};
    int tam2 = 0;

    system("cls");
    rlutil::locate(40,5);
    cout<< "============================" << endl;
    rlutil::locate(40,6);
    cout<< "   VIDEOJUEGOS  GRATUITOS   " << endl;
    rlutil::locate(40,7);
    cout<< "============================" << endl;

    usu = arcU.leerRegistros(datosUsuarioIniciado());

    for (int i = 0; i < tam; i++)
    {
        rlutil::locate(30,9+contGame);
        game = arcV.leerRegistros(i);
        if (game.getPrecio() == 0 && usu.getEdad() >= game.getRestriccion() && game.getActivo())
        {
            cout << tam2 + 1 << " - " << game.getTitulo();
            rlutil::locate(64, 9+(contGame));
            cout << " --- precio: $ " << game.getPrecio() << endl;
            juegosListados[tam2] = game.getidVideojuego();
            tam2++;
            contGame++;
        }
        else if (game.getPrecio() == 0 && usu.getEdad() >= game.getRestriccion() && !game.getActivo())
        {
            cout << "*JUEGO DESHABILITADO" << endl;
            contGame++;
        }
        else if (game.getPrecio() == 0 && usu.getEdad() < game.getRestriccion() && game.getActivo())
        {
            cout << "No tienes edad suficiente para este videojuego" << endl;
            contGame++;
        }
    }

    if (contGame == 0)
    {
        rlutil::locate(38,15);
        setConsoleColor(4, 1);
        cout << "No hay juegos gratis :(" << endl;
        rlutil::locate(38,16);
        system("pause");
    }
    else
    {
        comprarJuegosListados(juegosListados, tam2);
    }
}


///FUNCIONES ADMIN

void juegosVendidos()
{
    archivoBiblioteca arcB("archivos/biblioteca.dat");
    Biblioteca bib;
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;
    int cantJuegosVendidos = 0;
    int totalRecaudado = 0;

    int cantReg = arcB.contarRegistros();

    for (int i = 0; i < cantReg; i++)
    {
        bib = arcB.leerBiblioteca(i);
        for (int j = 0; j < 150; j++)
        {
            if (bib.getIdVideojuego(j)>0)
            {
                game = arcV.leerRegistros(j);
                cantJuegosVendidos++;
                totalRecaudado+=game.getPrecio();
            }
        }
    }
    cout<<"Total videojuegos vendidos: " << cantJuegosVendidos << endl;
    cout<<"Total recaudado: " << totalRecaudado << endl;
    system("pause");
}

void videojuegoMasVendidoGenero()
{
    system("cls");
    archivoGenero arcG("archivos/genero.dat");
    char genero[30];
    rlutil::locate(40,8);
    cout << "Videojuego mas vendido segun GENERO" << endl;
    rlutil::locate(40,9);
    cout << "===================================" << endl;
    rlutil::locate(40,10);
    cout<<"Generos disponibles: "<< endl;
    int tamanio= arcG.contarRegistros();
    for (int i = 0; i<tamanio; i++ )
    {
        Genero obj;
        rlutil::locate(40,11+i);
        obj= arcG.leerRegistros(i);
        obj.mostrar();
    }

    rlutil::locate(40,22);
    cout << "Ingrese el genero que desea buscar: " ;
    rlutil::locate(42,23); cout << char(201); ponerChar(205,30); cout << char(187);
    rlutil::locate(42,24);
    cout << char(186); rlutil::locate(73,24); cout << char(186);
    rlutil::locate(42,25); cout << char(200); ponerChar(205,30); cout << char(188);
    rlutil::locate(44,24);cargarCadena(genero,29);
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;
    archivoBiblioteca arcB ("archivos/biblioteca.dat");
    Biblioteca libro;
    //REVISO QUE EXISTA
    int tamanioCatalogo = arcV.contarRegistros();
    for (int i = 0 ; i < tamanioCatalogo ; i++)
    {
        game = arcV.leerRegistros(i);
        if (compararSinMayusculas(genero,game.getGenero()))
        {
            break;
        }
        else if (i == tamanioCatalogo-1 && compararSinMayusculas(genero,game.getGenero()) == false)
        {
            cout << "Genero no encontrado! " << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    int juegosMasComprados[150]= {};
    int tam = arcB.contarRegistros();
    int maxi =0;
    for (int l =0 ; l<tam ; l++ )
    {
        libro = arcB.leerBiblioteca(l);
        for (int j=0; j<150 ; j++ )
        {
            if (libro.getIdVideojuego(j) != 0)
            {
                game = arcV.leerRegistros(libro.getIdVideojuego(j)-1);//CARGO EL JUEGO EN LA ID ACTUAL -1 (su posicion)
                if (compararSinMayusculas(game.getGenero(),genero))
                {
                    juegosMasComprados[j]++;
                }
            }
        }
    }
    int pos=0;
    for (int i=0; i<150 ; i++ )
    {

        if (juegosMasComprados[i]> maxi)
        {
            maxi = juegosMasComprados[i];
            pos= i;
        }
    }

    if (maxi == 0)
    {
        system("cls");
        rlutil::locate(40,15);
        cout << "No se han realizado compras de este genero." << endl;
        rlutil::locate(40,21);
        system("pause");
        return;
    }

    int cantreg= arcV.contarRegistros();
    for (int i = 0; i<cantreg ; i++ )
    {
        game = arcV.leerRegistros(i);
        if (pos+1 == game.getidVideojuego())
        {
            system("cls");
            rlutil::locate(35,10);
            cout << "Videojuego mas vendido de "<< genero << " es: " << game.getTitulo() << endl;
            rlutil::locate(54,11);
            cout << "Precio: $" << game.getPrecio() << endl;
            rlutil::locate(51,12);
            cout << "Copias vendidas: " << juegosMasComprados[pos] << endl;
            rlutil::locate(40,13);
            system("PAUSE");
            system("cls");
            return;
        }
    }
}

void videojuegoMasVendidoDesarrollador()
{
    system("cls");
    char dev[30];
    rlutil::locate(40,8);
    cout << "Videojuego mas vendido segun DESARROLLADOR" << endl;
    rlutil::locate(40,9);
    cout << "===================================" << endl;
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;
    archivoBiblioteca arcB ("archivos/biblioteca.dat");
    Biblioteca libro;
    archivoDesarrollador arcD("archivos/desarrolladores.dat");
    //REVISO QUE EXISTA

    rlutil::locate(40,10);
    cout<<"Desarrolladores disponibles: "<< endl;
    int tamanio= arcD.contarRegistros();
    for (int i = 0; i<tamanio; i++ )
    {
        Desarrollador obj;
        rlutil::locate(40,11+i);
        obj= arcD.leerRegistros(i);
        obj.mostrar();
    }

    int juegosListados[150] = {};

    rlutil::locate(40,22);
    cout << "Ingrese el desarrollador que desea buscar: " ;
    rlutil::locate(42,23); cout << char(201); ponerChar(205,30); cout << char(187);
    rlutil::locate(42,24);
    cout << char(186); rlutil::locate(73,24); cout << char(186);
    rlutil::locate(42,25); cout << char(200); ponerChar(205,30); cout << char(188);
    rlutil::locate(44,24);cargarCadena(dev,29);

    //

    int tamanioCatalogo = arcV.contarRegistros();
    for (int i = 0 ; i < tamanioCatalogo ; i++)
    {
        game = arcV.leerRegistros(i);
        if (compararSinMayusculas(dev,game.getDesarrollador()))
        {
            break;
        }
        else if (i == tamanioCatalogo-1 && compararSinMayusculas(dev,game.getDesarrollador()) == false)
        {
            cout << "Desarrollador no encontrado! " << endl;
            system("pause");
            system("cls");
            return;
        }
    }

    int juegosMasComprados[150]= {};
    int tam = arcB.contarRegistros();
    int maxi =0;
    for (int l =0 ; l<tam ; l++ )
    {
        libro = arcB.leerBiblioteca(l);
        for (int j=0; j<150 ; j++ )
        {
            if (libro.getIdVideojuego(j) != 0)
            {
                game = arcV.leerRegistros(libro.getIdVideojuego(j)-1);//CARGO EL JUEGO EN LA ID ACTUAL -1 (su posicion)
                if (compararSinMayusculas(game.getDesarrollador(),dev))
                {
                    juegosMasComprados[j]++;
                }
            }
        }
    }
    int pos=0;
    for (int i=0; i<150 ; i++ )
    {

        if (juegosMasComprados[i]> maxi)
        {
            maxi = juegosMasComprados[i];
            pos= i;
        }
    }
    if (maxi == 0)
    {
        system("cls");
        rlutil::locate(40,15);
        cout << "No se han realizado compras de este desarrollador" << endl;
        rlutil::locate(40,21);
        system("pause");
        return;
    }
    int cantreg= arcV.contarRegistros();
    for (int i = 0; i<cantreg ; i++ )
    {
        game = arcV.leerRegistros(i);
        if (pos+1 == game.getidVideojuego())
        {
            system("cls");
            rlutil::locate(35,10);  //35 54 51 40
            cout << "Videojuego mas vendido de "<< dev << " es: " << game.getTitulo() << endl;
            rlutil::locate(54,11);
            cout << "Precio: $" << game.getPrecio() << endl;
            rlutil::locate(51,12);
            cout << "Copias vendidas: " << juegosMasComprados[pos] << endl;
            rlutil::locate(40,13);
            system("PAUSE");
            system("cls");
            return;
        }
    }
}

void modificarVideojuego()
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;
    char opcion;
    int idJuego;
    int tam = arcV.contarRegistros();
    system("cls");
    cout << "Desea listar los videojuegos?" << endl;
    cout << "Respuesta (s/n): ";
    cin >> opcion;
    if (opcion == 's')
    {
        for (int i = 0; i < tam; i++)
        {
            game = arcV.leerRegistros(i);
            cout<< i+1 << " --- " << game.getTitulo() << " --- "<< endl;
        }
    }
    cout << "=================================================" << endl;
    cout << "(0 Para salir)" << endl;
    cout << endl <<"Ingrese el ID de videojuego que desea modificar: ";
    cin >> idJuego;
    if (idJuego<0)
    {
        system("cls");
        setConsoleColor(4, 0);
        cout<<"La ID no puede ser negativa.";
        setConsoleColor(15, 0);
        system("pause");
        return;
    }
    if (idJuego == 0)
    {
        return;
    }
      if (idJuego > tam)
    {
        cout<<"id de videojuego no encontrada." << endl;

        return;
    }

    if (menuModificarVideojuego(idJuego)==1)
    {
        return;
    }

    system("PAUSE");
}

void deshabilitarVideojuego()
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;
    char opcion;
    int idJuegoDeshabilitar;
    system("cls");
    cout << "Desea listar los videojuegos?" << endl;
    cout << "Respuesta (s/n): ";
    cin >> opcion;
    if (opcion == 's')
    {
        listarVideojuegosAdmin();
    }
    cout << endl << "Ingrese la ID del videojuego a deshabilitar: ";
    cin >> idJuegoDeshabilitar;
    int tam = arcV.contarRegistros();
    for (int i=0 ; i < tam ; i++)
    {
        game = arcV.leerRegistros(i);
        if (game.getidVideojuego() == idJuegoDeshabilitar)
        {
            if (game.getActivo()==true)
            {
                game.setActivo(false);
                arcV.modificarVideojuego(game,i);
                cout << "El juego ha sido deshabilitado correctamente." << endl;
                system("pause");
                system("cls");
            }
            else
            {
                cout << "El juego ya se encontraba deshabilitado." << endl;
                system("pause");
                system("cls");
            }
        }
    }
}

void habilitarVideojuego()
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;
    char opcion;
    int idJuegoHabilitar;
    system("cls");
    cout << "Desea listar los videojuegos?" << endl;
    cout << "Respuesta (s/n): ";
    cin >> opcion;
    if (opcion == 's')
    {
        listarVideojuegosAdmin();
    }
    cout << endl <<"Ingrese la ID del videojuego a habilitar: ";
    cin >> idJuegoHabilitar;
    int tam = arcV.contarRegistros();
    for (int i=0 ; i < tam ; i++)
    {
        game = arcV.leerRegistros(i);
        if (game.getidVideojuego() == idJuegoHabilitar)
        {
            if (game.getActivo()==false)
            {
                game.setActivo(true);
                arcV.modificarVideojuego(game,i);
                cout << "El juego ha sido habilitado correctamente." << endl;
                system("pause");
                system("cls");
            }
            else
            {
                cout << "El juego ya se encontraba habilitado." << endl;
                system("pause");
                system("cls");
            }
        }
    }
}

void listarVideojuegosMod()
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;

    int tam = arcV.contarRegistros();
    system("cls");
    int y = 6;
    for (int i = 0; i < tam; i++)
    {

        game = arcV.leerRegistros(i);
        rlutil::locate(1, y-5);
        cout << "----|";
        rlutil::locate(1, y);
        cout<< "-ID: " << game.getidVideojuego() << " -";
        game.mostrarPorLocate(10, y-5);
        y+=11;
    }
    cout << endl;
    system("pause");
}

void deshabilitarCuentaUsuario()
{
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;
    char opcion;
    int idCuentaDeshabilitar;
    system("cls");
    cout << "Desea listar los usuarios?" << endl;
    cout << "Respuesta (s/n): ";
    cin >> opcion;
    if (opcion == 's')
    {
        listarUsuariosAdmin();
    }
    cout << endl <<"Ingrese el ID del usuario a deshabilitar: ";
    cin >> idCuentaDeshabilitar;
    int tam = arcU.contarRegistros();
    for (int i=0 ; i < tam ; i++)
    {
        usu = arcU.leerRegistros(i);
        if (usu.getID() == idCuentaDeshabilitar)
        {
            if (usu.getActivo()==true)
            {
                if (usu.getAdmin()==false)
                {
                    usu.setActivo(false);
                    arcU.modificarUsuario(usu,i);
                    system("cls");
                    cout << "El usuario ha sido deshabilitado correctamente." << endl;
                    system("pause");
                    system("cls");
                }
                else
                {
                    system("cls");
                    cout << "No se puede deshabilitar una cuenta de administrador." << endl;
                    system("pause");
                    system("cls");
                }

            }
            else
            {
                cout << "El usuario ya se encontraba deshabilitado." << endl;
                system("pause");
                system("cls");
            }
        }
    }
}

void habilitarCuentaUsuario()
{
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;
    char opcion;
    int idCuentaHabilitar;
    system("cls");
    cout << "Desea listar los usuarios?" << endl;
    cout << "Respuesta (s/n): ";
    cin >> opcion;
    if (opcion == 's')
    {
        listarUsuariosAdmin();
    }
    cout << endl <<"Ingrese el ID del usuario a habilitar: ";
    cin >> idCuentaHabilitar;
    int tam = arcU.contarRegistros();
    for (int i=0 ; i < tam ; i++)
    {
        usu = arcU.leerRegistros(i);
        if (usu.getID() == idCuentaHabilitar)
        {
            if (usu.getActivo()==false)
            {
                usu.setActivo(true);
                arcU.modificarUsuario(usu,i);
                cout << "El usuario ha sido habilitado correctamente." << endl;
                system("pause");
                system("cls");
            }
            else
            {
                cout << "El usuario ya se encontraba habilitado." << endl;
                system("pause");
                system("cls");
            }
        }
    }
}

void otorgarAdmin()
{
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;
    archivoAdmin arcA ("archivos/admin.dat");
    Admin adm;
    int tamArchivoAdmin = arcA.contarRegistros();
    char opcion;
    int idCuentaHabilitar;
    system("cls");
    cout << "Desea listar los usuarios?" << endl;
    cout << "Respuesta (s/n): ";
    cin >> opcion;
    if (opcion == 's')
    {
        listarAdmins();
    }
    cout << endl <<"Ingrese el ID de usuario a otorgar rango admin: ";
    cin >> idCuentaHabilitar;
    int tam = arcU.contarRegistros();
    for (int i=0 ; i < tam ; i++)
    {
        usu = arcU.leerRegistros(i);
        if (usu.getID() == idCuentaHabilitar)
        {
            if (usu.getAdmin()==false && usu.getActivo())
            {
                system("cls");
                usu.setAdmin(true);
                ///REVISO SI YA ESTABA REGISTRADO ANTES EN EL ARCHIVO DE ADMINISTRADORES:
                for (int j=0 ; j < tamArchivoAdmin ; j++)
                {
                    adm = arcA.leerRegistros(j);
                    if (adm.getIdAdmin()==idCuentaHabilitar)
                    {
                        cout << "Esta cuenta tuvo permisos de administrador anteriormente." << endl;
                        adm.setAdmin(true);
                        arcA.modificarAdmin(adm,j);
                        arcU.modificarUsuario(usu,i);
                        cout << "Se ha otorgado el rango nuevamente." << endl;
                        system("pause");
                        system("cls");
                        return;
                    }
                }
                ////////////////////////////////////////
                grabarRegistroadmin(idCuentaHabilitar);
                arcU.modificarUsuario(usu,i);
                cout << "Se ha otorgado el rango correctamente." << endl;
                system("pause");
                system("cls");
            }
            else
            {
                if (usu.getAdmin())
                {
                    cout << "El usuario ya contenía rango admin." << endl;
                    system("pause");
                    system("cls");
                }
                else if (usu.getActivo()==false)
                {
                    cout << endl << "El usuario esta deshabilitado actualmente. No puede otorgarle permisos de administrador." << endl;
                    cout << endl <<"Habilite este usuario primero." << endl;
                    system("pause");
                    system("cls");
                }
            }
        }
    }
}

void removerAdmin()
{
    archivoUsuario arcU("archivos/Usuario.dat");
    archivoAdmin arcA("archivos/admin.dat");
    usuario usu;
    Admin adm;
    char opcion;
    int idCuentaHabilitar;

    cout << "Desea listar los usuarios?" << endl;
    cout << "Respuesta (s/n): ";
    cin >> opcion;
    if (opcion == 's')
    {
        listarAdmins();
    }
    cout << endl <<"Ingrese el ID de usuario a remover rango admin: ";
    cin >> idCuentaHabilitar;
    int tam = arcU.contarRegistros();
    for (int i=0 ; i < tam ; i++)
    {
        usu = arcU.leerRegistros(i);
        if (usu.getID() == idCuentaHabilitar)
        {
            if (usu.getAdmin()==true)
            {
                int tamArchivoAdmin = arcA.contarRegistros();
                for (int j=0 ; j < tamArchivoAdmin ; j++)
                {
                    adm = arcA.leerRegistros(j);
                    if (adm.getIdAdmin() == idCuentaHabilitar)
                    {
                        adm.setAdmin(false);
                        arcA.modificarAdmin(adm,j);
                        cout << "Se ha removido el rango correctamente (Archivo ADMINS). ID: " << adm.getIdAdmin() << endl;
                        break;
                    }
                    ///BUSCA LA ID EN EL ARCHIVO DE ADMIN Y GRABA LOS DATOS EN EL OBJ ADM
                }

                usu.setAdmin(false);
                arcU.modificarUsuario(usu,i);
                cout << "Se ha removido el rango correctamente. (Archivo USUARIOS). ID: " << usu.getID() << endl;
                system("pause");
                system("cls");
            }
            else
            {
                cout << "El usuario no contenía rango admin." << endl;
                system("pause");
                system("cls");
            }
        }
    }
}

void listarVideojuegosAdmin()///LISTA LOS JUEGOS, PERO CON DESHABILITADOS INCLUIDOS
{
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    usuario usu;
    archivoUsuario arcU("archivos/Usuario.dat");
    usu = arcU.leerRegistros(datosUsuarioIniciado());
    int cantReg = arcV.contarRegistros();
    setConsoleColor(11, 1);
    cout<<"VideoJuegos: " << endl << endl;
    for (int i = 0; i < cantReg; i++)
    {
        game = arcV.leerRegistros(i);
        setConsoleColor(15, 1);
        cout<< i+1 << " - " << game.getTitulo();
        cout << " -----  Estado en la tienda: " ;
        if (game.getActivo())
        {
            cout << "Activo." << endl;
        }
        else
        {
            cout << "Deshabilitado." << endl;
        }
    }
}

void listarUsuariosAdmin()
{
    usuario usu;
    archivoUsuario arcU("archivos/Usuario.dat");
    usu = arcU.leerRegistros(datosUsuarioIniciado());
    int cantReg = arcU.contarRegistros();
    setConsoleColor(11, 1);
    cout<<"Usuarios: " << endl << endl;
    for (int i = 0; i < cantReg; i++)
    {
        usu = arcU.leerRegistros(i);
        setConsoleColor(15, 1);
        cout<< i+1 << " - " << usu.getNombre();
        cout << " -----  Estado de la cuenta: " ;
        if (usu.getActivo())
        {
            cout << "Habilitada" << endl;
        }
        else
        {
            cout << "Desabilitada" << endl;
        }
    }
}

void listarAdmins()
{
    usuario usu;
    archivoUsuario arcU("archivos/Usuario.dat");
    usu = arcU.leerRegistros(datosUsuarioIniciado());
    int cantReg = arcU.contarRegistros();
    setConsoleColor(11, 1);
    cout<<"Usuarios: " << endl << endl;
    for (int i = 0; i < cantReg; i++)
    {
        usu = arcU.leerRegistros(i);
        setConsoleColor(15, 1);
        cout<< i+1 << " - " << usu.getNombre();
        cout << " -----  Estado de la cuenta: " ;
        if (usu.getAdmin()==true)
        {
            cout << "Admin" << endl;
        }
        else
        {
            cout << "Usuario" << endl;
        }
    }


}

bool hayUnAdmin()
{
    Admin admin;
    archivoAdmin arcA("archivos/admin.dat");
    int tam = arcA.contarRegistros();
    for (int i = 0; i < tam; i++)
    {
        admin = arcA.leerRegistros(i);
        if (admin.getAdmin()) return true;
    }
    return false;
}

void mostrarArchivoAdmin()
{
    archivoAdmin arcA ("archivos/admin.dat");
    Admin adm;
    int tam = arcA.contarRegistros();
    rlutil::locate(0,0);
    system("cls");
    for (int i = 0; i<tam ; i++ )
    {
        cout << "============== REGISTRO: "<< i <<" ============" << endl;
        adm= arcA.leerRegistros(i);
        adm.mostrarDatos();
        cout << "======================================" << endl;
    }
    system("pause");
    system("cls");
}

void grabarRegistroadmin(int idCuentaHabilitar)
{
    archivoAdmin arcA("archivos/admin.dat");
    Admin adm;
    archivoUsuario arcU("archivos/usuario.dat");
    usuario usu;

    int tam = arcU.contarRegistros();
    for (int i = 0; i<tam ; i++)
    {
        usu = arcU.leerRegistros(i);
        if(usu.getID() == idCuentaHabilitar)
        {
            adm.setIdAdmin(idCuentaHabilitar);
            adm.setNombre(usu.getNombre());
            adm.setDNI(usu.getDNI());
            adm.setEdad(usu.getEdad());
            ///Creo que ahi funciona XD
            adm.setPais(usu.getPais());
            adm.setMail(usu.getMail());
            adm.setAdmin(true);
            //cout << endl << "TEXTOS PARA VERIFICAR QUE TODO FUNCIONE CORRECTAMENTE XD" << endl  << "Datos a grabar:" << endl;
            //adm.mostrarDatos();
            if (arcA.grabarRegistros(adm))
            {
                cout << "CUENTA REGISTRADA EN ARCHIVO DE ADMINISTRADORES"<<endl;   //El metodo de grabar registros retorna bool
            }
        }
    }
}

void estadisticasJuegosMasComprados()
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;
    archivoBiblioteca arcB ("archivos/biblioteca.dat");
    Biblioteca libro;

    int juegosMasComprados[150]= {};
    int tam = arcB.contarRegistros();
    int maxi =0;
    for (int l =0 ; l<tam ; l++ )
    {
        libro = arcB.leerBiblioteca(l);
        for (int j=0; j<150 ; j++ )
        {
            if (libro.getIdVideojuego(j) != 0)
            {
                juegosMasComprados[j]++;
            }
        }
    }
    int pos=0;

    for (int i=0; i<150 ; i++ )
    {

        if (juegosMasComprados[i]> maxi)
        {

            maxi = juegosMasComprados[i];
            pos= i;
        }
    }

    int cantreg= arcV.contarRegistros();
    for (int i = 0; i<cantreg ; i++ )
    {
        game = arcV.leerRegistros(i);
        if (  pos+1 == game.getidVideojuego())
        {
            rlutil::locate(10,5);
            cout<<"El juego mas comprado es-----> "<< game.getTitulo() << " con un precio de : "<< game.getPrecio() << "$ <-- con un total de: "<<juegosMasComprados[pos] << " compras"<<endl;
            rlutil::locate(40,6);
            system("PAUSE");
            return;
        }
    }
}

void puntoRestauracion()
{
    system("cls");
    int opcion;
    while (true)
    {
        cout << "================================" << endl;
        cout << "     PUNTOS DE RESTAURACION     " << endl;
        cout << "================================" << endl;
        cout << "(1) Crear punto de restauracion" << endl;
        cout << "(2) Cargar punto de restauracion" << endl;
        cout << "================================" << endl;
        cout << "(0) Salir" << endl;
        cout << "Ingrese una opcion:";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            crearPuntoRestauracion();
            return;
            break;
        case 2:
        {
            int opcion2;
            cout << "Estas seguro de que quieres restaurar al ultimo punto creado?"<<endl;
            cout << "(1) Si" << endl;
            cout << "(2) No" << endl;
            cin >> opcion2;
            if (opcion2 == 1)
            {
                cargarPuntoRestauracion();
            }
            return;
        }
        break;
        case 0:
            return;
        default:
            cout << "Opcion Invalida." << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}

void crearPuntoRestauracion()
{
    archivoAdmin registroAdmin("archivos/admin.dat");
    archivoVideoJuego registroVideojuego("archivos/videoJuego.dat");
    archivoUsuario registroUsuario("archivos/Usuario.dat");
    archivoBiblioteca registroBiblioteca("archivos/biblioteca.dat");
    archivoGenero registroGenero("archivos/genero.dat");
    archivoDesarrollador registroDesarrollador("archivos/desarrolladores.dat");
    ///ARCHIVOS BACKUP
    archivoAdmin registroAdminBackup("archivos/backupadmin.dat");
    archivoVideoJuego registroVideojuegoBackup("archivos/backupvideoJuego.dat");
    archivoUsuario registroUsuarioBackup("archivos/backupUsuario.dat");
    archivoBiblioteca registroBibliotecaBackup("archivos/backupbiblioteca.dat");
    archivoGenero registroGeneroBackup("archivos/backupGenero.dat");
    archivoDesarrollador registroDesarrolladorBackup("archivos/backupDesarrolladores.dat");
    Admin admin;
    videoJuego juego;
    usuario usu;
    Biblioteca lib;
    Desarrollador dev;
    Genero gen;

    //CREACION DE ARCHIVOS // SOBREESCRITURA DE 0
    registroAdminBackup.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroVideojuegoBackup.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroUsuarioBackup.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroBibliotecaBackup.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroGeneroBackup.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroDesarrolladorBackup.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    int tam = registroAdmin.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        admin = registroAdmin.leerRegistros(i);
        registroAdminBackup.grabarRegistros(admin);
    }

    tam = registroVideojuego.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        juego = registroVideojuego.leerRegistros(i);
        registroVideojuegoBackup.grabarRegistros(juego);
    }

    tam = registroUsuario.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        usu = registroUsuario.leerRegistros(i);
        registroUsuarioBackup.grabarRegistros(usu);
    }

    tam = registroBiblioteca.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        lib = registroBiblioteca.leerBiblioteca(i);
        registroBibliotecaBackup.grabarRegistros(lib);
    }

    tam = registroGenero.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        gen = registroGenero.leerRegistros(i);
        registroGeneroBackup.grabarRegistros(gen);
    }

    tam = registroDesarrollador.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        dev = registroDesarrollador.leerRegistros(i);
        registroDesarrolladorBackup.grabarRegistros(dev);
    }

    system("cls");
    rlutil::locate(35,14);
    cout << "Punto de restauracion creado correctamente!" << endl;
    rlutil::locate(40,15);
    system("pause");
    system("cls");
}

void cargarPuntoRestauracion()
{
    archivoAdmin registroAdmin("archivos/admin.dat");
    archivoVideoJuego registroVideojuego("archivos/videoJuego.dat");
    archivoUsuario registroUsuario("archivos/Usuario.dat");
    archivoBiblioteca registroBiblioteca("archivos/biblioteca.dat");
    archivoGenero registroGenero("archivos/genero.dat");
    archivoDesarrollador registroDesarrollador("archivos/desarrolladores.dat");
    ///ARCHIVOS BACKUP
    archivoAdmin registroAdminBackup("archivos/backupadmin.dat");
    archivoVideoJuego registroVideojuegoBackup("archivos/backupvideoJuego.dat");
    archivoUsuario registroUsuarioBackup("archivos/backupUsuario.dat");
    archivoBiblioteca registroBibliotecaBackup("archivos/backupbiblioteca.dat");
    archivoGenero registroGeneroBackup("archivos/backupGenero.dat");
    archivoDesarrollador registroDesarrolladorBackup("archivos/backupDesarrolladores.dat");
    Admin admin;
    videoJuego juego;
    usuario usu;
    Biblioteca lib;
    Desarrollador dev;
    Genero gen;

    //CREACION DE ARCHIVOS // SOBREESCRITURA DE 0
    registroAdmin.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroVideojuego.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroUsuario.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroBiblioteca.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroDesarrollador.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroGenero.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)

    int tam = registroAdminBackup.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        admin = registroAdminBackup.leerRegistros(i);
        registroAdmin.grabarRegistros(admin);
    }

    tam = registroVideojuegoBackup.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        juego = registroVideojuegoBackup.leerRegistros(i);
        registroVideojuego.grabarRegistros(juego);
    }

    tam = registroUsuarioBackup.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        usu = registroUsuarioBackup.leerRegistros(i);
        registroUsuario.grabarRegistros(usu);
    }

    tam = registroBibliotecaBackup.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        lib = registroBibliotecaBackup.leerBiblioteca(i);
        registroBiblioteca.grabarRegistros(lib);
    }

    tam = registroDesarrolladorBackup.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        dev = registroDesarrolladorBackup.leerRegistros(i);
        registroDesarrollador.grabarRegistros(dev);
    }

    tam = registroGeneroBackup.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        gen = registroGeneroBackup.leerRegistros(i);
        registroGenero.grabarRegistros(gen);
    }

    system("cls");
    rlutil::locate(35,14);
    cout << "Registros cargados al punto de restauracion correctamente!" << endl;
    rlutil::locate(40,15);
    system("cls");
}


/*
void cargarGenerosLista(int ){

archivoVideoJuego arcV ("archivos/videoJuego.dat");
videoJuego game;

archivoGenero arcG ("archivos/genero.dat");
Genero gene;

int tam = arcV.contarRegistros();
bool existe;

for (int i = 0; i<tam ;i++ ){

    game = arcV.leerRegistros(i);

    for (int i = 0; i < tam; i++)
        {
            if (strcmp())
                ;
        }



}
}*/

void ponerChar(int caracter, int largo)
{
    for (int i = 0 ; i < largo ; i++)
    {
        cout << char(caracter);
    }
}
