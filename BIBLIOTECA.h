#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include "funciones.h"
#include "FECHA.h"

class Biblioteca{
    private:
        int idUsuario;
        int idVideojuego[150]={};
        Fecha fechaCompra[150];
    public:
        void mostrar()
        {
            for (int i = 0; i < 150; i++)
            {
                if (idVideojuego[i]>0)
                {

                    cout<< "ID videojuego: " << idVideojuego[i] << " --- comprado el: "; fechaCompra[i].mostrar();
                    cout<< "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                }
            }
            cout<<endl;
        }

        void setIdUsuario(int _mas){idUsuario = _mas;}
        void setIdVideojuego(int pos, int _id){idVideojuego[pos] = _id;}
        void setFechaCompra(Fecha _fechaCompra, int pos){fechaCompra[pos] = _fechaCompra;}
        int getIdUsuario(){return idUsuario;}
        int getIdVideojuego(int pos){return idVideojuego[pos];}
        Fecha getFechaCompra(int pos){return fechaCompra[pos];}
};

class archivoBiblioteca{
    private:
        char nombre[50];
    public:
        archivoBiblioteca(const char* _nombre){strcpy(nombre,_nombre);}

        Biblioteca leerBiblioteca(int pos)
        {
            Biblioteca obj;
            FILE *p = fopen (nombre, "rb");
            if (p == nullptr){return obj;}
            fseek(p, pos * sizeof (Biblioteca), 0);
            fread(&obj, sizeof (Biblioteca), 1, p);
            fclose(p);
            return obj;
        }

        int contarRegistros(){
            FILE *P=fopen(nombre, "rb");
            if (P==NULL) return -1;
            fseek(P, 0, 2);
            int cant=ftell(P)/sizeof(Biblioteca);
            fclose(P);
            return cant;
        }

        bool grabarRegistros(Biblioteca obj)
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

        bool modificarBiblioteca (int pos, Biblioteca obj)
        {
            FILE *p = fopen(nombre, "rb+");
            if (p==NULL) return false;
            fseek(p, pos * sizeof obj, 0);
            fwrite(&obj, sizeof obj, 1, p);
            fclose(p);
            return true;

        }


};

#endif // BIBLIOTECA_H_INCLUDED
