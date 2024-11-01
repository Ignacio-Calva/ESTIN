#include <iostream>
using namespace std;
#include <cstring>
#include "funciones.h"
#include "VIDEOJUEGO.h"
#include "BIBLIOTECA.h"
#include "USUARIO.h"
#include "ADMIN.h"
#include <windows.h>

int idIniciada;
Admin cuentaAdmin("admin","password",0,true);

void setConsoleColor(int textColor, int backgroundColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute = textColor + (backgroundColor * 16);
    SetConsoleTextAttribute(hConsole, colorAttribute);
}



void inicioSesion()
{
    while (true){
        system("cls");
        cout << "         INICIO DE SESION       " << endl;
        cout << "================================" << endl;
//        cout << "1- Iniciar sesion como Usuario" << endl;
//        cout << "2- Iniciar sesion como Admin" << endl;
//        cout << "0- Volver" << endl;
//        cout << "================================" << endl<<endl;
//        cout << "Elija una opcion: ";
//        cin >> eleccion;
//        switch(eleccion){
//            case 1:
//                {
        archivoUsuario arcU("archivos/Usuario.dat");
        usuario usu;

        char nombre[30];
        char contrasenia[20];
        system("cls");
        cout << "       INICIO DE SESION      " << endl;
        cout << "=============================" << endl << endl;
        cout << "La cuenta admin es: " << endl;
        cout << cuentaAdmin.getNombre() << " " << cuentaAdmin.getContrasenia() << endl;
        cout << "BORRAR ESTAS LINEAS CUANDO EL PROGRAMA ESTE TERMINADO." << endl;
        cout<<"Ingrese su nombre de usuario: " ;
        cargarCadena(nombre, 29);

        int pos=0; ///USADA POR REFERENCIA PARA GUARDAR DONDE FUE ENCONTRADO EL NOMBRE EN LA FUNCION buscarNombre()

        ///LOGUEO ADMIN MAIN
        if(strcmp(cuentaAdmin.getNombre(),nombre) == 0)
        {
            if (cuentaAdmin.getActivo()==false)
            {
                cout << "La cuenta de administrador principal se encuentra deshabilitada.";
                system("pause");
                system("cls");
                return;
            }///CONFIRMO QUE NO HAYA SIDO DESHABILITADA ANTERIORMENTE
            system("cls");
            cout << "Usuario encontrado." << endl;
            cout << "Ingrese su contrasenia: " ;
            cargarCadena(contrasenia, 19);
            if (strcmp(contrasenia,cuentaAdmin.getContrasenia()) == 0)
            {
                cout<< endl <<"Contrasenia correcta. Se ha iniciado sesion con la cuenta de administrador principal. " << endl;
                if (cuentaAdmin.getAdmin()) cout << endl << "Esta cuenta tiene permisos de administrador."<<endl;
                system("pause");
                system("cls");
                menuAdministrador(); //MODIFICAR EL MENU DE ADMINISTRADOR
            } else
            {
                cout<<"La contrasenia es incorrecta. Vuelva a intentarlo." << endl;
                system("pause");
            }
        }
        else///SI NO SE PUDO INICIAR COMO ADMIN MAIN, PRUEBA CON OTROS USUARIOS
        {
            if (buscarNombre(nombre, pos))
            {
                usu = arcU.leerRegistros(pos);
                cout << "Usuario encontrado." << endl;
                cout << "Ingrese su contrasenia: " ;
                cargarCadena(contrasenia, 19);
                if (strcmp(usu.getContrasenia(),contrasenia) == 0)
                {
                    idIniciada = usu.getID(); //asignar ID iniciada
                    if (usu.getAdmin()==false)
                    {
                        cout << "Sesion iniciada correctamente!" << endl;
                        system("pause");
                        system("cls");
                        menuPrincipal();
                    }
                    else
                    {
                        cout << "Contrasenia correcta. Esta cuenta tiene permisos de administrador." << endl;
                        system("pause");
                        system("cls");
                        //menuAdministrador();
                    }
                }
                else
                {
                    cout << "La contrasenia es incorrecta. Vuelva a intentarlo." << endl;
                    system("pause");
                }
            }
            else
            {
                cout << "Nombre de usuario no encontrado." << endl;
                system("pause");
            }
            return;
        }


//        case 2:
//            cargarVideojuego();
//            system("pause");
//            return;
//        case 0:
//            return;
//        default:
//            cout << "Por favor, ingrese una opcion valida." << endl;
//            system("pause");
//            break;
    }
}


