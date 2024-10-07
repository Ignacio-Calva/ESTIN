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

#endif // TROFEO_H_INCLUDED
