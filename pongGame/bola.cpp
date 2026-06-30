#include "bola.h"

// Cria a bola posicionada no centro do campo
Bola criarBola(int largura, int altura)
{
    Bola b;
    b.x = largura / 2;
    b.y = altura / 2; // Começa no meio
    b.dx = 1;
    b.dy = 1; // Velocidade inicial: diagonal para baixo-direita
    return b;
}

// Avança a bola e inverte a direção vertical se bater na parede
void moverBola(Bola &bola, int largura, int altura)
{
    bola.x += bola.dx; // Avança horizontalmente
    bola.y += bola.dy; // Avança verticalmente

    // Rebate na borda superior ou inferior
    while (bola.y < 0 || bola.y >= altura)
    {
        if (bola.y < 0)
        {
            bola.y = -bola.y;   // Corrige a posição
            bola.dy = -bola.dy; // Inverte a direção vertical
        }
        else if (bola.y >= altura)
        {
            bola.y = 2 * (altura - 1) - bola.y;
            bola.dy = -bola.dy;
        }
    }
    (void)largura; // Evita aviso do compilador
}