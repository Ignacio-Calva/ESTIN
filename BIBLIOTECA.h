#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include "funciones.h"

class biblioteca
{
private:
    int ID_Usuario;
    int idVideojuego;
    int idTrofeo;
    int cantVideojuegos = 0;
    float horasRegistradas;
public:
    void Cargar()
    {
        cout << "INGRESE ID DE VIDEOJUEGO: " ;
        cin >> idVideojuego ;
        cout << "INGRESE ID DE TROFEO: " ;
        cin >> idTrofeo ;
        cout<< "INGRESE CANTIDAD DE VIDEOJUEGOS: ";
        cin>> cantVideojuegos;
        horasRegistradas = 0;
        cout << "JUEGO CARGADO EN LA BIBLIOTECA CORRECTAMENTE. " << endl;
    }
    void Mostrar()
    {
        cout << "ID DE VIDEOJUEGO: " << idVideojuego << endl;
        cout << "ID DE TROFEO: " << idTrofeo << endl;
        cout<< "VIDEOJUEGOS: " << cantVideojuegos << endl;
        cout << "HORAS REGISTRADAS: " << horasRegistradas<< endl;
    }
    void setIdVideojuego(int id){idVideojuego = id;}
    void setIdTrofeo(int id){idTrofeo = id;}
    void setHorasRegistradas(float horas){horasRegistradas = horas;}

    int getIdVideojuego(){return idVideojuego;}
    int getIdTrofeo(){return idTrofeo;}
    float getHorasRegistradas(){return horasRegistradas;}
};

class archivoBiblioteca{
    private:
        char nombre[50];
    public:
        archivoBiblioteca(const char* _nombre){strcpy(nombre,_nombre);}

        biblioteca leerBiblioteca(int pos)
        {
            biblioteca obj;
            FILE *p = fopen (nombre, "rb");
            if (p == nullptr){return obj;}
            fseek(p, pos * sizeof (biblioteca), 0);
            fread(&obj, sizeof (biblioteca), 1, p);
            fclose(p);
            return obj;
        }

        int contarRegistros(){
            FILE *P=fopen(nombre, "rb");
            if (P==NULL) return -1;
            fseek(P, 0, 2);
            int cant=ftell(P)/sizeof(biblioteca);
            fclose(P);
            return cant;
        }

        bool grabarRegistros(biblioteca obj)
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

#endif // BIBLIOTECA_H_INCLUDED
