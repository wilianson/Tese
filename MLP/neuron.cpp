#include "neuron.h"
#include <math.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <stdio.h>
#include<vector>
#include<stdlib.h>

using namespace std;

Neuron::Neuron(int prev_n_neurons)
{
    // each neuron know the weights of each connection
    // with neurons of the previous layer
    pesosSinapticos = new float[prev_n_neurons];
    // set default weights
    for (int i = 0; i < prev_n_neurons; ++i)
        pesosSinapticos[i] = (rand()%10000)/10000.0 - 0.5f;
}
int Neuron::getNumElem(float *array){
    int tam =sizeof(array)/sizeof(float);
    return tam;
}

float Neuron::activaciones(float* entradas){
    activacion = 0.0f;

    if (getNumElem(entradas) == getNumElem(pesosSinapticos)){
    for (int i = 0; i < getNumElem(entradas); ++i) // producto escalar del peso por las entradas
        activacion += entradas[i] * pesosSinapticos[i];
    // phi(activacion), our activation function (tanh(x))
    return 2.0f / (1.0f + (float) exp((-activacion) * lambda)) - 1.0f;
    }
    else
        cout<<"Error en las activaciones "<<endl;
    return -1;
}

float Neuron::getActivacionDerivativa(){
    float expmlx = (float) exp(lambda * activacion);
    return 2 * lambda * expmlx / ((1 + expmlx) * (1 + expmlx));
}
float* Neuron::getPesosSinapticos(){
    return pesosSinapticos;
}
float Neuron::getPesoSinaptico(int posicion){
    return pesosSinapticos[posicion];
}
void Neuron::setPesoSinaptico(int posicion, float valor){
    pesosSinapticos[posicion] = valor;
}
