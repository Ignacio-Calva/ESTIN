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

///FUNCIONES MENU

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
        cout<<"3 - Biblioteca"<<endl;
        cout<<"4 - Cuenta"<<endl;
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
        case 3:
            menuBiblioteca();
            break;
        case 4:
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

void menuBiblioteca()
{
    int opcion = 1;
    while (opcion!=0)
    {
        system("CLS");
        setConsoleColor(15, 1);
        cout<<"==============================" << endl;
        cout<<"      BIBLIOTECA ESTIM       "<<endl;
        cout<<"==============================" << endl;
        setConsoleColor(3,0);
        cout<<"ID de cuenta iniciada: " << idIniciada<<endl;
        cout<<"1 - Listar biblioteca personal"<<endl;
        cout<<"2 - Listar biblioteca por nombre"<<endl;
        cout<<"3 - Listar biblioteca por genero"<<endl;
        cout<<"4 - Listar biblioteca por desarrollador"<<endl;
        cout<<"5 - registro de compras"<<endl;

        cout<<"0 - cerrar"<<endl;
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
        int opcion;
        cout << "=======================================" << endl;
        cout << "        MENU DE ADMINISTRADOR          " << endl;
        cout << "=======================================" << endl;
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
            system("pause");
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
        cout << "=======================================" << endl;
        cout << "     MODIFICACION JUEGO: " << game.getTitulo() << endl;
        cout << "=======================================" << endl;
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
            cout<<"Ingrese el nuevo genero: ";
            cargarCadena(pal, 29);
            game = arcV.leerRegistros(idJuego-1);
            game.setGenero(pal);
            arcV.modificarVideojuego(game, idJuego-1);
            return true;
            break;
        case 3:
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
        cout << "(1) Videojuego mas vendido (SIN FILTROS)" << endl;
        cout << "(2) Videojuego mas vendido SEGUN GENERO" << endl;
        cout << "(3) Videojuego mas vendido SEGUN DESARROLLADOR" << endl;
        cout << "(4) Total vendido "<< endl;
        cout << "=======================================" << endl;
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
        system("cls");
        cout << "         INICIO DE SESION       " << endl;
        cout << "================================" << endl;
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
    }
}

