#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<vector>
#include "mlp.h"

using namespace std;


int main(){

    // inicializacion de entrada y salida
            vector<float*> entrada ;
            vector<float*> salida ;
            for (int i = 0; i < 4; ++i) {
                entrada.push_back(new float[2]);
                salida.push_back(new float[1]);
               // cout<<i<<endl;
            }

            // colocando los valores de entrada (la funcion XOR XD)
            entrada.at(0)[0] = -1; entrada.at(0)[1] = 1;  salida.at(0)[0] = 1;
            entrada.at(1)[0] = 1;  entrada.at(1)[1] = 1;  salida.at(1)[0] = -1;
            entrada.at(2)[0] = 1;  entrada.at(2)[1] = -1; salida.at(2)[0] = 1;
            entrada.at(3)[0] = -1; entrada.at(3)[1] = -1; salida.at(3)[0] = -1;


                    //en este arreglo se guardan los valores necesarios para el constructor
            int nn_neurons [3];
            nn_neurons[0] =2;// layer 1: input layer - 2 neurons
            nn_neurons[1] =1*3;// layer 2: hidden layer - 6 neurons
            nn_neurons[2] =1;// layer 3: output layer - 1 neuron

            MLP mlp(nn_neurons);

                for (int i = 0; i < 50000; ++i) {
                    mlp.aprende(entrada, salida, 0.3f);
                    float error = mlp.evaluarErrorCuadratico(entrada, salida);
                    cout<<i << " -> error : " << error;
                    //fout.println("\t" + i + "\t" + error);
                }


    return 0;
}


