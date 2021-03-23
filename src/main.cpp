#include <iostream>
#include "headers/Escalas.hpp"

using namespace std;

int main() {

    int n, d, t;
    cin >> n >> d >> t; //leitura qtde de escalas, qtde máxima de escalas com descontos cumulativos no intervalo t e tempo máximo para sua aplicação

    Escalas sistema_transporte(n, d, t);

    for (int i=0; i<n; i++) {
        float di;
        cin >> di; //leitura da qtde de desconto fornecido na escala i
        if(di/100==0.00){
            sistema_transporte.set_descontos(1, i);
        } else if(di/100==1.00){
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
        sistema_transporte.set_tempo(temp, i+1);
    }

    sistema_transporte.print_grafo();
    sistema_transporte.percorre_escalas();
}