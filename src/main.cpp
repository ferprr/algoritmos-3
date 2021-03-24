#include <iostream>
#include "headers/Escalas.hpp"

using namespace std;

int main() {

    int n, d, t;
    cin >> n >> d >> t; //leitura qtde de escalas, qtde máxima de escalas com descontos cumulativos no intervalo t e tempo máximo para sua aplicação

    Escalas sistema_cobranca(n, d, t);

    for (int i=0; i<d; i++) {
        int di;
        cin >> di; //leitura da qtde de desconto fornecido na escala i
        sistema_cobranca.set_descontos(di, i);
    }

    for (int i=0; i<n; i++) {
        int ti, ci;
        cin >> ti >> ci; //leitura do tempo gasto no translado da escala i e o preço do bilhete desta escala
        sistema_cobranca.set_preco(ci, i);
        sistema_cobranca.set_tempo(ti, i); //armazeno a partir da primeira posição do vetor, pois a primeira escala é zero, dado que este é o tempo até ela
    }

    sistema_cobranca.percorre_escalas();
    sistema_cobranca.~Escalas();
}