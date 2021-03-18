#include <iostream>

using namespace std;

int main() {

    int n, t;
    cin >> n >> d >> t; //leitura qtde de escalas, qtde máxima de escalas com descontos cumulativos no intervalo t e tempo máximo para sua aplicação

    for (int i=0; i<n; i++) {
        int di;
        cin >> di; //leitura da qtde de desconto fornecido na escala di
    }

    for (int i=0; i<t; i++) {
        int ti, ci;
        cin >> ti >> ci; //leitura do tempo gasto no translado da escala 0 e o preço do bilhete desta escala
    }

}