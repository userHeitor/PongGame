#ifndef BOLA_H // Proteção contra inclusão dupla do arquivo
#define BOLA_H

struct Bola
{
    int x, y;   // Posição da bola no campo
    int dx, dy; // Velocidade: quanto a bola anda por frame (direção X e Y)
};

Bola criarBola(int largura, int altura);             // Cria a bola no centro do campo
void moverBola(Bola &bola, int largura, int altura); // Move a bola e rebate nas paredes

#endif