#ifndef CONVERTEDATOS_H
#define CONVERTEDATOS_H

#include <string>
using namespace std;

string obtenerNombreTipoLibro(int tipoLibro);
int calcularPrecioLibro(int tipoLibro);
int calcularPorcentajeDescuento(int tipoLibro, int cantidadLibros);
int calcularMontoDescuento(int precioLibro, int porcentajeDescuento);
int calcularMontoNeto(int montoBruto, int montoDescuento);

const string TIPOS_LIBRO[] = {"Ficcion", "Novelas", "Cuentos", "Fisica Cuantica"};
const int PRECIOS_LIBRO[] = {90, 100, 80, 150};

string obtenerNombreTipoLibro(int tipoLibro)
{
    if (tipoLibro >= 1 && tipoLibro <= 4)
        return TIPOS_LIBRO[tipoLibro - 1];
    else
        return "Desconocido";
}

int calcularPrecioLibro(int tipoLibro)
{
    return PRECIOS_LIBRO[tipoLibro - 1];
}

int calcularPorcentajeDescuento(int tipoLibro, int cantidadLibros)
{
    int porcentajeDescuento = 0;
    if (cantidadLibros >= 1 && cantidadLibros <= 2)
    {
        if (tipoLibro == 1)
            porcentajeDescuento = 5;
        else if (tipoLibro == 2)
            porcentajeDescuento = 8;
        else if (tipoLibro == 3)
            porcentajeDescuento = 9;
        else if (tipoLibro == 4)
            porcentajeDescuento = 2;
    }
    else if (cantidadLibros >= 3 && cantidadLibros <= 6)
    {
        if (tipoLibro == 1)
            porcentajeDescuento = 6;
        else if (tipoLibro == 2)
            porcentajeDescuento = 16;
        else if (tipoLibro == 3)
            porcentajeDescuento = 18;
        else if (tipoLibro == 4)
            porcentajeDescuento = 2;
    }
    else if (cantidadLibros >= 7)
    {
        if (tipoLibro == 1)
            porcentajeDescuento = 8;
        else if (tipoLibro == 2)
            porcentajeDescuento = 32;
        else if (tipoLibro == 3)
            porcentajeDescuento = 36;
        else if (tipoLibro == 4)
            porcentajeDescuento = 4;
    }
    return porcentajeDescuento;
}

int calcularMontoDescuento(int precioLibro, int porcentajeDescuento)
{
    return precioLibro * porcentajeDescuento / 100;
}

int calcularMontoNeto(int montoBruto, int montoDescuento)
{
    return montoBruto - montoDescuento;
}

#endif // CONVERTEDATOS_H
