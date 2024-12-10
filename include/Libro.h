/**
 * @file Libro.h
 * @brief Declaración de la clase Libro que representa un libro con información básica.
 */

#ifndef _LIBRO_H
#define _LIBRO_H

#include <string>

using namespace std;

/**
 * @class Libro
 * @brief Clase que representa un libro con atributos como número de páginas, año de publicación, título y autor.
 */
class Libro
{
private:
    int numPag;         /**< Número de páginas del libro */
    int anoPublicacion; /**< Año de publicación del libro */
    string titulo;      /**< Título del libro */
    string autor;       /**< Autor del libro */

public:
    /**
     * @brief Constructor parametrizado de la clase Libro.
     * @param numPag Número de páginas del libro.
     * @param anoPublicacion Año de publicación del libro.
     * @param titulo Título del libro.
     * @param autor Autor del libro.
     */
    Libro(int numPag, int anoPublicacion, string titulo, string autor);

    /**
     * @brief Constructor de copia de la clase Libro.
     * @param otroLibro Objeto de tipo Libro a copiar.
     */
    Libro(const Libro &otroLibro);

    /**
     * @brief Sobrecarga del operador de asignación.
     * @param otroLibro Objeto de tipo Libro a asignar.
     * @return Referencia al objeto Libro actual.
     */
    Libro &operator=(const Libro &otroLibro);

    /**
     * @brief Constructor por defecto de la clase Libro.
     */
    Libro();

    /**
     * @brief Muestra la información del libro en la salida estándar.
     */
    void mostrarInfo();

    /**
     * @brief Obtiene el número de páginas del libro.
     * @return Número de páginas del libro.
     */
    int getNumPag();

    /**
     * @brief Obtiene el año de publicación del libro.
     * @return Año de publicación del libro.
     */
    int getAnoPublicacion();

    /**
     * @brief Obtiene el título del libro.
     * @return Título del libro.
     */
    string getTitulo();
};

#endif // _LIBRO_H
