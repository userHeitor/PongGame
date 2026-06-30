# Pong

Jogo de Pong para 2 jogadores no terminal do Windows, feito em C++.

## Requisitos

- Windows
- [MinGW / g++](https://www.mingw-w64.org/) instalado

## Como rodar

**1. Compile:**
```bash
g++ main.cpp bola.cpp raquete.cpp tabuleiro.cpp jogador.cpp persistencia.cpp jogo.cpp -o pong -std=c++17
```

**2. Execute:**
```bash
./pong
```

## Controles

| Jogador | Cima | Baixo |
|---|---|---|
| Jogador 1 | `W` | `S` |
| Jogador 2 | `↑` | `↓` |

`Q` — sair da partida

## Observação

O jogo **não funciona no terminal do Colab ou Linux**. Execute localmente no Windows.
É necessário estar dentro da pasta contendo os arquivos para compilar.
