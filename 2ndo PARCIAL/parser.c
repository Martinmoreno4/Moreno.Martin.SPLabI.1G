#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "paises.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_paisesDeTexto(FILE* pFile , LinkedList* arrayPaises)
{
    char buffer[5][128];
    int len;
    ePais* auxPais;
    int i;
    len = ll_len(arrayPaises);
    int cant;
    if(pFile==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
    do
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

        if(cant == 5)
        {
            auxPais = nuevoPaisParam(atoi(buffer[0]),buffer[1],atoi(buffer[2]),atoi(buffer[3]), atoi(buffer[4]));
            ll_add(arrayPaises, auxPais);
            i++;
        }
        else
        {
            break;
        }

    }while( !feof(pFile) && i>len);

    fclose(pFile);

    printf("\n%d ",ll_len(arrayPaises));

    return 1;
}
