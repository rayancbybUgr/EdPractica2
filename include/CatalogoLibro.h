/**
 * @file CatalogoLibro.h
 * @brief Declaración de la clase CatalogoLibro, que representa un catálogo de libros.
 */

#ifndef _CATALOGOLIBRO_H
#define _CATALOGOLIBRO_H

#include <string>
#include "Libro.h" 

using namespace std;

/**
 * @class CatalogoLibro
 * @brief Clase que representa un catálogo de libros, permitiendo agregar, buscar y mostrar libros.
 */
class CatalogoLibro
{
private:
    Libro **libros;
    int numLibros;  
public:
    /**
     * @brief Constructor de la clase CatalogoLibro.
     * @param numLibros Número inicial de libros que puede contener el catálogo.
     */
    CatalogoLibro(int numLibros);

    /**
     * @brief Busca un libro en el catálogo por su título.
     * @param titulo Título del libro a buscar.
     * @return Puntero al libro encontrado, o nullptr si no se encuentra.
     */
    Libro *buscarLibro(const string &titulo) const;

    /**
     * @brief Agrega un libro al catálogo.
     * @param libro Libro a agregar al catálogo.
     */
    void agregarLibro(Libro &libro);

    /**
     * @brief Muestra la información de todos los libros en el catálogo.
     */
friend std::ostream& operator<<(std::ostream& os, const CatalogoLibro& catalogo);
    /**
     * @brief Muestra los libros publicados en un año específico.
     * @param ano Año de publicación a buscar.
     */
    void mostrarLibrosPorAno(int ano) const;

    /**
     * @brief Busca el libro con el mayor número de páginas en el catálogo.
     * @return Puntero al libro con el mayor número de páginas, o nullptr si el catálogo está vacío.
     */
    Libro *buscarLibroMasLargo() const;

    /**
     * @brief Destructor de la clase CatalogoLibro. Libera la memoria asignada para los libros.
     */
    ~CatalogoLibro();
};

#endif 
