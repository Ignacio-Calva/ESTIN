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
        cin>> ID_Usuario;
        cargarCadena(NombreUsuario, 29);
        cargarCadena(Contrasenia, 19);
    }

    void mostrarDatos()
    {
        cout<< "Nombre usuario: " << NombreUsuario << endl;
        cout<< "ID: " << ID_Usuario << endl;
        cout<<"Contrasenia: " << Contrasenia << endl;
    }

    void setID(int id){ID_Usuario=id;}
    void setNombre(const char *n){strcpy(NombreUsuario, n);}
    void setContrasenia(const char *c){strcpy(Contrasenia, c);}

    int getID (){return ID_Usuario;}
    string getNombre(){return NombreUsuario;}
    string getContrasenia(){return Contrasenia;}
};

class archivoUsuario
{
private:
    char nombre[30];
public:
    archivoUsuario(const char *n)
    {
        strcpy(nombre, n);
    }

    usuario leerRegistros(int pos)
    {
        usuario obj;
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
                cout<< "Videojuegos: " << cantVideojuegos << endl;
        cout << "HORAS REGISTRADAS: " << horasRegistradas<< endl;
    }
    void setIdVideojuego(int id)
    {
        idVideojuego = id;
    }
    void setIdTrofeo(int id)
    {
        idTrofeo = id;
    }
    void setHorasRegistradas(float horas)
    {
        horasRegistradas = horas;
    }
    int getIdVideojuego()
    {
        return idVideojuego;
    }
    int getIdTrofeo()
    {
        return idTrofeo;
    }
    float getHorasRegistradas()
    {
        return horasRegistradas;
    }
};

class trofeo
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

#endif // USUARIO_H_INCLUDED
