#include "capa.h"
#include "neuron.h"
#include<vector>
#include<assert.h>

using namespace std;
Capa::Capa(int prev_n_neurons, int num_neu)
{
    num_neu_cap = num_neu + 1;
    _prev_n_neurons = prev_n_neurons + 1;
    // allocate everything
    salidas = vector< float>(num_neu_cap);
    for (int i = 0; i < num_neu_cap; ++i)
        cout<<"Neurona Numero: "<<i+1<<endl;
        neuronas.push_back( Neuron(_prev_n_neurons));
}
vector<float> Capa::agrega_bias(vector<float>entrada){
    vector<float> sal(entrada.size()+1);
    for (int i = 0; i < entrada.size(); ++i)
        sal.at(i + 1) = entrada.at(i);
        sal[0] = 1.0f;
        return sal;
}

vector<float> Capa::evalua(vector<float>entr){
    vector <float> entradas;
    // no aseguramos que la bias este colocada
    if (entr.size()!= getPesos(0).size())
        entradas = agrega_bias(entr);
    else
        entradas = entr;
   if(getPesos(0).size() == entradas.size()){
        // stimulate each neuron of the layer and get its output
        for (int i = 1; i < num_neu_cap; ++i)
            salidas[i] = neuronas.at(i).activaciones(entradas);
        // bias treatment
        salidas[0] = 1.0f;
        return salidas;
   }
   else {
       cout<<"hubo un problema con la evaluacion de la capa "<<endl;
   }
}
int Capa::getTamanio(){
    return num_neu_cap;
}

float Capa::getSalidas(int i){
    return salidas[i];
}

float Capa::getActivacionDerivativa(int i){
    return neuronas.at(i).getActivacionDerivativa();
}

vector<float> Capa::getPesos(int i){
    return neuronas.at(i).getPesosSinapticos();
}
float Capa::getPeso(int i, int j){
    return neuronas.at(i).getPesoSinaptico(j);
}
void Capa::setPeso(int i, int j, float valor){
     neuronas.at(i).setPesoSinaptico(j, valor);
}
int Capa::getNumElemFloat(float *array){
    int ite=0 ;
    float elem=1.0;
    while(elem!=NULL){
        elem=array[ite];
        ite++;
    }
    return ite-2;
}
