#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include "funciones.h"
#include "PERSONA.h"

class Admin : public Persona
{
    private:
        int idAdmin = 0;
        int juegosCargados;
        bool activo = true;
    public:
        void cargarDatos()
        {
            cargarDatosPersona();
            setAdmin(true);
            juegosCargados = 0;
        }

        void mostrarDatos()
        {
            mostrarDatosPersona();
            cout << "ID de Admin: " << idAdmin << endl;
        }
        //SETTERS
        void setIdAdmin(int _idAdmin){idAdmin = _idAdmin;}
        void setJuegosCargados(int _juegos){juegosCargados = _juegos;}
        void setActivo(bool esActivo){activo = esActivo;}
        //GETTERS
        int getIdAdmin(){return idAdmin;}
        int getJuegosCargados(){return juegosCargados;}
        bool getActivo(){return activo;}
};


class archivoAdmin
{
private:
    char nombre[30];
public:
    archivoAdmin(const char *n){strcpy(nombre, n);}

    Admin leerRegistros(int pos)
    {
        Admin obj;
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
        int cant=ftell(P)/sizeof(Admin);
        fclose(P);
        return cant;
    }

    bool grabarRegistros(Admin obj)
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

#endif // ADMIN_H_INCLUDED
