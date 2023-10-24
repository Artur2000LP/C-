#include <string>
#include <iostream>

std::string formatTitle(const std::string& title){
	return  ":::::::::::::\t" + title + "\t:::::::::::::::";
}

std::string formatOpcion(std::string numeroOpcion,std::string nombreOpcion){
  return "[" +numeroOpcion + "]\t" + nombreOpcion;
}

void imprimirMenuPrincipal(){
	std::cout << formatTitle("MENU PIZZERIA") << "\n";
  std::cout << formatOpcion("1","REGISTRAR VENTA")<<"\n";
  std::cout << formatOpcion("2","REPORTAR VENTA")<<"\n";
  std::cout << formatOpcion("3","SALIR")<<std::endl;
  std::cout << "Digite una Opcion:  ";
 
}

void imprimirMenuTipoPizza(){
    std::cout << formatTitle("TIPOS DE PIZZA") << "\n";
  std::cout << formatOpcion("1","PERSONAL") << "\n";
  std::cout << formatOpcion("2","MEDIANA") << "\n";
  std::cout << formatOpcion("3","FAMILIAR") << "\n";
  std::cout << formatOpcion("4","DEMASIADO") << std::endl;
  std::cout << "Digite una Opcion:  ";
}
void imprimirMenuGenero(){
  std::cout << formatTitle("GENERO") << "\n";
  std::cout << formatOpcion("1","FEMENINO") << "\n";
  std::cout << formatOpcion("2","MASCULINO") << std::endl;
  std::cout << "Digite una Opcion:  ";
}
