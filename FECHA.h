#pragma once
#include <string>
#include "rlutil.h"

class Fecha{
    private:
    int _dia, _mes, _anio;
    int anioActual;


    public:

        Fecha(){anioActual = 2024;}
    bool cargar()
    {
        int dia,mes,anio;
        cout << "Ingrese el dia: ";
        cin >> dia;
        if (dia <= 31 && dia > 0){_dia = dia;}
        else{cout << "Ingrese un dia valido."<<endl; return false;}
        cout << "Ingrese el mes: ";
        cin >> mes;
        if (mes <= 12 && mes > 0){_mes = mes;}
        else{cout << "Ingrese un mes valido."<<endl; return false;}
        cout << "Ingrese el anio: ";
        cin >> anio;
        if (anio <= 2024 && anio > 0){_anio = anio;}
        else{cout << "Ingrese un anio valido."<<endl; return false;}
        cout << "FECHA CARGADA" << endl;
        return true;
    }

    bool cargarPorLocate(int x, int y)
    {
        int dia,mes,anio;
        rlutil::locate(x,y);
        cout << "Ingrese el dia: ";
        cin >> dia;
        if (dia <= 31 && dia > 0){_dia = dia;}
        else{rlutil::locate(x,y+1);cout << "Ingrese un dia valido."<<endl; return false;}
        rlutil::locate(x,y+1);
        cout << "Ingrese el mes: ";
        cin >> mes;
        if (mes <= 12 && dia > 0){_mes = mes;}
        else{rlutil::locate(x,y+2);cout << "Ingrese un mes valido."<<endl; return false;}
        rlutil::locate(x,y+2);
        cout << "Ingrese el anio: ";
        cin >> anio;
        if (anio <= 2024 && anio > 0){_anio = anio;}
        else{rlutil::locate(x,y+3);cout << "Ingrese un anio valido."<<endl; return false;}
        rlutil::locate(x,y+3);
        cout << "FECHA CARGADA" << endl;
        return true;
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
