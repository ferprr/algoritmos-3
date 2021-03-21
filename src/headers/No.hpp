#ifndef no
#define no

class No {

    float desconto;
    int preco;
    int tempo;
    float custo_acumulado;

    public:
        No();
        void set_desconto(float d);
        void set_preco_e_tempo(int p, int t);
        void get_desconto_tempo_e_preco();
        int get_preco();
        float get_desconto();
        int get_tempo();
        
};

#endif