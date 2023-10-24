#include<string>
using namespace std;


const string PERSONAL = "personal";
const string MEDIANA = "mediana";
const string FAMILIAR = "familiar";
const string DEMASIADO = "demasiado";


struct Usuario{
	string nombre;
	string dni;
	string genero;
};


struct Pizza
{
  string tipo;
  double precio;
};



Usuario convertirUsuario(string nombre,string dni, string genero){
	Usuario usuario;
	usuario.nombre = nombre;
	usuario.dni = dni;
	usuario.genero = genero;
	return usuario;
}

Pizza convertirPizza(string tipoPizza){
	if(tipoPizza == PERSONAL) return {PERSONAL,10.0};
	if(tipoPizza == MEDIANA) return {MEDIANA,17.0};
	if(tipoPizza == FAMILIAR) return {FAMILIAR,60.0};
	return {DEMASIADO,95.0};
} 

