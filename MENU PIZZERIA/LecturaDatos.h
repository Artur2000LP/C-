#include <iostream>
#include "precentacion.h"
#include <regex>
using namespace std;

string lecturaNombre()
{
  regex patronNombre("^[A-Z][a-z]+([ ][A-Z][a-z]+)*$");
  string nombre;
  do{
    cout << "Ingresa el nombre de usuario con los iniciales en Mayuscula: ";
    fflush(stdin);
    getline(cin,nombre);
  }while(!regex_match(nombre,patronNombre));

	//validaciones
  return nombre;
}

string lecturaDNI()
{
  regex patronDni("^[0-9]{8}$");
  string dni;
  do{
    cout<<"Ingrese el DNI del usuario: ";
    cin >> dni;
  }
  while(!regex_match(dni,patronDni));

  return dni;
}

string lecturaGenero()
{
  string genero;
  int opcion=1;
  do{
    imprimirMenuGenero();
    cin >> opcion;
  }while(opcion > 2 || opcion < 1);
  if(opcion == 1) return "FEMENINO";
  return "MACULINO";
}

string lecturaTipoPizza()
{
  string tipos[] = {PERSONAL,MEDIANA,FAMILIAR,DEMASIADO};
  int opcion = 1;
  do
  {
    imprimirMenuTipoPizza();
    cin >> opcion;
  } while (opcion>4 || opcion<1);
  
  return tipos[opcion - 1];
}

int lecturaCantidadPizza()
{
  regex patronDNI("^[1-9][0-9]*$");
  string numString;
  int cantidad;
  do{
    cout << "Ingrese la cantidad de pizzas: ";
    fflush(stdin);
    getline(cin,numString);
  }while(!regex_match(numString, patronDNI));
  cantidad = stoi(numString);
	return cantidad;
}