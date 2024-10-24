#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include "funciones.h"

class usuario
{
private:
    int ID_Usuario = 0; //iniciado en 0 para que asigne IDs de 1 en adelante
    char NombreUsuario[30] = {};
    char Contrasenia[20] = {};
    int Edad; //agregué nuevas variables
    int DNI;
    char Mail[30] = {};
    int IDPais;
    bool admin = false;
public:
    void cargarDatos() //expandí los métodos y añadí SETTERS y GETTERS con las nuevas variables
    {
        cout << "INGRESE EL NOMBRE DE USUARIO: ";
        cargarCadena(NombreUsuario, 29);
        cout << "INGRESE LA CONTRASENIA DEL USUARIO: ";
        cargarCadena(Contrasenia, 19);
        cout<< "INGRESE SU EDAD: ";
        cin>> Edad;
        cout<< "INGRESE SU DNI: ";
        cin>> DNI;
        cout<< "INGRESE SU MAIL: ";
        cargarCadena(Mail, 29);
        cout<< "INGRESE EL ID DE SU PAIS: ";
        cin>> IDPais;
    }

    void mostrarDatos()
    {
        cout<< "Nombre usuario: " << NombreUsuario << endl;
        cout<< "ID: " << ID_Usuario << endl;
        cout<< "Edad: " << Edad << endl;
        cout<< "DNI:  " << DNI << endl;
        cout<< "Mail: " << Mail << endl;
        cout<< "ID de Pais: " << IDPais << endl;
    }

    void setID(int id){ID_Usuario=id;}
    void setNombre(const char *n){strcpy(NombreUsuario, n);}
    void setContrasenia(const char *c){strcpy(Contrasenia, c);}
    void setEdad(int e){Edad=e;}
    void setDNI(int d){DNI=d;}
    void setMail(const char *m){strcpy(Mail, m);}
    void setIDPais(int p){IDPais=p;}
    void setAdmin(bool a){admin=a;}

    int getID (){return ID_Usuario;}
    const char* getNombre(){return NombreUsuario;}
    const char* getContrasenia(){return Contrasenia;}
    int getEdad(){return Edad;}
    int getDNI(){return DNI;}
    const char* getMail(){return Mail;}
    int getIDPais(){return IDPais;}
    bool getAdmin(){return admin;}
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
