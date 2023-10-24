// estructura basica 

#include <iostream>
#include <conio.h>



struct Info_direccion{
    char direccion[30];
    char ciudad[20];
    char provincia[20];
};

struct Empleado{
    char nombre[20];
    struct Info_direccion dir_empleado;
    double salario;
}empleado[2];

using namespace std;
int main(){

    for(int i=0;i<2;i++){
        fflush(stdin); // vasiar en buffer y permitir digitar los valores        
        cout<<"Dijite su nombre: ";
        cin.getline(empleado[i].nombre,20,'\n');
        cout<<"digite su direccion: ";
        cin.getline(empleado[i].dir_empleado.direccion,30,'\n');
        cout<<"Ciudad: ";
        cin.getline(empleado[i].dir_empleado.ciudad,20,'\n');
        cout<<"Privincia: ";
        cin.getline(empleado[i].dir_empleado.provincia,20,'\n');
        cout<<"Salario: ";
        cin>>empleado[i].salario;
        cout<<"\n";

    }

    //imprimir datos 

    for(int i=0;i<2;i++){
        cout<<"Nombre: "<<empleado[i].nombre<<endl;        
        cout<<"Direccion: "<<empleado[i].dir_empleado.direccion<<endl;        
        cout<<"Ciudad: "<<empleado[i].dir_empleado.ciudad<<endl;       
        cout<<"Privincia: "<<empleado[i].dir_empleado.provincia<<endl;       
        cout<<"Salario: "<<empleado[i].salario;        
        cout<<"\n";

    }


    getch();
    return 0;
}