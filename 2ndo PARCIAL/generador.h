#ifndef GENERADOR_H_INCLUDED
#define GENERADOR_H_INCLUDED

#include "LinkedList.h"

int cargarTextoDeArchivo(char* path , LinkedList* arrayPaises);
int listarPaises(LinkedList* arrayPaises);
int filtrarPaisesExitosos(void* elemento);
int filtrarPaisesEnELHorno(void* elemento);

int aleatorioRecuperados(void* elemento);
int aleatorioInfectados(void* elemento);
int aleatorioMuertos(void* elemento);



#endif // GENERADOR_H_INCLUDED
