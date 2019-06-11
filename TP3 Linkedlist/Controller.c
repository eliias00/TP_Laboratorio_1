#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "valid.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile = NULL;

    if( path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            parser_EmployeeFromText(pFile,pArrayListEmployee);
        }
        fclose(pFile);

    }
    return 1;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile = NULL;

    if( path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        }
        fclose(pFile);
    }
    return 1;
}
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int bufferId;
    char bufferName[4096];
    char bufferHoras[4096];
    char bufferSueldo[4096];

    Employee *auxEmp=employee_new();
    if (!getName(bufferName,"ingrese un nombre: ","error, vuelva a ingresar\n\n",5,51,1))
    {
        employee_setNombre(auxEmp, bufferName);
        if(!getInt("ingrese las horas: ","\nerror,vuelva a intentar",1,4,1,bufferHoras))
        {
            Employee_setHorasTrabajadasStr(auxEmp,bufferHoras);
            if(!getInt("ingrese el sueldo: ","\nerror,vuelva a intentar",1,5,1,bufferSueldo))
            {
                Employee_setSueldoStr(auxEmp,bufferSueldo);
                bufferId=generadorId(pArrayListEmployee);
                employee_setId(auxEmp,bufferId);
                ll_add(pArrayListEmployee,auxEmp);
                printf("empleado ingresado correctamente");
            }
            ll_sort(pArrayListEmployee,employee_compararPorNombre,1);
        }
    }
    return 1;
}
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int cant;
    int posId;
    char bufferName[4096];
    char bufferHoras[4096];
    char bufferSueldo[4096];
    Employee* auxiliar;
    int opcionM;

    cant=ll_len(pArrayListEmployee);
    for(i=0; i<cant+1; i++)
    {
        printf("id disponibles:%d\n",i);
    }
    if(!buscaId(pArrayListEmployee, &posId))
    {
        auxiliar = ll_get(pArrayListEmployee, posId);
        printf("Elija que campo desea modificar:\n 1- Nombre \n 2- Horas de trabajo \n 3- Sueldo \n");
        scanf("%d", &opcionM);
        switch(opcionM)
        {
        case 1:
            if(!getName(bufferName,"ingrese un nombre: ","error, vuelva a ingresar\n\n",5,51,1))
            {
                employee_setNombre(auxiliar,bufferName);
            }
            break;
        case 2:
            if(!getInt("ingrese las horas: ","\nerror,vuelva a intentar",1,4,1,bufferHoras))
            {
                Employee_setHorasTrabajadasStr(auxiliar,bufferHoras);
            }
            break;
        case 3:
            if(!getInt("ingrese el sueldo: ","\nerror,vuelva a intentar",1,9,1,bufferSueldo))
            {
                Employee_setSueldoStr(auxiliar,bufferSueldo);
            }
            break;
        default:
            printf("Opcion invalida");
        }
    }
    return 1;
}
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int indice;
    int cant;
    int i;
    Employee* empAux = NULL;
    if(pArrayListEmployee != NULL)
    {
        cant=ll_len(pArrayListEmployee);
        for(i=0; i<cant+1; i++)
        {
            printf("id disponibles:%d\n",i);
        }
        if(!buscaId(pArrayListEmployee, &indice))
        {
            empAux = ll_pop(pArrayListEmployee, indice);
            employee_delete(empAux);
            printf("Empleado eliminado de la aplicacion");
        }
    }
    return 1;
}
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmp;
    int auxID;
    int auxSueldo;
    int auxHoras;
    char bufferName[4096];
    int i;
    if(pArrayListEmployee != NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmp = ll_get(pArrayListEmployee, i);
            employee_getId(auxEmp, &auxID);
            employee_getSueldo(auxEmp, &auxSueldo);
            employee_getHorasTrabajadas(auxEmp, &auxHoras);
            employee_getNombre(auxEmp, bufferName);
            printf("ID: %d | Nombre: %s | Horas Trabajadas: %d | Sueldo: $%d\n",
            auxID, bufferName, auxHoras, auxSueldo);
        }
    }
    return 1;
}
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL)
    {
        printf("Realizando reordenamiento alfabetico\n");
        if(!ll_sort(pArrayListEmployee,employee_compararPorNombre,1))
        {
            controller_ListEmployee(pArrayListEmployee);
        }
    }
    return 1;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int i;
    int auxId;
    char auxNombre[1000];
    int auxHorasTrabajadas;
    int auxSueldo;
    FILE* pArchivo = NULL;
    pArchivo=fopen(path,"w");

    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = ll_get(pArrayListEmployee,i);
            employee_getId(auxEmployee,&auxId);
            employee_getHorasTrabajadas(auxEmployee,&auxHorasTrabajadas);
            employee_getNombre(auxEmployee,auxNombre);
            employee_getSueldo(auxEmployee,&auxSueldo);
            fprintf(pArchivo,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        }
        printf("\n El grabado de datos en formato texto ha sido un exito.\n");
    }
    fclose(pArchivo);
    return 1;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile = NULL;
    int i;
    int cant;
    Employee *auxEmp=NULL;
    cant=ll_len(pArrayListEmployee);
    if( path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            for(i=0; i<cant; i++)
            {
                auxEmp=ll_get(pArrayListEmployee,i);
                fwrite(auxEmp,sizeof(Employee),1,pFile);
            }
            printf("\n El grabado de datos en formato binario ha sido un exito.\n");
        }
        fclose(pFile);
    }
    return 1;
}
