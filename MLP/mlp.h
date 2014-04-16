#ifndef MLP_H
#define MLP_H
#include"capa.h"
#include<vector>
using namespace std;
class MLP
{
    vector<Capa> capas;
    vector<float** > _delta_w;
    vector<vector <float> > _grad_ex;

public:
    int x,y;
    MLP(vector <int> array_num_capas);
    vector <float> evaluar(vector <float> entra);
    float evaluarError(vector <float >salida, vector <float> salida_deseada);
    float evaluarErrorCuadratico(vector<vector <float> > muestras,vector<vector <float> > resultados);
    void evaluarGradientes(vector <float> resultados);
    void resetPesosDelta();
    void evaluarPesosDelta();
    void actualizarPesos(float tasaAprendizaje);
    void BackPropagation(vector<vector <float> > muestras,
                         vector<vector <float> > resultados,
                         float factor_aprendizaje);
    void aprende(vector<vector <float> > muestras,
                 vector<vector <float> > resultados,
                 float tasa_aprendizaje);

    vector <float> agrega_bias(vector <float >entrada);

};

#endif // MLP_H
