#ifndef GENERO_H_INCLUDED
#define GENERO_H_INCLUDED

class Genero{

private:
    char nombre[30];

public:

    void cargar(){
    cargarCadena(nombre, 29);
    }
    void mostrar(){
    cout<< " - " << nombre << endl;
    }

    void setNombre(const char* _nombre){strcpy(nombre, _nombre);}
    const char *getNombre(){return nombre;}
};


class archivoGenero{

private:
char nombre[50];
public:
   archivoGenero(const char *n){strcpy(nombre, n);}

   Genero leerRegistros(int pos)
    {
        Genero obj;
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
        int cant=ftell(P)/sizeof(Genero);
        fclose(P);
        return cant;
    }

    bool grabarRegistros(Genero obj)
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

    bool modificarGenero(Genero obj, int pos)
    {
        FILE *p=fopen(nombre,"rb+");
        if(p==NULL){
            return false;
        }
        fseek(p, pos * sizeof obj, 0);
        fwrite(&obj, sizeof obj, 1, p);
        fclose(p);
        return true;
    }
};
#endif // GENERO_H_INCLUDED
