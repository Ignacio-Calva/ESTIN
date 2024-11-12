#pragma once
#include <string>

class Fecha{
    private:
    int _dia, _mes, _anio;
    int anioActual;


    public:

        Fecha(){anioActual = 2024;}
    void cargar()
    {
        cout << "Ingrese el dia: ";
        cin >> _dia;
        cout << "Ingrese el mes: ";
        cin >> _mes;
        cout << "Ingrese el anio: ";
        cin >> _anio;
    }

    void mostrar()
    {

        cout << _dia << "/" << _mes << "/" << _anio << endl;

    }
    int getDia(){return _dia;}
    int getMes(){return _mes;}
    int getAnio(){return _anio;}
    int getAnioActual(){return anioActual;}
    void setDia(int dia){_dia = dia;}
    void setMes(int mes){_mes = mes;}
    void setAnio(int anio){_anio = anio;}
    std::string toString();
};
