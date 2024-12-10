#include "Libro.h"
#include <iostream>
using namespace std;

Libro::Libro(int numPag, int anoPublicacion, string titulo, string autor)
{
    this->numPag = numPag;
    this->anoPublicacion = anoPublicacion;
    this->titulo = titulo;
    this->autor = autor;
}

Libro::Libro(const Libro &otroLibro)
{
    *this = otroLibro;
}

Libro &Libro::operator=(const Libro &otroLibro)
{
    if (this != &otroLibro)
    {
        this->numPag = otroLibro.numPag;
        this->anoPublicacion = otroLibro.anoPublicacion;
        this->titulo = otroLibro.titulo;
        this->autor = otroLibro.autor;
    }
    return *this;
}

Libro::Libro() : numPag(0), anoPublicacion(0), titulo(""), autor("") {}

void Libro::mostrarInfo()
{
    cout << "Título: " << this->titulo << endl;
    cout << "Número de páginas: " << this->numPag << endl;
    cout << "Año de publicación: " << this->anoPublicacion << endl;
    cout << "Autor: " << this->autor << endl;
}

int Libro::getNumPag()
{
    return numPag;
}

int Libro::getAnoPublicacion()
{
    return anoPublicacion;
}

string Libro::getTitulo()
{
    return titulo;
}
