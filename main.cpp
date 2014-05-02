#include <QCoreApplication>
#include <stdio.h>
#include <math.h>
#include <deque>
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv/cxcore.h"
#include <proceso.h>
#include "robot.h"
#include <fstream>
using namespace std;
using namespace cv;
#define g 9.81
double x,y,z,t=0;
double velcdad,anglo;
double h=0.1,T=10;

int main()
{

    Proceso camara1(0);
    Robot robots[1];
    int key=0;
    ofstream file_pos("Posicion_Procesamiento.dat");
    ofstream file_orie;
    file_orie.open("Orientacion_Procesamiento.txt", ofstream::out);
    int cont=0;
    while (key!=27)
    {

        camara1.proces_camera(robots);
        key = cvWaitKey( 1 );
        cont++;
    }

    cout<<"Las veces que se estuvo son: "<<cont<<endl;
    for(int i=0;i<camara1.posiciones.size();i++)
    {
        cout<<"ciclo numero "<<i<<endl;
        //file_pos<<camara1.posiciones.at(i)<<endl;
        //file_orie. write('d');
        cout<<camara1.orientaciones[i]<<endl;

    }

    file_pos.close();
    file_orie.close();

    FILE *archivo;/*El manejador de archivo*/
    archivo=fopen("prueba.txt", "w");
    if(archivo==NULL){
        cout<<"El fucvking archivo no se puede"<<endl;
    }
    else{
        printf("Fichero creado(ABIERTO) \n");
        velcdad=12;
        anglo=15.3;
            while(t<T){
                x=velcdad*anglo*t;
                y=velcdad*anglo*t;
                z=velcdad*anglo*t-0.5*g*(t*t);
                t=t+h;
                fprintf(archivo,"(%lf, %lf, %lf)",x,y,y); //Escribimos en el archivo las coordenadas
            }/*Fin del while*/
            fclose(archivo);/*Cerramos el archivo*/
            return 0;

    }

}
