#include <iostream>
#include "Libro.h"
#include "CatalogoLibro.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/**
 * @brief Programa principal que gestiona un catálogo de libros.
 *
 * Este programa lee un archivo de texto que contiene información sobre libros
 * y la almacena en un catálogo. Luego muestra el catálogo y busca el libro más largo.
 *
 * @return int Código de salida del programa.
 */
int main()
{
    int respuesta1 = -1; 
    int respuesta2 = -1;
    while (respuesta1 != 0)
    {
        cout << "Libreria Online" << endl;
        cout << "---------------------------" << endl;
        cout << "¿Qué catalogo deseas leer? Introduzca el número o 0 para salir" << endl;
        cout << "1-Classic" << endl;
        cout << "2-Fantasy" << endl;
        cout << "3-Scifi" << endl;
        cout << "---------------------------" << endl;
        cin >> respuesta1;
        cout << "  " << endl;

        
      

        cout << "---------------------------" << endl;

        ifstream file;
        if (respuesta1 == 1)
            file.open("classic.txt");
        else if (respuesta1 == 2)
            file.open("fantasy.txt");
        else if (respuesta1 == 3)
            file.open("scifi.txt");
        else
        {
            cout << "Opción no válida. Por favor, seleccione una opción correcta." << endl;
            continue;
        }

        CatalogoLibro catalogo(5);

        if (!file.is_open())
        {
            cout << "No se pudo abrir el archivo" << endl;
            return 1;
        }

        string line;
        while (getline(file, line))
        {
            string titulo, autor, strNumPag, strAnoPublicacion;
            int numPag, anoPublicacion;

            stringstream ss(line);
            getline(ss, titulo, ',');
            getline(ss, autor, ',');
            getline(ss, strNumPag, ',');
            getline(ss, strAnoPublicacion);

            numPag = stoi(strNumPag);
            anoPublicacion = stoi(strAnoPublicacion);

            Libro libro(numPag, anoPublicacion, titulo, autor);
            catalogo.agregarLibro(libro);
        }
        file.close();

        respuesta2 = -1;
        while (respuesta2 != 0)
        {
            cout << "  " << endl;
            cout << "¿Qué deseas hacer? Introduzca el número o 0 para salir" << endl;
            cout << "1-Mostrar catalogo" << endl;
            cout << "2-Buscar libro" << endl;
            cout << "3-Libro más largo" << endl;
            cout << "4-Agregar libro" << endl;
            cout << "---------------------------" << endl;
            cin >> respuesta2;
            cout << "  " << endl;

            if (respuesta2 == 1)
            {
                cout << "---------------------------" << endl;
               cout <<catalogo;
                cout << "---------------------------" << endl;
            }
            else if (respuesta2 == 2)
            {
                cout << "  " << endl;
                cout << "Introduzca el título del libro que quieras buscar: " << endl;
                cin.ignore();
                string busquedaLibro;
                getline(cin, busquedaLibro);

                Libro *librobuscar = catalogo.buscarLibro(busquedaLibro);
                if (librobuscar != nullptr)
                {
                    cout << "  " << endl;
                    cout << "El libro que buscas es: ";
                    librobuscar->mostrarInfo();
                    cout << "  " << endl;
                }
                else
                {
                    cout << "No se encontró el libro en el catálogo." << endl;
                }
            }

            else if (respuesta2 == 3)
            {
                cout << "---------------------------" << endl;
                Libro *libromaslargo = catalogo.buscarLibroMasLargo();
                if (libromaslargo)
                {
                    cout << "  " << endl;
                    cout << "El libro más largo es: ";
                    libromaslargo->mostrarInfo();
                    cout << "  " << endl;
                }
                else
                {
                    cout << "No hay libros en el catálogo." << endl;
                }
                cout << "---------------------------" << endl;
            }
            else if (respuesta2 == 4){
                int numPag, anoPublicacion;
                string titulo,autor;
                cout << "Introduzca el titulo: "<<endl;
                cin >> titulo;
                cout << "Introduzca el numero de paginas: "<< endl;
                cin >> numPag;
                cout << "Introduzca el nombre del autor: "<<endl;
                cin >> autor;
                cout << "Introduzca el año de publicacion: "<< endl;
                cin >> anoPublicacion;

                Libro libroAgregar(numPag,anoPublicacion,titulo,autor);
                catalogo.agregarLibro(libroAgregar);

            }
            else if (respuesta2 != 0)
            {
                cout << "Opción no válida. Por favor, seleccione una opción correcta." << endl;
            }
        }
    }
    return 0;
}
