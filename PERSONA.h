#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "funciones.h"
#include "PAIS.h"
class Persona
{
    private:
        char NombreUsuario[30] = {};
        char Contrasenia[20] = {};
        Fecha fechaNacimiento;
        int DNI;
        int Edad;
        char Mail[30] = {};
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
            DNI = 0;
            nombrePais.setNombrePais("");
            Mail[0] = 0;
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
            cout<< "INGRESE SU PAIS: ";
            nombrePais.cargar();
        }

        void mostrarDatosPersona() ///ACLARO QUE ES DE LA CLASE PERSONA PARA PODER IMPLEMENTARLA DENTRO DE LAS CLASES HEREDADAS
        {
            rlutil::locate(40,8);
            cout<< "Nombre usuario: " << NombreUsuario << endl;
            rlutil::locate(40,9);
            cout<< "Edad: " << Edad << endl;
            rlutil::locate(40,10);
            cout<< "DNI:  " << DNI << endl;
            rlutil::locate(40,11);
            cout<< "Pais: " << nombrePais.getNombrePais() << endl;
            rlutil::locate(40,12);
            cout<< "Mail: " << Mail << endl;
            rlutil::locate(40,13);
            cout<< "Numero de tarjeta: " << numTarjeta << endl;

        }

        void setNombre(const char *n){strcpy(NombreUsuario, n);}
        void setContrasenia(const char *c){strcpy(Contrasenia, c);}
        void setFechaNacimiento(Fecha f){ fechaNacimiento = f;}
        void setEdad(int e){ Edad = e;}
        void setDNI(int d){DNI=d;}
        void setMail(const char *m){strcpy(Mail, m);}
        void setAdmin(bool a){admin=a;}
        void setTarjet(int numTar) {numTarjeta=numTar;}
        void setPais(const char *p)
        {
            nombrePais.setNombrePais(p);
        }
        const char* getPais(){return nombrePais.getNombrePais();}
        const char* getNombre(){return NombreUsuario;}
        const char* getContrasenia(){return Contrasenia;}
        int getEdad(){return Edad;}
        int getDNI(){return DNI;}
        const char* getMail(){return Mail;}
        bool getAdmin(){return admin;}
        int getTarjet() {return numTarjeta;}
};


#endif // PERSONA_H_INCLUDED
