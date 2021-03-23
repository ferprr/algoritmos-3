#include <iostream>
#include "headers/Escalas.hpp"

using namespace std;

int main() {

    int n, d, t;
    cin >> n >> d >> t; //leitura qtde de escalas, qtde máxima de escalas com descontos cumulativos no intervalo t e tempo máximo para sua aplicação

    Escalas sistema_transporte(n, d, t);

    for (int i=0; i<d; i++) {
        int di;
        cin >> di; //leitura da qtde de desconto fornecido na escala i
        sistema_transporte.set_descontos(di, i);
    }

    for (int i=0; i<n; i++) {
        int ti, ci;
        cin >> ti >> ci; //leitura do tempo gasto no translado da escala i e o preço do bilhete desta escala
        sistema_transporte.set_preco(ci, i);
        sistema_transporte.set_tempo(ti, i+1); //armazeno a partir da primeira posição do vetor, pois a primeira escala é zero, dado que este é o tempo até ela
    }

    sistema_transporte.print_escalas();
    sistema_transporte.percorre_escalas();

}