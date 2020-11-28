#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "biblioteca.h"
#include "LinkedList.h"
#include "generador.h"
#include "paises.h"

    //srand (time(NULL));  // esta linea va al inicio de main
    //int aleatorio;

    //aleatorio = rand()%((a-b) + 1)+b; // esta linea va en la funcion que asigna el tiempo donde a es el maximo y b el minimo

int menu();

int main()
{
    srand (time(NULL));
    int aleatorio;
    int rta;
    char seguir = 's';
    char confirma;
    int seIngresaronDatos=0;

    LinkedList* listaPaises = ll_newLinkedList();

    LinkedList* paisesGanadores = NULL;
    LinkedList* PaisesEnHorno = NULL;

    do
    {
        switch(menu())
        {
        case 1:
            if(!cargarTextoDeArchivo("pandemia.csv",listaPaises))
            {
                printf("No se logro cargar los paises\n");
            }
            else
            {
                printf("de paises se lograron cargar\n");
                seIngresaronDatos=1;
            }
            break;

        case 2:
            if(seIngresaronDatos==0)
            {
                printf("ingrese primero los datos\n");
            }
            else
            {
                system("cls");
                if(!listarPaises(listaPaises))
                {
                    printf("Problema al listar los paises");
                }
            }
            break;

        case 3:
            if(seIngresaronDatos==0)
            {
                printf("ingrese primero los datos\n");
            }
            else
            {
                listaPaises =ll_map(listaPaises,aleatorioRecuperados);
                listaPaises =ll_map(listaPaises,aleatorioInfectados);
                listaPaises =ll_map(listaPaises,aleatorioMuertos);

            }
            break;

        case 4:
            if(seIngresaronDatos==0)
            {
                printf("ingrese primero los datos\n");
            }
            else
            {
                paisesGanadores=ll_filter(listaPaises, filtrarPaisesExitosos);
                if(paisesGanadores!=NULL)
                {
                    listarPaises(paisesGanadores);
                }
                else
                {
                    printf("error al filtrar");
                }


            }
            break;

        case 5:
            if(seIngresaronDatos==0)
            {
                printf("ingrese primero los datos\n");
            }
            else
            {
                PaisesEnHorno=ll_filter(listaPaises, filtrarPaisesEnELHorno);
                if(PaisesEnHorno!=NULL)
                {
                    listarPaises(PaisesEnHorno);
                }
                else
                {
                    printf("error al filtrar");
                }
            }
            break;

        case 6:
            if(seIngresaronDatos==0)
            {
                printf("ingrese primero los datos\n");
            }
            else
            {
                ll_sort(listaPaises, paisOrdenPorinfeccion, 1);
            }
            break;

        case 7:
            if(seIngresaronDatos==0)
            {
                printf("ingrese primero los datos\n");
            }
            else
            {

            }
            break;

        case 8:
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("ingrese dato valido\n");
            break;
        }
        system("pause");
    }while(seguir=='s');

    printf("Hello world!\n");
    return 0;
}

int menu()
{
    int opcion;
    system("cls");

    printf(" Menu \n\n");
    printf("1) Cargar archivo\n");
    printf("2) Imprimir lista\n");
    printf("3) Asignar estadisticas:\n");
    printf("4) filtrar por paises exitosos\n");
    printf("5) filtrar por paises en el horno\n");
    printf("6) ordenar por nivel de infeccion\n");
    printf("7) mostrar mas castigado\n");
    printf("8) Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
