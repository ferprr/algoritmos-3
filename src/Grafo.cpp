#include "headers/Grafo.hpp"
#include <iostream>

using namespace std;

Grafo::Grafo(int n, int d, int t){
    this->qtde_nos = n;
    this->maximo_descontos = d;
    this->tempo_maximo = t;
    this->custo_minimo = 0;

    inicializa_grafo();
}
Grafo::~Grafo(){
    delete this;
}
void Grafo::inicializa_grafo(){
    trajeto = new No[qtde_nos];
    for(int i=0; i<qtde_nos; i++){
        trajeto[i].set_desconto(0);
        trajeto[i].set_preco_e_tempo(0,0);
    }
}
void Grafo::set_descontos(float d, int i){
    trajeto[i].set_desconto(d/100);
}
void Grafo::set_preco_e_tempo(int p, int t, int i){
    trajeto[i].set_preco_e_tempo(p, t);
}
void Grafo::print_grafo(){
    for(int i=0; i<qtde_nos; i++){
        trajeto[i].get_desconto_tempo_e_preco();
    }
}
void Grafo::caminha_grafo(){
    int temp, count;
    temp = 0;
    count = 1;
    cout << "descontos: " << maximo_descontos << endl;
    cout << "tempo maximo: "  << tempo_maximo << endl;

    for(int i=0; i<qtde_nos; i++){
        cout << "custo: " << custo_minimo << endl;
        cout << "temp: "  << temp << endl;
        cout << "count: " << count << endl;

        if(temp < tempo_maximo && count <= maximo_descontos) {
            if (trajeto[i].get_desconto() == 0.00){
                custo_minimo += trajeto[i].get_preco();
            } else if (trajeto[i].get_desconto() == 1.00){
                custo_minimo += 0;
            } else {
                custo_minimo += trajeto[i].get_preco() * trajeto[i].get_desconto();
            }
            count++;
        } else {
            count = 0;
            custo_minimo += trajeto[i].get_preco();
            temp = 0;
        }
        temp += trajeto[i].get_tempo();
    }
    cout << "custo minimo: " << custo_minimo;
}