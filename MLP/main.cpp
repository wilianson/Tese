#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<vector>
#include "mlp.h"

using namespace std;

int main(){
    /*
    int num_neu=5;
    Neuron neu(num_neu);

    vector <float> inputs(5);
    inputs.at(0)=2.3;inputs.at(1)=1.36;inputs.at(2)=1.69;inputs.at(3)=3.26;inputs.at(4)=1.02;
    
    float activa=neu.activaciones(inputs);*/

     //LO QUE DEBERIA IR

    // inicializacion de entrada y salida
            vector<vector <float> > entrada ;
            vector<vector <float> > salida ;
            for (int i = 0; i < 4; ++i) {
                entrada.push_back(vector < float>(2));
                salida.push_back(vector < float>(1));
               // cout<<i<<endl;
            }

            // colocando los valores de entrada (la funcion XOR XD)
            entrada.at(0)[0] = -1; entrada.at(0)[1] = 1;  salida.at(0)[0] = 1;
            entrada.at(1)[0] = 1;  entrada.at(1)[1] = 1;  salida.at(1)[0] = -1;
            entrada.at(2)[0] = 1;  entrada.at(2)[1] = -1; salida.at(2)[0] = 1;
            entrada.at(3)[0] = -1; entrada.at(3)[1] = -1; salida.at(3)[0] = -1;


                    //en este arreglo se guardan los valores necesarios para el constructor
            vector <int> nn_neurons (3);
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


