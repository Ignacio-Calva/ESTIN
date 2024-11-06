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
int designarBiblioteca(int idIniciada);
void aniadirTarjeta(int idIniciada);

<<<<<<< Updated upstream
=======
void comprarJuego();
void comprarJuegosListados(int juegosListados[], int tam);
Fecha compararFecha(Fecha fecha1, Fecha fecha2);
void listarOrdenAnio(archivoVideoJuego archivo);
void listarPorOrdenes();

void comprarJuego(int idVideojuego);
void agregarVideojuegoBiblioteca(int idVideojuego, int idIniciada);
void mostrarBibliotecaDeUsuario(int idIniciada);
void bibliotecaXnombre(int idIniciada);
void menuBiblioteca();
void bibliotecaXgenero(int idIniciada);
void bibliotecaXdesarrollador(int idIniciada);
void bibliotecaXanio(int idIniciada);
void registroCompras();
///ADMINISTRADOR
void juegosVendidos();
void listarVideojuegosAdmin();
void listarUsuariosAdmin();
void listarAdmins();
void menuAdministrador();
void modificarVideojuego();
bool menuModificarVideojuego(int idJuego);
void deshabilitarVideojuego();
void habilitarVideojuego();
void listarVideojuegosAdmin2();
void deshabilitarCuentaUsuario();
void habilitarCuentaUsuario();
void otorgarAdmin();
void removerAdmin();
void mostrarArchivoAdmin();
void grabarRegistroadmin(int idCuentaHabilitar);
void estadisticasJuegosMasComprados();
void menuVideojuegosMasVendidos();
void videojuegoMasVendidoGenero();
void videojuegoMasVendidoDesarrollador();
void listarPorGratuito();
void puntoRestauracion();
void crearPuntoRestauracion();
void cargarPuntoRestauracion();

bool hayUnAdmin();
>>>>>>> Stashed changes
#endif // FUNCIONES_H_INCLUDED
