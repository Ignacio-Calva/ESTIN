#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <cstring>
using namespace std;
void cargarCadena(char *pal, int tam);

#include "FECHA.h"
#include "VIDEOJUEGO.h"
///COLORES
void setConsoleColor(int textColor, int backgroundColor);

///FUNCIONES COMUNES
void elegirVideojuego();
void buscarVideojuego();
void mostrarTitulo(const string &titulo);
void listarVideojuegos();
void caracteristicasVideojuego(int j);
void buscarPorNombre(const char *n);
///MOVI LA FUNCION DE CARGAR CADENA PORQUE DABA PROBLEMAS
bool compararSinMayusculas(const char* texto1, const char* texto2);
void grabarRegistroUsuario();
void inicioSesion();
void menuPrincipal();
void listarPorGenero();
void menuFiltro();
void infoCuenta(); //nueva funcion
void listarPorCreador();
void listarPorAnio();
bool buscarNombre(const char* _nombre, int &posicion);
int datosUsuarioIniciado();
void mostrarPorPrecio();
void bajaUsuario(int idIniciada);
void bajaUsuario(int idIniciada);
void cargarVideojuego();
int designarBiblioteca(int idIniciada);
void aniadirTarjeta(int idIniciada);

void comprarJuego();
Fecha compararFecha(Fecha fecha1, Fecha fecha2);
void listarOrdenAnio(archivoVideoJuego archivo);
void listarPorOrdenes();

void comprarJuego(int idVideojuego);
void agregarVideojuegoBiblioteca(int idVideojuego, int idIniciada);
void mostrarBibliotecaDeUsuario(int idIniciada);

///ADMINISTRADOR
void listarVideojuegosAdmin();
void menuAdministrador();
void deshabilitarVideojuego();
void habilitarVideojuego();



#endif // FUNCIONES_H_INCLUDED
