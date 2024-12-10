#include "CatalogoLibro.h"
#include <iostream>

using namespace std;

CatalogoLibro::CatalogoLibro(int numLibros)
{
    this->numLibros = numLibros;
    libros = new Libro *[numLibros];
    for (int i = 0; i < numLibros; i++)
    {
        libros[i] = nullptr;
    }
}

void CatalogoLibro::agregarLibro(Libro &libro)
{
    for (int i = 0; i < numLibros; ++i)
    {
        if (libros[i] == nullptr)
        {
            libros[i] = new Libro(libro);
            return;
        }
    }

    int nuevoTamano = numLibros + 1;
    Libro **nuevoArray = new Libro *[nuevoTamano];

    for (int i = 0; i < numLibros; ++i)
    {
        nuevoArray[i] = libros[i];
    }

    for (int i = numLibros; i < nuevoTamano; ++i)
    {
        nuevoArray[i] = nullptr;
    }

    delete[] libros;
    libros = nuevoArray;
    numLibros = nuevoTamano;

    libros[numLibros - 1] = new Libro(libro);
}

Libro *CatalogoLibro::buscarLibro(const string &titulo) const
{
    for (int i = 0; i < numLibros; ++i)
    {
        if (libros[i] != nullptr && libros[i]->getTitulo() == titulo)
        {
            return libros[i];
        }
    }
    cout << "Libro no encontrado en el catálogo." << endl;
    return nullptr;
}

std::ostream &operator<<(std::ostream &os, const CatalogoLibro &catalogo)
{
    for (int i = 0; i < catalogo.numLibros; ++i)
    {
        if (catalogo.libros[i] != nullptr)
        {
            os << i << ". ";
            catalogo.libros[i]->mostrarInfo();
            os << endl;
        }
    }
    return os;
}

void CatalogoLibro::mostrarLibrosPorAno(int ano) const
{
    bool encontrado = false;
    for (int i = 0; i < numLibros; ++i)
    {
        if (libros[i] != nullptr && libros[i]->getAnoPublicacion() == ano)
        {
            libros[i]->mostrarInfo();
            cout << endl;
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        cout << "No se encontraron libros publicados en el año " << ano << "." << endl;
    }
}

Libro *CatalogoLibro::buscarLibroMasLargo() const
{
    Libro *libroMasLargo = nullptr;
    for (int i = 0; i < numLibros; ++i)
    {
        if (libros[i] != nullptr)
        {
            if (libroMasLargo == nullptr || libros[i]->getNumPag() > libroMasLargo->getNumPag())
            {
                libroMasLargo = libros[i];
            }
        }
    }
    return libroMasLargo;
}

CatalogoLibro::~CatalogoLibro()
{
    for (int i = 0; i < numLibros; ++i)
    {
        delete libros[i];
    }
    delete[] libros;
}
