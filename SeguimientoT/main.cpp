#include <QCoreApplication>
#include <stdio.h>
#include<stdlib.h>
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

    Proceso camara1(1);
    Robot robots[1];
    int key=0;
    FILE *Pos;/*El manejador de archivo*/
    Pos=fopen("Posicion.dat", "w");
    FILE *Orie;/*El manejador de archivo*/
    Orie=fopen("Orientacion.dat", "w");

    int cont=0;
    while (key!=27)
    {

        camara1.proces_camera(robots);
        key = cvWaitKey( 1 );
        cont++;
    }

    cout<<"Las veces que se estuvo son: "<<cont<<endl;
    if(Pos==NULL&&Orie==NULL){
        cout<<"El archivo ha sido fuentes"<<endl;//el archivo fuentes
    }
    else{
        for(int i=0;i<camara1.posiciones.size();i++)
        {
            cout<<"ciclo numero "<<i<<endl;
            cout<<camara1.posiciones[i].x<<" , " <<camara1.posiciones[i].y<<endl;
            cout<<camara1.orientaciones[i]<<endl;
            fprintf(Pos,"%d %d %f\n", camara1.posiciones[i].x,camara1.posiciones[i].y,camara1.orientaciones[i]);
            //poner en cero decimales, porque por alguna extraña razon el matlab solo quiere enteros pa no separarlos
            fprintf(Orie," %4.0f\n", camara1.orientaciones[i]*1000000);
        }
    }
    fclose(Orie);
    fclose(Pos);
    cout<<"Tamaños de orientaciones "<<camara1.orientaciones.size()<<endl;
    cout<<"Tamaños de posiciones "<<camara1.posiciones.size()<<endl;
    return 0;

}
