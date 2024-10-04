#ifndef PUNTOH_H_INCLUDED
#define PUNTOH_H_INCLUDED
#include "funciones.h"




class videoJuego
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
    void cargar()
    {
        cargarCadena(titulo, 49);
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
        cout<< "PRECIO (SOL PERUANO): " << "$" <<precio <<endl;
        cout<< "Calificacion: " << calificacion << "/100" <<endl;
        cout<< "Modo de juego: " << modoDeJuego <<endl;
        cout<< "Idioma: " << idioma << endl;
        cout<< "Desarrolladora: " << desarrollador <<endl;
        cout<< "Almacenamiento requerido: " << peso << "GB" <<endl;
        cout<< "Edad: " << "+" << restriccionEdad <<endl << endl;
    }

    string getTitulo(){return titulo;}


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
};


class usuario
{

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
        void setIdVideojuego(int id){idVideojuego = id;}
        void setIdTrofeo(int id){idTrofeo = id;}
        void setHorasRegistradas(float horas){horasRegistradas = horas;}
        int getIdVideojuego(){return idVideojuego;}
        int getIdTrofeo(){return idTrofeo;}
        float getHorasRegistradas(){return horasRegistradas;}
};

class trofeo{
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
        void setIdTrofeo(int id){idTrofeo = id;}
        void setNombre(char* _nombre){strcpy(nombre,_nombre);}
        void setCategoria(char* _cat){strcpy(categoria,_cat);}
        int getIdTrofeo(){return idTrofeo;}
        char* getNombre(){return nombre;}
        char* getCategoria(){return categoria;}
};

#endif // PUNTOH_H_INCLUDED
