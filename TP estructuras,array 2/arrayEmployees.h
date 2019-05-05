#ifndef ARRAYEMPLOYEES_H
#define ARRAYEMPLOYEES_H

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;

}Empleado;

/**\brief muestra las opciones del menu
 *\param ingresa a la opcion que ejecute el usuario
 * \return retorna 0
 */
int functionMenu(void);

/**\brief recorre el array
 *\param inicializa el array en VACIO
 * \return retorna 0 si dios bien o -1 si dio mal
 */
int arrayInialization(Empleado *arrayEmpleado, int cant);

/**\brief recorre el array
 *\param busca VACIO y devuelve la posicion de ese VACIO
 * \return retorna 0 si dios bien o -1 si dio mal
 */
int spaceFinderInTheArray(Empleado *arrayEmpleado,int cant,int *indice);

/**\brief ingreso de los campos
 *\param validacion de los campos
 * \return retorna 0 si dios bien o -1 si dio mal
 */
int employeeIncomeFunction(Empleado *arrayEmpleado,int cant,int posLibre);

/**\brief ingresa un id
 *\param lo busca y devuelva la posicion donde se encuentra
 * \return retorna 0 si dios bien o -1 si dio mal
 */
int searchId (Empleado *arrayEmpleado, int cant, int *idEncontrado);

/**\brief se ingresa id para modificar los campos
 *\param si el id es correcto se modifican y si no sale del programa
 * \return retorna 0 si dios bien o -1 si dio mal
 */
int modifyFields(Empleado *arrayEmpleado,int cant);


/**\brief se ingresa id para dar de baja a un empleado
 *\param si el id es correcto se da de baja y si no sale del programa
 * \return retorna 0
 */
int employeeLow(Empleado *arrayEmpleado,int cant);


/**\brief se recorre el array
 *\param se hace un hintecambio de posicion hasta que quede ordenado el apellido y sector de forma ascendente
 * \return retorna 0
 */
int alphabeticallyOrderedByUpward(Empleado *arrayEmpleado, int cant);


/**\brief se recorre el array
 *\param se hace un hintecambio de posicion hasta que quede ordenado el sector y apellido de forma descendente
 * \return retorna 0
 */
int alphabeticalOrderByFalling(Empleado *arrayEmpleado, int cant);


/**\brief  recorre el array
 *\param saca el salario total ,el primedio y se fija que empleado
 * \param supera el promedio del salario
 * \return retorna void
 */
void totalAndAverageSalary(Empleado *arrayEmpleado,int cant);

#endif

