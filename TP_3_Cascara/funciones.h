
#define FUNCIONES_H_INCLUDED

#define A 3

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[50];
    int estado;
    int idPelicula;

}eMovie;

/** \brief reserva espacio en memoria
 *
 * \return puntero a la estructura de eMovie
 *
 */
eMovie* nuevaPelicula();

/** \brief Pide los datos de la pelicula
 *
 * \param pide id, titulo, genero, duracion
 * \param descripcion, puntaje, link de imagen
 * \return retorno
 *
 */
int agregarDatosPelicula(eMovie*);

/** \brief muestra todos los datos
 *
 * \param de la estructura eMovie
 * \return void
 */
void mostrarPelicula(eMovie*);

/** \brief agrega una pelicula al archivo
 *
 * \param pelicula de la estructura
 * \param
 * \return
 */
int agregarPelicula(eMovie* pelicula, FILE* archivo);

/** \brief Se encarga de borrar la pelicula ingresada
 *
 * \return
 *
 */
void borrarPelicula(eMovie*);

/** \brief Se encarga de modificar
 *
 * \param
 * \param
 * \return
 *
 */

void modificarPelicula(eMovie*);
