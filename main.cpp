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

int main()
{

        Proceso camara1(1);
        Robot robots[1];
        int key=0;
        ofstream file_pos("Posicion_Procesamiento.dat");
        ofstream file_orie("Orientacion_Procesamiento.dat");
        int cont=0;
        while (key!=27)
        {

             camara1.proces_camera(robots);
             key = cvWaitKey( 1 );
             file_pos<<robots[0].pos_t.x<<" "<<robots[0].pos_t.y<<endl;
             file_orie<<cont<<" "<<robots[0].orien_t<<endl;
             cont++;
        }

        cout<<"Las veces que se estuvo son: "<<cont<<endl;
        file_pos.close();
        file_orie.close();





}
