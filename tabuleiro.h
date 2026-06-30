#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include "bola.h"
#include "raquete.h"

void limparTela();
std::vector<std::vector<char>> montarCampo(int largura, int altura, const Bola &bola, const Raquete &esquerda, const Raquete &direita);
void desenharCampo(const std::vector<std::vector<char>> &campo, int placarEsquerda, int placarDireita);

#endif