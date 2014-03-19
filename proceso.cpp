#include "proceso.h"
#include <QtCore/QCoreApplication>
#include <stdio.h>
#include <math.h>
#include <deque>
#include "robot.h"
#include<fstream>
using namespace std;
const int MIN_IDENT = 50;
const int MAX_RAD_DIFF = 10;
const int HISTORY_SIZE = 6;
const int X_THRESH = 15;
const int Y_THRESH = 15;
const int R_THRESH = 20;
const int MATCHES_THRESH = 3;
const int HUE_BINS = 32;

Proceso::Proceso(int idCama)
{
    //inicializar la camara con todos sus parametros
    idCam=idCama;
    this->frame =0;
    int cam;
    cam=getIdcam();
    //Se le abre la camara con su Id
    this->capture = cvCaptureFromCAM(cam);
    cvSetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH,640);
    cvSetCaptureProperty(capture,CV_CAP_PROP_FRAME_HEIGHT,480);

    if (this->chkCam()) {
      printf("No se pudo conectar con la camara" );
    }
    //pedir el frame
    this->frame = cvQueryFrame( this->capture );
    //Se crean una ventana de la imagen procesado
    cvNamedWindow( "video_procesado", CV_WINDOW_AUTOSIZE );
    this->storage = cvCreateMemStorage(0);
    this->grayscaleImg = cvCreateImage(cvSize(640, 480), +8/*depth*/, 1/*channels*/);
    this->key= 0;

}
int Proceso::getIdcam()
{
   return this->idCam;
}


bool Proceso::chkCam()
{
    return (this->capture)? true :false;
}


void Proceso::proces_camera(Robot robots[])
{
    cout<<"EL TAMAÑO DEL SAMPLES SERIA "<<this->samples.size()<<endl;
    //Pedir el siguiente frame
    this->frame = cvQueryFrame( this->capture );
    CvSeq* circles = getCirclesInImage(this->frame,  this->storage, this->grayscaleImg);
    cout<<endl<<"EL TAMAÑO DEL    CIRCLES ES "<<circles->total<<endl;
    float radios[2];
    CvPoint centros[2];

    ////*** Ya conte los circulos ahora deberia saber si es modulo de 2 y saber cuantos circulos son :O y luego iterar para hallar la posicion de cada robot***////

    //verifico si no hay circulos impares lo cual demostraria algun tipo de error.
    if(circles->total%2!=0){
        //error de circulos no pueden haber impares
        cout<<endl<<"Los circulos en el frame son impares";
        //break;
    }
    //itera frame por frame despues de conseguir los circulos en la funcion getcircles in image
    for(int i = 0; i < circles->total; i++ ) {
        int matches = 0;
        float* p = (float*)cvGetSeqElem( circles, i );
        float x = p[0];
        centros[i].x=p[0];
        float y = p[1];
        centros[i].y =p[1];
        float r = p[2];
        radios[i] =p[2];
        cout<<"ciclo numero "<<i<<endl;
        cout<<"numero de circulos"<<circles->total<<endl;
        cout<<""<<circles->total<<endl;
        cout<<"radio de la posicion "<<i<<" "<<r<<endl;
        cout<<"posicion"<<x<<" , "<<y<<endl;
        if (x-r < 0 || y-r < 0 || x+r >= this->frame->width || y+r >= this->frame->height) {
          continue;
        }
        for (int j = 0; j < this->samples.size(); j++) {
          CvSeq* oldSample =this-> samples[j];
          for (int k = 0; k < oldSample->total; k++) {
            float* p2 = (float*)cvGetSeqElem( oldSample, k );
            if (circlesBeHomies(p, p2)) {
              matches++;
              break;
            }
          }
        }
        //le color
        if (matches > MATCHES_THRESH) {
            //pasar el frame radio x y
          int highestBinSeen=findCol(this->frame,r,x,y);
          cvResetImageROI(this->frame);
          const char *color;
          color=getColor(highestBinSeen);
          char label[64];
          sprintf(label, "color: %s", color);
          drawCircleAndLabel(this->frame, p, label);
        }
      }
    this->samples.push_back(circles);
    if (this->samples.size() > HISTORY_SIZE) {
        this->samples.pop_front();
    }
    cvShowImage( "video_procesado", this->frame);
    //mostrando la posicion eso espero :D
    //distancia entre radios
    float dist =eucdist(centros[0],centros[1]);
    cout <<"La supuesta distancia seria:"<<dist<<endl;
    //encontrando la posicion segun kelson
    CvPoint pos=find_pos(centros[0],centros[1]);
    cout <<"La posicion del robot es: "<<pos.x <<" , " <<pos.y<<endl;
    //crear un archivo
    fstream file("posiciones.txt");

    //Colocando las posiciones en el Robot
    for (int i=0;i<circles->total;i=+2)
    {
        robots[i].orien_t=find_orien(centros[i],centros[i+1]);
        robots[i].pos_t=find_pos(centros[i],centros[i+1]);
        //guardarlo en un fichero
        //file<<"( "<<robots[i].orien_t.x<<" , "<<robots[i].orien_t.y<<" )"<<"\t"<<"\t"<<robots[i].pos_t<<endl;


    }


}


