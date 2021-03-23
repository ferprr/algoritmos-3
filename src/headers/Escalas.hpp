#ifndef escalas
#define escalas

using namespace std;

class Escalas {

    int qtde_escalas;
    int tempo_maximo;
    int maximo_descontos;
    float custo_minimo;
    float* descontos;
    int* precos;
    int* tempo;
    int* trajeto;

    public:
        Escalas(int n, int d, int t);
        ~Escalas();
        void inicializa_escalas();
        void set_descontos(float d, int i);
        void set_preco(int p, int i);
        void set_tempo(int t, int i);
        void print_escalas();
        void percorre_escalas();
};

#endif