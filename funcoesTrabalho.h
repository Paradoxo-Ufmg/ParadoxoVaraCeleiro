#include <stdio.h>
#include <math.h>
#define _VELOCIDADE_LUZ_ 299792458

/**
 * @brief Função que cria a expressão que será usada para calcular o fator de lorentz
 *
 * Está função recebe a velocidade que o meu objeto está e a utilizando.
 * cria a expressão a ser calculado do fator de lorentz e a retorna.
 *
 * @param velocidadeObjeto Variável que armazena a velocidade a qual o objeto se encontra
 * @return A expressão
 * 
 * Exemplo de uso:
 * @code
 * double velocidade = 56732.0;
 * double expressao = expressaoFatorLorentz(velocidade);
 * @endcode
 */

double expressaoFatorLorentz(double velocidadeObjeto) {
    double razaoLorentz = 1/(1 - (pow(velocidadeObjeto,2) / pow(_VELOCIDADE_LUZ_, 2)));
    return razaoLorentz;
}

/**
 * @brief Função que cria a expressão que será usada para a velocidade para que sofra uma dada contração
 *
 * Está função recebe dois valores de comprimento.
 * E retorna a expressão para calcular a velocidade.
 *
 * @param comprimentoCeleiro Variável que armazena o comprimento do celeiro
 * @param comprimentoVara Variável que armazena o comprimento da vara
 * @return A expressão
 * 
 * Exemplo de uso:
 * @code
 * double compCel = 20.0;
 * double compVar = 34.2;
 * double expressao = expressaoVelocidade(compCel, compVar);
 * @endcode
 */

double expressaoVelocidade(double comprimentoCeleiro, double comprimentoVara) {
    double velocidade = 1 - pow(comprimentoCeleiro/comprimentoVara, 2);
    return velocidade;
}

/**
 * @brief Função que cria a função a ser usada no método de Newton-Rapshon
 *
 * Está função recebe um valor de estimativa e calcula a função x² a retornando-a 
 *
 * @param estimativa Variável que armazena a estimativa da raiz
 * @return x²
 * 
 * Exemplo de uso:
 * @code
 * double x = 1.0;
 * double func = funcaoCalculaRaiz(x);
 * @endcode
 */

double funcaoCalculaRaiz(double estimativa) {
    double funcaoRaiz = pow(estimativa, 2);
    return funcaoRaiz;
}

/**
 * @brief Função que calcula a derivada da função usada no método de Newton-Rapshon
 *
 * Está função recebe dois valores e com base neles.
 * É calculada a derivada da função utilizando o.
 * Método da diferença central.
 *
 * @param estimativa Variável que armazena a estimativa da derivada
 * @param h Variável que armazena o incremento entre os pontos
 * @return derivada da função
 * 
 * Exemplo de uso:
 * @code
 * double est = 1.0;
 * double h = 0.05;
 * double derivada = derivadaFuncaoRaiz(est, h);
 * @endcode
 */

double derivadaFuncaoRaiz(double estimativa, double h) {
    double funcaoSoma = funcaoCalculaRaiz(estimativa + h);
    double funcaoSub = funcaoCalculaRaiz(estimativa - h);
    double derivada = (funcaoSoma - funcaoSub) / (2 * h);

    return derivada;
}

/**
 * @brief Função que calcula a raiz quadrada de qualquer função com base no método de Newton-Rapshon
 *
 * Está função recebe quatro valores e os utiliza para calcular.
 * A raiz quadrada de qualquer valor ou função.
 * Pelo método de Newton-Rapshon.
 *
 * @param expressao Variável que armazena a expressão que será calculada 
 * @param tolerancia Variável que armazena o quão pequeno a derivada deve ser
 * @param estimativa Variável que armazena a estimativa da raiz quadrada
 * @param maxInteracoes Variável que armazena o número máximo de interações o programa deve fazer
 * @return raiz da expressão
 * 
 *Exemplo de uso:
 * @code
 * double x = 1.434;
 * double exp = 2 + x;
 * int inte = 500;
 * double tol = 5e-5;
 * double raiz = calculoRaizQuadrada(exp, tol, x, inte);
 * @endcode
 */

double calculoRaizQuadrada(double expressao, double tolerancia, double estimativa, int maxInteracoes) {
    double x = estimativa;
    int i;

    for (i = 0; i < maxInteracoes; i++) {
        double fx = funcaoCalculaRaiz(x) - expressao;
        double dfx = derivadaFuncaoRaiz(x, 0.001);

        x = x - fx/dfx;

        if(fabs(fx) < tolerancia)
            break;
    }

    return x;
}

