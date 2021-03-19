#include <iostream>
#include "headers/Grafo.hpp"

using namespace std;

int main() {

    int n, d, t;
    cin >> n >> d >> t; //leitura qtde de escalas, qtde máxima de escalas com descontos cumulativos no intervalo t e tempo máximo para sua aplicação

    Grafo trajeto(n, d, t);

    for (int i=0; i<n; i++) {
        int di;
        cin >> di; //leitura da qtde de desconto fornecido na escala i
        trajeto.set_descontos(di, i);
    }

    for (int i=0; i<n; i++) {
        int ti, ci;
        cin >> ti >> ci; //leitura do tempo gasto no translado da escala i e o preço do bilhete desta escala
        trajeto.set_preco_e_tempo(ci, ti, i);
    }

    trajeto.print_grafo();
    trajeto.caminha_grafo();
}