#include "funcoesTrabalho.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Definindo as dimensões dos objetos

    int tamanhoVara = 16;
    int tamanhoCeleiro = 10;

    // Calculando os valores 
    double expVelocidade = expressaoVelocidade(tamanhoCeleiro, tamanhoVara);
    double velocidade = velocidadeNecessaria(expVelocidade, 10e-10, 1, 1000);
    double expLorentz = expressaoFatorLorentz(velocidade);
    double fatorLorenzt = calculoRaizQuadrada(expLorentz, 10e-10, 1, 1000);
    double comprimento_Vara = comprimentoObjeto(tamanhoVara, fatorLorenzt);
    double comprimento_Celeiro = comprimentoObjeto(tamanhoCeleiro, fatorLorenzt);

    // Verificando a presença de simultaneidade
    simultaneidade(comprimento_Vara, comprimento_Celeiro, tamanhoVara, tamanhoCeleiro, velocidade);

    return 0;
}