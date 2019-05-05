#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "validaciones.h"
#define E 3
#define VACIO -1
#define LLENO 1
int functionMenu(void)
{
    int opcion;
    char seguir;
    int posLibre;
    int flag=0;
    int informe;
    Empleado arrayEmpleado[E];

    arrayInialization(arrayEmpleado,E);
    do
    {
        printf(":::::::::::::::::::::::::::\n");
        printf(": 1) ALTAS    2)MODIFICAR :\n");
        printf(": 3) BAJA     4)INFORMAR  :\n");
        printf(":::::::::::::::::::::::::::\n");
        printf("elija una opcion: ");
        scanf("%d", &opcion);
        system("clear");
        switch(opcion)
        {
        case 1:
            if(!spaceFinderInTheArray(arrayEmpleado,E,&posLibre))
            {
                flag=1;
                switch(employeeIncomeFunction(arrayEmpleado,E,posLibre))
                {
                case 0:
                    printf("dato ingresado correctamente\n\n");
                    break;

                case 1:
                    printf("dato ingresado INCORRECTAMENTE\n\n");
                    break;
                }
            }
            else
            {
                printf("lleno");
            }
            break;
        case 2:
            if(flag==0)
            {
                printf("debe cargar al empleado primero");
            }
            else
            {
                modifyFields(arrayEmpleado,E);
            }
            break;
        case 3:
            if(flag==0)
            {
                printf("debe cargar al empleado primero");
            }
            else
            {
                employeeLow(arrayEmpleado,E);
            }
            break;
        case 4:
            if(flag==0)
            {
                printf("debe cargar al empleado primero");
            }
            else
            {
                printf(":::::::::::::::::::::::::::::::::::\n");
                printf(": 1) LAST NAME AND SECTOR UPWARD  :\n");
                printf(": 2) LAST NAME AND SECTOR FALLING :\n");
                printf(": 3) TOTAL AND AVERAGE SALARY     :\n");
                printf(":::::::::::::::::::::::::::::::::::\n");
                printf("elija una opcion: ");
                scanf("%d", &informe);
                switch(informe)
                {
                case 1:
                    alphabeticallyOrderedByUpward(arrayEmpleado,E);
                    break;
                case 2:
                    alphabeticalOrderByFalling(arrayEmpleado,E);
                    break;
                case 3:
                    totalAndAverageSalary(arrayEmpleado,E);
                    break;
                }
            }
            break;
        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        scanf("%s",&seguir);
        system("clear");
    }
    while(seguir =='s');
    return 0;
}
static int generarId(void)
{
    static int idPant=0;
    return idPant++;
}
int arrayInialization(Empleado *arrayEmpleado, int cant)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        arrayEmpleado[i].isEmpty=VACIO;
        ret=0;
    }
    return ret;
}
int spaceFinderInTheArray(Empleado *arrayEmpleado,int cant,int *indice)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        if(arrayEmpleado[i].isEmpty==VACIO)
        {
            *indice=i;
            ret=0;
            break;
        }
        ret=-1;
    }
    return ret;
}
int employeeIncomeFunction(Empleado *arrayEmpleado,int cant,int posLibre)
{
    int ret;
    char salario[50];
    float auxsal;
    char sector[50];
    int auxsec;
    if (!getName(arrayEmpleado[posLibre].nombre,"ingrese un nombre: ","error, vuelva a ingresar\n\n",2,20,1))
    {
        if (!getName(arrayEmpleado[posLibre].apellido,"ingrese un apellido: ","error, vuelva a ingresar\n\n",2,20,1))
        {
            if (!getFloat("ingrese salario: ","error,vuelva a intentar",0,10,1,salario))
            {
                auxsal=atof(salario);
                arrayEmpleado[posLibre].salario=auxsal;
                if(!getInt("ingrese un sector:","\nerror,vuelva a intentar",1,10,1,sector))
                {
                    auxsec=atoi(sector);
                    arrayEmpleado[posLibre].sector=auxsec;
                    arrayEmpleado[posLibre].id=generarId();
                    arrayEmpleado[posLibre].isEmpty=0;
                    ret=0;
                }
            }
        }
    }
    else
    {
        ret=1;
    }
    return ret;
}
int searchId (Empleado *arrayEmpleado, int cant, int *idEncontrado)
{
    int i;
    int retorno = -1;
    Empleado auxEmpleado;
    printf("\ningrese id a buscar: ");
    scanf("%d", &auxEmpleado.id);
    for(i=0; i < cant; i++)
    {
        if (arrayEmpleado[i].id == auxEmpleado.id)
        {
            retorno=0;
            *idEncontrado=i;
            break;
        }
    }
    return retorno;
}
int modifyFields(Empleado *arrayEmpleado,int cant)
{
    int aceptar2;
    char modificacion;
    int ret=-1;
    int posId;
    char salario[50];
    float auxsal;
    char sector[50];
    int auxsec;
    int i;
    int posPrueba=0;
    for(i=0;i<cant;i++)
    {
        if(arrayEmpleado[i].isEmpty!=VACIO)
        {
            printf("id disponibles: %d\n",arrayEmpleado[i].id);
        }
    }
    if(!searchId(arrayEmpleado,cant,&posId))
    {
        do
        {
            system("clear");
            printf("--------------\n");
            printf("-5) NOMBRE   -\n");
            printf("-6) APELLIDO -\n");
            printf("-7) SALARIO  -\n");
            printf("-8) SECTOR   -\n");
            printf("--------------\n");
            printf("ingrese el campo a modificar: ");
            scanf("%d",&aceptar2);
            system("clear");
            switch(aceptar2)
            {
            case 5:
                getName(arrayEmpleado[posPrueba].nombre,"modifique el nombre: ","error, vuelva a ingresar\n\n",2,20,1);
                break;
            case 6:
                getName(arrayEmpleado[posPrueba].apellido,"modifique el apellido: ","error, vuelva a ingresar\n\n",2,20,1);
                break;
            case 7:
                getFloat("modifique el salario: ","error,vuelva a intentar",0,10,1,salario);
                auxsal=atof(salario);
                arrayEmpleado[posPrueba].salario=auxsal;
                break;
            case 8:
                getInt("modifique el sector:","\nerror,vuelva a intentar",1,2,1,sector);
                auxsec=atoi(sector);
                arrayEmpleado[posPrueba].sector=auxsec;
                break;
            }
            printf("\nquiere modificar otro campo?\ns/para continuar n/para salir\n");
            scanf("%s",&modificacion);
            system("clear");
        }
        while(modificacion=='s');
        ret=0;
    }
    else
    {
        printf("no se encontro id");
    }
    return ret;
}
int employeeLow(Empleado *arrayEmpleado,int cant)
{
    int posId;
    char resp;
    int posBaja=0;
    int i;
    for(i=0;i<cant;i++)
    {
        if(arrayEmpleado[i].isEmpty!=VACIO)
        {
            printf("id disponibles: %d\n",arrayEmpleado[i].id);
        }
    }
    if(!searchId(arrayEmpleado,cant,&posId))
    {
        printf("esta seguro que quiere dar de baja ese id: \n s|n: ");
        scanf("%s",&resp);
        if(resp=='s')
        {
            printf("se ah dado de baja este empleado");
            arrayEmpleado[posBaja].isEmpty=VACIO;
        }
        else
        {
            printf("vuelva al menu");
        }
    }
    return 0;
}
int alphabeticallyOrderedByUpward(Empleado *arrayEmpleado, int cant)
{
    int i;
    int j;
    int a;
    int b;
    int c;
    int d;
    Empleado aux;
    Empleado aux1;
    printf("  ordenado alfabeticamente ascendente por apellido:\n");
    for(i = 1; i < cant; i++)
    {
        aux = arrayEmpleado[i];
        j = i;
        while(j > 0 && strcmp( aux.apellido, arrayEmpleado[j - 1].apellido)<0)
        {
            arrayEmpleado[j] = arrayEmpleado[j - 1];
            j--;
        }
        arrayEmpleado[j] = aux;
    }
    for (d=0; d<cant; d++)
    {
        if(arrayEmpleado[d].isEmpty!=VACIO)
        {
            printf("  nombre:%s  apellido:%s  salario:%.2f  sector:%d\n",arrayEmpleado[d].nombre,arrayEmpleado[d].apellido,arrayEmpleado[d].salario,arrayEmpleado[d].sector);
        }
    }
    printf("\n  ordenado alfabeticamente ascendente por sector:\n");
    for(b = 1; b < cant; b++)
    {
        aux1 = arrayEmpleado[b];
        c = b;
        while(c > 0 &&  aux1.sector < arrayEmpleado[j - 1].sector)
        {
            arrayEmpleado[c] = arrayEmpleado[c - 1];
            c--;
        }
        arrayEmpleado[c] = aux1;
    }
    for (a=0; a<cant; a++)
    {
        if(arrayEmpleado[a].isEmpty!=VACIO)
        {
            printf("  nombre:%s  apellido:%s  salario:%.2f  sector:%d\n",arrayEmpleado[a].nombre,arrayEmpleado[a].apellido,arrayEmpleado[a].salario,arrayEmpleado[a].sector);
        }
    }
    return 0;
}
int alphabeticalOrderByFalling(Empleado *arrayEmpleado, int cant)
{
    int i;
    int j;
    int a;
    int b;
    int c;
    int d;
    Empleado aux;
    Empleado aux1;
    printf("  ordenado alfabeticamente descendente por apellido:\n");
    for(i = 1; i < cant; i++)
    {
        aux = arrayEmpleado[i];
        j = i;
        while(j > 0 && strcmp( aux.apellido, arrayEmpleado[j - 1].apellido)>0)
        {
            arrayEmpleado[j] = arrayEmpleado[j - 1];
            j--;
        }
        arrayEmpleado[j] = aux;
    }
    for (d=0; d<cant; d++)
    {
        if(arrayEmpleado[d].isEmpty!=VACIO)
        {
            printf("  nombre:%s  apellido:%s  salario:%.2f  sector:%d\n",arrayEmpleado[d].nombre,arrayEmpleado[d].apellido,arrayEmpleado[d].salario,arrayEmpleado[d].sector);
        }
    }
    printf("\n  ordenado alfabeticamente descendente por sector:\n");
    for(b = 1; b < cant; b++)
    {
        aux1 = arrayEmpleado[b];
        c = b;
        while(c > 0 &&  aux1.sector > arrayEmpleado[j - 1].sector)
        {
            arrayEmpleado[c] = arrayEmpleado[c - 1];
            c--;
        }
        arrayEmpleado[c] = aux1;
    }
    for (a=0; a<cant; a++)
    {
        if(arrayEmpleado[a].isEmpty!=VACIO)
        {
            printf("  nombre:%s  apellido:%s  salario:%.2f  sector:%d\n",arrayEmpleado[a].nombre,arrayEmpleado[a].apellido,arrayEmpleado[a].salario,arrayEmpleado[a].sector);
        }
    }
    return 0;
}
void totalAndAverageSalary(Empleado *arrayEmpleado,int cant)
{
    int i;
    float acum=0;
    float prom;
    float cont=0;
    int contDeProm=0;
    for(i=0; i<cant; i++)
    {
        acum=acum+arrayEmpleado[i].salario;
        if(arrayEmpleado[i].isEmpty!=VACIO)
        {
            cont++;
        }
    }
    prom=acum/cont;
    if(arrayEmpleado[i].isEmpty>prom)
    {
        contDeProm++;
    }
    printf("\n  el salario total es:%.2f y el promedio es:%.2f\n",acum,prom);
    printf("\n  los empleados que superaron el salario son:%d\n",contDeProm);
}