CvPoint Proceso::find_pos( CvPoint cent1,CvPoint cent2)
{
    CvPoint res;
    res.x=2*(abs(cent1.y-cent2.y));
    res.y=2*(abs(cent1.x-cent2.x));
    return res;
}

CvSeq* Proceso::getCirclesInImage(IplImage* frame, CvMemStorage* storage, IplImage* grayscaleImg) {
  // houghificacion
  // convertir la imagen a escala de grises
  cvCvtColor(frame, grayscaleImg, CV_BGR2GRAY);

  // Usar el filtro de Gauss para reducir el ruido
  cvSmooth(grayscaleImg, grayscaleImg, CV_GAUSSIAN, 7, 9 );

  //Detectar los circulos en el frame
  CvSeq* circles = cvHoughCircles(grayscaleImg,
      storage,
      CV_HOUGH_GRADIENT,
      2,
      grayscaleImg->height/4,
      200,
      100 );
  if (circles->total>0)
      return circles;
  else
      return null;
}

void Proceso::drawCircleAndLabel(IplImage* frame, float* p, const char* label) {
  //dibuja el circulo en la imagen original

  CvFont font;
  cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 1, 1, 0.0, 1, 8);
  cvCircle( frame, cvPoint(cvRound(p[0]),cvRound(p[1])), cvRound(p[2]), CV_RGB(255,0,0), 3, 8, 0 );
  cvPutText( frame, label, cvPoint(cvRound(p[0]),cvRound(p[1])), &font, CV_RGB(255,0,0) );
}

bool Proceso::circlesBeHomies(float* c1, float* c2) {
  return (abs(c1[0]-c2[0]) < X_THRESH) && (abs(c1[1]-c2[1]) < Y_THRESH) &&
      (abs(c1[2]-c2[2]) < R_THRESH);
}

double Proceso::find_orien( CvPoint point1,CvPoint point2)
{
    double orien;
    orien=atan((double)(abs(point1.y-point2.y))/((double)abs(point1.x-point2.x)));
    return orien;
}

float Proceso::eucdist(CvPoint c1, CvPoint c2) {
  float d = sqrt(pow((float)c1.x - c2.x, 2) + pow((float)c1.y - c2.y, 2));
  return d;
}

char* Proceso::getColor(int val){
    char* color;
    switch(val) {
       case 2: case 3: case 4:
           color = "naranja";
       break;
       case 5: case 6: case 7: case 8:
           color = "amarillo";
       break;
       case 9: case 10: case 11: case 12:
       case 13: case 14: case 15: case 16:
           color = "verde";
       break;
       case 17: case 18: case 19: case 20:
       case 21: case 22: case 23:
           color = "azul";
       break;
       case 24: case 25: case 26: case 27:
       case 28:
           color = "morado";
       break;
       default:
           color = "rojo";
    }
return color;
}

int Proceso::findCol(IplImage *frame, float r, float x, float y)
{
    cvSetImageROI(frame, cvRect(x-r, y-r, 2*r, 2*r));
    //se saca un rectangulo de la imagen del ciruclo
    IplImage* copy = cvCreateImage(cvSize(2*r, 2*r), frame->depth, 3);
    cvCvtColor(frame, copy, CV_BGR2HSV);
    //copia en blanco y negro
    IplImage* hue = cvCreateImage(cvGetSize(copy), copy->depth, 1);
    cvCvtPixToPlane(copy, hue, 0, 0, 0);
    int hsize[] = {HUE_BINS};
    float hrange[] = {0,180};
    float* range[] = {hrange};
    IplImage* hueArray[] = {hue};
    //int channel[] = {0};
    CvHistogram* hist = cvCreateHist(1, hsize, CV_HIST_ARRAY, range, 1);
    cvCalcHist(hueArray, hist, 0, 0);
    cvNormalizeHist(hist, 1.0);
    int highestBinSeen = -1;
    float maxVal = -1;
    for (int b=0; b<HUE_BINS; b++) {
      float binVal = cvQueryHistValue_1D(hist, b);
      if (binVal > maxVal) {
        maxVal = binVal;
        highestBinSeen = b;
      }
    }
    return highestBinSeen;
}
