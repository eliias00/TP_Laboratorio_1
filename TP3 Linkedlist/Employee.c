#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "valid.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee *retorno = NULL;
    Employee *auxEmployee;
    if(idStr != NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL )
    {
        auxEmployee=employee_new();
        if(auxEmployee!=NULL)
        {
            if(!employee_setNombre(auxEmployee,nombreStr)&&
               !Employee_setHorasTrabajadasStr(auxEmployee,horasTrabajadasStr)&&
               !Employee_setIdStr(auxEmployee,idStr)&&
               !Employee_setSueldoStr(auxEmployee,sueldoStr))
            {
                retorno=auxEmployee;
            }
            else
            {
                employee_delete(auxEmployee);
            }
        }
    }
    return retorno;
}
void employee_delete(Employee *auxEmployee)
{
    if(auxEmployee != NULL)
    {
        free(auxEmployee);
    }
}
int Employee_setIdStr(Employee* this, char *id)
{
    int retorno = -1;
    if(this != NULL && id >=0)
    {
        retorno = employee_setId(this, atoi(id));
    }
    return retorno;
}
int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL  && id >=0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidName(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre, this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int Employee_setHorasTrabajadasStr(Employee* this, char *horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas>=0)
    {
        retorno = employee_setHorasTrabajadas(this,atoi(horasTrabajadas));
    }
    return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
int Employee_setSueldoStr(Employee* this, char *sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >=0)
    {
        retorno = employee_setSueldo(this,atoi(sueldo));
    }
    return retorno;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >=0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}
int generadorId(LinkedList* pArrayListEmployee)
{
    Employee* auxiliar;
    int cant;
    int auxId;
    int maxID = -1;
    int i;
    if(pArrayListEmployee != NULL)
    {
        cant = ll_len(pArrayListEmployee);
        for(i=0;i<cant;i++)
        {
            auxiliar = ll_get(pArrayListEmployee, i);
            employee_getId(auxiliar, &auxId);
            if(auxId > maxID)
            {
                maxID = auxId;
            }
        }
    }
    maxID += 1;
    return maxID;
}
int buscaId (LinkedList* pArrayListEmployee, int *idEncontrado)
{
    int i;
    int retorno = -1;
    int id;
    Employee *empleado;
    int auxid;
    int cant;

    printf("\ningrese id a buscar: ");
    scanf("%d", &auxid);
    cant = ll_len(pArrayListEmployee);
    for(i=0; i < cant; i++)
    {
        empleado = ll_get(pArrayListEmployee, i);
        employee_getId(empleado,&id);
        if (id == auxid)
        {
            retorno=0;
            *idEncontrado=i;
            break;
        }
    }
    return retorno;
}
int employee_compararPorNombre(void *this1,void *this2)
{
    char auxStrA[4096];
    char auxStrB[4096];
    int retorno;
    employee_getNombre((Employee*)this1, auxStrA);
    employee_getNombre((Employee*)this2, auxStrB);
    if(strcmp(auxStrA,auxStrB)>0)
    {
      retorno=1;
    }
    else if(strcmp(auxStrA,auxStrB)<0)
    {
      retorno=-1;
    }
      return retorno;
}
