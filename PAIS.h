#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

class Pais{

private:
    char nombrePais[30];
public:

    void cargar(){

    cout<<"Ingrese su pais"<<endl;
    cargarCadena(nombrePais, 29);
    }

    void mostrar(){
    cout<<"Su pais es: "<< nombrePais <<endl;
    }
};

class archivoPais{

private:
    char nombre[30];

public:
archivoPais(const char *n){strcpy(nombre, n);}

    Pais leerRegistros(int pos)
    {
        Pais obj;
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
        int cant=ftell(P)/sizeof(Pais);
        fclose(P);
        return cant;
    }

    bool grabarRegistros(Pais obj)
    {
        FILE *P=fopen(nombre, "ab");
        if(P==NULL) return false;
        int info=fwrite(&obj, sizeof obj, 1, P);
        fclose(P);
        return info;
    }

    void borrarArchivo()
    {
        FILE *p = fopen(nombre, "wb");
        if (p == nullptr) return;
        fclose(p);
    }


};

#endif // PAIS_H_INCLUDED
