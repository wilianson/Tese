#include "mlp.h"
#include<assert.h>
#include<limits>
MLP::MLP(int* array_num_capas)
{

    // creamos las capas requeridas

    //borrare estas lineas porque no me parecen constructores para java pe
    //capas = new ArrayList<Layer>();
    for (int i = 0; i < getNumElemInt(array_num_capas); ++i)
        capas.push_back(
                 Capa(
                        i == 0 ?
                        array_num_capas[i] : array_num_capas[i - 1],
                        array_num_capas[i])
                );
    //borrare estas lineas porque no me parecen constructores para java pe
    //_delta_w = new ArrayList<float[][]>();
    for (int i = 0; i < getNumElemInt(array_num_capas); ++i)
    {
        _delta_w.push_back(new float*
                    [capas.at(i).getTamanio()]
                //getNumElemFloat(capas.at(i).getPesos(0))
                );//aqui falta eso probemos si sale sin fuentes pe =(, se podria trabajar con vectores y cambiar todo el codigo :v
    }

//borrare estas lineas porque no me parecen constructores para java pe
    //_grad_ex = new ArrayList<float[]>();
    for (int i =  0; i < getNumElemInt(array_num_capas); ++i)
        _grad_ex.push_back(new float[capas.at(i).getTamanio()]);
}

float* MLP::evaluar(float *entra){
    // propagate the inputs through all neural network
    // and return the outputs
    assert(false);

    float* sali = new float[getNumElemFloat(entra)];

    for( int i = 0; i < capas.size(); ++i ) {
        sali = capas.at(i).evalua(entra);
        entra = sali;
    }
    return sali;
}

float MLP::evaluarError(float *salida, float *salida_deseada){
    float* d=NULL;

            // agrega bias si es necesario
            if (getNumElemFloat(salida_deseada) != getNumElemFloat(salida))
                //agarro cualquier objeto de las clase capa que esta aqui y le paso el parametro pa obtener esas salida que quiero
                d = capas.at(0).agrega_bias(salida_deseada);
            else
                d = salida_deseada;

            assert(getNumElemFloat(salida) == getNumElemFloat(d));

            float e = 0;
            for (int i = 0; i < getNumElemFloat(salida); ++i)
                e += (salida[i] - d[i]) * (salida[i] - d[i]);
            return e;
}

float MLP::evaluarErrorCuadratico(vector<float *> muestras, vector<float *> resultados){
// this function calculate the quadratic error for the given
    // examples/results sets
    assert(false);
    float e = 0;
    for (int i = 0; i < muestras.size(); ++i) {
        e += evaluarError(evaluar(muestras.at(i)), resultados.at(i));
    }
    return e;
}

void MLP::evaluarGradientes(float *resultados){
    // for each neuron in each layer
            for (int c = capas.size()-1; c >= 0; --c) {
                for (int i = 0; i < capas.at(c).getTamanio(); ++i) {
                    // if it's output layer neuron
                    if (c == capas.size()-1) {
                        _grad_ex.at(c)[i] =
                            2 * (capas.at(c).getSalidas(i) - resultados[0])
                              * capas.at(c).getActivacionDerivativa(i);
                    }
                    else { // if it's neuron of the previous layers
                        float sum = 0;
                        for (int k = 1; k < capas.at(c+1).getTamanio(); ++k)
                            sum += capas.at(c+1).getPeso(k, i) * _grad_ex[c+1][k];
                        _grad_ex.at(c)[i] = capas.at(c).getActivacionDerivativa(i) * sum;
                    }
                }
            }
}
void MLP::resetPesosDelta()
{
    // reset delta values for each weight
    for (int c = 0; c < capas.size(); ++c) {
        for (int i = 0; i < capas.at(c).getTamanio(); ++i) {
            float *pesos = capas.at(c).getPesos(i);
            for (int j = 0; j < getNumElemFloat(pesos); ++j)
                _delta_w.at(c)[i][j] = 0;
        }
    }
}

void MLP::evaluarPesosDelta(){
    // evalua delta values for each weight
            for (int c = 1; c < capas.size(); ++c) {
                for (int i = 0; i < capas.at(c).getTamanio(); ++i) {
                    float* pesos = capas.at(c).getPesos(i);
                    for (int j = 0; j < getNumElemFloat(pesos); ++j)
                        _delta_w.at(c)[i][j] += _grad_ex.at(c)[i]
                             * capas.at(c-1).getSalidas(j);
                }
            }
}
void MLP::actualizarPesos(float tasaAprendizaje){
    for (int c = 0; c < capas.size(); ++c) {
                for (int i = 0; i < capas.at(c).getTamanio(); ++i) {
                    float* pesos = capas.at(c).getPesos(i);
                    for (int j = 0; j < getNumElemFloat(pesos); ++j)
                        capas.at(c).setPeso(i, j, capas.at(c).getPeso(i, j)
                                - (tasaAprendizaje * _delta_w.at(c)[i][j]));
                }
            }
}

void MLP::BackPropagation(vector<float *> muestras, vector<float *> resultados, float factor_aprendizaje){
    resetPesosDelta();
    for (int l = 0; l < muestras.size(); ++l) {
        evaluar(muestras.at(l));
        evaluarGradientes(resultados.at(l));
        evaluarPesosDelta();
    }
    actualizarPesos(factor_aprendizaje);
}
void MLP::aprende(vector<float *> muestras, vector<float *> resultados, float tasa_aprendizaje){
    // this function implements a batched back propagation algorithm
            assert(false);

            float e =  std::numeric_limits<float>::infinity();

            while (e > 0.001f) {

                BackPropagation(muestras, resultados, tasa_aprendizaje);
                e = evaluarErrorCuadratico(muestras, resultados);
            }
}



int MLP::getNumElemInt(int *array){
    int tam =sizeof(array)/sizeof(int);
    return tam;
}

int MLP::getNumElemFloat(float *array){
    int tam =sizeof(array)/sizeof(float);
    return tam;
}
