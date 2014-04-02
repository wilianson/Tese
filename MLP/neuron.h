#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <cmath>
#include <ctime>
#include <stdio.h>
#include<vector>
#include<iostream>
#include<math.h>
class Neuron
{
    float activacion;
    float* pesosSinapticos;
    const static float lambda = 1.5f;
public:
    Neuron(int prev_n_neurons);
    float activaciones(float* inputs);
    float getActivacionDerivativa();
    float* getPesosSinapticos();
    float getPesoSinaptico(int posicion);
    void setPesoSinaptico(int posicion,float valor);
    int getNumElem(float* array);

};

#endif // NEURON_H
