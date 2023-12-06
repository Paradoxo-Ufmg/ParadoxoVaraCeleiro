#include "funcoesTrabalho.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função principal
 * Está função pede ao usuario dois valores, para o tamanho da vara e o outro para o tamanho do celeiro.
 * Com base nesses valores é chamada as funções que foram criadas para o trabalho e elas são executadas.
 * 
 * @return 0
 */

int main() {
    // Definindo as dimensões dos objetos

    double tamanhoVara;
    double tamanhoCeleiro;

    do {

        printf("Escreva o tamanho da Vara: ");
        scanf("%lf", &tamanhoVara);

        printf("Escreva o tamanho do celeiro: ");
        scanf("%lf", &tamanhoCeleiro);

    } while (tamanhoVara < tamanhoCeleiro);

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
