#include <iostream>
using namespace std;
#include <cstring>
#include "funciones.h"
#include "VIDEOJUEGO.h"
#include "BIBLIOTECA.h"
#include "USUARIO.h"
#include <windows.h>

int idIniciada;

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

    usu = arcU.leerRegistros(datosUsuarioIniciado());

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
    int eleccion;
    while (true){
        system("cls");
        cout << "         INICIO DE SESION       " << endl;
        cout << "================================" << endl;
        cout << "1- Iniciar sesion como Usuario" << endl;
        cout << "2- Iniciar sesion como Admin" << endl;
        cout << "0- Volver" << endl;
        cout << "================================" << endl<<endl;
        cout << "Elija una opcion: ";
        cin >> eleccion;
        switch(eleccion){
            case 1:
                {
                    archivoUsuario arcU("archivos/Usuario.dat");
                    usuario usu;

                    char nombre[30];
                    char contrasenia[20];
                    system("cls");
                    cout << "INICIO DE SESION COMO USUARIO" << endl;
                    cout << "=============================" << endl << endl;
                    cout<<"Ingrese su nombre de usuario: " ;
                    cargarCadena(nombre, 29);

                    int pos=0; ///USADA POR REFERENCIA PARA GUARDAR DONDE FUE ENCONTRADO EL NOMBRE EN LA FUNCION buscarNombre()
                    if (buscarNombre(nombre, pos))
                    {
                        usu = arcU.leerRegistros(pos);
                        cout << "Usuario encontrado." << endl;
                        cout << "Ingrese su contrasenia: " ;
                        cargarCadena(contrasenia, 19);
                        if (strcmp(usu.getContrasenia(),contrasenia) == 0)
                        {
                            idIniciada = usu.getID(); //asignar ID iniciada
                            cout << "Sesion iniciada correctamente!" << endl;
                            system("pause");
                            system("cls");
                            menuPrincipal();
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
            case 2:
                ///inicioSesionAdmin(); <---- desarrollar xd jaja xd
                cargarVideojuego();
                system("pause");
                return;
            case 0:
                return;
            default:
                cout << "Por favor, ingrese una opcion valida." << endl;
                system("pause");
                break;
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
                   if (usu.getActivo() == false){setConsoleColor(4, 0);cout << "-----------CUENTA DESHABILITADA-----------" << endl;}
                   cout << endl; setConsoleColor(15, 0);
                   cout<<"1 - Deshabilitar cuenta"<<endl;
                   cout<<"0 - Salir"<<endl;
                   cin>>opcion;
                   switch (opcion)
                   {
                   case 1:
                       bajaUsuario(idIniciada);
                       break;
                   case 0: break;
                   default: system("CLS");setConsoleColor(4, 0); cout<<"Opcion invalida" <<endl;
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
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Filtro aplicado: "<< genero <<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for (int i = 0; i< cantReg ; i++ )
    {
    game = arcV.leerRegistros(i);
    if(strcmp(game.getGenero(), genero) == 0){ cout<< i+1<< " - "<< game.getTitulo() <<endl; }
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
            cout << i + 1 << " - " << game.getTitulo() << endl;
            contgame++;
        }
    }
    system("PAUSE");
    if (contgame == 0) {
            setConsoleColor(4, 0);
        cout << "No hay juegos con esa desarrolladora :(" << endl;
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
    if (montoMin<=game.getPrecio() <= montoMax){ cout<< i+1 <<"-"<< game.getTitulo()<<endl; contGame++;}
}
if(contGame== 0){system("CLS");setConsoleColor(4, 0);cout<< "No hay ningun juego con ese monto."<<endl;setConsoleColor(15, 0);}
system("PAUSE");
}

void listarPorAnio()
{
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    int tam = arcV.contarRegistros();
    int anio;
    int contGame = 0;
    cout<< "Ingrese el anio con el cual filtrar: "<<endl;
    cin>>anio;
    system("CLS");
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Filtro aplicado: "<<anio<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for (int i =0; i<tam ; i++ )
    {
        game = arcV.leerRegistros(i);

        if(game.getAnio() == anio)
        {
            cout<<i+1 << "-"<< game.getTitulo()<<endl;
            contGame++;
        }
    }
    if (contGame == 0)
    {
        setConsoleColor(4, 0);
        cout<< "No existen juegos con ese anio" << endl; setConsoleColor(15, 0);
    }
    system("PAUSE");
}

///FUNCIONES PARA DAR DE BAJA UN USUARIO
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


void designarBiblioteca(int idIniciada)
{
    archivoBiblioteca arcB("archivos/biblioteca.dat");
    Biblioteca libro;

    archivoUsuario arcU("archivos/usuarios.dat");
    usuario usu;
    int pos = buscarUsuarioPorID(idIniciada);
    int tam = arcB.contarRegistros();
    int cantReg = arcU.contarRegistros();


    for (int i =0;i< cantReg;i++ ){

        libro = arcB.leerBiblioteca(i);

        if((usu.getActivo()== true) && (i == pos)){libro.setIdBiblioteca(usu.getID());}
    }

    arcB.grabarRegistros(libro);
}

//lol
