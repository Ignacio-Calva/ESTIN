#ifndef TROFEO_H_INCLUDED
#define TROFEO_H_INCLUDED
#include "funciones.h"

class trofeo  ///HACER CLASE DE ARCHIVO TROFEOS
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

class archivoTrofeo
{
private:
       char nombre[30];
public:
    archivoTrofeo(const char *n)
    {
        strcpy(nombre, n);
    }

    trofeo leerRegistros(int pos)
    {
        trofeo obj;
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
        int cant=ftell(P)/sizeof(trofeo);
        fclose(P);
        return cant;
    }

    bool grabarRegistros(trofeo obj)
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

#endif // TROFEO_H_INCLUDED
