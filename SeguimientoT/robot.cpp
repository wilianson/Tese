#include "robot.h"

Robot::Robot()
{
    //inicializar el robot
    pos_t.x=0,pos_t.y=0;
    pos_t1.x=0,pos_t1.y=0;
    orien_t=0;
    orien_t1=0;
    radPri=0;
    radSec=0;
    cenPri.x=0,cenPri.y=0;
    cenSec.x=0,cenSec.y=0;

}
void Robot::set_pos_t(CvPoint pos_t){
    this->pos_t=pos_t;

}
void Robot::set_pos_t1(CvPoint pos_t1){
    this->pos_t1=pos_t1;

}
void Robot::set_orien_t(double orien_t){
    this->orien_t=orien_t;

}
void Robot::set_orien_t1(double orien_t1){
    this->orien_t1=orien_t1;

}


void Robot::set_radPri(double radPri){
    this->radPri=radPri;

}
void  Robot::set_radSec(double radSec){
    this->radSec=radSec;

}
void Robot::set_cenPri(CvPoint cenPri){
    this->cenPri=cenPri;

}
void Robot::set_cenSec(CvPoint cenSec){
    this->cenSec=cenSec;

}


CvPoint Robot::get_pos_t(){
    return this->pos_t;

}
CvPoint Robot::get_pos_t1(){
    return this->pos_t1;
}
double Robot::get_orien_t(){
    return this->orien_t;
}

double Robot::get_orien_t1(){
    return this->orien_t1;
}

double Robot::get_radPri(){
    return this->radPri;

}
double  Robot::get_radSec(){
    return this->radSec;

}
CvPoint Robot::get_cenPri(){
    return this->cenPri;

}
CvPoint Robot::get_cenSec(){
    return this->cenSec;

}
