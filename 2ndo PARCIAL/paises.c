#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "paises.h"

void mostrarPais(ePais* pais)
{
    printf("%4d  %s  %d  %d  %d\n", pais->id, pais->nombre, pais->recuperados, pais->infectados, pais->muertos);
}



int paisSetId(ePais* this,int id)
{
    int todoOk = 0;
    if(this!=NULL && id > 0)
    {
        this->id= id;
        todoOk= 1;
    }
    return todoOk;
}
int paisGetId(ePais* this,int* id)
{
    int todoOk = 0;
    if(this!=NULL && id != NULL)
    {
        *id = this->id;
        todoOk= 1;
    }
    return todoOk;
}

int paisSetNombre(ePais* this,char* nombre)
{
    int todoOk = 0;
    if(this!=NULL && nombre != NULL )
    {
        strcpy(this->nombre, nombre);
        todoOk=1;
    }
    return todoOk;
}
int paisGetNombre(ePais* this,char* nombre)
{
    int todoOk = 0;
    if(this!=NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk= 1;
    }
    return todoOk;
}

int paisSetRecuperados(ePais* this,int recuperados)
{
    int todoOk = 0;
    if(this!=NULL && recuperados > 0)
    {
        this->recuperados= recuperados;
        todoOk= 1;
    }
    return todoOk;
}
int paisGetRecuperados(ePais* this,int* recuperados)
{
    int todoOk = 0;
    if(this!=NULL && recuperados != NULL)
    {
        *recuperados = this->recuperados;
        todoOk= 1;
    }
    return todoOk;
}

int paisSetInfectados(ePais* this,int infectados)
{
    int todoOk = 0;
    if(this!=NULL && infectados > 0)
    {
        this ->infectados= infectados;
        todoOk= 1;
    }
    return todoOk;
}
int paisGetInfectados(ePais* this,int* infectados)
{
    int todoOk = 0;
    if(this!=NULL && infectados != NULL)
    {
        *infectados = this->infectados;
        todoOk= 1;
    }
    return todoOk;
}

int paisSetMuertos(ePais* this,int muertos)
{
    int todoOk = 0;
    if(this!=NULL && muertos > 0)
    {
        this ->muertos=muertos;
        todoOk= 1;
    }
    return todoOk;
}
int paisGetMuertos(ePais* this,int* muertos)
{
    int todoOk = 0;
    if(this!=NULL  && muertos != NULL)
    {
        *muertos = this->muertos;
        todoOk= 1;
    }
    return todoOk;
}

ePais* nuevoPais()
{
    ePais* nuevoPaisAux = (ePais*) malloc(sizeof(ePais));
    if(nuevoPaisAux!=NULL)
    {
        nuevoPaisAux->id = 0;
        strcpy(nuevoPaisAux->nombre, " ");
        nuevoPaisAux->recuperados = 0;
        nuevoPaisAux->infectados = 0;
        nuevoPaisAux->muertos = 0;
    }
    return nuevoPaisAux;
}

ePais* nuevoPaisParam(int id, char* nombre, int recuperados, int infectados, int muertos)
{
    ePais* nuevoPaisAux = nuevoPais();
    if(nuevoPaisAux!=NULL)
    {
        if(!(paisSetId(nuevoPaisAux, id)
        && paisSetNombre(nuevoPaisAux, nombre)
        && paisSetRecuperados(nuevoPaisAux, recuperados)
        && paisSetInfectados(nuevoPaisAux, infectados)
        && paisSetMuertos(nuevoPaisAux, muertos)))
        {
            free(nuevoPaisAux);
            nuevoPaisAux = NULL;
        }
    }
    return nuevoPaisAux;
}

int paisOrdenPorinfeccion(void* paisA, void* paisB)
{
    int retorno = 0;
    int infectadosA;
    int infectadosB;

    if(paisGetInfectados((ePais*)paisA, &infectadosA) &&
        paisGetInfectados((ePais*)paisB, &infectadosB))
    {
        retorno = infectadosA - infectadosB;
    }

    return retorno;
}

int paisOrdenPorMuertes(void* paisA, void* paisB)
{
    int retorno = 0;
    int muertosA;
    int muertosB;

    if(paisGetMuertos((ePais*)paisA, &muertosA) &&
        paisGetMuertos((ePais*)paisB, &muertosB))
    {
        retorno = muertosA - muertosB;
    }

    return retorno;
}
