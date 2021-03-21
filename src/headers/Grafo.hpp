#ifndef grafo
#define grafo
#include "No.hpp"

using namespace std;

class Grafo {

    int qtde_nos;
    int tempo_maximo;
    int maximo_descontos;
    float custo_minimo;
    No *trajeto;

    public:
        Grafo(int n, int d, int t);
        ~Grafo();
        void inicializa_grafo();
        void set_descontos(float d, int i);
        void set_preco_e_tempo(int p, int t, int i);
        void print_grafo();
        void caminha_grafo();
};

#endif