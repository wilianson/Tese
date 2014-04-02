#ifndef MLP_H
#define MLP_H
#include"capa.h"
#include<vector>
using namespace std;
class MLP
{
    vector<Capa> capas;
    vector<float**> _delta_w;
    vector<float*> _grad_ex;

public:
    MLP(int* array_num_capas);
    float* evaluar(float* entra);
    float evaluarError(float* salida, float* salida_deseada);
    float evaluarErrorCuadratico(vector<float*> muestras,vector<float*> resultados);
    void evaluarGradientes(float* resultados);
    void resetPesosDelta();
    void evaluarPesosDelta();
    void actualizarPesos(float tasaAprendizaje);
    void BackPropagation(vector<float*> muestras,
                         vector<float*> resultados,
                         float factor_aprendizaje);
    void aprende(vector<float*> muestras,
                 vector<float*> resultados,
                 float tasa_aprendizaje);

    float* agrega_bias(float* entrada);
    int getNumElemFloat(float* array);
    int getNumElemInt(int* array);
};

#endif // MLP_H
