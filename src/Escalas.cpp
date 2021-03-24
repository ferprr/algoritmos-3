#include "headers/Escalas.hpp"
#include <iostream>
#include <iomanip> 
#include <math.h>

using namespace std;

Escalas::Escalas(int n, int d, int t){ //inicializando variáveis e vetores
    this->qtde_escalas = n;
    this->maximo_descontos = d;
    this->tempo_maximo = t;
    this->tempo = new int[n];
    this->descontos = new int[d];
    this->precos = new int[n];
    this->custo_acumulado = new int[n+1]; //vetor para custo acumulado

    inicializa_escalas();
}
Escalas::~Escalas(){
    delete this; //destrutor
}
void Escalas::inicializa_escalas(){ //inicializando vetores
    for(int i=0; i<maximo_descontos; i++) {
        descontos[i] = 0; 
    }
    for(int i=0; i<qtde_escalas; i++) {
        precos[i] = 0; 
    }
    for(int i=0; i<qtde_escalas; i++) {
        tempo[i] = 0; 
    }
    custo_acumulado[0] = 0;
    for(int k=1; k<qtde_escalas+1; k++){
        custo_acumulado[k]= 999999999;
    }
}
void Escalas::set_descontos(int d, int i){
    descontos[i] = d; //armazenando desconto da escala i
}
void Escalas::set_preco(int p, int i){
    precos[i] = p; //armazenando preço do bilhete da escala i
}
void Escalas::set_tempo(int t, int i){
    tempo[i] = t; //armazenando tempo de translado da escala i
    
}
void Escalas::percorre_escalas(){
    int temp, desconto_acumulado, cust

    for(int i=0; i<qtde_escalas; i++){
        custo = custo_acumulado[i]; //auxiliar recebe custo acumulado
        temp = 0; //reinicia auxiliar tempo
        desconto_acumulado = 0; //reinicia desconto acumulado
        for(int j=0; j<maximo_descontos; j++){ //enquanto j for menor que o máximo de descontos
            if(temp<tempo_maximo && i+j<qtde_escalas){ //se o tempo acumulado até o momento for menor que o tempo máximo para aplicação de desconto e a quantidade de escalas passadas e descontos aplicados for menor que a quantidade de escalas
                desconto_acumulado += descontos[j]; //acumula desconto
                custo += precos[i+j] * (100 - desconto_acumulado); //custo recebe preço x desconto
                custo_acumulado[i+j+1] = min(custo_acumulado[i+j+1], custo); //custo acumulado recebe menor valor entre custo acumulado atual e próximo custo acumulado
            }
            temp += tempo[i+j]; //acumula tempo
        }
    }

    float custo_minimo = custo_acumulado[qtde_escalas]/100.00; //menor custo para percorrer trajeto
    cout << fixed << setprecision(2);
    cout << custo_minimo << endl;
}