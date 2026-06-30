#ifndef RAQUETE_H
#define RAQUETE_H

struct Raquete
{
    int x;       // Coluna fixa da raquete no campo
    int y;       // Linha do topo da raquete
    int tamanho; // Quantas linhas a raquete ocupa verticalmente
};

Raquete criarRaquete(int x, int altura, int tamanho);         // Cria a raquete centralizada na tela
void moverRaquete(Raquete &raquete, int direcao, int altura); // Move a raquete para cima ou para baixo
bool colidiu(const Raquete &raquete, int bolaX, int bolaY);   // Verifica se a bola tocou a raquete

#endif