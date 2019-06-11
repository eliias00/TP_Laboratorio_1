#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief crea un empleado en memoria
 *
 * \param void
 * \return employee
 *
 */
Employee* employee_new();

/** \brief retorna el puntero al empleado
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return retorno
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief elimina el empleado en memoria
 *
 * \param auxEmployee Employee*
 * \return void
 *
 */
void employee_delete(Employee *auxEmployee);

/** \brief setea el valor
 *
 * \param auxEmployee Employee*
 * \param int id
 * \return int
 *
 */
int employee_setId(Employee* this,int id);

/** \brief toma el valor
 *
 * \param auxEmployee Employee*
 * \param int* id
 * \return int
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief setea el valor
 *
 * \param auxEmployee Employee*
 * \param char* nombre
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief toma el valor
 *
 * \param auxEmployee Employee*
 * \param char* nombre
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief setea el valor
 *
 * \param auxEmployee Employee*
 * \param int horasTrabajadas
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief toma  el valor
 *
 * \param auxEmployee Employee*
 * \param int* horasTrabajadas
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief setea el valor
 *
 * \param auxEmployee Employee*
 * \param int sueldo
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief toma el valor
 *
 * \param auxEmployee Employee*
 * \param int* sueldo
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief setea el valor como char
 *
 * \param auxEmployee Employee*
 * \param char* id
 * \return int
 *
 */
int Employee_setIdStr(Employee* this, char *id);

/** \brief setea el valor como char
 *
 * \param auxEmployee Employee*
 * \param char* sueldo
 * \return int
 *
 */
int Employee_setSueldoStr(Employee* this, char *sueldo);

/** \brief setea el valor como char
 *
 * \param auxEmployee Employee*
 * \param char* horasTrabajadas
 * \return int
 *
 */
int Employee_setHorasTrabajadasStr(Employee* this, char *horasTrabajadas);

/** \brief compara los nombres
 *
 * \param void* this1
 * \param void* this2
 * \return int
 *
 */
int employee_compararPorNombre(void *this1,void *this2);

/** \brief busca el proximo id en la linkedlist
 *
 * \param LinkedList* pArrayListEmployee
 * \return int
 *
 */
int generadorId(LinkedList* pArrayListEmployee);

/** \brief se comparan dos id y se retorna la pocision de donde esta ese id
 *
 * \param LinkedList* pArrayListEmployee
 * \return int
 *
 */
int buscaId (LinkedList* pArrayListEmployee, int *idEncontrado);

#endif // employee_H_INCLUDED
