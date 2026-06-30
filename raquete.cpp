#include "raquete.h"

// Cria a raquete centralizada verticalmente na coluna X indicada
Raquete criarRaquete(int x, int altura, int tamanho)
{
    Raquete r;
    r.x = x;
    r.tamanho = tamanho;
    r.y = (altura / 2) - (tamanho / 2); // Centraliza verticalmente
    return r;
}

// Desloca a raquete para cima (-1) ou para baixo (+1), sem sair do campo
void moverRaquete(Raquete &raquete, int direcao, int altura)
{
    raquete.y += direcao;
    if (raquete.y < 0)
        raquete.y = 0; // Não sai pelo topo
    if (raquete.y + raquete.tamanho > altura)
        raquete.y = altura - raquete.tamanho; // Não sai pelo fundo
}

// Retorna true se a bola está na coluna e dentro da faixa vertical da raquete
bool colidiu(const Raquete &raquete, int bolaX, int bolaY)
{
    if (bolaX != raquete.x)
        return false;                                                     // Bola não está na coluna da raquete
    return (bolaY >= raquete.y) && (bolaY < raquete.y + raquete.tamanho); // Bola está na altura da raquete
}