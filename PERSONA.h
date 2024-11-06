#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "funciones.h"

class Persona : public Fecha
{
    private:
        char NombreUsuario[30] = {};
        char Contrasenia[20] = {};
        Fecha fechaNacimiento;
        int DNI;
        int Edad;
        char Mail[30] = {};
        int IDPais;
        Pais nombrePais;
        int numTarjeta;
        bool admin = false;
    public:
        Persona (){}
        Persona(const char* _nombre, const char* _contra)
        {
            strcpy(NombreUsuario,_nombre);
            strcpy(Contrasenia,_contra);

            fechaNacimiento.setAnio(0);
            fechaNacimiento.setMes(0);
            fechaNacimiento.setDia(0);

            Edad=(2024 - fechaNacimiento.getAnio());

            DNI = 0;
            Mail[0] = 0;
            IDPais = 0;
            numTarjeta = 0;
            admin = false;
        }

        void cargarDatosPersona()
        {
            cout << "INGRESE EL NOMBRE DE USUARIO: ";
            cargarCadena(NombreUsuario, 29);
            cout << "INGRESE LA CONTRASENIA DEL USUARIO: ";
            cargarCadena(Contrasenia, 19);
            cout<< "INGRESE SU FECHA DE NACIMIENTO: ";
            fechaNacimiento.cargar();
            Edad = fechaNacimiento.getAnioActual() - fechaNacimiento.getAnio();
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
            cout<< "Numero de tarjeta: " << numTarjeta << endl;
        }

        void setNombre(const char *n){strcpy(NombreUsuario, n);}
        void setContrasenia(const char *c){strcpy(Contrasenia, c);}
        void setFechaNacimiento(Fecha f){ fechaNacimiento = f;}
        void setEdad(int e){ Edad = e;}
        void setDNI(int d){DNI=d;}
        void setMail(const char *m){strcpy(Mail, m);}
        void setIDPais(int p){IDPais=p;}
        void setAdmin(bool a){admin=a;}
        void setTarjet(int numTar) {numTarjeta=numTar;}

        const char* getNombre(){return NombreUsuario;}
        const char* getContrasenia(){return Contrasenia;}
        int getEdad(){return Edad;}
        int getDNI(){return DNI;}
        const char* getMail(){return Mail;}
        int getIDPais(){return IDPais;}
        bool getAdmin(){return admin;}
        int getTarjet() {return numTarjeta;}
};


#endif // PERSONA_H_INCLUDED
