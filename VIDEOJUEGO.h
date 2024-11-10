#ifndef PUNTOH_H_INCLUDED
#define PUNTOH_H_INCLUDED
#include "funciones.h"
#include "rlutil.h"

class videoJuego
{
private:
    int idVideojuego = 0;
    char titulo[30];
    char genero[30];
    float precio;
    float calificacion;
    char idioma[30];
    char desarrollador[30];
    int peso;
    int restriccionEdad;
    int anio;
    bool activo;

public:
    void cargar()
    {
        cout<<"Genero: ";
        cargarCadena(genero, 29);
        cout<<"Precio: ";
        cin>>precio;
        cout<<"Calificacion: ";
        cin>>calificacion;
        cout<<"Idioma: ";
        cargarCadena(idioma, 29);
        cout<<"Desarroladora: ";
        cargarCadena(desarrollador, 29);
        cout<<"Peso en GB: ";
        cin>>peso;
        cout<<"Restriccion de edad: ";
        cin>>restriccionEdad;
        cout<<"Anio de lanzamiento: ";
        cin>>anio;
        activo = true;
    }

    void mostrar()
    {
        rlutil::locate(55,5);
        cout<< "- " << titulo << " -" <<endl;
        rlutil::locate(44,6);
        cout<< "----------------------------------";
        rlutil::locate(45,7);
        cout<< ".Genero: " << genero <<endl;
        rlutil::locate(45,9);
        cout<< ".Precio: " << "$" <<precio <<endl;
        rlutil::locate(45,11);
        cout<< ".Calificacion: " << calificacion << "/100" <<endl;
        rlutil::locate(45,13);
        cout<< ".Idioma: " << idioma << endl;
        rlutil::locate(45,15);
        cout<< ".Desarrolladora: " << desarrollador <<endl;
        rlutil::locate(45,17);
        cout<< ".Almacenamiento requerido: " << peso << "GB" <<endl;
        rlutil::locate(45,19);
        cout<< ".Edad: " << "+" << restriccionEdad <<endl;
        rlutil::locate(45,21);
        cout<< ".Anio de lanzamiento: " << anio <<endl << endl;
        rlutil::locate(44,22);
        cout<< "----------------------------------";
    }

    void setTitulo(char* _titulo)
    {
        strcpy(titulo,_titulo);
    }
    void setGenero(char* _genero)
    {
        strcpy(genero,_genero);
    }
    void setPrecio(float _precio)
    {
        precio = _precio;
    }
    void setCalificacion(float _calificacion)
    {
        calificacion = _calificacion;
    }
    void setIdioma(char* _idioma)
    {
        strcpy(idioma,_idioma);
    }
    void setDesarrollador(char* _desarrollador)
    {
        strcpy(desarrollador,_desarrollador);
    }
    void setPeso(int _peso)
    {
        peso = _peso;
    }
    void setRestriccionEdad(int _restriccion)
    {
        restriccionEdad = _restriccion;
    }
    void setAnio(int _anio)
    {
        anio = _anio;
    }
    void setidVideojuego(int _idVideojuego)
    {
        idVideojuego = _idVideojuego;
    }
    void setActivo(bool _activo)
    {
        activo=_activo;
    }
    char* getTitulo()
    {
        return titulo;
    }
    char* getGenero()
    {
        return genero;
    }
    float getPrecio()
    {
        return precio;
    }
    float getCalificacion()
    {
        return calificacion;
    }
    char* getIdioma()
    {
        return idioma;
    }
    char* getDesarrollador()
    {
        return desarrollador;
    }
    int getPeso()
    {
        return peso;
    }
    int getRestriccion()
    {
        return restriccionEdad;
    }
    int getAnio()
    {
        return anio;
    }
    int getidVideojuego()
    {
        return idVideojuego;
    }
    bool getActivo()
    {
        return activo;
    }
};

class archivoVideoJuego
{
private:
    char nombre[30];
public:
    archivoVideoJuego(const char *n)
    {
        strcpy(nombre, n);
    }

    videoJuego leerRegistros(int pos)
    {
        videoJuego obj;
        FILE *P=fopen(nombre, "rb");
        if (P==NULL)
        {
            return obj;
        }
        fseek(P, pos * sizeof obj, 0);
        fread(&obj, sizeof obj, 1, P);
        fclose(P);
        return obj;
    }

    int contarRegistros()
    {
        FILE *P=fopen(nombre, "rb");
        if (P==NULL) return -1;

        fseek(P, 0, 2);
        int cant=ftell(P)/sizeof(videoJuego);
        fclose(P);
        return cant;
    }

    bool grabarRegistros(videoJuego obj)
    {
        FILE *P=fopen(nombre, "ab");
        if(P==NULL) return false;

        int info=fwrite(&obj, sizeof obj, 1, P);
        fclose(P);
        return info;
    }

    void borrarArchivo()
    {
        FILE *p = fopen(nombre, "wb");
        if (p == nullptr) return;
        fclose(p);
    }

    bool modificarVideojuego(videoJuego obj, int pos)
    {
        FILE *p=fopen(nombre,"rb+");
        if(p==NULL)
        {
            return false;
        }
        fseek(p, pos * sizeof obj, 0);
        fwrite(&obj, sizeof obj, 1, p);
        fclose(p);
        return true;
    }
};

#endif // PUNTOH_H_INCLUDED
