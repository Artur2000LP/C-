
#include <iostream>

#include <iomanip>
using namespace std;
struct tienda{
	char nombre[50];
	char cliente[50];	
	char nmbobj1[20];
	char nmbobj2[20];
	char nmbobj3[20];
	int bj1;
	int bj2;
	int bj3;	
	float pago;
}venta[100];
int main(int argc, char *argv[]) {
	int i,n;
	cout<<"ingrese la cantidad de numeros ";
	cin>>n;
	for(i=1;i<=n;i++){
		cout<<"la la cantidad de venta=>"<<i<<endl;
		cout<<"ingrese el nobre del vendedor "; cin>>venta[i].nombre;
		cout<<"ingrese el nombre del cliente "; cin>>venta[i].cliente;		
		cout<<"nombre del objeto1 "; cin>>venta[i].nmbobj1;
		cout<<"nombre del objeto2 "; cin>>venta[i].nmbobj2;
		cout<<"nombre del objeto3 "; cin>>venta[i].nmbobj3;
		cout<<"$ del objeto1 "; cin>>venta[i].bj1;
		cout<<"$ del objeto2 "; cin>>venta[i].bj2;
		cout<<"$ del objeto3 "; cin>>venta[i].bj3;		
		venta[i].pago=(venta[i].bj1+venta[i].bj2+venta[i].bj3);
		
	}
	cout<<setw(15)<<"vendedor";
	cout<<setw(15)<<"cliente";	
	cout<<setw(15)<<"nomb objeto1";
	cout<<setw(15)<<"nomb objeto2";
	cout<<setw(15)<<"nomb objto3";
	cout<<setw(15)<<"pago total"<<endl;
	for(i=1;i<=n;i++){
		cout<<setw(15)<<venta[i].nombre;
		cout<<setw(15)<<venta[i].cliente;		
		cout<<setw(15)<<venta[i].nmbobj1;
		cout<<setw(15)<<venta[i].nmbobj2;
		cout<<setw(15)<<venta[i].nmbobj3;
		cout<<setw(15)<<venta[i].pago<<endl;
	}
	return 0;
}
