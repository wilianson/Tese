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
    // cada neuron sabe los pesos de cada coneccion con los neurones de la capa anterior
    //pesosSinapticos = new float[prev_n_neurons];
    // dar los pesos por defecto

    for (int i = 0; i < prev_n_neurons; ++i)
    {
        pesosSinapticos.push_back( (rand()%10000)/10000.0 - 0.5f);
        cout<<" el peso en con el neuron " << pesosSinapticos[i]   <<endl;
    }
    cout<<"El tamaño del neuron es "<<pesosSinapticos.size()<<endl;
}

float Neuron::activaciones(vector <float> entradas){
    activacion = 0.0f;

    cout<<"El tamaño de la entrada es: "<<sizeof(entradas)/sizeof(entradas[0]);
    if (entradas.size() == pesosSinapticos.size()){
    for (int i = 0; i < entradas.size(); ++i) // producto escalar del peso por las entradas
        activacion += entradas.at(i) * pesosSinapticos.at(i);
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
vector<float> Neuron::getPesosSinapticos(){
    return pesosSinapticos;
}
float Neuron::getPesoSinaptico(int posicion){
    return pesosSinapticos.at(posicion);
}
void Neuron::setPesoSinaptico(int posicion, float valor){
    pesosSinapticos.at(posicion) = valor;
}
