#ifndef PUNTOH_H_INCLUDED
#define PUNTOH_H_INCLUDED
#include "funciones.h"

class videoJuego
{
private:
    int idVideojuego;
    char titulo[30];
    char genero[30];
    int precio;
    float calificacion;
    char idioma[30];
    char desarrollador[30];
    int peso;
    int restriccionEdad;
public:
    void cargar()
    {
        cargarCadena(titulo, 29);
        cargarCadena(genero, 29);
        cin>>precio;
        cin>>calificacion;
        cargarCadena(modoDeJuego, 29);
        cargarCadena(idioma, 29);
        cargarCadena(desarrollador, 29);
        cin>>peso;
        cin>>restriccionEdad;
    }

    void mostrar()
    {
        cout<< "- " << titulo << " -" <<endl;
        cout<< "Genero: " << genero <<endl;
        cout<< "Precio: " << "$" <<precio <<endl;
        cout<< "Calificacion: " << calificacion << "/100" <<endl;
        cout<< "Modo de juego: " << modoDeJuego <<endl;
        cout<< "Idioma: " << idioma << endl;
        cout<< "Desarrolladora: " << desarrollador <<endl;
        cout<< "Almacenamiento requerido: " << peso << "GB" <<endl;
        cout<< "Edad: " << "+" << restriccionEdad <<endl << endl;
    }

    void setTitulo(string _titulo){strcpy(titulo,_titulo);}
    void setGenero(string _genero){strcpy(genero,_genero);}
    void setPrecio(int _precio){precio = _precio;}
    void setCalificacion(float _calificacion){calificacion = _calificacion;}
    void setIdioma(string _idioma){strcpy(idioma,_idioma);}
    void setDesarrollador(string _desarrollador){strcpy(desarrollador,_desarrollador);}
    void setPeso(int _peso){peso = _peso;}
    void setRestriccionEdad(int _restriccion){restriccionEdad = _restriccion;}
    string getTitulo(){return titulo;}
};

class archivoVideoJuego
{
private:
    char nombre[30];
public:
    archivoVideoJuego(const char *n){strcpy(nombre, n);}

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
};

#endif // PUNTOH_H_INCLUDED
