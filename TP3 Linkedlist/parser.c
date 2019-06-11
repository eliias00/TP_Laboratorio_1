#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Employee.h"
#include "valid.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int flag=0;
    char bufferId[4096];
    char bufferName[4096];
    char bufferHoras[4096];
    char bufferSueldo[4096];
    Employee* auxEmp;

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferHoras, bufferSueldo);
        if(flag == 0)
        {
            flag++;
            continue;
        }
        auxEmp=employee_newParametros(bufferId, bufferName, bufferHoras,bufferSueldo);
        if(auxEmp != NULL)
        {
            ll_add(pArrayListEmployee, auxEmp);
        }
    }
    return 1;
}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee auxEmp;
    Employee *pEmp=NULL;
    char bufferId[4096];
    char bufferName[4096];
    char bufferHoras[4096];
    char bufferSueldo[4096];

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
           fread(&auxEmp,sizeof(Employee),1,pFile);
           if(!employee_setNombre(pEmp,bufferName)&&
              !Employee_setHorasTrabajadasStr(pEmp,bufferHoras)&&
              !Employee_setIdStr(pEmp,bufferId)&&
              !Employee_setSueldoStr(pEmp,bufferSueldo))
            {
            ll_add(pArrayListEmployee, pEmp);
            }
        }
    }
    return 1;
}
