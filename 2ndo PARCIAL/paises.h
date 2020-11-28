#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int recuperados;
    int infectados;
    int muertos;
}ePais;

void mostrarPais(ePais* pais);

void borrarPais();

int paisSetId(ePais* this,int id);
int paisGetId(ePais* this,int* id);

int paisSetNombre(ePais* this,char* nombre);
int paisGetNombre(ePais* this,char* nombre);

int paisSetRecuperados(ePais* this,int recuperados);
int paisGetRecuperados(ePais* this,int* recuperados);

int paisSetInfectados(ePais* this,int infectados);
int paisGetInfectados(ePais* this,int* infectados);

int paisSetMuertos(ePais* this,int muertos);
int paisGetMuertos(ePais* this,int* muertos);

int paisOrdenPorinfeccion(void* paisA, void* paisB);

ePais* nuevoPais();
ePais* nuevoPaisParam(int id, char* nombre, int recuperados, int infectados, int muertos);

#endif // PAISES_H_INCLUDED
