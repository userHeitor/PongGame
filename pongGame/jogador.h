#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <vector>

struct Jogador
{
    std::string nome;
    int vitorias = 0;
    int derrotas = 0;
};

int buscarJogador(const std::vector<Jogador> &jogadores, const std::string &nome);
void exibirRanking(std::vector<Jogador> jogadores);

#endif