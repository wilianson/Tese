#ifndef CAPA_H
#define CAPA_H
#include "neuron.h"
#include<vector>

using namespace std;
class Capa
{
    int _n_neurons, _prev_n_neurons;
    vector<Neuron> neuronas;
    float*  salidas;
public:
    Capa(int prev_n_neurons, int n_neurons);
    float* agrega_bias(float* entrada);
    float* evalua(float* entr);
    int getTamanio();
    float getSalidas(int i);
    float getActivacionDerivativa(int i);
    float* getPesos(int i);
    float getPeso(int i,int j);
    void setPeso(int i, int j, float valor);

    int getNumElemFloat(float* array);
};

#endif // CAPA_H
