#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "jogador.h"
#include "persistencia.h"
#include "jogo.h"

using namespace std;

// Busca o jogador pelo nome; se não existir, cria um novo e o adiciona à lista
int obterOuCriarJogador(vector<Jogador> &jogadores, const string &nome)
{
    int indice = buscarJogador(jogadores, nome);
    if (indice == -1)
    { // Jogador novo: cria e insere no vetor
        Jogador novo;
        novo.nome = nome;
        jogadores.push_back(novo);
        return (int)jogadores.size() - 1;
    }
    return indice; // Jogador já existe: retorna o índice dele
}

// Imprime o menu principal na tela
void exibirMenu()
{
    cout << "\n========================================\n";
    cout << "              PONG - MENU\n";
    cout << "========================================\n";
    cout << "1. Jogar partida (2 jogadores)\n";
    cout << "2. Ver ranking\n";
    cout << "3. Sair\n";
    cout << "========================================\n";
    cout << "Escolha uma opcao: ";
}

int main()
{
    vector<Jogador> jogadores = carregarPlacar();
    int opcao = 0;

    while (opcao != 3)
    {
        system("cls");
        exibirMenu();
        cin >> opcao;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (opcao == 1)
        {
            string nome1, nome2;
            cout << "Nome do Jogador 1: ";
            cin >> nome1;
            cout << "Nome do Jogador 2: ";
            cin >> nome2;

            int idx1 = obterOuCriarJogador(jogadores, nome1);
            int idx2 = obterOuCriarJogador(jogadores, nome2);

            system("cls");
            jogarPartida(jogadores[idx1], jogadores[idx2]);
            salvarPlacar(jogadores);

            // Pausa simples para o jogador ver o resultado antes de voltar ao menu
            cout << "\nPressione ENTER para continuar...";
            cin.ignore();
            cin.get();
        }
        else if (opcao == 2)
        {
            system("cls");
            exibirRanking(jogadores);

            // Pausa para o jogador ler o ranking antes de voltar ao menu
            cout << "\nPressione ENTER para voltar ao menu...";
            cin.ignore();
            cin.get();
        }
        else if (opcao == 3)
        {
            salvarPlacar(jogadores);
        }
    }
    return 0;
}