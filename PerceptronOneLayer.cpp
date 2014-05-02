/*
#include <QCoreApplication>
#include <stdio.h>
#include<vector>
#include<iostream>
#include<math.h>
using namespace std;

double RecalcularPesos(double peso_actual, double salida_esperada, double entrada){
    double wj = peso_actual + 0.5 * salida_esperada * entrada;
    return (wj);
}
int main()
{
    //Declracion de pesos
    vector <double> pesos;
    pesos.push_back(0.0);
    pesos.push_back(0.0);
    pesos.push_back(0.0);
    //Creacion de psos aleatorios
    for(int j=0;j<pesos.size();j++){
        pesos[j]=(rand()%10000)/10000.0;//pesos aleatorios
        cout<<"Peso "<<j<<" = "<<pesos[j]<<endl;
    }
    cout<<"*******************************************************************"<<endl;
    //Salidas que debe aprender
    vector <double> salidas;

    //SALIDAS PARA AND NOT

    salidas.push_back(1);
    salidas.push_back(1);
    salidas.push_back(-1);


    double **entrada;
    int numparinput=3;
    entrada=new double* [numparinput];
    int numinput=3;
    for(int i = 0; i < numparinput; i++)
        entrada[i] = new double [numinput];
    //entradas
    entrada [0][0]=-1;
    entrada [0][1]=-1;
    entrada [0][2]=-1;
    entrada [1][0]=-1;
    entrada [1][1]=1;
    entrada [1][2]=-1;
    entrada [2][0]=1;
    entrada [2][1]=1;
    entrada [2][2]=-1;


    double yi=0; //salida calculada
    int i=0; // control de proceso
    while (i<numinput){
        yi=pesos[0]*entrada[i][0]+pesos[1]*entrada[i][1]+pesos[2]*entrada[i][2];
        if(yi>=0)
            yi=1;
        else
            yi=-1;
        if(yi==salidas[i]){
            cout<<"Entrada* ("<< entrada[i][0]<<"), ("<<entrada[i][1]<< ") Salida ("<<salidas[i]<<") Calculada (Si) "<<yi<<endl;
        }
        else{
            cout<<"Entrada* ("<< entrada[i][0]<<"), ("<<entrada[i][1]<< ") Salida ("<<salidas[i]<<") Calculada (No) "<<yi<<endl;
            cout<<"**************************************Correcion de pesos****************************************"<<endl;
            for(int k=0;k<pesos.size();k++){
                pesos[k]=RecalcularPesos(pesos[i],salidas[i],entrada[i][k]);
                cout<<pesos[k]<<endl;
            }
            cout<<"******************************************************************"<<endl;
            i=-1;
        }
        i++;
    }
}
*/
