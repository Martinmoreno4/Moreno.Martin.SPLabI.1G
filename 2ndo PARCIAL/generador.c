#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "paises.h"
#include "parser.h"
#include "generador.h"

int cargarTextoDeArchivo(char* path , LinkedList* arrayPaises)
{
    int todoOk = -1;
    FILE* pFile;

    if(path != NULL && arrayPaises != NULL)
    {
        pFile = fopen(path,"r");

        if(pFile != NULL)
        {
            if(parser_paisesDeTexto(pFile, arrayPaises))
            {
                todoOk = 1;
            }
            fclose(pFile);
        }
    }

    return todoOk;
}

int listarPaises(LinkedList* arrayPaises)
{
    int todoOk=0;
    int tam = ll_len(arrayPaises);
    ePais* auxPais;
    if(arrayPaises != NULL)
    {
        todoOk=1;
        printf("  id   Nombre   Recuperados  Infectados  Muertos\n");
        for(int i=0; i<tam; i++)
        {
            auxPais = (ePais*) ll_get(arrayPaises, i);
            if(auxPais!=NULL)
            {
                mostrarPais(auxPais);
            }
        }
    }
    return todoOk;
}


int filtrarPaisesExitosos(void* elemento)
{
    int rta=0;
    ePais* e=(ePais*) elemento;
    if(e->muertos < 5)
    {
        rta = 1;
    }
    return rta;
}

int filtrarPaisesEnELHorno(void* elemento)
{
    int rta=0;
    ePais* e=(ePais*) elemento;
    if(e->infectados > (e->recuperados)*3)
    {
        rta = 1;
    }
    return rta;
}

int aleatorioRecuperados(void* elemento)
{
    int rta=0;
    ePais* e=(ePais*) elemento;
    int aleatorio;

    aleatorio = rand()%((1000 - 50) + 1)+50;

    e->recuperados=aleatorio;

    return rta;
}

int aleatorioInfectados(void* elemento)
{
    int rta=0;
    ePais* e=(ePais*) elemento;
    int aleatorio;

    aleatorio = rand()%((2000 - 400) + 1)+400;

    e->infectados=aleatorio;

    return rta;
}

int aleatorioMuertos(void* elemento)
{
    int rta=0;
    ePais* e=(ePais*) elemento;
    int aleatorio;

    aleatorio = rand()%((50 - 1) + 1)+1;

    e->muertos=aleatorio;

    return rta;
}
