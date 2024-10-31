#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include "funciones.h"
#include "PERSONA.h"

class  usuario: public Persona
{
private:
    int ID_Usuario = 0;
    //iniciado en 0 para que asigne IDs de 1 en adelante
    /*char NombreUsuario[30] = {};
    char Contrasenia[20] = {};
    int Edad; //agregué nuevas variables
    int DNI;
    char Mail[30] = {};
    int IDPais;
    bool admin = false;*/ //PASO EL BOOL DE ADMIN A LA CLASE DE PERSONA PORQUE ES
                          //UN ATRIBUTO EN COMUN ENTRE LAS DOS, CAMBIO EN QUE SE SETEA AL USAR cargarDatos()
    bool activo;
public:
    void cargarDatos() //expandí los métodos y añadí SETTERS y GETTERS con las nuevas variables
    {
        cargarDatosPersona();
        setAdmin(false);
        activo = true;
    }

    void mostrarDatos(){mostrarDatosPersona(); cout<< "ID Usuario: " << ID_Usuario << endl;}
    void setID(int id){ID_Usuario=id;}
    void setActivo(bool esActivo){activo = esActivo;}
    int getID (){return ID_Usuario;}
    bool getActivo(){return activo;}

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

    bool modificarUsuario(usuario obj, int pos)
    {
        FILE *p=fopen(nombre,"rb+");
        //p=fopen(nombre,"rb+");
        if(p==NULL){
            return false;
        }
        fseek(p, pos * sizeof obj, 0);
        fwrite(&obj, sizeof obj, 1, p);
        fclose(p);
        return true;
    }
};
#endif // USUARIO_H_INCLUDED
