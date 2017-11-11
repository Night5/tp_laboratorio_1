#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int dni;
    int estado;

}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona persona[], int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona persona[], int, int);

/** \brief Se encarga de mostrar los datos
 *
 * \param De la estructura ePersona
 * \param y controla las iteraciones con el for
 * \return devuelve ePersona
 *
 */
void inicializarPersona(ePersona persona[],int);

 /** \brief Se encarga del alta
  *
  * \param pide los datos
  * \param de todas las persona
  * \return un void
  *
  */
void altaPersona(ePersona persona[], int);

 /** \brief Se encarga de eliminar a las personas
  *
  * \param pide el dni de la persona que deseas borrar
  * \param pide la confirmar o cancelar la operacion
  * \return un void
  *
  */
void borrarPersona(ePersona persona[],int);

/** \brief Muestra
 *
 * \param Se encarga
 * \param de mostrar de forma ordenada los datos
 *
 */
void mostrarPersona(ePersona persona[],int);

/** \brief Ordenar
 *
 * \param Se encarga
 * \param de ordenar a las personas
 *
 */
void ordenarPersona(ePersona persona[],int);

/** \brief Grafico
 *
 * \param
 * \param
 * \return
 */
void graficoPersona(int,int,int);



#endif // FUNCIONES_H_INCLUDED
