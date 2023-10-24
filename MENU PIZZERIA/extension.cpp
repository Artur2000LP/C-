/*
Integrantes:
-  AYDEE LETONA PORRAS
-  RONALD CRISTHIAN MAMANI RUIZ
-  SHIOMARA IRENE ESPINOZA SANCHEZ
-  HOMERO ELIAS HUAMAN COSTILLA
*/

#include <iostream>
#include <conio.h>
#include "ProcesoVentas.h"
#include <vector>
using namespace std;

int cantidadRegistradaPizzasFamiliar(const vector<Venta>& ventas);
int cantidadRegistradaPizzasMediana(const vector<Venta>& ventas);
int cantidadRegistradaVaronesConDescuentoNeto(const vector<Venta>& ventas);
double montoTotalImporteNeto(const vector<Venta>& ventas);
double montoTotalImporteNetoMujeresPizzaPersonal(const vector<Venta>& venta);
void reporteGeneral(const vector<Venta>& ventas);
double promedioImporteNetoVaronesPizzaTipoMediana(const vector<Venta>& ventas);


int main()
{
  int opcion = 0;
	vector<Venta> ventas = {};
  do
  {

    imprimirMenuPrincipal();
    cin >> opcion;
    switch (opcion)
    {
    case 1:
    {
			Usuario usuario = registroUsuario();
			Pizza pizza = registroPizza();
			Venta venta = registroVenta(usuario,pizza);
      mostrarReporteVenta(venta);
			ventas.push_back(venta);
    }
    break;
    case 2:
			reporteGeneral(ventas);
      break;
    default:
      cout << "HASTA LA VISTA BEIBI..."<< "\n";
      break;
    }
  } while (opcion != 3);

  return EXIT_SUCCESS;
}

int cantidadRegistradaPizzasFamiliar(const vector<Venta>& ventas){
	int acumulador = 0;
	for(int i = 0; i < ventas.size(); ++i){
		if(ventas[i].pizza.tipo == FAMILIAR) ++acumulador;
	}
	return acumulador;
}

int cantidadRegistradaPizzasMediana(const vector<Venta>& ventas){
	int acumulador = 0;
	for(int i = 0; i < ventas.size(); ++i){
    Pizza pizza = ventas[i].pizza;

		if(pizza.tipo == MEDIANA && ventas[i].descuento  == 8){
      ++acumulador;
    }
	}
	return acumulador;
}

int cantidadRegistradaVaronesConDescuentoNeto(const vector<Venta>& ventas){
	int acumulador = 0;
	for(int i = 0; i < ventas.size(); ++i){
    Usuario usuario = ventas[i].usuario;
	  double importeBruto = ventas[i].cantidad * ventas[i].pizza.precio;
    double descuentoNeto = importeBruto * ventas[i].descuento;
		if(usuario.genero == "MASCULINO" && (descuentoNeto>=200 && descuentoNeto<=1500)){
      ++acumulador;
    }
	}
	return acumulador;
}


double montoTotalImporteNeto(const vector<Venta>& ventas){
	double acumulador = 0.0;
	for(int i = 0; i < ventas.size(); ++i){
    Venta venta = ventas[i];
	  double importeBruto = venta.cantidad * venta.pizza.precio;
	  double montoDescuento = importeBruto * venta.descuento / 100;
    acumulador += (importeBruto - montoDescuento);
	}
  return acumulador;
}

double montoTotalImporteNetoMujeresPizzaPersonal(const vector<Venta>& ventas){
  double acumulador = 0.0;
	for(int i = 0; i < ventas.size(); ++i){
    Venta venta = ventas[i];
    if(venta.usuario.genero == "FEMENINO" && venta.pizza.tipo == PERSONAL){
	    double importeBruto = venta.cantidad * venta.pizza.precio;
	    double montoDescuento = importeBruto * venta.descuento / 100;
      acumulador += (importeBruto - montoDescuento);
    }
	}
  return acumulador;
}

double promedioImporteNetoVaronesPizzaTipoMediana(const vector<Venta>& ventas){

  double acumulador = 0.0;
  double sumPizzaMediana = 0;
	for(int i = 0; i < ventas.size(); ++i){
    Venta venta = ventas[i];
    if(venta.usuario.genero == "MASCULINO" && venta.pizza.tipo == MEDIANA){
	    double importeBruto = venta.cantidad * venta.pizza.precio;
	    double montoDescuento = importeBruto * venta.descuento / 100;
      acumulador += (importeBruto - montoDescuento);
      sumPizzaMediana++;
    }
	}
  if(sumPizzaMediana ==0){
    return 0;
  }
  return acumulador/sumPizzaMediana;

  
}

void reporteGeneral(const vector<Venta>& ventas){
  
  cout<< formatTitle("::::::::::  REPORTE GENERAL DE TODAS LAS VENTAS ::::::::::::::")<<"\n \n";
	cout <<"Cantidad de ventas registradas de tipo Familiar: " << cantidadRegistradaPizzasFamiliar(ventas) << std::endl;
	cout <<"Cantidad de ventas registradas de tipo MEDIANA y descuento 8%: " << cantidadRegistradaPizzasMediana(ventas) << std::endl;
  cout <<"Cantidad de ventas registradas de clientes varones cuyo Descuento Neto sea >=200 y <=1500:  "<<cantidadRegistradaVaronesConDescuentoNeto(ventas)<<endl;
	cout <<"Monto Total de importe neto: " << montoTotalImporteNeto(ventas) << std::endl;
	cout <<"Monto total de Importe Neto de los clientes mujeres que compraron pizzas de tipo Personal: " << montoTotalImporteNetoMujeresPizzaPersonal(ventas) << std::endl;
  cout<<"Promedio de Importe Neto de clientes varones que compraron pizzas de tipo Mediana:  "<< promedioImporteNetoVaronesPizzaTipoMediana(ventas)<<"\n"<<endl;
}