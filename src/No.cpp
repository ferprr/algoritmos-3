#include "headers/No.hpp"
#include <iostream>

using namespace std;

No::No(){}
void No::set_preco_e_tempo(int p, int t) {
    this->preco = p;
    this->tempo = t;
}
void No::set_desconto(float d){
    this->desconto = d;
}
void No::get_desconto_tempo_e_preco(){
    cout << "desconto: " << desconto << " tempo: " << tempo << " preco: " << preco;
    cout <<  endl;
}
float No::get_desconto(){
    return this->desconto;
}
int No::get_preco(){
    return this->preco;
}
int No::get_tempo(){
    return this->tempo;
}