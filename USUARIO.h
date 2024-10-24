#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include "funciones.h"


class usuario
{
private:
    int ID_Usuario;
    char NombreUsuario[30] = {};
    char Contrasenia[20] = {};
public:
    void cargarDatos()
    {
        cout << "INGRESE EL NOMBRE DE USUARIO: ";
        cargarCadena(NombreUsuario, 29);
        cout << "INGRESE LA CONTRASENIA DEL USUARIO: ";
        cargarCadena(Contrasenia, 19);
    }

    void mostrarDatos()
    {
        cout<< "Nombre usuario: " << NombreUsuario << endl;
        cout<< "ID: " << ID_Usuario << endl;
    }

    void setID(int id){ID_Usuario=id;}
    void setNombre(const char *n){strcpy(NombreUsuario, n);}
    void setContrasenia(const char *c){strcpy(Contrasenia, c);}

    int getID (){return ID_Usuario;}
    const char* getNombre(){return NombreUsuario;}
    const char* getContrasenia(){return Contrasenia;}
};

class archivoUsuario
{
private:
    char nombre[30];
public:
    archivoUsuario(const char *n){strcpy(nombre, n);}

    usuario leerRegistros(int pos)
    {
        usuario obj;
        FILE *P=fopen(nombre, "rb");
        if (P==NULL)return obj;
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
        int cant=ftell(P)/sizeof(usuario);
        fclose(P);
        return cant;
    }

    bool grabarRegistros(usuario obj)
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

#endif // USUARIO_H_INCLUDED