///FUNCIONES VIDEOJUEGOS

void elegirVideojuego()
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");

    int tam = arcV.contarRegistros();
    int numJuego;
    while (true)
    {
        system("CLS");
        listarVideojuegos();

        setConsoleColor(4, 0);
        cout<<endl<<"0 - ATRAS" << endl;
        setConsoleColor(8, 0);
        cout<<"-------------------------------------------------------------------"<<endl;
        cout<<endl<<"INGRESE EL NUMERO DEL JUEGO DESEADO: ";
        cout<<"-------------------------------------------------------------------"<<endl;

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
        comprarJuego();
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

void mostrarTitulo(const string &titulo)
{
    setConsoleColor(15, 1);
    cout << "----- " << titulo << " -----" << endl;
    setConsoleColor(8, 0);
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


///FUNCIONES BUSCAR USUARIO
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

    int IdBiblioteca = designarBiblioteca(obj.getID());
    cout<< "ID de biblioteca seteada como: "<< IdBiblioteca<<endl;
    cout << "ID DEL NUEVO USUARIO SETEADA COMO: " << obj.getID() << endl;
    system("pause");
    archivo.grabarRegistros(obj);
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
return -1;}

int buscarUsuarioPorID(int id)
{
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario obj;
    int tam = arcU.contarRegistros();
    for (int i = 0 ; i < tam ; i++)
    {
        obj = arcU.leerRegistros(i);
        if (id == obj.getID()){return i;}
    }
    return -1;
}

int designarBiblioteca(int idUsuario)
{
    archivoBiblioteca arcB("archivos/biblioteca.dat");
    Biblioteca libro;
    archivoUsuario arcU("archivos/usuario.dat");
    usuario usu;
    int pos = buscarUsuarioPorID(idUsuario);
    arcB.leerBiblioteca(pos);
    libro.setIdUsuario(idUsuario);
    arcB.modificarBiblioteca(pos, libro);
    cout<<"Tu biblioteca asignada tiene ID: "<< libro.getIdUsuario()<<endl;
    int idBibloteca = libro.getIdUsuario();
    return idBibloteca;
    }


///FUNCIONES USUARIO INTERACTIVAS :

void aniadirTarjeta(int idIniciada)
{
    usuario obj;
    archivoUsuario arcU("archivos/Usuario.dat");
    int pos = buscarUsuarioPorID(idIniciada);
    int num;
    if(pos<0)
    {
        cout<<"Error al aniadir tarjeta."<<endl;
        cout << "Codigo de error: " << pos << endl;
        system("pause");
        return;
    }
    cout << "REGISTRO: " << pos << endl;
    cout << "ID SELECCIONADA: " << idIniciada << endl;
    obj = arcU.leerRegistros(pos);
    if(obj.getActivo()==false)
    {
        cout<<"El usuario se encontraba deshabilitado" << endl;
        system("pause");
        return;
    }
    cout<<"Ingrese el numero de tarjeta: ";
    cin>>num;
    obj.setTarjet(num);
    arcU.modificarUsuario(obj,pos);
    cout << "La tarjeta asignada a la cuenta es: " << obj.getTarjet() << endl;
    system("pause");
}

void comprarJuego()
{
    int opcion;

    archivoVideoJuego arcV("archivos/videoJuego.dat");
    usuario usu;
    archivoUsuario arcU("archivos/Usuario.dat");

    while (opcion != 0)
        {
            int opcion2 = 1;
            cout<<"1 - Comprar"<<endl;
            cout<<"0 - Salir"<<endl;
            cout<<"-----------"<<endl;
            cin>>opcion;
            switch (opcion)
            {
            case 1:
                    usu = arcU.leerRegistros(idIniciada-1);
                    if (usu.getTarjet() != 0)
                    {
                        cout<<"juego comprado, disfrute :D";
                        system("PAUSE");
                        return;
                    }else if (usu.getTarjet() == 0)
                    {
                        cout<<"No tienes alguna tarjeta asociada."<<endl;
                        cout<<"Desea añadir una a su cuenta?"<<endl<<endl;
                        cout<<"1 - si"<<endl;
                        cout<<"2 - no"<<endl;
                        cin>>opcion2;
                        switch (opcion2)
                        {
                        case 1:
                            aniadirTarjeta(idIniciada);
                            system("CLS");
                            return;
                        case 2:
                            cout<<"Okay..."<<endl;
                            system("PAUSE");
                            system("CLS");
                            return;
                        default:
                            break;
                        }
                    }
                break;
            }
        }
}

void bajaUsuario(int idIniciada)
{
    usuario obj;
    archivoUsuario arcU("archivos/Usuario.dat");
    int pos = buscarUsuarioPorID(idIniciada);
    if(pos<0){
        cout<<"Error al modificar usuario."<<endl;
        cout << "Codigo de error: " << pos << endl;
        system("pause");
        return;
    }
    cout << "REGISTRO: " << pos << endl;
    cout << "ID SELECCIONADA: " << idIniciada << endl;
    obj = arcU.leerRegistros(pos);
    if(obj.getActivo()==false){
        cout<<"El usuario ya se encontraba deshabilitado" << endl;
        system("pause");
        return;
    }
    obj.setActivo(false);
    arcU.modificarUsuario(obj,pos);
    cout << "La cuenta ha sido deshabilitada." << endl;
    system("pause");
}

void infoCuenta()
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
                   if (usu.getActivo() == false){setConsoleColor(4, 0);cout << "-----------CUENTA DESHABILITADA-----------" << endl;}
                   cout << endl; setConsoleColor(15, 0);
                   cout<<"1 - Deshabilitar cuenta"<<endl;
                   cout<<"2 - Asignar tarjeta"<<endl;
                   cout<<"0 - Salir"<<endl;
                   cin>>opcion;
                   switch (opcion)
                   {
                   case 1:
                       bajaUsuario(idIniciada);
                       break;
                   case 2:
                     aniadirTarjeta(idIniciada);
                       break;
                   case 0: break;
                   default: system("CLS");setConsoleColor(4, 0); cout<<"Opcion invalida" <<endl;
                       break;
                   }
                   }
                }
        }
}

