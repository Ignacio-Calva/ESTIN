#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include "funciones.h"
#include "FECHA.h"

//class biblioteca
//{
//private:
//    int ID_Usuario;
//    int idVideojuego;
//    int idTrofeo;
//    int cantVideojuegos = 0;
//    float horasRegistradas;
//public:
//    void cargar()
//    {
//        cout << "INGRESE ID DE VIDEOJUEGO: " ;
//        cin >> idVideojuego ;
//        cout << "INGRESE ID DE TROFEO: " ;
//        cin >> idTrofeo ;
//        cout<< "INGRESE CANTIDAD DE VIDEOJUEGOS: ";
//        cin>> cantVideojuegos;
//        horasRegistradas = 0;
//        cout << "JUEGO CARGADO EN LA BIBLIOTECA CORRECTAMENTE. " << endl;
//    }
//    void mostrar()
//    {
//        cout << "ID DE VIDEOJUEGO: " << idVideojuego << endl;
//        cout << "ID DE TROFEO: " << idTrofeo << endl;
//        cout<< "VIDEOJUEGOS: " << cantVideojuegos << endl;
//        cout << "HORAS REGISTRADAS: " << horasRegistradas<< endl;
//    }
//    void setIdVideojuego(int id){idVideojuego = id;}
//    void setIdTrofeo(int id){idTrofeo = id;}
//    void setHorasRegistradas(float horas){horasRegistradas = horas;}
//
//    int getIdVideojuego(){return idVideojuego;}
//    int getIdTrofeo(){return idTrofeo;}
//    float getHorasRegistradas(){return horasRegistradas;}
//};

class Biblioteca{
    private:
        int idUsuario;
        int idVideojuego[150]={};
        Fecha fechaCompra[150];
    public:
        void mostrar()
        {
            int i=0;
            cout << "IDS de Videojuegos comprados: " << endl;
            while (idVideojuego[i] != 0)
            {
                cout << i+1 << ") " << idVideojuego[i] << ", Fecha de adquisicion: ";
                fechaCompra[i].mostrar();
                i++;
            }
        }

        void setIdUsuario(int _id){idUsuario = _id;}
        void setIdVideojuego(int _id, int pos){idVideojuego[pos] = _id;}
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
};

#endif // BIBLIOTECA_H_INCLUDED
