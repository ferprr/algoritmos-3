#include "headers/Escalas.hpp"
#include <iostream>
#include <math.h>

using namespace std;

Escalas::Escalas(int n, int d, int t){
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
void Escalas::inicializa_escalas(){
    for(int i=0; i<qtde_escalas+1; i++) {
        trajeto[i] = 0; //populando casos base
    }
    for(int i=0; i<qtde_escalas; i++) {
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
    descontos[i] = d;
}
void Escalas::set_preco(int p, int i){
    precos[i] = p;
}
void Escalas::set_tempo(int t, int i){
    if(i==1){
        tempo[i] = t;
    } else {
        tempo[i] = tempo[i-1] + t;
    }
    
}
void Escalas::print_grafo(){
    for(int i=0; i<qtde_escalas; i++){
        cout << "Escala " << i+1 << ": " << endl;
        cout << "Preco: " << precos[i] << endl;
        cout << "Desconto: " << descontos[i] << endl;
        cout << "Tempo: " << tempo[i] << endl;
    }
}
void Escalas::percorre_escalas(){
    int temp=0, desconto_atual=0, count=1;

    for(int i=1; i<=qtde_escalas; i++){
        for(int j=qtde_escalas; j>=1; j--){
            
            if(i-desconto_atual >= maximo_descontos || tempo[i] - tempo[desconto_atual] >= tempo_maximo) {
                custo_minimo += 999999;
            } else if(i == qtde_escalas-1){
                custo_minimo += 0;
            } else {
                float aux1, aux2;
                aux1 = precos[i+1] * descontos[i+1-i+1];
                aux2 = precos[i+1] * descontos[i+1-desconto_atual];
                custo_minimo += precos[i] * descontos[i-desconto_atual]  + min(aux1, aux2);
                desconto_atual++;
            }
            cout << "custo acumulado: " << custo_minimo;
        }
    }
    cout << "custo minimo: " << custo_minimo;
}