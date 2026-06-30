#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <vector>
#include "jogador.h"

void salvarPlacar(const std::vector<Jogador> &jogadores);
std::vector<Jogador> carregarPlacar();

#endif