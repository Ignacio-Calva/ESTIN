#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <cstring>
using namespace std;

///COLORES
void setConsoleColor(int textColor, int backgroundColor);

///FUNCIONES COMUNES
void elegirVideojuego();
void buscarVideojuego();
void mostrarTitulo(const string &titulo);
void listarVideojuegos();
void caracteristicasVideojuego(int j);
void buscarPorNombre(const char *n);
void cargarCadena(char *pal, int tam);
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
void designarBiblioteca(int idIniciada);
void aniadirTarjeta(int idIniciada);

#endif // FUNCIONES_H_INCLUDED
