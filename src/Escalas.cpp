#include "headers/Escalas.hpp"
#include <iostream>
#include <math.h>

using namespace std;

Escalas::Escalas(int n, int d, int t){ //inicializando variáveis e vetores
    this->qtde_escalas = n;
    this->maximo_descontos = d;
    this->tempo_maximo = t;
    this->custo_minimo = 0;
    this->trajeto = new int[n];
    this->tempo = new int[n];
    this->descontos = new float[n];
    this->precos = new int[n];

    inicializa_escalas();
}
Escalas::~Escalas(){
    delete this;
}
void Escalas::inicializa_escalas(){ //inicializando vetores
    for(int i=0; i<qtde_escalas; i++) {
        trajeto[i] = 0; //populando casos base
    }
    for(int i=0; i<maximo_descontos; i++) {
        descontos[i] = 0; 
    }
    for(int i=0; i<qtde_escalas; i++) {
        precos[i] = 0; 
    }
    for(int i=0; i<qtde_escalas+1; i++) {
        tempo[i] = 0; 
    }
}
void Escalas::set_descontos(float d, int i){
    if(i==0){
        descontos[i] = d; //armazenando desconto da escala i
    } else {
        descontos[i] = descontos[i-1] + d; //armazenando descontos acumulados
    }
    
}
void Escalas::set_preco(int p, int i){
    precos[i] = p; //armazenando preço do bilhete da escala i
}
void Escalas::set_tempo(int t, int i){
    if(i==1){
        tempo[i] = t; //armazenando tempo de translado da escala i
    } else {
        tempo[i] = tempo[i-1] + t; //armazenando tempos acumulados 
    }
    
}
void Escalas::print_escalas(){
    for(int i=0; i<qtde_escalas; i++){
        cout << "Escala " << i+1 << ": " << endl;
        cout << "Preco: " << precos[i] << endl;
        cout << "Desconto: " << descontos[i] << endl;
        cout << "Tempo: " << tempo[i] << endl;
    }
}
void Escalas::percorre_escalas(){
    int temp, j, desconto_acumulado;

    float* custo_acumulado = new float[qtde_escalas]; //vetor auxiliar para custo acumulado

    for(int k=1; k<qtde_escalas; k++){
        custo_acumulado[k]= 999999;
    }
    custo_acumulado[0] = 0;
    for(int i=0; i<qtde_escalas; i++){
        custo_minimo = custo_acumulado[i];
        temp = 0;
        desconto_acumulado = 0;
        for(int j = 0; j < maximo_descontos; j++){
            if(temp < tempo_maximo && i+j < qtde_escalas){
                custo_minimo = custo_minimo + precos[i+j] * (1 - descontos[j]);
                custo_acumulado[i+j+1] = min(custo_acumulado[i+j+1], custo_minimo);
            }
            temp = temp + tempo[i+j];
        }
    }
    cout << "custo minimo: " << custo_minimo;
}