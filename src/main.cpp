#include <iostream>
#include "headers/Escalas.hpp"

using namespace std;

int main() {

    int n, d, t;
    cin >> n >> d >> t; //leitura qtde de escalas, qtde máxima de escalas com descontos cumulativos no intervalo t e tempo máximo para sua aplicação

    Escalas sistema_transporte(n, d, t);

    for (int i=0; i<d; i++) {
        float di;
        cin >> di; //leitura da qtde de desconto fornecido na escala i
        if(di/100==0.00){ //se valor de desconto informado dividido por 100 for igual a 0.00, armazeno o desconto como 1. Assim, na multiplicação já tenho o valor adequado
            sistema_transporte.set_descontos(1, i);
        } else if(di/100==1.00){ //e se for igual a 1.00, já armazeno como 0, para que o valor resultante da multiplicação seja 0
            sistema_transporte.set_descontos(0, i);
        } else { 
            sistema_transporte.set_descontos(di/100, i);
        }
        
    }

    for (int i=0; i<n; i++) {
        int ti, ci, temp=0;
        cin >> ti >> ci; //leitura do tempo gasto no translado da escala i e o preço do bilhete desta escala
        temp += ti;
        sistema_transporte.set_preco(ci, i);
        sistema_transporte.set_tempo(temp, i+1); //armazeno a partir da primeira posição do vetor, pois a primeira escala é zero, dado que este é o tempo até ela
    }

    sistema_transporte.print_escalas();
    sistema_transporte.percorre_escalas();
}