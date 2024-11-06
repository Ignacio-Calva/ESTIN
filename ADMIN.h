#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include "funciones.h"
#include "PERSONA.h"

class Admin : public Persona
{
    private:
        int idAdmin = 0;
        int juegosCargados = 0;
        bool activo = true;
    public:
        Admin(){}
        Admin(const char* _usuario,const char* _contra,int _idAdmin,bool _activo) : Persona(_usuario,_contra){
            idAdmin = _idAdmin;
            activo = _activo;
            setAdmin(true);
        }
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
            cout << "Juegos cargados: " << juegosCargados << endl;
            cout << "Activo: ";
            if (activo){cout << "Si." << endl;} else {cout << "No." << endl;}
            cout << "ADMIN: ";
            if (getAdmin()){cout << "Si." << endl;} else {cout << "No. (Permisos removidos anteriormente)" << endl;}
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
        if(P==nullptr)
        {
            cout << "Error al abrir el archivo " << nombre << " para escritura." << endl;
            system("pause");
            return false;
        }
        int info=fwrite(&obj, sizeof (Admin), 1, P);
        fclose(P);
        return info;
    }

    void borrarArchivo()
    {
        FILE *p = fopen(nombre, "wb");
        if (p == nullptr) {return;}
        system("pause");
        fclose(p);
    }

    bool modificarAdmin(Admin obj,int pos)
    {
        FILE *p=fopen(nombre,"rb+");
        if(p==NULL){
            return false;
        }
        fseek(p, pos * sizeof obj, 0);
        fwrite(&obj, sizeof obj, 1, p);
        fclose(p);
        return true;
    }
};

#endif // ADMIN_H_INCLUDED
