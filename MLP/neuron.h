#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <cmath>
#include <ctime>
#include <stdio.h>
#include<vector>
#include<iostream>
#include<math.h>
//#include<array>
using namespace std;
class Neuron
{
    float activacion;
    //array <float> pesosSinapticos;
    vector<float> pesosSinapticos;
    //float* pesosSinapticos;
    const static float lambda = 1.5f;
public:
    Neuron(int prev_n_neurons);
    float activaciones(vector<float>);
    float getActivacionDerivativa();
    vector<float> getPesosSinapticos();
    float getPesoSinaptico(int posicion);
    void setPesoSinaptico(int posicion,float valor);
    int getNumElem(float* array);

};

#endif // NEURON_H
