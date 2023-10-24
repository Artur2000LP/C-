#ifndef LECTURADATOS_H
#define LECTURADATOS_H

#include <iostream>
#include <string>
using namespace std;

string leerGeneroCliente();
int leerTipoLibro();
int leerCantidadLibros();
string leerNombreCliente();

string leerGeneroCliente()
{
    string genero;
    do
    {
        cout << "Ingrese genero del cliente (M o F): ";
        cin >> genero;
    } while (genero != "M" && genero != "F");

    return genero;
}

int leerTipoLibro()
{
    int tipoLibro;
    do
    {
        cout <<"Ingrese tipo de Libro:"<<endl;
        cout <<"[1] -Ficcion"<<endl;
        cout <<"[2] -Novelas"<<endl;
        cout <<"[3] -Cuentos"<<endl;
        cout <<"[4] -Fisica Cuantica"<<endl;
        cout <<"Ingrerse Una Opcion: ";
        cin >> tipoLibro;
    } while (tipoLibro < 1 || tipoLibro > 4);

    return tipoLibro;
}

int leerCantidadLibros()
{
    int cantidad;
    do
    {
        cout << "Ingrese cantidad de libros: ";
        cin >> cantidad;
    } while (cantidad <= 0);

    return cantidad;
}

string leerNombreCliente()
{
    string nombre;
    cout << "Ingrese nombre del cliente: ";
    cin.ignore(); // Limpiar el buffer del teclado
    getline(cin, nombre); // Leer el nombre completo del cliente
    return nombre;
}

#endif // LECTURADATOS_H
