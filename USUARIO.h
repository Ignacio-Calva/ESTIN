#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include "funciones.h"


class usuario
{
private:
    char titulo[50];
    char genero[30];
    int precio;
    int calificacion;
    char modoDeJuego [30];
    char idioma[30];
    char desarrollador[30];
    int peso;
    int restriccionEdad;
public:

};

class biblioteca
{
private:
    int idVideojuego;
    int idTrofeo;
    float horasRegistradas;
public:
    void Cargar()
    {
        cout << "INGRESE ID DE VIDEOJUEGO: " ;
        cin >> idVideojuego ;
        cout << "INGRESE ID DE TROFEO: " ;
        cin >> idTrofeo ;
        horasRegistradas = 0;
        cout << "JUEGO CARGADO EN LA BIBLIOTECA CORRECTAMENTE. " << endl;
    }
    void Mostrar()
    {
        cout << "ID DE VIDEOJUEGO: " << idVideojuego << endl;
        cout << "ID DE TROFEO: " << idTrofeo << endl;
        cout << "HORAS REGISTRADAS: " << horasRegistradas<< endl;
    }
    void setIdVideojuego(int id)
    {
        idVideojuego = id;
    }
    void setIdTrofeo(int id)
    {
        idTrofeo = id;
    }
    void setHorasRegistradas(float horas)
    {
        horasRegistradas = horas;
    }
    int getIdVideojuego()
    {
        return idVideojuego;
    }
    int getIdTrofeo()
    {
        return idTrofeo;
    }
    float getHorasRegistradas()
    {
        return horasRegistradas;
    }
};

class trofeo
{
private:
    int idTrofeo;
    char nombre[31];
    char categoria[31];
public:
    void Cargar()
    {
        cout << "INGRESE LA ID DEL TROFEO: " ;
        cin >> idTrofeo;
        cout << "INGRESE EL NOMBRE DEL TROFEO: " ;
        cargarCadena(nombre,30);
        cout << "INGRESE LA CATEGORIA DEL TROFEO: " ;
        cargarCadena(categoria,30);
        cout << "TROFEO CARGADO EN JUEGO CORRECTAMENTE. " << endl;
    }
    void Mostrar()
    {
        cout << "ID DEL TROFEO: " << idTrofeo << endl;
        cout << "NOMBRE DEL TROFEO: " << nombre << endl;
        cout << "CATEGORIA: " << categoria << endl;
    }
    void setIdTrofeo(int id)
    {
        idTrofeo = id;
    }
    void setNombre(char* _nombre)
    {
        strcpy(nombre,_nombre);
    }
    void setCategoria(char* _cat)
    {
        strcpy(categoria,_cat);
    }
    int getIdTrofeo()
    {
        return idTrofeo;
    }
    char* getNombre()
    {
        return nombre;
    }
    char* getCategoria()
    {
        return categoria;
    }
};

#endif // USUARIO_H_INCLUDED
