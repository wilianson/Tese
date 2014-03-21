#ifndef PROCESO_H
#define PROCESO_H
#include <QtCore/QCoreApplication>
#include <stdio.h>
#include <math.h>
#include <deque>
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv/cxcore.h"
#include "robot.h"
#include <fstream>

using namespace std;
class Proceso
{
    int idCam; //id de camara para real time
    char* nomVid; //nombre de video si es secuencia de video
    int idColor; //id color primario
    char* color; //nombre de color
    double* radPri; //radio de circulo primario
    double* radSec; // radio circulos secundario
    CvPoint* cenPri; //centro de circulo primario
    CvPoint* cenSec; //centro de circulo secundario
    double orien; //orientacion del robot
    bool tipVid; //0 si es secuencia, 1 si es real time XD
    CvCapture *capture;//para capturar los cuadros
    IplImage *frame;//frame para iterar en cada camara
    CvMemStorage* storage ;// //donde se almacenan los ciruclos de Hough
    IplImage* grayscaleImg;//imagen en escala de grises para realizar el filtro de gauss
    deque<CvSeq*> samples;//cola doblemente enlazada para contener los frames
    int key;
    ofstream fs;

public:
    Proceso(int idCama);//constructor de clase si es realtime
    Proceso(char* nomVid);//constructor si es secuencia de video
    CvSeq* getCirclesInImage(IplImage*, CvMemStorage*, IplImage*);
    void drawCircleAndLabel(IplImage*, float*, const char*);
    void drawObjectPosition(IplImage*, CvPoint);
    void drawOrientationAndLabel(IplImage*, double);
    bool circlesBeHomies(float*, float*);
    CvPoint find_pos( CvPoint,CvPoint);
    CvPoint find_pos_trig(CvPoint,CvPoint,double,float);
    CvPoint find_pos_sing(CvPoint,CvPoint);
    void processing_camera(int id_cam,int col);
    float eucdist(CvPoint c1, CvPoint c2);
    char* getColor(int);
    void proces_camera(Robot[]);
    double find_orien( CvPoint point1,CvPoint point2);
    int getIdcam();
    int findCol(IplImage* frame, float r, float x, float y);
    bool chkCam();
    void write_file(char*);




};
#endif // PROCESO_H