/**
 * @brief Função que calcula a velocidade nescessária para um dado comprimento
 *
 * Está função recebe quatro valores e com base neles.
 * É estimada a velocidade para que seja feita uma dada contração.
 * Realizando o produto da raiz obtida pela função que calcula raiz.
 * pela velocidade da luz.
 *
 * @param expressao Variável que armazena a expressao da velocidade
 * @param tolerancia Variável que armazena a tolerancia para ser usada na função que calcula a raiz
 * @param estimativa Variável que armazena a estimativa da velocidade
 * @param maxInteracoes Variável que armazena o número de interações que devem ser feitas na função que calcula a raiz
 * @return velocidade
 * 
 *Exemplo de uso:
 * @code
 * double est = 1.2;
 * double exp = 2 + x² + 3;
 * double tol = 2e-8;
 * int max = 1000;
 * double vel = velocidadeNecessaria(exp,tol, est, max);
 * @endcode
 */

double velocidadeNecessaria(double expressao, double tolerancia, double estimativa, int maxInteracoes) {
    double raiz = calculoRaizQuadrada(expressao, tolerancia, estimativa, maxInteracoes);
    double velocidade = _VELOCIDADE_LUZ_ * raiz;
    return velocidade;
}

/**
 * @brief Função que calcula o comprimento do meu objeto em um cenário relativístico
 *
 * Está função recebe dois valores e com base neles.
 * É calculada o comprimento de um objeto dado o fator de lorentz.
 * Realizando o produto do comprimento pelo fator de lorentz.
 *
 * @param comprimentoOriginal Variável que armazena o comprimento original do meu objeto
 * @param fatorLorentz Variável que armazena o fator de Lorentz
 * @return comprimento
 * 
 * @code
 * double comp = 32.5;
 * double fatLor = 0.387;
 * double compRel = comprimentoObjeto(comp, fatLor);
 * @endcode
 */

double comprimentoObjeto(double comprimentoOriginal, double fatorLorentz) {
    double comprimento = comprimentoOriginal / fatorLorentz;
    return comprimento;

}

/**
 * @brief Função mostra se existe ou não simultaneidade
 *
 * Está função recebe cinco valores e com base eles.
 * É calculada a distancia da ponta esquerda e direita da vara.
 * Também a distancia da porta esquerda e da porta direita.
 * E calcula o tempo nescessário para a ponta esquerda atingir a porta esquerda.
 * E calcula o tempo nescessário para a ponta direita atingir a porta direita.
 * Depois de calculado ela mostra se há ou não simultaneidade.
 *
 * @param comprimentoVara Variável que armazena o comprimento da vara dada uma certa velocidade
 * @param comprimentoCeleiro Variável que armazena o comprimento do celeiro dada uma certa velocidade
 * @param comprimentoVaraOriginal Variável que armazena o comprimento original da vara
 * @param comprimentoCeleiroOriginal Variável que armazena o comprimento original do celeiro
 * @param velocidade variável que armazena a velocidade que o objeto se encontra
 * @return none
 * 
 * @code
 * double compVara = 10;
 * double compVaraOri = 16;
 * double compCelOri = 10;
 * double compCel = 6.25;
 * double vel = 234025312.518117;
 * simultaneidade(compVara, compCel, compVaraOri, compCelOri, vel);
 * @endcode
 */

void simultaneidade(double comprimentoVara, double comprimentoCeleiro, double comprimentoVaraOriginal, double comprimentoCeleiroOriginal, double velocidade) {

    // Simultaneidade Vara
    double distanciaPontaDireita = 10.0 + comprimentoCeleiroOriginal;
    double distanciaPontaEsquerda = 10.0 + comprimentoVara;

    double tempoDireitaVara = distanciaPontaDireita / velocidade;
    double tempoEsquerdaVara = distanciaPontaEsquerda / velocidade;

    // Simultaneidade Celeiro
    double distanciaPortaDireita = 10 + comprimentoCeleiro;
    double distanciaPortaEsquerda = 10 + comprimentoVaraOriginal;

    double tempoDireitaCeleiro = distanciaPortaDireita / velocidade;
    double tempoEsquerdaCeleiro = distanciaPortaEsquerda / velocidade;

    printf("\n-==-==-==-==-==-==-==-==-==-==-==-\n");
    printf("      SIMULTANEIDADE VARA");
    printf("\n-==-==-==-==-==-==-==-==-==-==-==-\n");

    printf("O tempo que a ponta direita da vara alcanca a porta direita do celeiro: %.12lf s\n", tempoDireitaVara);
    printf("O tempo que a ponta esquerda da vara alcanca a porta esquerda do celeiro: %.12lf s\n", tempoEsquerdaVara);
    printf("Existe simultaneidade\n");

    printf("\n-==-==-==-==-==-==-==-==-==-==-==-\n");
    printf("      SIMULTANEIDADE CELEIRO");
    printf("\n-==-==-==-==-==-==-==-==-==-==-==-\n");

    printf("O tempo que a porta direita do celeiro alcanca a ponta direita da vara: %.12lf s\n", tempoDireitaCeleiro);
    printf("O tempo que a porta esquerda do celeiro alcanca a ponta esquerda da vara: %.12lf s\n", tempoEsquerdaCeleiro);
    printf("Nao ha simultaneidade");

}
