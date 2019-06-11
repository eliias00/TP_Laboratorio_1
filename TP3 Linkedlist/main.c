#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "valid.h"
int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
        printf("\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
        printf("\n3. Alta de empleado");
        printf("\n4. Modificar datos de empleado");
        printf("\n5. Baja de empleado");
        printf("\n6. Listar empleados");
        printf("\n7. Ordenar empleados");
        printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
        printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).");
        printf("\n10.Salir");

        printf("\ningrese opcion: ");
        scanf("%d",&option);
        system("clear");
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                printf("se ha cargado data.csv(txt)\n");
                break;
            case 2:
                controller_loadFromBinary("salvado2.bin",listaEmpleados);
                printf("se ha cargado data.csv(binario)\n");
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                 controller_editEmployee(listaEmpleados);
                break;
            case 5:
                 controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText("salvado1.csv",listaEmpleados);
                break;
            case 9:
                 controller_saveAsBinary("salvado2.bin", listaEmpleados);
                break;
            case 10:
                 printf("\nsalio de la aplicacion\n");
                break;
                }
    }while(option != 10);
    return 0;
}
