#ifndef CALCU_H
#define CALCU_H

/**\brief ingresa los operandos
 *\param hace el proceso
 * \return muestra los resultados
 */
int funcionMenu(void);

/**\brief Pide un numero flotante
 *\param guarda el numero1
 * \return retorna el operando1
 */
float ingresarOperando(void);

/**\brief recibe el valor que hay en las dos posiciones de memoria
 *\param los suma
 * \return retorna el resultado de la suma
 */
float sumaDeOperandos( float* operando1,float*  operando2);

/**\brief recibe el valor que hay en las dos posiciones de memoria
 *\param los resta
 * \return retorna el resultado de la resta
 */
float restaDeOperandos( float* operando1,float* operando2);

/**\brief recibe el valor que hay en las dos posiciones de memoria
 *\param se fija si el divisor es mayor a 0,
 *\param si es mayor los divide y sino cancela la operacion
 * \return retorna el resultado de la division
 */
float divisionDeOperandos( float *operando1,float  *operando2);

/**\brief recibe el valor que hay en las dos posiciones de memoria
 *\param los multiplica
 * \return retorna el resultado de la multiplicacion
 */
float multiplicacionDeOperandos( float *operando1,float *operando2);

/**\brief recibe el valor que hay en las dos posiciones de memoria
 *\param se fija si el numero es mayor a 0
 *\param y si lo es lo factorea
 * \return retorna el resultado del factoreo
 */
float factorialDeLosOperandos( float *operando1,float *operando2);

#endif


