#pragma once
#include <string>

class Fecha{
    private:
    int _dia, _mes, _anio;

    public:
    void mostrar()
    {
        cout << _dia << "/" << _mes << "/" <<_anio << endl;
    }
    void cargar()
    {
        cout<<"ingrese el dia:";
        cin>>_dia;
        cout<<"ingrese el mes:";
        cin>>_mes;
        cout<<"ingrese el anio:";
        cin>>_anio;
    }
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    std::string toString();
};
