#include "jogo.h"
#include <iostream>
#include <windows.h> // Para a função Sleep()
#include <conio.h>   // Para _kbhit() e _getch()
#include "bola.h"
#include "raquete.h"
#include "tabuleiro.h"

using namespace std;

const int larguraCampo = 40;
const int ALTURA_CAMPO = 16;
const int TAMANHO_RAQUETE = 4;
const int PONTOS_PARA_VENCER = 3;

// Funções simples para o Windows ler o teclado
bool teclaPressionada() { return _kbhit() != 0; }
char lerTecla() { return _getch(); }

void jogarPartida(Jogador &jogador1, Jogador &jogador2)
{
    Raquete raqueteEsq = criarRaquete(1, ALTURA_CAMPO, TAMANHO_RAQUETE);
    Raquete raqueteDir = criarRaquete(larguraCampo - 2, ALTURA_CAMPO, TAMANHO_RAQUETE);
    Bola bola = criarBola(larguraCampo, ALTURA_CAMPO);

    int placarEsq = 0, placarDir = 0;
    bool jogoAtivo = true;

    while (jogoAtivo)
    {
        int movEsq = 0, movDir = 0;

        while (teclaPressionada())
        {
            char tecla = lerTecla();

            // Setinhas do teclado (códigos especiais do Windows)
            if (tecla == (char)224 || tecla == -32)
            {
                char codigoSeta = lerTecla();
                if (codigoSeta == 72)
                    movDir = -1;
                else if (codigoSeta == 80)
                    movDir = 1;
            }
            else if (tecla == 'q' || tecla == 'Q')
                jogoAtivo = false;
            else if (tecla == 'w' || tecla == 'W')
                movEsq = -1;
            else if (tecla == 's' || tecla == 'S')
                movEsq = 1;
        }

        if (movEsq != 0)
            moverRaquete(raqueteEsq, movEsq, ALTURA_CAMPO);
        if (movDir != 0)
            moverRaquete(raqueteDir, movDir, ALTURA_CAMPO);

        moverBola(bola, larguraCampo, ALTURA_CAMPO);

        if (bola.x == raqueteEsq.x + 1 && colidiu(raqueteEsq, raqueteEsq.x, bola.y))
            bola.dx = -bola.dx;
        if (bola.x == raqueteDir.x - 1 && colidiu(raqueteDir, raqueteDir.x, bola.y))
            bola.dx = -bola.dx;

        if (bola.x < 0)
        {
            placarDir++;
            bola = criarBola(larguraCampo, ALTURA_CAMPO);
        }
        else if (bola.x >= larguraCampo)
        {
            placarEsq++;
            bola = criarBola(larguraCampo, ALTURA_CAMPO);
        }

        vector<vector<char>> campo = montarCampo(larguraCampo, ALTURA_CAMPO, bola, raqueteEsq, raqueteDir);
        desenharCampo(campo, placarEsq, placarDir);

        if (placarEsq >= PONTOS_PARA_VENCER || placarDir >= PONTOS_PARA_VENCER)
            jogoAtivo = false;

        Sleep(120);
    }

    cout << "\n===== FIM DE JOGO =====\n";
    cout << "Placar final: " << placarEsq << " x " << placarDir << "\n";

    if (placarEsq > placarDir)
    {
        cout << jogador1.nome << " venceu!\n";
        jogador1.vitorias++;
        jogador2.derrotas++;
    }
    else if (placarDir > placarEsq)
    {
        cout << jogador2.nome << " venceu!\n";
        jogador2.vitorias++;
        jogador1.derrotas++;
    }
    else
    {
        cout << "Partida encerrada sem vencedor.\n";
    }
}