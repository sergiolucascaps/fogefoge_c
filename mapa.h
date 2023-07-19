#ifndef _MAPA_H_
#define _MAPA_H_

#include<stdbool.h>

#define MAP_FILE "mapa.txt"

#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA 'P'

struct mapa {
    // matriz de 5 (linhas) X 10 (colunas)
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

struct posicao {
    int x;
    int y;
};

typedef struct posicao POSICAO;

void liberamapa(MAPA* m);
void readmap(MAPA* m);
void alocamapa(MAPA* m);
// void imprimemapa(MAPA* m);
bool encontramapa(MAPA* m, POSICAO* p, char c);
bool direcaopermitida(MAPA* m, int x, int y);
bool direcaoestavazia(MAPA* m, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* origem, MAPA* destino);
bool podeandar(MAPA* m, char personagem, int x, int y);
bool ehparede(MAPA*m, int x, int y);
bool ehpersonagem(MAPA*m, char personagem, int x, int y);

#endif