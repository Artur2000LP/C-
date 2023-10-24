#include "ConvierteDatos.h"
#include "LecturaDatos.h"

using namespace std;

struct Venta{
	Usuario usuario;
	Pizza pizza;
	int cantidad;
	int descuento;
};

struct Descuento{
	int nivel1;
	int nivel2;
	int nivel3;
};


Usuario registroUsuario(){
	string nombre = lecturaNombre();
	string dni = lecturaDNI();
	string genero = lecturaGenero();
	return convertirUsuario(nombre, dni, genero);
}

Pizza registroPizza(){
	string tipoPizza = lecturaTipoPizza();
	return convertirPizza(tipoPizza);
}

Descuento obtenerDescuentos(string tipoPizza){
	if(tipoPizza == PERSONAL) return {5,6,8};
	if(tipoPizza == MEDIANA) return {8,10,12};
	if(tipoPizza == FAMILIAR) return {9,15,17};
	return {12,12,15};
}

int generarDescuento(int cantidad,string tipoPizza){
	Descuento descuentos = obtenerDescuentos(tipoPizza);
	if(cantidad == 1 || cantidad == 2) return descuentos.nivel1;
	if(cantidad >= 3 && cantidad <= 6) return descuentos.nivel2;
	return descuentos.nivel3;
}


Venta registroVenta(Usuario usuario, Pizza pizza){
	Venta venta;
	venta.usuario = usuario;
	venta.pizza = pizza;
	venta.cantidad = lecturaCantidadPizza();
	venta.descuento = generarDescuento(venta.cantidad,venta.pizza.tipo);
	return venta;
}

void mostrarReporteVenta(Venta venta){
  cout<<formatTitle(" REPORTE ") << endl;
	cout<< "Nombre del cliente:   " << venta.usuario.nombre << '\n';
	double importeBruto = venta.cantidad * venta.pizza.precio;
	double montoDescuento = importeBruto * venta.descuento / 100;
	cout << "Importe Bruto:      " << importeBruto << '\n';
	cout << "Monto descuento:    " << montoDescuento << '\n';
	cout << "Importe Neto:       " << importeBruto - montoDescuento << '\n'; 
}

