#include <iostream>
#include <string>
#include "LecturaDatos.h"
#include "ConvierteDatos.h"
#include "Estructuras.h"

using namespace std;

int totalRegistros = 0;
const int MAX_VENTAS = 1000;
TipoDatos ventas[MAX_VENTAS];

int main()
{
    int opcion;
    int resultado1, resultado2, resultado3, resultado4, resultado5, resultado6;

    do
    {
        cout << "\n::::::::: LIBRERIA COLIBRI DORADO ::::::::::" << endl;
        cout << "---------- MENU DE OPCIONES ----------" << endl;
        cout << "[1] REGISTRAR VENTA" << endl;
        cout << "[2] REPORTAR VENTA" << endl;
        cout << "[3] SALIR" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            if (totalRegistros < MAX_VENTAS)
            {
                ventas[totalRegistros].sexo = leerGeneroCliente();
                ventas[totalRegistros].Tlibro = leerTipoLibro();
                ventas[totalRegistros].Clibro = leerCantidadLibros();
                ventas[totalRegistros].nombreCliente = leerNombreCliente();

                int precioLibro = calcularPrecioLibro(ventas[totalRegistros].Tlibro);
                int porcentajeDescuento = calcularPorcentajeDescuento(ventas[totalRegistros].Tlibro, ventas[totalRegistros].Clibro);

                ventas[totalRegistros].montoBruto = precioLibro * ventas[totalRegistros].Clibro;
                ventas[totalRegistros].descuento = calcularMontoDescuento(ventas[totalRegistros].montoBruto, porcentajeDescuento);
                ventas[totalRegistros].montoNeto = calcularMontoNeto(ventas[totalRegistros].montoBruto, ventas[totalRegistros].descuento);

                cout << "\n ::::::  Informe de Venta:  ::::::" << endl;
                cout << "Nombre del Cliente: " << ventas[totalRegistros].nombreCliente << endl;
                cout << "Tipo de Libro: " << obtenerNombreTipoLibro(ventas[totalRegistros].Tlibro) << endl;
                cout << "Cantidad de Libros: " << ventas[totalRegistros].Clibro << endl;
                cout << "Importe Bruto: " << ventas[totalRegistros].montoBruto << endl;
                cout << "Monto de Descuento: " << ventas[totalRegistros].descuento << endl;
                cout << "Importe Neto: " << ventas[totalRegistros].montoNeto << endl;

                totalRegistros++;
            }
            else
                cout << "Maximo de registros alcanzado." << endl;
            break;
        case 2:
            resultado1 = 0;
            resultado2 = 0;
            resultado3 = 0;
            resultado4 = 0;
            resultado5 = 0;
            resultado6 = 0;

            for (int i = 0; i < totalRegistros; i++)
            {
                if (ventas[i].Tlibro == 4)
                    resultado1++;
                if (ventas[i].Tlibro == 1 && ventas[i].descuento == ventas[i].montoBruto * 6 / 100)
                    resultado2++;
                if (ventas[i].sexo == "M" && (ventas[i].descuento >= 200 && ventas[i].descuento <= 2500))
                    resultado3++;
                resultado4 += ventas[i].montoNeto;
                if (ventas[i].sexo == "F" && ventas[i].Tlibro == 2)
                    resultado5 += ventas[i].montoNeto;
                if (ventas[i].sexo == "M" && ventas[i].Tlibro == 3)
                    resultado6 += ventas[i].montoNeto;
            }

            cout<<"\n:::::::::::::::: Reporte Venta :::::::::::::::::::::::::::"<<endl;
            cout << "Cantidad de ventas registradas de libros de Fisica Cuantica: " << resultado1 << endl;
            cout << "Cantidad de ventas registradas de libros de Ficcion que tengan un descuento del 6%: " << resultado2 << endl;
            cout << "Cantidad de ventas registradas de clientes varones cuyo Descuento Neto sea >=200 y <=2500: " << resultado3 << endl;
            cout << "Monto total de Importe Neto: " << resultado4 << endl;
            cout << "Monto total de Importe Neto de los clientes mujeres que compraron libros de Novelas: " << resultado5 << endl;
            cout << "Promedio de Importe Neto de clientes varones que compraron libros de Cuentos: " << (resultado6 == 0 ? 0 : resultado6 / resultado6) << endl;
            break;

        case 3:
            cout << "GRACIAS POR SU COMPRA" << endl;
            break;

        default:
            cout << "Opcion desconocida!" << endl;
            break;
        }
    } while (opcion != 3);

    return 0;
}