void menuPrincipal()
{
    int opcion = 1;
    while (opcion!=0)
    {
        system("CLS");
        setConsoleColor(15, 1);
        cout<<"VALEAM"<<endl<<endl;
        setConsoleColor(3, 0);
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


///FUNCIONES ADMINISTRADOR :

void menuAdministrador()
{
    while (true)
    {
        int opcion;
        cout << "=======================================" << endl;
        cout << "        MENU DE ADMINISTRADOR          " << endl;
        cout << "=======================================" << endl;
        cout << "(1) Agregar juego a la tienda" << endl;
        cout << "(2) Deshabilitar juego de la tienda" << endl;
        cout << "(3) Habilitar juego de la tienda" << endl;
        cout << "(4) Habilitar cuenta" << endl;
        cout << "(5) Deshabilitar cuenta" << endl;
        cout << "(6) Otorgar permisos de administrador" << endl;
        cout << "(7) Remover permisos de administrador" << endl;
        cout << "(0) Cerrar Sesion" << endl;
        cout << "=======================================" << endl;
        cout << endl << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cargarVideojuego();
            system("pause");
            system("cls");
            break;
        case 2:
            deshabilitarVideojuego();//(Lo deshabilita)
            break;
        case 3:
            habilitarVideojuego();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 0:
            return;
        default:
            break;
        }
    }
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
    if (opcion == 's'){listarVideojuegosAdmin();}
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
            else{cout << "El juego ya se encontraba deshabilitado." << endl; system("pause"); system("cls");}
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
    if (opcion == 's'){listarVideojuegosAdmin();}
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
            else{cout << "El juego ya se encontraba habilitado." << endl; system("pause"); system("cls");}
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
        if (game.getActivo()){cout << "Activo." << endl;}
        else {cout << "Deshabilitado." << endl;}
    }
    system("pause");
}

