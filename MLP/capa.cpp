#include "capa.h"
#include "neuron.h"
#include<vector>
#include<assert.h>


using namespace std;
Capa::Capa(int prev_n_neurons, int n_neurons)
{
    // all the layers/neurons must use the same random number generator,
    _n_neurons = n_neurons + 1;
    _prev_n_neurons = prev_n_neurons + 1;
    // allocate everything
    //no me convence esta linea pe
    /*
    vector<Neuron> neur;
    neuronas =  neur;*/
    salidas = new float[_n_neurons];
    for (int i = 0; i < _n_neurons; ++i)
        neuronas.push_back( Neuron(_prev_n_neurons));
}
float* Capa::agrega_bias(float *entrada){
    float* sal=new float[getNumElemFloat(entrada)+1];
    for (int i = 0; i < getNumElemFloat(entrada); ++i)
                sal[i + 1] = entrada[i];
            sal[0] = 1.0f;
            return sal;
}

float* Capa::evalua(float *entr){
    float* entradas;

            // add an input (bias) if necessary
            if (getNumElemFloat(entr)!= getNumElemFloat(getPesos(0)))
                entradas = agrega_bias(entr);
            else
                entradas = entr;

            assert (getNumElemFloat(getPesos(0)) == getNumElemFloat(entradas));

                // stimulate each neuron of the layer and get its output
                for (int i = 1; i < _n_neurons; ++i)
                    salidas[i] = neuronas.at(i).activaciones(entradas);

                // bias treatment
                salidas[0] = 1.0f;
                return salidas;

}
int Capa::getTamanio(){
    return _n_neurons;
}

float Capa::getSalidas(int i){
    return salidas[i];
}

float Capa::getActivacionDerivativa(int i){
    return neuronas.at(i).getActivacionDerivativa();
}

float* Capa::getPesos(int i){
    return neuronas.at(i).getPesosSinapticos();
}
float Capa::getPeso(int i, int j){
    return neuronas.at(i).getPesoSinaptico(j);
}
void Capa::setPeso(int i, int j, float valor){
     neuronas.at(i).setPesoSinaptico(j, valor);
}



int Capa::getNumElemFloat(float *array){
    int tam =sizeof(array)/sizeof(float);
    return tam;
}
