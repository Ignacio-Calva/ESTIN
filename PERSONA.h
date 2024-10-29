#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "funciones.h"

class Persona
{
    private:
        char NombreUsuario[30] = {};
        char Contrasenia[20] = {};
        int Edad; //agregué nuevas variables
        int DNI;
        char Mail[30] = {};
        int IDPais;
        bool admin = false;
    public:
        void cargarDatosPersona()
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

        void mostrarDatosPersona() ///ACLARO QUE ES DE LA CLASE PERSONA PARA PODER IMPLEMENTARLA DENTRO DE LAS CLASES HEREDADAS
        {
            cout<< "Nombre usuario: " << NombreUsuario << endl;
            cout<< "Edad: " << Edad << endl;
            cout<< "DNI:  " << DNI << endl;
            cout<< "Mail: " << Mail << endl;
            cout<< "ID de Pais: " << IDPais << endl;
        }

        void setNombre(const char *n){strcpy(NombreUsuario, n);}
        void setContrasenia(const char *c){strcpy(Contrasenia, c);}
        void setEdad(int e){Edad=e;}
        void setDNI(int d){DNI=d;}
        void setMail(const char *m){strcpy(Mail, m);}
        void setIDPais(int p){IDPais=p;}
        void setAdmin(bool a){admin=a;}

        const char* getNombre(){return NombreUsuario;}
        const char* getContrasenia(){return Contrasenia;}
        int getEdad(){return Edad;}
        int getDNI(){return DNI;}
        const char* getMail(){return Mail;}
        int getIDPais(){return IDPais;}
        bool getAdmin(){return admin;}

};


#endif // PERSONA_H_INCLUDED
