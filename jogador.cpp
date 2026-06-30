#include "jogador.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Procura um jogador pelo nome e retorna sua posição no vetor (-1 se não encontrar)
int buscarJogador(const vector<Jogador> &jogadores, const string &nome)
{
    for (int i = 0; i < (int)jogadores.size(); i++)
    {
        if (jogadores[i].nome == nome)
            return i; // Encontrou: retorna o índice
    }
    return -1; // Não encontrou
}

// Exibe a tabela de jogadores ordenada por número de vitórias
void exibirRanking(vector<Jogador> jogadores)
{
    // Ordena do maior para o menor número de vitórias usando uma função lambda
    sort(jogadores.begin(), jogadores.end(), [](const Jogador &a, const Jogador &b)
         { return a.vitorias > b.vitorias; });

    cout << "\n===== RANKING =====\n";
    if (jogadores.empty())
    { // Se não há jogadores registrados, avisa e encerra
        cout << "Nenhum jogador registrado ainda.\n";
        return;
    }

    cout.width(20);
    cout << left << "Nome";
    cout.width(10);
    cout << "Vitorias";
    cout.width(10);
    cout << "Derrotas" << "\n";

    for (const auto &j : jogadores)
    { // Imprime uma linha por jogador
        cout.width(20);
        cout << left << j.nome;
        cout.width(10);
        cout << j.vitorias;
        cout.width(10);
        cout << j.derrotas << "\n";
    }
}