void cargarVideojuego()
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    videoJuego game;
    videoJuego gameAnt;
    game.cargar();

    int tam=arcV.contarRegistros();

    gameAnt = arcV.leerRegistros(tam-1); //CARGA LOS DATOS DEL ULTIMO REGISTRO
    game.setidVideojuego(gameAnt.getidVideojuego()+1);

     cout << "ID del nuevo videojuego seteada como : " << game.getidVideojuego() << endl;
    arcV.grabarRegistros(game);
}


///FUNCIONES LISTAR POR : FILTRO

void menuFiltro()
{
int opcion = 1;
while(opcion != 0){

    system("CLS");
    setConsoleColor(9, 0);
    cout << "==========================================" << endl;
    cout << "  <<<  Menu para buscar videojuegos   <<<           " << endl;
    cout << "==========================================" << endl;
    cout << endl;  // Espacio para separación
    cout << "======== Seleccione una opcion:  =======" << endl;

    cout << endl;  // Espacio para separación
    cout << "----------------------------------------------------------" << endl;
    cout << "     1. Listar todos los videojuegos                                         " << endl;
    cout << "     2. Listar por genero                                                       " << endl;
    cout << "     3. Listar por creador                                                       " << endl;
    cout << "     4. Listar por precio                                                         " << endl;
    cout << "     5- Listar por anio          "<<endl;
    cout << "     6- Listar pot gratuito    "<<endl;
    setConsoleColor(4, 0);
    cout << "     0. ATRAS                                                                     " << endl;
    setConsoleColor(8, 0);
    cout << "-----------------------------------------------------------" << endl;
    cout << endl;
    cout << "======== Gracias por utilizar el sistema  ===========" << endl;
    cout << "=================================================" << endl;


    cin>> opcion;
    setConsoleColor(15, 0);
    switch (opcion)
    {
    case 1: elegirVideojuego(); break;
    case 2: listarPorGenero(); break;
    case 3: listarPorCreador();break;
    case 4: mostrarPorPrecio();break;
    case 5: listarPorAnio();break;
    default: cout<< "Opcion invalida."; break;
    }
  }
}

void listarPorAnio()  //función a arreglar
{
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    int tam = arcV.contarRegistros();
    int anio;
    int contGame = 0;
    int numJuego;
    int videoJuegos[150] = {0};
    system("CLS");
    cout<< "Ingrese el anio con el cual filtrar: "<<endl;
    cin>>anio;
    system("CLS");

    cout<<"------------------------------------------"<<endl;
    cout<<"Filtro aplicado: "<<anio<<endl;
    cout<<"------------------------------------------"<<endl;
    for (int i =0; i<tam ; i++ )
    {
        game = arcV.leerRegistros(i);

        if(game.getAnio() == anio)
        {
            cout<<game.getidVideojuego() << "-"<< game.getTitulo()<< "   -- precio: $ " << game.getPrecio()<<endl;
            contGame++;
            videoJuegos[i]+1;
        }
    }
    if(contGame== 0)
    {
        cout<<"NO HAY VIDEOJUEGOS CON ESE ANIO"<<endl;
        system("PAUSE");
    }
    else
    {

        setConsoleColor(4, 0);
        cout << "0 - ATRAS" << endl;
        setConsoleColor(8, 0);
        cout << "--------------------------------------------" << endl;
        cout << "INGRESE EL NUMERO DEL JUEGO DESEADO: " <<endl;
        cout << "--------------------------------------------" << endl;
        cin >> numJuego;

        for (int i = 0; i < tam; i++)
        {
            if (numJuego > 0 && videoJuegos[numJuego-1] == 1)
            {
                caracteristicasVideojuego(videoJuegos[i]);
                system("pause");
            }
        }
    }
}

