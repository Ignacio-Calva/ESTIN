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
        cout<<"0 - cerrar"<<endl;
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
        case 0:
            break;
        default:
            cout<< "Opcion invalida.";
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
        cout<<"5) - registro de compras"<<endl;

        rlutil::locate(45,20);
        setConsoleColor(4,3);
        cout<<"0 - cerrar"<<endl;

        setConsoleColor(15, 3);

        rlutil::locate(10,26);
        cout<<"Ingrese su opcion :"<<endl;
        rlutil::locate(25,26);
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
            cout<< "Opcion invalida.";
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
        default:
            cout<< "Opcion invalida.";
            break;
        }
    }
}

void menuAdministrador()
{
    while (true)
    {
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
        setConsoleColor(11, 0);
        cout << "=======================================" << endl;
        cout << "        MENU DE ADMINISTRADOR          " << endl;
        cout << "=======================================" << endl;
        setConsoleColor(15, 0);
        cout << "----------------------------------------------------------" << endl;
        cout << "(1) Agregar juego a la tienda" << endl;
        cout << "(2) Modificar videojuego existente" << endl;
        cout << "(3) Deshabilitar juego de la tienda" << endl;
        cout << "(4) Habilitar juego de la tienda" << endl;
        cout << "(5) Listar todos los videojuegos+info" << endl;
        cout << "(6) Habilitar cuenta" << endl;
        cout << "(7) Deshabilitar cuenta" << endl;
        cout << "(8) Otorgar permisos de administrador" << endl;
        cout << "(9) Remover permisos de administrador" << endl;
        cout << "(10) Listar admins registrados" << endl;
        cout << "(11) Videojuegos mas vendidos" << endl;
        cout << "(12) Puntos de restauracion del sistema" << endl;
        cout << "=======================================" << endl;
        setConsoleColor(4,0);
        cout << "(0) SALIR." << endl;
        setConsoleColor(15,0);
        cin >> opcion;
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
    system("CLS");
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
        cout << "=======================================" << endl;
        cout << "     MODIFICACION JUEGO: " << game.getTitulo() << endl;
        cout << "=======================================" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "(1) modificar nombre" << endl;
        cout << "(2) modificar genero" << endl;
        cout << "(3) modificar precio" << endl;
        cout << "(4) modificar calificacion"<< endl;
        cout << "(5) modificar idioma"<< endl;
        cout << "(6) modificar desarrollador"<< endl;
        cout << "(7) modificar peso"<< endl;
        cout << "(8) modificar restriccion anio"<< endl;
        cout << "(9) modificar anio"<< endl;
        cout << "(10) modificar todo" << endl;
        cout << "=======================================" << endl;
        setConsoleColor(4,0);
        cout << "(0) SALIR." << endl;
        setConsoleColor(15,0);
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        case 1:
            cout<<"------------------------"<<endl;
            cout<<"->Modificar Nombre"<<endl;
            cout<<"------------------------"<<endl;
            cout<<"Ingrese el nuevo nombre: ";
            cargarCadena(pal, 29);

            for (int i = 0; i < tam; i++)
            {
                game = arcV.leerRegistros(i);
                if (strcmp(pal, game.getTitulo())==0)
                {
                    cout<<"Ya existe un videojuego con ese nombre.";
                    system("pause");
                    system("cls");
                    return false;
                }
            }
            game = arcV.leerRegistros(idJuego-1);
            game.setTitulo(pal);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 2:
            cout<<"------------------------"<<endl;
            cout<<"->Modificar Genero"<<endl;
            cout<<"------------------------"<<endl;
            cout<<"Ingrese el nuevo genero: ";
            cargarCadena(pal, 29);
            game = arcV.leerRegistros(idJuego-1);
            game.setGenero(pal);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 3:
            cout<<"------------------------"<<endl;
            cout<<"->Modificar Precio"<<endl;
            cout<<"------------------------"<<endl;
            cout<<"Ingrese el nuevo precio: ";
            cin>>num2;
            if (num2 < 0)
            {
                system("cls");
                setConsoleColor(4,0);
                cout<<"El precio no puede ser negativo.";
                setConsoleColor(15,0);
                system("pause");
                return false;
            }
            game = arcV.leerRegistros(idJuego-1);
            game.setPrecio(num2);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 4:
            cout<<"Ingrese la nueva calificacion: ";
            cin>>num2;
            if (num2 < 0)
            {
                system("cls");
                setConsoleColor(4,0);
                cout<<"La calificacion no puede ser negativa.";
                setConsoleColor(15,0);
                system("pause");
                return false;
            }
            if (num2 > 100)
            {
                system("cls");
                setConsoleColor(4,0);
                cout<<"La calificacion no puede ser mayor que 100 .";
                setConsoleColor(15,0);
                system("pause");
                return false;
            }
            game = arcV.leerRegistros(idJuego-1);
            game.setCalificacion(num2);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 5:
            cout<<"Ingrese el nuevo idioma: ";
            cargarCadena(pal, 29);

            game = arcV.leerRegistros(idJuego-1);
            game.setIdioma(pal);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 6:
            cout<<"Ingrese el nuevo desarrollador: ";
            cargarCadena(pal, 29);

            game = arcV.leerRegistros(idJuego-1);
            game.setDesarrollador(pal);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 7:
            cout<<"Ingrese el nuevo peso: ";
            cin>>num1;

            game = arcV.leerRegistros(idJuego-1);
            game.setPeso(num1);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 8:
            cout<<"Ingrese la nueva restriccion de edad: ";
            cin>>num1;

            game = arcV.leerRegistros(idJuego-1);
            game.setRestriccionEdad(num1);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 9:
            cout<<"Ingrese el nuevo anio de salida: ";
            cin>>num1;
            game = arcV.leerRegistros(idJuego-1);
            game.setAnio(num1);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 10:
            cout<< "---- ID: " << idJuego << " ----"<<endl<<endl;
            cout<<"Ingrese el nuevo nombre: ";
            cargarCadena(pal, 29);

            for (int i = 0; i < tam; i++)
            {
                game = arcV.leerRegistros(i);
                if (strcmp(pal, game.getTitulo())==0)
                {
                    cout<<"Ya existe un videojuego con ese nombre.";
                    system("pause");
                    system("cls");
                    return false;
                }
            }
            game = arcV.leerRegistros(idJuego-1);
            game.setTitulo(pal);
            cout<<"Ingrese el nuevo genero: ";
            cargarCadena(pal, 29);
            game.setGenero(pal);
            cout<<"Ingrese el nuevo precio: ";
            cin>>num2;
            game.setPrecio(num2);
            cout<<"Ingrese la nueva calificacion: ";
            cin>>num2;
            game.setCalificacion(num2);
            cout<<"Ingrese el nuevo idioma: ";
            cargarCadena(pal, 29);
            game.setIdioma(pal);
            cout<<"Ingrese el nuevo desarrollador: ";
            cargarCadena(pal, 29);
            game.setDesarrollador(pal);
            cout<<"Ingrese el nuevo peso: ";
            cin>>num1;
            game.setPeso(num1);
            cout<<"Ingrese la nueva restriccion: ";
            cin>>num1;
            game.setRestriccionEdad(num1);
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
        setConsoleColor(4,0);
        cout << "(0) SALIR." << endl;
        setConsoleColor(15,0);
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            estadisticasJuegosMasComprados();
            break;
        case 2:
            videojuegoMasVendidoGenero();
            break;
        case 3:
            videojuegoMasVendidoDesarrollador();
            break;
        case 4:
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
                        cout << "                     contrase"<< char(164) <<"a correcta!                     " << endl;
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
    cout << "         REGISTRO USUARIO       " << endl;
    cout << "================================" << endl;
    usuario obj, objAux;
    archivoUsuario archivo("archivos/Usuario.dat");
    char nombre[30];
    char contra[20];
    Fecha obj2;
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
    cout << "INGRESE EL NOMBRE DE USUARIO: ";
    cargarCadena(nombre, 29);
    for (int i=0 ; i < tam ; i++)
    {
        objAux = archivo.leerRegistros(i);
        if (strcmp(nombre,objAux.getNombre())==0 || strcmp(nombre,"admin")==0)
        {
            cout << "El nombre de usuario ya esta en uso." << endl;
            system("pause");
            system("cls");
            return;
        }
        else if (strcmp(nombre,"")==0)
        {
            cout << "No puede dejar este campo vacio." << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    obj.setNombre(nombre);
    cout << "INGRESE LA CONTRASENIA DEL USUARIO: ";
    cargarCadena(contra, 19);
    if (strcmp(contra,"")==0)
    {
        cout << "No puede dejar este campo vacio." << endl;
        system("pause");
        system("cls");
        return;
    }
    obj.setContrasenia(contra);
    cout<< "INGRESE SU FECHA DE NACIMIENTO..." << endl;
    obj2.cargar();
    edad = 2024 - obj2.getAnio();
    obj.setEdad(edad);
    cout<< "TU EDAD ES: " << edad << endl;
    system("pause");
    cout<< "INGRESE SU DNI: ";
    cin>> dni;
    if (dni < 0)
    {
        cout << "El DNI debe ser mayor a 0." << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < tam; i++)
    {
        objAux = archivo.leerRegistros(i);
        if (dni == objAux.getDNI())
        {
            cout<< "Ya existe una cuenta con dicho DNI." << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    obj.setDNI(dni);
    cout<< "INGRESE SU MAIL: ";
    cargarCadena(mail, 29);
    if (strcmp(mail,"")==0)
    {
        cout << "No puede dejar este campo vacio." << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < tam; i++)
    {
        objAux = archivo.leerRegistros(i);
        if (strcmp(mail, objAux.getMail())==0)
        {
            cout<< "Ya existe una cuenta con dicho mail." << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    obj.setMail(mail);
    cout<< "INGRESE SU PAIS (SOLO LATAM): ";
    cargarCadena(pais,29);
    obj.setPais(pais);
    int IdBiblioteca = designarBiblioteca(obj.getID());
    cout<< "ID de biblioteca seteada como: "<< IdBiblioteca<<endl;
    cout << "ID DEL NUEVO USUARIO SETEADA COMO: " << obj.getID() << endl;
    obj.setTarjet(0);
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
                system("cls");
                setConsoleColor(15, 5);
                cout<<"==============================" << endl;
                cout<<"     INFO CUENTA PERSONAL     "<<endl;
                cout<<"==============================" << endl<<endl;
                setConsoleColor(15,0);
                usu.mostrarDatos();
                if (usu.getActivo() == false)
                {
                    setConsoleColor(4, 0);
                    cout << "-----------CUENTA DESHABILITADA-----------" << endl;
                }
                cout << endl;
                setConsoleColor(15, 0);
                cout<<"1 - Deshabilitar cuenta"<<endl;
                cout<<"2 - Asignar tarjeta"<<endl;
                cout<<"0 - Salir"<<endl;
                cout<<"======================="<<endl<<endl;
                cout<<"Elija una opcion: ";
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
    cout<<"Tu biblioteca asignada tiene ID: "<< libro.getIdUsuario()<<endl;
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
    archivoBiblioteca arcB ("archivos/biblioteca.dat");
    Biblioteca libro;
    Fecha compra;
    cout<<"----------------------------"<<endl;
    cout<<"Cagando Videojuego nuevo: "<<endl;
    cout<<"----------------------------"<<endl;
    int tam = arcB.contarRegistros();
    for (int i =0; i<tam ; i++)
    {
        libro= arcB.leerBiblioteca(i);
        if(idIniciada == libro.getIdUsuario())
        {
            cout << "Numero de registro de biblioteca cargado: " << i << endl;
            cout << "ID de Biblioteca de usuario cargada: " << libro.getIdUsuario() << endl;
            compra.cargar();
            libro.setFechaCompra(compra,idVideojuego-1);
            libro.setIdVideojuego(idVideojuego-1, idVideojuego);
            arcB.modificarBiblioteca(i,libro);
            //arcB.grabarRegistros(libro);
            cout<<"El videojuego ha sido agregado a tu biblioteca con exito, disfruta!! " << endl;
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
            rlutil :: locate(40, 3);
            cout<<"              BIBLIOTECA ESTIM        "<<endl;
            rlutil :: locate(40, 4);
            cout<<"=============================================" << endl<<endl;
            setConsoleColor(15, 3);
            rlutil::locate(10,3);
            cout << "Mostrando biblioteca ID: " << libro.getIdUsuario() << endl;
            rlutil::locate(10,4);
            cout << "Biblioteca del usuario ID: " << idIniciada << endl << endl;
            cout << "============================" << endl;
            libro.mostrar();
            cout << "============================" << endl;
            cout << "Biblioteca del usuario ID: " << idIniciada << endl << endl;

            //libro.mostrar();
            for (int j=0 ; j<150 ; j++)
            {
                if (libro.getIdVideojuego(j)!=0)
                {
                    juego = arcV.leerRegistros(j);
                    juego.mostrar();
                }
            }
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

    rlutil::locate(35,20);
    setConsoleColor(4, 1);
    cout << "0 - ATRAS" << endl;
    setConsoleColor(3, 1);
    rlutil::locate(30,21);
    cout << "---------------------------------------" << endl;
    setConsoleColor(15, 1);
    rlutil::locate(30,22);
    cout << "Ingrese una opcion: ";
    rlutil::locate(50,22);
    cin >> numJuego;

    if (numJuego == 0)
    {
        return;
    }

    if (numJuego < 1 || numJuego > tam)
    {
        rlutil::locate(50,22);
        setConsoleColor(4,1);
        cout << "Numero de juego no encontrado." << endl;
        system("pause");
        return;
    }

    int idJuegoSeleccionado = juegosListados[numJuego - 1];
    caracteristicasVideojuego(idJuegoSeleccionado);
    comprarJuego(idJuegoSeleccionado);
    system("PAUSE");
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
    setConsoleColor(15, 11);
    cout<<"==============================" << endl;
    cout<<"      BIBLIOTECA ESTIM        "<<endl;
    cout<<"==============================" << endl<<endl;
    setConsoleColor(3,0);

    char nombre [30];
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Ingrese el titulo que quiere buscar en su biblioteca: ";
    cargarCadena(nombre, 29);

    system("CLS");
    setConsoleColor(15, 11);
    cout<<"==============================" << endl;
    cout<<"      BIBLIOTECA ESTIM        "<<endl;
    cout<<"==============================" << endl<<endl;
    setConsoleColor(3,0);

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
                            setConsoleColor(15, 0);
                            cout<< "ID: " << game.getidVideojuego()<< " --- " << game.getTitulo()<<" $ "<< game.getPrecio() <<endl;
                            setConsoleColor(8, 0);
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
            setConsoleColor(15,0);
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

    int cantReg = arcV.contarRegistros();
    int tam = arcB.contarRegistros();
    bool salir=false;

    system("CLS");
    setConsoleColor(15, 11);
    cout<<"==============================" << endl;
    cout<<"      BIBLIOTECA ESTIM        "<<endl;
    cout<<"==============================" << endl<<endl;
    setConsoleColor(3,0);

    char genero [30];
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Ingrese el genero que quiere buscar en su biblioteca: ";
    cargarCadena(genero, 29);

    system("CLS");
    setConsoleColor(15, 11);
    cout<<"==============================" << endl;
    cout<<"      BIBLIOTECA ESTIM        "<<endl;
    cout<<"==============================" << endl<<endl;
    setConsoleColor(3,0);

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
                            setConsoleColor(15, 0);
                            cout<< "ID: " << game.getidVideojuego()<< " --- " << game.getTitulo()<<" $ "<< game.getPrecio() <<endl;
                            setConsoleColor(8, 0);
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
            setConsoleColor(15,0);
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

    int cantReg = arcV.contarRegistros();
    int tam = arcB.contarRegistros();
    bool salir=false;

    system("CLS");
    setConsoleColor(15, 11);
    cout<<"==============================" << endl;
    cout<<"      BIBLIOTECA ESTIM        "<<endl;
    cout<<"==============================" << endl<<endl;
    setConsoleColor(3,0);

    char desarrollador [30];
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Ingrese el desarrollador que quiere buscar en su biblioteca: ";
    cargarCadena(desarrollador, 29);

    system("CLS");
    setConsoleColor(15, 11);
    cout<<"==============================" << endl;
    cout<<"      BIBLIOTECA ESTIM        "<<endl;
    cout<<"==============================" << endl<<endl;
    setConsoleColor(3,0);

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
                            setConsoleColor(15, 0);
                            cout<< "ID: " << game.getidVideojuego()<< " --- " << game.getTitulo()<<" $ "<< game.getPrecio() <<endl;
                            setConsoleColor(8, 0);
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
            setConsoleColor(15,0);
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
    float totalGastado;

    system("cls");
    libro = arcB.leerBiblioteca(idIniciada-1);
    cout<<"<<------------------COMPRAS TOTALES DE VIDEOJUEGOS----------------------->>"<<endl;
    cout<<"                            BIBLIOTECA CON ID: "<< libro.getIdUsuario()<<"                       "<<endl;
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

                    }
                }
            }
            setConsoleColor(15, 0);
            libro.mostrar();
        }
    }
    cout<<"El total gastado es : "<< totalGastado<<endl;
    system("PAUSE");
}

///FUNCIONES VIDEOJUEGOS


void comprarJuego(int idVideojuego)
{
    int opcion;
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    usuario usu;
    archivoUsuario arcU("archivos/Usuario.dat");
    archivoBiblioteca arcB("archivos/biblioteca.dat");
    Biblioteca bib;

    while (true)
    {
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
                cout<<"No tienes alguna tarjeta asociada."<<endl;
                rlutil::locate(40, 11);
                cout<<"Desea aniadir una a su cuenta?"<<endl<<endl;
                rlutil::locate(40, 12);
                cout<<"1 - Si"<<endl;
                rlutil::locate(40, 13);
                cout<<"2 - No"<<endl;
                rlutil::locate(40, 14);
                cin>>opcion2;
                switch (opcion2)
                {
                case 1:
                    aniadirTarjeta(idIniciada);
                    system("CLS");
                    return;
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
            return;
        case 0:
            return;
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
    rlutil::locate(30,22);
    cout << "Ingrese una opcion: ";
    rlutil::locate(50,22);
    cargarCadena(genero, 29);
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
        cout << "No hay juegos con esa desarrolladora :(" << endl;
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

    rlutil::locate(30,22);
    cout << "Ingrese una opcion: ";
    rlutil::locate(50,22);
    cargarCadena(desarrolladora, 29);
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
            cout << tam + 1 << " - " << game.getTitulo();
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
            cout << tam + 1 << " - " << game.getTitulo();
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
    usu = arcU.leerRegistros(datosUsuarioIniciado());
    rlutil::locate(40,5);
    cout<< "============================" << endl;
    rlutil::locate(40,6);
    cout << "El filtro aplicado es: " << anio << endl;
    rlutil::locate(40,7);
    cout<< "============================" << endl;

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
    cout<<"==============================" << endl;
    cout<<"->  Cargar Videojuego nuevo      "<<endl;
    cout<<"==============================" << endl<<endl;

    cout<<"Ingrese el nombre del videojuego: ";
    cargarCadena(nombre, 29);

    int tam=arcV.contarRegistros();
    for (int i = 0; i < tam; i++)
    {
        game = arcV.leerRegistros(i);
        if (strcmp(nombre, game.getTitulo())==0)
        {
            cout<<"Dicho videojuego ya se encuentra en el sistema.";
            system("pause");
            return;
        }
    }
    game.setTitulo(nombre);
    game.cargar();
    //if (game.getPrecio()<0  game.getCalificacion() < 0  game.getPeso() < 0 || game.getRestriccion() < 0)
    //  {
    //     return;
//   }
    Genero gene, geneAux;
    archivoGenero arcG("archivos/genero.dat");
    bool existeG=false;
    int tamG = arcG.contarRegistros();
    gene.setNombre(game.getGenero());
    for (int i = 0; i < tamG; i++)
    {
        geneAux = arcG.leerRegistros(i);
        cout << "Registro N" << i << " Genero: " << geneAux.getNombre() << endl;
        if (compararSinMayusculas(geneAux.getNombre(), gene.getNombre()))
        {
            existeG = true;
            break;
        }
    }
    if (existeG == false)
    {
        arcG.grabarRegistros(gene);
        cout<<"se aniadio un nuevo genero al sistema." <<endl;
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
    cout << "Desarrollador a grabar: " << dev << endl;
    objDev.setNombre(dev);
    for (int i=0 ; i < tamDev ; i++)
    {
        devAux = archivoDev.leerRegistros(i);
        cout << "Registro N" << i << ". Desarrollador: " << devAux.getNombre() << endl;
        if (compararSinMayusculas(devAux.getNombre(),objDev.getNombre()))
        {
            existe = true;
            break;
        }
    }
    if (existe == false)
    {
        archivoDev.grabarRegistros(objDev);
        cout << "Se aniadio un nuevo desarrollador al sistema. " << endl;
    }

    cout << "ID del nuevo videojuego seteada como : " << game.getidVideojuego() << endl;

    arcV.grabarRegistros(game);
    system("pause");
}

void listarVideojuegos()
{

    cout<<"==============================" << endl;
    cout<<"-> Listar videojuegos cargados      "<<endl;
    cout<<"==============================" << endl<<endl;
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;

    usuario usu;
    archivoUsuario arcU("archivos/Usuario.dat");

    archivoBiblioteca arcB("archivos/biblioteca.dat");
    Biblioteca bib;
    usu = arcU.leerRegistros(datosUsuarioIniciado());
    bib = arcB.leerBiblioteca(idIniciada-1);
    int cantReg = arcV.contarRegistros();
    setConsoleColor(11, 0);
    cout<<"VideoJuegos: " << endl << endl;
    for (int i = 0; i < cantReg; i++)
    {
        game = arcV.leerRegistros(i);
        if (game.getActivo() && usu.getEdad() >= game.getRestriccion())
        {
            setConsoleColor(15, 0);
            cout<< i+1 << " - " << game.getTitulo() << " <-------> PRECIO: ";
            if (bib.getIdVideojuego(game.getidVideojuego()-1) == 0)
            {
                cout << "$" << game.getPrecio();
            }
            else
            {
                setConsoleColor(4,0);
                cout << "*JUEGO ADQUIRIDO*" ;
                setConsoleColor(15,0);
            }
            cout << " <-------> PESO (GB): " << game.getPeso() << " GB." << endl;
        }
        else if (game.getActivo()==false)
        {
            setConsoleColor(4,0);
            cout << "*JUEGO DESHABILITADO" << endl;
            setConsoleColor(15,0);
        }
        else
        {
            setConsoleColor(4,0);
            cout << "No tienes edad suficiente para este videojuego" << endl;
            setConsoleColor(15,0);
        }
    }
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
    for (int i = 0; i < cantReg; i++)
    {
        system("CLS");
        setConsoleColor(0, 6);
        cout<<"==============================" << endl;
        cout<<"   RESULTADO DE LA BUSQUEDA   "<<endl;
        cout<<"==============================" << endl<<endl;
        setConsoleColor(15,0);
        game = arcV.leerRegistros(i);
        if (compararSinMayusculas(n, game.getTitulo()))
        {
            setConsoleColor(15, 0);
            game.mostrar();
            setConsoleColor(8, 0);
            comprarJuego(game.getidVideojuego());
            return;
        }
    }
    setConsoleColor(12, 0);
    cout<<"Titulo no encontrado, intente nuevamente." << endl;
    setConsoleColor(8, 0);
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
            cout << " --- precio: $ " << game.getPrecio() << endl;
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
    system("CLS");
    char titJuego[50];
    setConsoleColor(0, 6);
    cout<<"==============================" << endl;
    cout<<"            BUSCADOR          " << endl;
    cout<<"==============================" << endl<<endl;
    setConsoleColor(15,0);
    cout<< "INGRESE NOMBRE DEL VIDEOJUEGO: ";
    setConsoleColor(8, 0);
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
    setConsoleColor(0, 12);
    cout<<"==============================" << endl;
    cout<<"           GRATIS!            "<<endl;
    cout<<"==============================" << endl<<endl;
    setConsoleColor(15,0);

    usu = arcU.leerRegistros(datosUsuarioIniciado());
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Filtro aplicado: Precio $0" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    for (int i = 0; i < tam; i++)
    {
        game = arcV.leerRegistros(i);
        if (game.getPrecio() == 0 && usu.getEdad() >= game.getRestriccion() && game.getActivo())
        {
            cout << tam2 + 1 << " - " << game.getTitulo() << "   -- Precio: $ " << game.getPrecio() << endl;
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
        cout << "NO HAY VIDEOJUEGOS GRATIS" << endl;
        system("PAUSE");
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
    char genero[30];
    cout << "Videojuego mas vendido segun GENERO" << endl;
    cout << "===================================" << endl;
    cout << "Ingrese el genero que desea buscar: " ;
    cargarCadena(genero,29);
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
    int cantreg= arcV.contarRegistros();
    for (int i = 0; i<cantreg ; i++ )
    {
        game = arcV.leerRegistros(i);
        if (pos+1 == game.getidVideojuego())
        {
            system("cls");
            cout << "Videojuego mas vendido de "<< genero << " es: " << game.getTitulo() << endl;
            cout << "Precio: $" << game.getPrecio() << endl;
            cout << "Copias vendidas: " << juegosMasComprados[pos] << endl;
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
    cout << "Videojuego mas vendido segun DESARROLLADOR" << endl;
    cout << "===================================" << endl;
    cout << "Ingrese el desarrollador que desea buscar: " ;
    cargarCadena(dev,29);
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;
    archivoBiblioteca arcB ("archivos/biblioteca.dat");
    Biblioteca libro;
    //REVISO QUE EXISTA
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
    int cantreg= arcV.contarRegistros();
    for (int i = 0; i<cantreg ; i++ )
    {
        game = arcV.leerRegistros(i);
        if (pos+1 == game.getidVideojuego())
        {
            system("cls");
            cout << "Videojuego mas vendido de "<< dev << " es: " << game.getTitulo() << endl;
            cout << "Precio: $" << game.getPrecio() << endl;
            cout << "Copias vendidas: " << juegosMasComprados[pos] << endl;
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

    if (menuModificarVideojuego(idJuego)==1)
    {
        return;
    }
    if (idJuego > tam)
    {
        cout<<"id de videojuego no encontrada." << endl;
    }
    system("PAUSE");
}

void deshabilitarVideojuego()
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;
    char opcion;
    int idJuegoDeshabilitar;
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
    for (int i = 0; i < tam; i++)
    {
        game = arcV.leerRegistros(i);
        cout<< endl << "----- ID: " << i+1 << " -----" << endl;
        game.mostrar();
    }
    system("pause");
}

void deshabilitarCuentaUsuario()
{
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;
    char opcion;
    int idCuentaDeshabilitar;
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
    setConsoleColor(11, 0);
    cout<<"VideoJuegos: " << endl << endl;
    for (int i = 0; i < cantReg; i++)
    {
        game = arcV.leerRegistros(i);
        setConsoleColor(15, 0);
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
    setConsoleColor(11, 0);
    cout<<"Usuarios: " << endl << endl;
    for (int i = 0; i < cantReg; i++)
    {
        usu = arcU.leerRegistros(i);
        setConsoleColor(15, 0);
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
    setConsoleColor(11, 0);
    cout<<"Usuarios: " << endl << endl;
    for (int i = 0; i < cantReg; i++)
    {
        usu = arcU.leerRegistros(i);
        setConsoleColor(15, 0);
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
            cout << endl << "TEXTOS PARA VERIFICAR QUE TODO FUNCIONE CORRECTAMENTE XD" << endl  << "Datos a grabar:" << endl;
            adm.mostrarDatos();
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

            cout<<"el juego mas comprado es-----> "<< game.getTitulo() << " con un precio de : "<< game.getPrecio() << "$ <-- con un total de: "<<juegosMasComprados[pos] << " compras"<<endl;

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
    ///ARCHIVOS BACKUP
    archivoAdmin registroAdminBackup("archivos/backupadmin.dat");
    archivoVideoJuego registroVideojuegoBackup("archivos/backupvideoJuego.dat");
    archivoUsuario registroUsuarioBackup("archivos/backupUsuario.dat");
    archivoBiblioteca registroBibliotecaBackup("archivos/backupbiblioteca.dat");
    Admin admin;
    videoJuego juego;
    usuario usu;
    Biblioteca lib;

    //CREACION DE ARCHIVOS // SOBREESCRITURA DE 0
    registroAdminBackup.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroVideojuegoBackup.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroUsuarioBackup.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroBibliotecaBackup.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
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
    system("cls");
    cout << "Punto de restauracion creado correctamente!" << endl;
    system("pause");
    system("cls");
}

void cargarPuntoRestauracion()
{
    archivoAdmin registroAdmin("archivos/admin.dat");
    archivoVideoJuego registroVideojuego("archivos/videoJuego.dat");
    archivoUsuario registroUsuario("archivos/Usuario.dat");
    archivoBiblioteca registroBiblioteca("archivos/biblioteca.dat");
    ///ARCHIVOS BACKUP
    archivoAdmin registroAdminBackup("archivos/backupadmin.dat");
    archivoVideoJuego registroVideojuegoBackup("archivos/backupvideoJuego.dat");
    archivoUsuario registroUsuarioBackup("archivos/backupUsuario.dat");
    archivoBiblioteca registroBibliotecaBackup("archivos/backupbiblioteca.dat");
    Admin admin;
    videoJuego juego;
    usuario usu;
    Biblioteca lib;

    //CREACION DE ARCHIVOS // SOBREESCRITURA DE 0
    registroAdmin.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroVideojuego.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroUsuario.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
    registroBiblioteca.borrarArchivo(); ///LO ABRE EN WB (SI NO EXISTE LO CREA, SI EXISTE LO VACIA)
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
    system("cls");
    cout << "Registros cargados al punto de restauracion correctamente!" << endl;
    system("pause");
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
