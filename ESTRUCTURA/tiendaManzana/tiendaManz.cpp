/*examen:  desarrolle un programa en c++ que muetre un menu y permita el ingreso de datos de n clientes 
            que compran de una fruteria (Manzanas). el sistema debe calcular el descuento por compra en kilos 
            (1 kilo = s/ 7.30) de acuerdo con el sigiente tabla.
            Numero de kg comprados       % descuento
            0-5                           0%
            5.1-10                        10%
            10.1-en adelante              15%

            los datos del cliente son:
                - nombre y apellidos 
                - edad
            determine :
                a. la cantidad de clientes que realizaron la compra
                b. la cantidad de clientes mayores a 18 años 
                c. la cantidad de kilos vendidos 
                d. el monto de descuento aplicado (de descuento con la tabla anterior).
            solucion
*/

#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
using namespace std;


struct DatosVenta{
    char nombreCli[50];
	char apellidosCli[50];	
	int edadCli;
    float kgManzana;
    float PrecioDescuento;
    float pago;

}venta[100];
char NombVendedor[50];
float precio;
string si = "si",no = "no",op;
int n,cont,aux;
float precioManzaKg,ManzanaKg,DescuentoAplicado,PagoObtenido;



int main(int argc, char *argv[]) {
	
    int menu;
 
    do{
        cout<<"MENU DE OPCIONES"<<endl;
        cout<<"[1]  REALIZAR COMPRA "<<endl;
        cout<<"[2]  REPORTE DE COMPRA "<<endl;
        cout<<"[3]  SALIR"<<endl;
        cin>>menu;
        switch(menu){
            case 1:
                cout<<"ingrese el nobre del vendedor "; cin>>NombVendedor;
                int i;
                n=1,cont = 1,aux =1;;
                precioManzaKg = 7.30f;
                
        
                for(i=1;i<=n;i++){
                    cout<<"venta =>"<<i<<endl;
                    cout<<"ingrese el nombre del cliente "; cin>>venta[i].nombreCli;		
                    cout<<"Ingrese el apellido del cliente "; cin>>venta[i].apellidosCli;
                    cout<<"Ingrese edad del cliente  "; cin>>venta[i].edadCli;
                    cout<<"cantidad de Manzanas en Kg "; cin>>venta[i].kgManzana;
                    ManzanaKg = venta[i].kgManzana;
                	if(venta[i].kgManzana>=0 && venta[i].kgManzana<=5){
                         precio = precioManzaKg*venta[i].kgManzana;
                         //0% = 0
                         venta[i].PrecioDescuento = 0*precio;
                         DescuentoAplicado=venta[i].PrecioDescuento;
                    }else{
                        if(venta[i].kgManzana>=5.1 && venta[i].kgManzana<=10){
                            precio = precioManzaKg*venta[i].kgManzana;
                            // 10% = 0.1
                            venta[i].PrecioDescuento = 0.1*precio;
                            DescuentoAplicado=venta[i].PrecioDescuento;
                        }else{
                            if(venta[i].kgManzana>=10.1){
                                precio = precioManzaKg*venta[i].kgManzana;
                                // 15% = 0.15
                                venta[i].PrecioDescuento = 0.15*precio;
                                DescuentoAplicado=venta[i].PrecioDescuento;
                            }
                        }
                    }
                    
                    
                    venta[i].pago= precio - venta[i].PrecioDescuento ;
                    PagoObtenido = venta[i].pago;

                    cout<<"Desea continuar ?"<<endl;
                    cout<<"si / no"<<endl;
                    cin>>op;
                    if(op==si){
                        n++;
                        cont++;
                    }else{
                        cout<<"Gracias por su compra "<<endl;
                        cout<<"                          Datos de Compras "<<endl;
                    }              
                }
                cout<<setw(15)<<"Clientes";
                cout<<setw(15)<<"Apellidos";	
                cout<<setw(15)<<"edad";
                cout<<setw(15)<<"Manzanas(Kg)";
                cout<<setw(15)<<"Descuento";
                cout<<setw(15)<<"pago total"<<endl;

                for(i=1;i<=n;i++){
                cout<<setw(15)<<venta[i].nombreCli;		
                cout<<setw(15)<<venta[i].apellidosCli;
                cout<<setw(15)<<venta[i].edadCli;
                cout<<setw(15)<<venta[i].kgManzana;
                cout<<setw(15)<<venta[i].PrecioDescuento;
                cout<<setw(15)<<venta[i].pago<<endl;
         	    }
                cout<<"\n";
                //mayores de 18 años 
                
                if(venta[i].edadCli>=18){
                    aux++;
                }
            break;
            case 2:
                cout<<"cantidad = "<<cont<<endl;
                cout<<"cantidad de Clientes                "<<cont<<endl;
                cout<<"Clientes mayores de 18 de edad      "<<aux <<endl;
                cout<<"Total de Kilos Vendidos             "<<cont*ManzanaKg<<endl;
                cout<<"Total de monto Descuento aplicado   "<<cont*DescuentoAplicado<<endl;
                cout<<"total de pago optenido              "<<cont*PagoObtenido<<endl;

               
            break;
        }
    }while(menu != 3);

	return 0;
}
