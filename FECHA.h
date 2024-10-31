#pragma once
#include <string>

class Fecha{
    private:
    int _dia, _mes, _anio;

    public:
    void mostrar()
    {
        cout << _dia << "/" << _mes << _anio << endl;
    }
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    std::string toString();
};