void listarVideojuegos()
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
        if (game.getActivo())
        {
            setConsoleColor(15, 0);
            cout<< i+1 << " - " << game.getTitulo() << endl;
        }
        else
        {
            cout << "*JUEGO DESHABILITADO (COUT DE PRUEBA)" << endl;
        }
    }
}

void listarPorGenero() //nueva funcion xddd
{
    system("CLS");
    archivoVideoJuego arcV ("archivos/videojuego.dat");
    videoJuego game;
    char genero[30];
    cout<<"INGRESE EL GENERO QUE DESEA BUSCAR"<<endl;
    cargarCadena(genero, 29);
    int cantReg =arcV.contarRegistros();
    system("CLS");
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Filtro aplicado: "<< genero <<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for (int i = 0; i< cantReg ; i++ )
    {
    game = arcV.leerRegistros(i);
    if(strcmp(game.getGenero(), genero) == 0){ cout<< i+1<< " - "<< game.getTitulo()<< "    -- precio: $ " << game.getPrecio()<<endl;; }
    }
    system("PAUSE");
  }

void listarPorCreador()
{
    system("CLS");
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    int tam = arcV.contarRegistros();
    char desarrolladora[30];
    int contgame = 0;

    cout << "Ingrese la desarrolladora a buscar: ";
    cargarCadena(desarrolladora, 29);
    system("CLS");
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout << "Filtro aplicado: " << desarrolladora << endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;

    for (int i = 0; i < tam; i++) {
        game = arcV.leerRegistros(i);
        if (strcmp(game.getDesarrollador(), desarrolladora) == 0) {
            cout << i + 1 << " - " << game.getTitulo()<< "    -- precio: $ " << game.getPrecio()<<endl;;
            contgame++;
        }
    }
    system("PAUSE");
    if (contgame == 0) {
            setConsoleColor(4, 0);
        cout << "No hay juegos con esa desarrolladora :(" << endl;
    }
}

void mostrarPorPrecio ()
{
archivoVideoJuego arcV("archivos/videojuego.dat");
videoJuego game;
int tam = arcV.contarRegistros();
int montoMax = 0;
int montoMin= 0;
int contGame= 0;
system("CLS");
setConsoleColor(15, 0);
cout<<"Ingrese el monto maximo "<<endl;
cin>>montoMax;
cout<<"Ingrese el monto minimo "<<endl;
cin>>montoMin;
system("CLS");
cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
cout<<"El filtro aplicado es: " <<" desde : " <<montoMin<< "$"<<" hasta : "<< montoMax<< "$"<<endl;
cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
for (int i= 0;i< tam ; i++)
{
    game= arcV.leerRegistros(i);
    if ((montoMin<=game.getPrecio())&&(game.getPrecio()<= montoMax)){ cout<< i+1 <<"-"<< game.getTitulo() << "    -- precio: $ " << game.getPrecio()<<endl; contGame++;}
}
if(contGame== 0){system("CLS");setConsoleColor(4, 0);cout<< "No hay ningun juego con ese monto."<<endl;setConsoleColor(15, 0);}
system("PAUSE");
}
