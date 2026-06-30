#include "tabuleiro.h"
#include <iostream>
#include <string>
#include <windows.h> // Necessário para mexer no cursor do Windows

using namespace std;

// Peguei essa função na internet para a tela do jogo não piscar (system("cls") tava travando)
void limparTela()
{
    COORD cursor_origem;
    cursor_origem.X = 0;
    cursor_origem.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_origem);
}

vector<vector<char>> montarCampo(int largura, int altura, const Bola &bola, const Raquete &esquerda, const Raquete &direita)
{
    vector<vector<char>> campo(altura, vector<char>(largura, ' '));

    for (int i = 0; i < esquerda.tamanho; i++)
    {
        int linha = esquerda.y + i;
        if (linha >= 0 && linha < altura)
            campo[linha][esquerda.x] = '|';
    }

    for (int i = 0; i < direita.tamanho; i++)
    {
        int linha = direita.y + i;
        if (linha >= 0 && linha < altura)
            campo[linha][direita.x] = '|';
    }

    if (bola.y >= 0 && bola.y < altura && bola.x >= 0 && bola.x < largura)
    {
        campo[bola.y][bola.x] = 'O';
    }

    return campo;
}

void desenharCampo(const vector<vector<char>> &campo, int placarEsquerda, int placarDireita)
{
    limparTela(); // Agora usa a função que move o cursor e não trava o frame rate

    string textoPlacar = "   PONG - Placar: " + to_string(placarEsquerda) + " x " + to_string(placarDireita);
    while (textoPlacar.size() < 50)
        textoPlacar += ' ';
    cout << textoPlacar << "\n";

    // Desenha a parede de cima
    int larguraParede = campo[0].size() + 2;
    for (int i = 0; i < larguraParede; i++)
    {
        cout << "-";
    }
    cout << "\n";

    // Imprime a matriz do jogo
    for (int i = 0; i < campo.size(); i++)
    {
        cout << "|"; // Parede esquerda
        for (int j = 0; j < campo[i].size(); j++)
        {
            cout << campo[i][j];
        }
        cout << "|\n"; // Parede direita
    }

    // Desenha a parede de baixo
    for (int i = 0; i < larguraParede; i++)
    {
        cout << "-";
    }
    cout << "\n";

    cout << "Jog 1: W(cima) / S(baixo) | Jog 2: Setinhas | Q sair\n";
}