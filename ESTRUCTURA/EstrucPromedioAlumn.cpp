/*2 hacer una estructura llamada alumnos, en el cual se tendran los sigientes 
campos: Nombre, Edad, Promedio, pedir datos al usuario para tres alumnos comprobar cuan de los tres tiene 
el mejor promedio y posterior mente imprimer los datos del alumno.*/

#include<iostream>
#include<conio.h>
using namespace std;
struct Alumnos{
    char nombre[30];
    int edad;
    float promedio;
    
}alumno[3];

int main(){
    float mayor=0;
    int pos;
    for(int i=0; i<3;i++){
        fflush(stdin);
        cout<<"Alumno "<<i+1<<endl;
        cout<<"["<<i+1<<"]"<<" Digite su nombre: "; 
        cin.getline(alumno[i].nombre,30,'\n');
        cout<<"["<<i+1<<"]"<<" Digite su edad: "; 
        cin>>alumno[i].edad;
        cout<<"["<<i+1<<"]"<<" Digite su Promedio "; 
        cin>>alumno[i].promedio;
        cout<<"\n";

        // comprobando cual de los 3 alumnos tiene el mejor promedio
        if(alumno[i].promedio > mayor){
            mayor = alumno[i].promedio;
            pos = i;
        }

    }
    //imprima datos del mayor promedio
    cout<<"El Dato del Alumno con el Mayor Pomedio"<<endl;
    cout<<"\nNombre: "<<alumno[pos].nombre<<endl;
    cout<<"Edad: "<<alumno[pos].edad<<endl;
    cout<<"Promedio: "<<alumno[pos].promedio<<endl;
    cout<<"\n";

    getch();
    return 0;

}