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
        cout<<endl<<"Ingrese el numero del juego deseado (0 Para cancelar): "<< endl;
        setConsoleColor(4, 0);
        cin>>numJuego;
        if(numJuego >= 0)
        {
            if (numJuego == 0 )
            {
                break;
            }
            else if (numJuego > tam)
            {
                cout << "Numero de juego no encontrado."<<endl;
                system("pause");
                break;
            }
        }
        caracteristicasVideojuego(numJuego);
        comprarJuego(numJuego);
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
            }else
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
        if (compararSinMayusculas(n, game.getTitulo()))
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
    bool existe = false;
    obj.cargarDatos();
    int tam=archivo.contarRegistros();
    if (tam > 0)
    {
        objAux = archivo.leerRegistros(tam-1); //CARGA LOS DATOS DEL ULTIMO REGISTRO
        obj.setID(objAux.getID()+1); //AUTOMATICAMENTE ASIGNA COMO ID EL NUMERO SIGUIENTE
    } else {obj.setID(1);}
    if (tam > 0)
    {
        for (int i = 0 ; i < tam ; i++)
        {
            objAux = archivo.leerRegistros(i);
            if (strcmp(obj.getNombre(),objAux.getNombre())==0)
            {
                existe = true;
                break;
            }
            else
            {
                existe = false;
            }
        }
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

void inicioSesion()
{
    while (true)
    {
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
        cout << cuentaAdmin.getNombre() << " " << cuentaAdmin.getContrasenia() << endl<<endl;
        cout << "BORRAR ESTAS LINEAS CUANDO EL PROGRAMA ESTE TERMINADO." << endl;
        cout<<"Ingrese su nombre de usuario: " ;
        cargarCadena(nombre, 29);

        int pos=0; ///USADA POR REFERENCIA PARA GUARDAR DONDE FUE ENCONTRADO EL NOMBRE EN LA FUNCION buscarNombre()



        ///LOGUEO ADMIN MAIN
        if(strcmp(cuentaAdmin.getNombre(),nombre) == 0)
        {
            if (hayUnAdmin()==true)
            {
                cout << "La cuenta de administrador principal se encuentra deshabilitada." << endl;
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
                break;
            }
            else
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
                if (usu.getActivo() == false && usu.getAdmin()==false)
                {
                    cout << "Esta cuenta esta deshabilitada"<< endl;
                    system("pause");
                    return;
                }
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
                        menuAdministrador();
                        break;
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

void menuPrincipal()
{
    int opcion = 1;
    while (opcion!=0)
    {
        system("CLS");
        setConsoleColor(15, 1);
        cout<<"==============================" << endl;
        cout<<"            ESTIM             "<<endl;
        cout<<"==============================" << endl;
        setConsoleColor(3,0);
        cout<<"ID de cuenta iniciada: " << idIniciada<<endl;
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
            menuFiltro();
            break;
        case 2:
            buscarVideojuego();
            break;
        case 4:
            menuBiblioteca();
            break;
        case 5:
            infoCuenta();
            break; //AGREGO LA FUNCION AL MENU
        case 0:
            break;
        default:
            cout<< "Opcion invalida.";
            break;
        }
    }
}


void menuBiblioteca(){
    int opcion = 1;
    while (opcion!=0)
    {
        system("CLS");
        setConsoleColor(15, 1);
        cout<<"==============================" << endl;
        cout<<" BIBLIOTECA ESTIM             "<<endl;
        cout<<"==============================" << endl;
        setConsoleColor(3,0);
        cout<<"ID de cuenta iniciada: " << idIniciada<<endl;
        cout<<"1 - Biblioteca personal"<<endl;
        cout<<"2 - Listar biblioteca por nombre"<<endl;
        cout<<"3 - Listar biblioteca por genero"<<endl;
        cout<<"0 - cerrar"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            mostrarBibliotecaDeUsuario(idIniciada);
            break;
        case 2:
            bibliotecaXfiltros(idIniciada);
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
        cout << "     6- Listar por gratuito    "<<endl;
        cout << "     7- comprar Videojuego    "<<endl;
        cout << "     8- Listar por ordenes     " << endl;
        setConsoleColor(4, 0);
        cout << "     0. ATRAS                                                                     " << endl;
        setConsoleColor(8, 0);
        cout << "-----------------------------------------------------------" << endl;
        cout << endl;
        cout << "======== Gracias por utilizar el sistema  ===========" << endl;
        cout << "=====================================================" << endl;
        setConsoleColor(15, 0);
        cout << "Ingrese la opcion deseada: ";
        cin>> opcion;
        setConsoleColor(15, 0);
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
        case 7:
            comprarJuego(idIniciada);
            break;
        case 8:
            listarPorOrdenes();
            break;
        default:
            cout<< "Opcion invalida.";
            break;
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
            while (opcion != 0)
            {
                system("CLS");
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
                cin>>opcion;
                switch (opcion)
                {
                case 1:
                    bajaUsuario(idIniciada);
                    break;
                case 2:
                    aniadirTarjeta(idIniciada);
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

void listarPorGenero()
{
    system("CLS");
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;
    char genero[30];
    cout << "INGRESE EL GENERO QUE DESEA BUSCAR" << endl;
    cargarCadena(genero, 29);
    int cantReg = arcV.contarRegistros();
    int juegosListados[150] = {};
    int tam = 0;

    system("CLS");
    usu = arcU.leerRegistros(datosUsuarioIniciado());
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Filtro aplicado: " << genero << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    for (int i = 0; i < cantReg; i++) {
        game = arcV.leerRegistros(i);
        if (compararSinMayusculas(genero, game.getGenero()) && usu.getEdad() >= game.getRestriccion() && game.getActivo()) {
            cout << tam + 1 << " - " << game.getTitulo() << "    -- precio: $ " << game.getPrecio() << endl;
            juegosListados[tam] = game.getidVideojuego();
            tam++;
        } else if (compararSinMayusculas(genero, game.getGenero()) && usu.getEdad() >= game.getRestriccion() && !game.getActivo()) {
            cout << "*JUEGO DESHABILITADO" << endl;
        } else if (compararSinMayusculas(genero, game.getGenero()) && usu.getEdad() < game.getRestriccion() && game.getActivo()) {
            cout << "No tienes edad suficiente para este videojuego" << endl;
        }
    }
    comprarJuegosListados(juegosListados, tam);
}

void listarPorCreador()
{
    system("CLS");
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;
    int tam = arcV.contarRegistros();
    char desarrolladora[30];
    int contgame = 0;
    int juegosListados[150] = {};
    int tam2 = 0;

    cout << "Ingrese la desarrolladora a buscar: ";
    cargarCadena(desarrolladora, 29);
    system("CLS");
    usu = arcU.leerRegistros(datosUsuarioIniciado());
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Filtro aplicado: " << desarrolladora << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    for (int i = 0; i < tam; i++) {
        game = arcV.leerRegistros(i);
        if (compararSinMayusculas(desarrolladora, game.getDesarrollador()) && usu.getEdad() >= game.getRestriccion() && game.getActivo()) {
            cout << tam2 + 1 << " - " << game.getTitulo() << "    -- precio: $ " << game.getPrecio() << endl;
            juegosListados[tam2] = game.getidVideojuego();
            tam2++;
            contgame++;
        } else if (compararSinMayusculas(desarrolladora, game.getDesarrollador()) && usu.getEdad() >= game.getRestriccion() && !game.getActivo()) {
            cout << "*JUEGO DESHABILITADO" << endl;
            contgame++;
        } else if (compararSinMayusculas(desarrolladora, game.getDesarrollador()) && usu.getEdad() < game.getRestriccion() && game.getActivo()) {
            cout << "No tienes edad suficiente para este videojuego" << endl;
            contgame++;
        }
    }

    if (contgame == 0) {
        setConsoleColor(4, 0);
        cout << "No hay juegos con esa desarrolladora :(" << endl;
    } else {
        comprarJuegosListados(juegosListados, tam2);
    }
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

void mostrarPorPrecio()
{
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;
    int tam = arcV.contarRegistros();
    int montoMax = 0;
    int montoMin = 0;
    int contGame = 0;
    int juegosListados[150] = {};
    int tam2 = 0;

    system("CLS");
    setConsoleColor(15, 0);
    cout << "Ingrese el monto maximo: ";
    cin >> montoMax;
    cout << "Ingrese el monto minimo: ";
    cin >> montoMin;
    system("CLS");

    usu = arcU.leerRegistros(datosUsuarioIniciado());
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "El filtro aplicado es: desde $" << montoMin << " hasta $" << montoMax << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < tam; i++) {
        game = arcV.leerRegistros(i);
        if ((montoMin <= game.getPrecio()) && (game.getPrecio() <= montoMax) && game.getActivo() && usu.getEdad() >= game.getRestriccion()) {
            cout << tam2 + 1 << " - " << game.getTitulo() << "    -- precio: $ " << game.getPrecio() << endl;
            juegosListados[tam2] = game.getidVideojuego();
            tam2++;
            contGame++;
        } else if ((montoMin <= game.getPrecio()) && (game.getPrecio() <= montoMax) && !game.getActivo() && usu.getEdad() >= game.getRestriccion()) {
            cout << "*JUEGO DESHABILITADO" << endl;
            contGame++;
        } else if ((montoMin <= game.getPrecio()) && (game.getPrecio() <= montoMax) && game.getActivo() && usu.getEdad() < game.getRestriccion()) {
            cout << "No tienes edad suficiente para este videojuego" << endl;
            contGame++;
        }
    }

    if (contGame == 0) {
        system("CLS");
        setConsoleColor(4, 0);
        cout << "No hay ningun juego con ese monto." << endl;
        setConsoleColor(15, 0);
    } else {
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
    cout << "Ingrese el anio con el cual filtrar: ";
    cin >> anio;
    system("CLS");

    usu = arcU.leerRegistros(datosUsuarioIniciado());
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Filtro aplicado: " << anio << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    for (int i = 0; i < tam; i++) {
        game = arcV.leerRegistros(i);
        if (game.getAnio() == anio && usu.getEdad() >= game.getRestriccion() && game.getActivo()) {
            cout << tam2 + 1 << " - " << game.getTitulo() << "   -- Precio: $ " << game.getPrecio() << endl;
            juegosListados[tam2] = game.getidVideojuego();
            tam2++;
            contGame++;
        } else if (game.getAnio() == anio && usu.getEdad() >= game.getRestriccion() && !game.getActivo()) {
            cout << "*JUEGO DESHABILITADO" << endl;
            contGame++;
        } else if (game.getAnio() == anio && usu.getEdad() < game.getRestriccion() && game.getActivo()) {
            cout << "No tienes edad suficiente para este videojuego" << endl;
            contGame++;
        }
    }

    if (contGame == 0) {
        cout << "NO HAY VIDEOJUEGOS CON ESE ANIO" << endl;
        system("PAUSE");
    } else {
        comprarJuegosListados(juegosListados, tam2);
    }
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

void bajaUsuario(int idIniciada)
{
    usuario obj;
    archivoUsuario arcU("archivos/Usuario.dat");
    int pos = buscarUsuarioPorID(idIniciada);
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
    cout << "La cuenta ha sido deshabilitada." << endl;
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

int designarBiblioteca(int idUsuario)
{
    archivoBiblioteca arcB("archivos/biblioteca.dat");
    Biblioteca libro;
    archivoUsuario arcU("archivos/usuario.dat");
    usuario usu;
    int pos = buscarUsuarioPorID(idUsuario);
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

void menuAdministrador()
{
    while (true)
    {
        system("cls");
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
        cout << "(8) Listar admins registrados" << endl;
        cout << "(9) videojuegos mas vendidos" << endl;
        cout << "(0) Cerrar Sesion" << endl;
        cout << "=======================================" << endl;
        cout << endl << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cargarVideojuego();
            system("pause");
            break;
        case 2:
            deshabilitarVideojuego();//(Lo deshabilita)
            break;
        case 3:
            habilitarVideojuego();
            break;
        case 4:
            habilitarCuentaUsuario();
            break;
        case 5:
            deshabilitarCuentaUsuario();
            break;
        case 6:
            otorgarAdmin();
            break;
        case 7:
            removerAdmin();
            break;
        case 8:
            mostrarArchivoAdmin();
            break;
        case 9:
            estadisticasJuegosMasComprados();
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
                    cout << "El usuario ha sido deshabilitado correctamente." << endl;
                    system("pause");
                    system("cls");
                } else
                {
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
                } else if (usu.getActivo()==false)
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
                cout << "Se ha removido el rango correctamente. (Archivo Usuario)" << endl;
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

void comprarJuego(int idVideojuego)
{
    int opcion;
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    usuario usu;
    archivoUsuario arcU("archivos/Usuario.dat");
    archivoBiblioteca arcB("archivos/biblioteca.dat");
    Biblioteca bib;

    while (opcion != 0)
    {
        int opcion2 = 1;
        setConsoleColor(4,0);
        cout<<"1 - Comprar"<<endl;
        cout<<"0 - Salir"<<endl;
        cout<<"-----------"<<endl;
        setConsoleColor(15,0);
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
                        setConsoleColor(4,0);
                        cout << "Ya tienes el juego en tu biblioteca. " << endl;
                        setConsoleColor(15,0);
                        return;
                    }
                }
                agregarVideojuegoBiblioteca(idVideojuego,idIniciada);
                return;
            }
            else if (usu.getTarjet() == 0)
            {
                cout<<"No tienes alguna tarjeta asociada."<<endl;
                cout<<"Desea aniadir una a su cuenta?"<<endl<<endl;
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
            return;
        case 0:
            break;
        }
    }
}

Fecha compararFecha(Fecha fecha1, Fecha fecha2) ///DEVUELVE LA FECHA MAS CHICA
{
    if(fecha1.getAnio() < fecha2.getAnio())
    {
        return fecha1;
    }
    else if(fecha2.getAnio() < fecha1.getAnio())
    {
        return fecha2;
    }
    else  //LOS DOS AÑOS SON IGUALES
    {
        if (fecha1.getMes() < fecha2.getMes())
        {
            return fecha1;
        }
        else if (fecha2.getMes() < fecha1.getMes())
        {
            return fecha2;
        }
        else //LOS DOS MESES SON IGUALES
        {
            if (fecha1.getDia() < fecha2.getDia())
            {
                return fecha1;
            }
            else if(fecha2.getDia() < fecha1.getDia())
            {
                return fecha2;
            }
            else
            {
                return fecha1;   //LAS DOS FECHAS SON IGUALES, RETORNA LA PRIMERA
            }
        }
    }
}

void agregarVideojuegoBiblioteca(int idVideojuego, int idIniciada)
{
    archivoBiblioteca arcB ("archivos/biblioteca.dat");
    Biblioteca libro;
    Fecha compra;
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

    int tam = arcB.contarRegistros();
    cout << "TAMANIO DEL ARCHIVO DE BIBLIOTECA: " << tam << endl;
    system("Pause");
    for (int i = 0; i<tam ; i++ )
    {
        libro = arcB.leerBiblioteca(i);
        if(idIniciada == libro.getIdUsuario())
        {
            system("cls");
            cout << "Mostrando biblioteca ID: " << libro.getIdUsuario() << endl;
            cout << "Biblioteca del usuario ID: " << idIniciada << endl;
            libro.mostrar();
            system("PAUSE");
            return;
        }
    }
   cout << "Error al cargar biblioteca." << endl;system("pause");return;
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

void listarPorOrdenes()
{
    int opcion = 1;
    archivoVideoJuego archivoTienda("archivos/videoJuego.dat");
    while (opcion!=0)
    {
        system("cls");
        cout << "===================================" << endl;
        cout << "   SELECCIONE EL FILTRO DESEADO"     << endl;
        cout << "===================================" << endl;
        cout << " (1) - Listar por anio"              << endl;
        cout << " (2) - Desarrollar"                  << endl;
        cout << " (3) - Desarrollar"                  << endl;
        cout << " (4) - Desarrollar"                  << endl;
        cout << " (0) - SALIR"                        << endl;
        cout << "===================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            listarOrdenAnio(archivoTienda);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Por favor, elija una opcion valida" << endl;
            system("pause");
            break;
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
    for (int i = 0;i<tam ;i++ )
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
    for (int i = 0;i<tam ; i++)
    {
        usu = arcU.leerRegistros(i);
        if(usu.getID() == idCuentaHabilitar)
        {
            adm.setIdAdmin(idCuentaHabilitar);
            adm.setNombre(usu.getNombre());
            adm.setDNI(usu.getDNI());
            adm.setEdad(usu.getEdad());
            adm.setIDPais(usu.getIDPais());
            adm.setMail(usu.getMail());
            adm.setAdmin(true);
            cout << endl << "TEXTOS PARA VERIFICAR QUE TODO FUNCIONE CORRECTAMENTE XD" << endl  << "Datos a grabar:" << endl;
            adm.mostrarDatos();
            if (arcA.grabarRegistros(adm)){cout << "CUENTA REGISTRADA EN ARCHIVO DE ADMINISTRADORES"<<endl;} //El metodo de grabar registros retorna bool
        }
    }
}

void comprarJuegosListados(int juegosListados[], int tam)
{
    archivoVideoJuego arcV("archivos/videoJuego.dat");
    int numJuego;

    cout << endl << "0 - ATRAS" << endl;
    setConsoleColor(8, 0);
    cout << "-------------------------------------------------------------------" << endl;
    setConsoleColor(4, 0);
    cout << endl << "Ingrese el numero del juego deseado (0 Para cancelar): " << endl;
    cin >> numJuego;

    if (numJuego == 0) {
        return;
    }

    if (numJuego < 1 || numJuego > tam) {
        cout << "Numero de juego no encontrado." << endl;
        system("pause");
        return;
    }

    int idJuegoSeleccionado = juegosListados[numJuego - 1];
    caracteristicasVideojuego(idJuegoSeleccionado);
    comprarJuego(idJuegoSeleccionado);
    system("PAUSE");
}

void estadisticasJuegosMasComprados(){
archivoVideoJuego arcV("archivos/videoJuego.dat");
videoJuego game;
archivoBiblioteca arcB ("archivos/biblioteca.dat");
Biblioteca libro;

int juegosMasComprados[150]={};
int tam = arcB.contarRegistros();
int maxi =0;
for (int l =0 ;l<tam ; l++ ){
    libro = arcB.leerBiblioteca(l);
    for (int j=0;j<150 ; j++ ){
        if (libro.getIdVideojuego(j) != 0){
            juegosMasComprados[j]++;
        }
    }
}
int pos=0;

for (int i=0;i<150 ;i++ ){

if (juegosMasComprados[i]> maxi){

    maxi = juegosMasComprados[i];
    pos= i;
}
}

int cantreg= arcV.contarRegistros();
for (int i = 0; i<cantreg ;i++ ){
        game = arcV.leerRegistros(i);
    if (  pos+1 == game.getidVideojuego()){

        cout<<"el juego mas comprado es-----> "<< game.getTitulo() << " con un precio de : "<< game.getPrecio() << "$ <-- con un total de: "<<juegosMasComprados[pos] << " compras"<<endl;

system("PAUSE");
return;
}
}
}


void bibliotecaXfiltros(int idIniciada){

archivoBiblioteca arcB("archivos/biblioteca.dat");
Biblioteca libro;

archivoVideoJuego arcV ("archivos/videojuego.dat");
videoJuego game;

int cantReg = arcV.contarRegistros();
int tam = arcB.contarRegistros();

char nombre [30];
cout<<"-----------------------------------------"<<endl;
cout<<" Ingrese el titulo que quiere buscar en su biblioteca : ---->"<<endl;
cargarCadena(nombre, 29);

    for (int j = 0; j<tam ; j++)
    {   libro = arcB.leerBiblioteca(j);
        if(libro.getIdUsuario() == idIniciada){
            cout<<"BIBLIOTECA CON ID : "<< libro.getIdUsuario()<<endl;
            cout<<"Juegos obtenidos con el titulo : "<< nombre <<endl;
            cout<<"-------------------------------------------"<<endl;

           for (int i = 0; i < cantReg; i++)
            {   game = arcV.leerRegistros(i);
                if (compararSinMayusculas(nombre, game.getTitulo())){
                for (int l = 0; l<150 ; l++)
                    {   if(game.getidVideojuego()== libro.getIdVideojuego(l)){
                        setConsoleColor(15, 0);
                        cout<< game.getidVideojuego()<< "---> " << game.getTitulo()<<"$ "<< game.getPrecio() <<endl;
                        setConsoleColor(8, 0);
                        system("PAUSE");
                        }
                    }
                }
            }
        }
    }
}
