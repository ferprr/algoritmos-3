#ifndef escalas
#define escalas

using namespace std;

class Escalas {

    int qtde_escalas;
    int tempo_maximo;
    int maximo_descontos;
    double* custo_acumulado;
    double* descontos;
    int* precos;
    int* tempo;
    int* trajeto;

    public:
        Escalas(int n, int d, int t);
        ~Escalas();
        void inicializa_escalas();
        void set_descontos(double d, int i);
        void set_preco(int p, int i);
        void set_tempo(int t, int i);
        void print_escalas();
        void percorre_escalas();
};

#endif