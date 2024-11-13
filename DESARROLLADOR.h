#ifndef DESARROLLADOR_H_INCLUDED
#define DESARROLLADOR_H_INCLUDED

class Desarrollador
{
    private:
        char nombre[30];
    public:
        void mostrar()
        {
            cout<< " - " << nombre << endl;
        }

        const char* getNombre(){return nombre;}
        void setNombre(const char* _nombre){strcpy(nombre,_nombre);}
};


class archivoDesarrollador
{
    private:
        char nombre[50];
    public:
        archivoDesarrollador(const char *n){strcpy(nombre, n);}
        Desarrollador leerRegistros(int pos)
        {
            Desarrollador obj;
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
            int cant=ftell(P)/sizeof(Desarrollador);
            fclose(P);
            return cant;
        }

        bool grabarRegistros(Desarrollador obj)
        {
            FILE *P=fopen(nombre, "ab");
            if(P==nullptr)
            {
                cout << "Error al abrir el archivo " << nombre << " para escritura." << endl;
                system("pause");
                return false;
            }
            int info=fwrite(&obj, sizeof (Desarrollador), 1, P);
            fclose(P);
            return info;
        }

        void borrarArchivo()
        {
            FILE *p = fopen(nombre, "wb");
            if (p == nullptr) {return;}
            system("pause");
            fclose(p);
        }
};
#endif // DESARROLLADOR_H_INCLUDED
