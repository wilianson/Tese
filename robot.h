#ifndef ROBOT_H
#define ROBOT_H

#include <QtCore/QCoreApplication>
#include <stdio.h>
#include <math.h>
#include <deque>
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv/cxcore.h"
class Robot
{
    public:
    Robot();
    double orien_t;
    double orien_t1;
    double radPri; //radio de circulo primario
    double radSec; // radio circulos secundario
    CvPoint cenPri; //centro de circulo primario
    CvPoint cenSec; //centro de circulo secundario
    CvPoint pos_t;
    CvPoint pos_t1;
    void set_pos_t(CvPoint);
    void set_pos_t1(CvPoint);
    void set_orien_t(double);
    void set_orien_t1(double);
    void set_radSec(double);
    void set_radPri(double );
    void set_cenPri(CvPoint );
    void set_cenSec(CvPoint );
    CvPoint get_cenSec();
    CvPoint get_cenPri();
    CvPoint get_pos_t();
    CvPoint get_pos_t1();
    double get_radPri();
    double  get_radSec();
    double get_orien_t();
    double get_orien_t1();

};

#endif // ROBOT_H