/*Fecha compararFecha(Fecha fecha1, Fecha fecha2) ///DEVUELVE LA FECHA MAS CHICA
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
}*/


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
    cout<< "INGRESE EL ID DE SU PAIS: ";
    cin>> idPais;
    obj.setIDPais(idPais);
    cout << "ID actual: " << obj.getID();
    system("pause");
    cout<< "INGRESE SU PAIS (SOLO LATAM) : ";
    cargarCadena(pais,29);
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
                    return;
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
    system("cls");
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
            system("cls");
            cout << "Mostrando biblioteca ID: " << libro.getIdUsuario() << endl;
            cout << "Biblioteca del usuario ID: " << idIniciada << endl;
            libro.mostrar();
            cout << "Biblioteca del usuario ID: " << idIniciada << endl << endl;
            setConsoleColor(15,0);
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

    cout << endl << "0 - ATRAS" << endl;
    setConsoleColor(8, 0);
    cout << "-------------------------------------------------------------------" << endl;
    setConsoleColor(4, 0);
    cout << endl << "Ingrese el numero del juego deseado (0 Para cancelar): " << endl;
    cin >> numJuego;

    if (numJuego == 0)
    {
        return;
    }

    if (numJuego < 1 || numJuego > tam)
    {
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

    system("cls");

    char nombre [30];
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Ingrese el titulo que quiere buscar en su biblioteca: ";
    cargarCadena(nombre, 29);

    system("cls");

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

    system("cls");

    char genero [30];
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Ingrese el genero que quiere buscar en su biblioteca: ";
    cargarCadena(genero, 29);

    system("cls");

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

    system("cls");

    char desarrollador [30];
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Ingrese el desarrollador que quiere buscar en su biblioteca: ";
    cargarCadena(desarrollador, 29);

    system("cls");

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

    cout<<"<<------------------COMPRAS TOTALES DE VIDEOJUEGOS----------------------->>"<<endl;

    for (int j = 0; j<tam ; j++)
    {
        libro = arcB.leerBiblioteca(j);
        if(libro.getIdUsuario() == idIniciada)
        {
    cout<<"                            BIBLIOTECA CON ID: "<< libro.getIdUsuario()<<"                       "<<endl;
    cout<<"<<----------------------------------------------------------------------->>"<<endl;
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
                system("cls");
                cout<<"No tienes alguna tarjeta asociada."<<endl;
                cout<<"Desea aniadir una a su cuenta?"<<endl<<endl;
                cout<<"1 - Si"<<endl;
                cout<<"2 - No"<<endl;
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

    for (int i = 0; i < cantReg; i++)
    {
        game = arcV.leerRegistros(i);
        if (compararSinMayusculas(genero, game.getGenero()) && usu.getEdad() >= game.getRestriccion() && game.getActivo())
        {
            cout << tam + 1 << " - " << game.getTitulo() << "    -- precio: $ " << game.getPrecio() << endl;
            juegosListados[tam] = game.getidVideojuego();
            tam++;
        }
        else if (compararSinMayusculas(genero, game.getGenero()) && usu.getEdad() >= game.getRestriccion() && !game.getActivo())
        {
            cout << "*JUEGO DESHABILITADO" << endl;
        }
        else if (compararSinMayusculas(genero, game.getGenero()) && usu.getEdad() < game.getRestriccion() && game.getActivo())
        {
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

    for (int i = 0; i < tam; i++)
    {
        game = arcV.leerRegistros(i);
        if (compararSinMayusculas(desarrolladora, game.getDesarrollador()) && usu.getEdad() >= game.getRestriccion() && game.getActivo())
        {
            cout << tam2 + 1 << " - " << game.getTitulo() << "    -- precio: $ " << game.getPrecio() << endl;
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
        setConsoleColor(4, 0);
        cout << "No hay juegos con esa desarrolladora :(" << endl;
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
    cout << "La cuenta ha sido deshabilitada." << endl;
    system("pause");
}

void mostrarPorPrecio()
{
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;
    int tam = arcV.contarRegistros();
    float montoMax = 0;
    float montoMin = 0;
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

    for (int i = 0; i < tam; i++)
    {
        game = arcV.leerRegistros(i);
        if ((montoMin <= game.getPrecio()) && (game.getPrecio() <= montoMax) && game.getActivo() && usu.getEdad() >= game.getRestriccion())
        {
            cout << tam2 + 1 << " - " << game.getTitulo() << "    -- precio: $ " << game.getPrecio() << endl;
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
        system("CLS");
        setConsoleColor(4, 0);
        cout << "No hay ningun juego con ese monto." << endl;
        setConsoleColor(15, 0);
        system("PAUSE");

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
    cout << "Ingrese el anio con el cual filtrar: ";
    cin >> anio;
    system("CLS");

    usu = arcU.leerRegistros(datosUsuarioIniciado());
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Filtro aplicado: " << anio << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    for (int i = 0; i < tam; i++)
    {
        game = arcV.leerRegistros(i);
        if (game.getAnio() == anio && usu.getEdad() >= game.getRestriccion() && game.getActivo())
        {
            cout << tam2 + 1 << " - " << game.getTitulo() << "   -- Precio: $ " << game.getPrecio() << endl;
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
        cout << "NO HAY VIDEOJUEGOS CON ESE ANIO" << endl;
        system("PAUSE");
    }
    else
    {
        comprarJuegosListados(juegosListados, tam2);
    }
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

void elegirVideojuego()
{
    system("CLS");
    archivoVideoJuego arcV("archivos/videojuego.dat");
    videoJuego game;
    archivoUsuario arcU("archivos/Usuario.dat");
    usuario usu;

    int cantReg = arcV.contarRegistros();
    int juegosListados[150] = {};
    int tam = 0;

    system("CLS");
    usu = arcU.leerRegistros(datosUsuarioIniciado());

    for (int i = 0; i < cantReg; i++)
    {
        game = arcV.leerRegistros(i);
        if (usu.getEdad() >= game.getRestriccion() && game.getActivo())
        {
            cout << tam + 1 << " - " << game.getTitulo() << "    -- precio: $ " << game.getPrecio() << endl;
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
    setConsoleColor(14, 0);
    cout<< "BUSCADOR: ";
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

    system("CLS");

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
            ///FALTA AGREGARLE EL GET PAIS JAJASSS
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



void cargarPaises(){

archivoPais arcP("archivos/pais");
Pais obj;
int tam = arcP.contarRegistros();
for (int i= 0; i<150;i++ ){



}


}
