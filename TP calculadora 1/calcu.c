#include <stdio.h>
#include <stdlib.h>
#include "calcu.h"

int funcionMenu (void)
{
    float operando1;
    float operando2;
    int opcion;
    char respuesta = 's';

    do
    {
        system("color 0C");
        printf ("*-------------------------------------*\n");
        printf ("* (1)INGRESE PRIMER OPERANDO A:%.2f   *\n", operando1);
        printf ("*-------------------------------------*\n");
        printf ("* (2)INGRESE SEGUNDO OPERANDO B:%.2f  *\n", operando2);
        printf ("*-------------------------------------*\n");
        printf ("* (3)CALCULE OPERACIONES              *\n");
        printf ("*    SUMA: A:%.2f + B:%.2f            *\n",operando1,operando2);
        printf ("*    RESTA:  A:%.2f - B:%.2f          *\n",operando1,operando2);
        printf ("*    DIVISION:  A:%.2f / B:%.2f       *\n",operando1,operando2);
        printf ("*    MULTIPLICACION:  A:%.2f * B:%.2f *\n",operando1,operando2);
        printf ("*    FACTORIAL:  A:%.2f ! B:%.2f      *\n",operando1,operando2);
        printf ("*-------------------------------------*\n");
        printf ("* (4)INFORME DE TODOS LOS RESULTADOS  *\n");
        printf ("*-------------------------------------*\n");
        printf ("* (5)SALIR                            *\n");
        printf ("*-------------------------------------*\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            operando1=ingresarOperando();
            break;
        case 2:
            system("cls");
            operando2=ingresarOperando();
            break;
        case 3:
            system("cls");
            printf("CALCULNDO OPERACIONES\nVUELVA AL MENU Y PRECIONE 4 PARA SABER LOS RESULTADOS ");
            break;
        case 4:
            system("cls");
            printf("\nLA SUMA ES: %.2f\n", sumaDeOperandos(&operando1,&operando2));
            printf("\nLA RESTA ES: %.2f\n", restaDeOperandos(&operando1,&operando2));
            divisionDeOperandos(&operando1,&operando2);
            printf("\nLA MULTIPLICACION ES: %.2f\n", multiplicacionDeOperandos(&operando1,&operando2));
            factorialDeLosOperandos(&operando1,&operando2);
            break;
        case 5:
            system("cls");
            printf("PRECIONE n PARA SALIR DE LA CALCULADORA");
            break;
        }
        printf("\nQUIERE VOLVER AL MENU? s/n :");
        fflush(stdin);
        scanf("%c", & respuesta);
        system("cls");
    }
    while(respuesta== 's');
    return 0;
}
float ingresarOperando (void)
{
    float operando;
    printf ("INGRESE OPERANDO: ");
    scanf("%f", &operando);
    return operando;
}
float sumaDeOperandos(float *numero1, float *numero2)
{
    int retorno = -1;

    if(numero1!= NULL && numero2!= NULL)
    {
        return *numero1 + *numero2;
        retorno =0;
    }
    return retorno;
}
float restaDeOperandos(float *numero1, float *numero2)
{
    int retorno = -1;

    if(numero1!= NULL && numero2!= NULL)
    {
        return *numero1 - *numero2;
        retorno =0;
    }
    return retorno;
}
float divisionDeOperandos(float* numero1, float* numero2 )
{
    int retorno = -1;
    float divi;
    if(*numero2!=0 && numero1!=NULL && numero2!=NULL)
    {
        divi = *numero1 / *numero2;
        printf("\nLA DIVISION ES: %.2f\n",divi);
        retorno =0;
    }
    else
    {
        printf("\nNOSE PUEDE DIVIDIR POR 0.\nVUELVE A INGRESAR EL DIVISOR\n");
    }
    return retorno;
}
float multiplicacionDeOperandos(float *numero1, float *numero2)
{
    int retorno = -1;
    if(numero1!= NULL && numero2!= NULL)
    {
        return *numero1 * *numero2;
        retorno =0;
    }
    return retorno;
}
float factorialDeLosOperandos(float *numero1,float *numero2)
{
    float factorDelNumero1=1;
    float factorDelNumero2=1;
    float iNumero1;
    float iNumero2;
    int retorno = -1;
    if(*numero1>0 && numero1!=NULL)
    {
        for(iNumero1=1; iNumero1<= *numero1; iNumero1++)
        {
            factorDelNumero1=factorDelNumero1 * iNumero1;
        }
                retorno =0;
        printf("\nEL FACTOR DEL OPERANDO1 ES: %.2f \n",factorDelNumero1);
    }
    else
    {
    printf("\nNO SE PUEDE SACAR EL FACTORIAL DE 0 Y NUMEROS NEGATIVOS\n");
    }
    if(*numero2>0 && numero2!=NULL)
    {
        for(iNumero2=1; iNumero2<= *numero2; iNumero2++)
        {
            factorDelNumero2=factorDelNumero2 * iNumero2;
        }
                retorno =0;
        printf("\nEL FACTOR DEL OPERANDO2 ES: %.2f \n",factorDelNumero2);
    }
    else
    {
        printf("\nNO SE PUEDE SACAR EL FACTORIAL DE 0 Y NUMEROS NEGATIVOS\n");
    }
    return retorno;
}


