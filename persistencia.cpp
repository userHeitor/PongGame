#include "persistencia.h"
#include <fstream>
#include <stdexcept>

using namespace std;

const string ARQUIVO_PLACAR = "placar.txt";

// Salva todos os jogadores no arquivo, um por linha (formato: nome vitorias derrotas)
void salvarPlacar(const vector<Jogador> &jogadores)
{
    ofstream arquivo(ARQUIVO_PLACAR);
    if (!arquivo.is_open())
    { // Lança erro se o arquivo não puder ser aberto
        throw runtime_error("Nao foi possivel abrir o arquivo de placar para escrita.");
    }
    for (const auto &j : jogadores)
    { // Escreve cada jogador em uma linha
        arquivo << j.nome << " " << j.vitorias << " " << j.derrotas << "\n";
    }
    arquivo.close();
}

// Lê o arquivo e reconstrói a lista de jogadores
vector<Jogador> carregarPlacar()
{
    vector<Jogador> jogadores;
    ifstream arquivo(ARQUIVO_PLACAR);
    if (!arquivo.is_open())
        return jogadores; // Se o arquivo não existe, retorna lista vazia

    Jogador j;
    while (arquivo >> j.nome >> j.vitorias >> j.derrotas)
    { // Lê linha por linha
        jogadores.push_back(j);
    }
    arquivo.close();
    return jogadores;
}