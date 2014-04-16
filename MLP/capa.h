#ifndef CAPA_H
#define CAPA_H
#include "neuron.h"
#include<vector>

using namespace std;
class Capa
{
    //int num_neu_cap, _prev_n_neurons;
    //vector<Neuron> neuronas;
    //vector<float> salidas;
public:
    int num_neu_cap, _prev_n_neurons;
    vector<Neuron> neuronas;
    vector<float> salidas;

    Capa(int prev_n_neurons, int n_neurons);
    vector<float> agrega_bias(vector<float> entrada);
    vector<float> evalua(vector<float> entr);
    int getTamanio();
    float getSalidas(int i);
    float getActivacionDerivativa(int i);
    vector<float> getPesos(int i);
    float getPeso(int i,int j);
    void setPeso(int i, int j, float valor);

    int getNumElemFloat(float* array);
};

#endif // CAPA_H
